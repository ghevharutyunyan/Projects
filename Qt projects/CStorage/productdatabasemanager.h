#ifndef PRODUCTDATABASEMANAGER_H
#define PRODUCTDATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>

struct Product {
    QString name;
    int id;
    double price;
    int position;
};

class ProductDatabaseManager {
public:
    static ProductDatabaseManager& instance();

    bool createTable();
    int getNextPosition();

    bool insertProduct(const Product& product);
    bool insertHistory(const QString& action);
    bool updateProduct(const Product& product);

    bool updateProductPosition(int productId, int newPosition);
    bool swapProductsPosition(int id1,int id2);
    void compactPositionsAfterRemoval(int removedPosition);
    bool deleteProduct(int id);

    QList<Product> getAllProducts();
    QList<Product> filtred_by_Id(int id);
    QList<Product> filtred_by_Name(const QString &name);
    QList<Product> getAllProductsSortedById();
    QList<Product> getAllProductsSortedByName();
    QList<QPair<QString,QString>> getLastHistory(int limit);

    bool registerUser(const QString &username,const QString& password);
    QString authenticateUser(const QString& username,const QString& password);

    bool get_db();

private:
    explicit ProductDatabaseManager(const QString& path = "products.db");
    ~ProductDatabaseManager();

    ProductDatabaseManager(const ProductDatabaseManager&) = delete;
    ProductDatabaseManager& operator=(const ProductDatabaseManager&) = delete;

    QSqlDatabase db;
};

#endif // PRODUCTDATABASEMANAGER_H
