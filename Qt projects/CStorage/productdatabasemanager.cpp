#include "productdatabasemanager.h"
#include <QCryptographicHash>
#include <QDebug>

static QString hashPassword(const QString &password) {
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}

ProductDatabaseManager& ProductDatabaseManager::instance() {
    static ProductDatabaseManager instance("products.db");
    return instance;
}

ProductDatabaseManager::ProductDatabaseManager(const QString& path) {
    if (QSqlDatabase::contains("product_connection")) {
        db = QSqlDatabase::database("product_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "product_connection");
        db.setDatabaseName(path);
    }

    if (!db.open()) {
        qDebug() << "Unable to open db:" << db.lastError().text();
    }
}

ProductDatabaseManager::~ProductDatabaseManager() {
    db.close();
}

bool ProductDatabaseManager::createTable() {
    QSqlQuery query(db);

    QString productTableSql = R"(
        CREATE TABLE IF NOT EXISTS products (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            price REAL NOT NULL,
            position INTEGER
        )
    )";

    query.exec("ALTER TABLE products ADD COLUMN position INTEGER");
    if (!query.exec(productTableSql)) return false;

    QString usersTableSql = R"(
        CREATE TABLE IF NOT EXISTS users(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            role TEXT CHECK(role IN('admin', 'user')) NOT NULL
        )
    )";
    if (!query.exec(usersTableSql)) return false;

    QString historyTableSql = R"(
        CREATE TABLE IF NOT EXISTS history (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            action TEXT NOT NULL,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    )";

    if (!query.exec(historyTableSql)) return false;

    QSqlQuery checkAdminQuery(db);
    checkAdminQuery.prepare("SELECT COUNT(*) FROM users WHERE role = 'admin'");
    if (checkAdminQuery.exec() && checkAdminQuery.next()) {
        int count = checkAdminQuery.value(0).toInt();
        if (count == 0) {
            QSqlQuery insertAdminQuery(db);
            insertAdminQuery.prepare("INSERT INTO users (username, password, role) VALUES (:u, :p, 'admin')");
            insertAdminQuery.bindValue(":u", "admin");
            insertAdminQuery.bindValue(":p", hashPassword("admin"));
            insertAdminQuery.exec();
        }
    }

    return true;
}

/*int ProductDatabaseManager::getNextPosition() {
    QSqlQuery query(db);
    query.prepare("SELECT MAX(position) FROM products");
    if (query.exec() && query.next()) {
        return query.value(0).toInt() + 1;
    }
    return 0;
}*/

bool ProductDatabaseManager::insertProduct(const Product& product){
    QSqlQuery query(db);


    int newPosition = 0;
    QSqlQuery posQuery(db);
    posQuery.prepare("SELECT MAX(position) FROM products");
    if(posQuery.exec() && posQuery.next()) {
        QVariant result = posQuery.value(0);
        if (result.isValid() && !result.isNull()) {
            newPosition = result.toInt() + 1;
            qDebug() << newPosition;
        }
    }

    query.prepare("INSERT INTO products (id, name, price, position) VALUES (?, ?, ?, ?)");
    query.addBindValue(product.id);
    query.addBindValue(product.name);
    query.addBindValue(product.price);
    query.addBindValue(newPosition);

    return query.exec();
}


bool ProductDatabaseManager::insertHistory(const QString& action){
    QSqlQuery query(db);
    query.prepare("INSERT INTO history (action) VALUES (:action)");
    query.bindValue(":action", action);
    query.exec();

    QSqlQuery cleanupQuery(db);
    cleanupQuery.prepare(R"(
        DELETE FROM history
        WHERE id NOT IN (
            SELECT id FROM history ORDER BY id DESC LIMIT 100
        )
    )");
    return cleanupQuery.exec();
}

QList<QPair<QString,QString>> ProductDatabaseManager::getLastHistory(int limit){
    QList<QPair<QString,QString>> history;
    QSqlQuery query(db);
    query.prepare("SELECT action, timestamp FROM history ORDER BY id DESC LIMIT :limit");
    query.bindValue(":limit", limit);

    if (query.exec()) {
        while (query.next()) {
            QString action = query.value(0).toString();
            QString timestamp = query.value(1).toString();
            history.append(qMakePair(action, timestamp));
        }
    } else {
        qDebug() << "History query failed:" << query.lastError().text();
    }
    return history;
}

bool ProductDatabaseManager::updateProduct(const Product& product){
    QSqlQuery query(db);
    query.prepare("UPDATE products SET name = ?, price = ? WHERE id = ?");
    query.addBindValue(product.name);
    query.addBindValue(product.price);
    query.addBindValue(product.id);

    return query.exec();
}

bool ProductDatabaseManager::updateProductPosition(int productID,int newPosition){
    QSqlQuery query(db);
    query.prepare("UPDATE products SET position = :pos WHERE id = :id");
    query.bindValue(":pos",newPosition);
    query.bindValue(":id",productID);

    if (!query.exec()) {
        qDebug() << "Failed to update product position:" << query.lastError().text();
        return false;
    }
    return true;
}

bool ProductDatabaseManager::swapProductsPosition(int id1,int id2){
    QSqlQuery query(db);
    query.prepare("SELECT id, position FROM products WHERE id = :id1 OR id = :id2");
    query.bindValue(":id1",id1);
    query.bindValue(":id2",id2);

    int pos1 = -1;
    int pos2 = -1;

    if(query.exec()){
        while(query.next()){
            int id = query.value(0).toInt();
            int pos = query.value(1).toInt();

            if(id == id1) pos1 = pos;
            else if(id == id2) pos2 = pos;
        }
    }

    if(pos1 == -1 || pos2 == -1)return false;

    QSqlQuery query1(db);
    query1.prepare("UPDATE products SET position = :pos WHERE id = :id");
    query1.bindValue(":id",id1);
    query1.bindValue(":pos",pos2);

    QSqlQuery query2(db);
    query2.prepare("UPDATE products SET position = :pos WHERE id = :id");
    query2.bindValue(":id",id2);
    query2.bindValue(":pos",pos1);

    return query1.exec() && query2.exec();
}

void ProductDatabaseManager::compactPositionsAfterRemoval(int removedPosition) {
    QSqlQuery updateQuery(db);
    updateQuery.prepare(R"(
        UPDATE products
        SET position = position - 1
        WHERE position > :removedPosition)");

    updateQuery.bindValue(":removedPosition", removedPosition);
    updateQuery.exec();
}

bool ProductDatabaseManager::deleteProduct(int id){
    QSqlQuery getPosQuery(db);
    getPosQuery.prepare("SELECT position FROM products WHERE id = ?");
    getPosQuery.addBindValue(id);

    int pos = -1;
    if(getPosQuery.exec() && getPosQuery.next()){
        pos = getPosQuery.value(0).toInt();
    }

    QSqlQuery deleteQuery(db);
    deleteQuery.prepare("DELETE FROM products WHERE id = ?");
    deleteQuery.addBindValue(id);
    bool success = deleteQuery.exec();

    if(success && pos != -1){
        compactPositionsAfterRemoval(pos);
    }

    return success;
}

QList<Product> ProductDatabaseManager::getAllProducts(){
    QList<Product> products;
    QSqlQuery query(db);

    query.prepare("SELECT id, name, price, position FROM products ORDER BY position ASC");
    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return {};
    }

    while (query.next()) {
        Product p;
        p.id = query.value(0).toInt();
        p.name = query.value(1).toString();
        p.price = query.value(2).toDouble();
        p.position = query.value(3).toInt();

        products.append(p);
    }

    return products;
}

QList<Product> ProductDatabaseManager::filtred_by_Id(int id) {
    QList<Product> products;
    QSqlQuery query(db);
    query.prepare("SELECT id, name, price, position FROM products WHERE id = ?");
    query.addBindValue(id);

    if (query.exec()) {
        while (query.next()) {
            Product p;
            p.id = query.value(0).toInt();
            p.name = query.value(1).toString();
            p.price = query.value(2).toDouble();
            p.position = query.value(3).toInt();
            products.append(p);
        }
    }
    return products;
}

QList<Product> ProductDatabaseManager::filtred_by_Name(const QString &name) {
    QList<Product> products;
    QSqlQuery query(db);
    query.prepare("SELECT id, name, price, position FROM products WHERE name LIKE ?");
    query.addBindValue("%" + name + "%");

    if (query.exec()) {
        while (query.next()) {
            Product p;
            p.id = query.value(0).toInt();
            p.name = query.value(1).toString();
            p.price = query.value(2).toDouble();
            p.position = query.value(3).toInt();
            products.append(p);
        }
    }
    return products;
}

QList<Product> ProductDatabaseManager::getAllProductsSortedById(){
    QList<Product> products;
    QSqlQuery query(db);
    query.prepare("SELECT id, name, price, position FROM products ORDER BY id");

    if(query.exec()){
        while(query.next()){
            Product p;
            p.id = query.value(0).toInt();
            p.name = query.value(1).toString();
            p.price = query.value(2).toDouble();
            p.position = query.value(3).toInt();
            products.append(p);
        }
    }
    return products;
}


QList<Product> ProductDatabaseManager::getAllProductsSortedByName(){
    QList<Product> products;
    QSqlQuery query(db);
    query.prepare("SELECT id, name, price, position FROM products ORDER BY name");

    if(query.exec()){
        while(query.next()){
            Product p;
            p.id = query.value(0).toInt();
            p.name = query.value(1).toString();
            p.price = query.value(2).toDouble();
            p.position = query.value(3).toInt();
            products.append(p);
        }
    }
    return products;
}


bool ProductDatabaseManager::registerUser(const QString &username, const QString& password){
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (username, password, role) VALUES (:username, :password, 'user')");
    query.bindValue(":username", username);
    query.bindValue(":password", hashPassword(password));
    return query.exec();
}

QString ProductDatabaseManager::authenticateUser(const QString& username, const QString& password){
    QSqlQuery query(db);
    query.prepare("SELECT role, password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString storedHash = query.value(1).toString();
        if (storedHash == hashPassword(password)) {
            return query.value(0).toString();
        }
    }
    return "";
}

bool ProductDatabaseManager::get_db(){
    return db.isOpen();
}
