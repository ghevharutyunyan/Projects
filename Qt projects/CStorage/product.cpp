#include "product.h"
#include <QMessageBox>
#include <QContextMenuEvent>
#include <QFont>
#include "menuedit.h"

ProductWidget::ProductWidget(const Product& product,const QString& role, QWidget *parent)
    :QWidget{parent},m_product{product},m_role{role}
{
    QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setSizePolicy(policy);

    nameLabel = new QLabel(QString("<b>%1</b>").arg(product.name));
    idLabel = new QLabel(QString("%1").arg(product.id));
    priceLabel = new QLabel(QString("%1").arg(product.price, 0, 'f', 2));

    nameLabel->setSizePolicy(policy);
    idLabel->setSizePolicy(policy);
    priceLabel->setSizePolicy(policy);

    QFont font;
    font.setPointSize(15);
    nameLabel->setFont(font);
    idLabel->setFont(font);
    priceLabel->setFont(font);


    mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(3, 0, 0, 0);
    mainLayout->addWidget(nameLabel);
    mainLayout->addWidget(idLabel);
    mainLayout->addWidget(priceLabel);
    mainLayout->setAlignment(Qt::AlignTop);

    setupStyle();
}

void ProductWidget::setupStyle()
{
    setStyleSheet(
        "QWidget {"
        " background-color: rgb(64, 64, 64);"
        "  color: rgb(144, 238, 144);"
        "border: 1px solid black;"
        "  border-radius: 10px;"
        "  padding: 13px;"
        "}"
        "QLabel {"
        "  padding: 4px;"
        "  font-size: 14px;"
        "}"
        );


    auto shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0, 1);
    shadow->setColor(QColor(0, 0, 0, 160));
    setGraphicsEffect(shadow);
}

Product ProductWidget::getProduct()const{
    return m_product;
}

void ProductWidget::contextMenuEvent(QContextMenuEvent* event)
{
    if (m_role == "user") return;
    QMenu menu(this);
    QAction* editAction = menu.addAction(QIcon(":/Downloads/free-icon-edit-tools-9386099.png"), "Edit");
    QAction* deleteAction = menu.addAction(QIcon(":/Downloads/free-icon-delete-7104075.png"),"Remove");
    connect(editAction, &QAction::triggered, this, &ProductWidget::editTriggered);
    connect(deleteAction, &QAction::triggered, this, &ProductWidget::deleteTriggered);

    QAction* moveUp = menu.addAction(QIcon(":/Downloads/free-icon-up-arrow-25223.png"),"Move up");
    QAction* moveDown = menu.addAction(QIcon(":/Downloads/free-icon-chevron-3549510.png"),"Move down");
    QAction* moveTo = menu.addAction(QIcon(":/Downloads/free-icon-up-and-down-arrows-3314253.png"),"Move to");
    QAction* selectedAction = menu.exec(event->globalPos());

    if (selectedAction == moveUp) {
        emit moveUpRequested(this);
    } else if (selectedAction == moveDown) {
        emit moveDownRequested(this);
    } else if (selectedAction == moveTo) {
        emit moveToIndexRequested(this);
    }
}

void ProductWidget::Edit(){
    menuEdit* NewMenu = new menuEdit(this);
    NewMenu->set_id(m_product.id);
    NewMenu->set_name(m_product.name);
    NewMenu->set_price(m_product.price);

    if(NewMenu->exec() == QDialog::Accepted){
        QString newName = NewMenu->get_name();
        double  newPrice = NewMenu->get_price();
        int newId = NewMenu->get_id();

        bool changed = false;

        if (newName != m_product.name) {
            m_product.name = newName;
            nameLabel->setText(QString("<b>%1</b>").arg(newName));
            changed = true;
        }

        if (!qFuzzyCompare(1.0 + newPrice, 1.0 + m_product.price)) {
            m_product.price = newPrice;
            priceLabel->setText(QString("%1").arg(newPrice, 0, 'f', 2));
            changed = true;
        }

        if (newId != m_product.id) {
            m_product.id = newId;
            idLabel->setText(QString(" %1").arg(newId));
            changed = true;
        }

        if (changed) {
            ProductDatabaseManager::instance().updateProduct(m_product);
            ProductDatabaseManager::instance().insertHistory("Edited: " + m_product.name);
        }
    }

    delete NewMenu;
}

void ProductWidget::mouseDoubleClickEvent(QMouseEvent* event){
    if(m_role == "user")return;
    Edit();
}


void ProductWidget::editTriggered()
{
    if(m_role == "user")return;
    Edit();
}

void ProductWidget::deleteTriggered()
{
    if (!ProductDatabaseManager::instance().get_db()) {
        QMessageBox::warning(this, "Database Error", "Database is not open.");
        return;
    }

    QString historyEntry = "Deleted: " + m_product.name;
    if (!ProductDatabaseManager::instance().insertHistory(historyEntry)) {
        QMessageBox::warning(this, "Error", "Failed to insert history record.");
        return;
    }

    if (!ProductDatabaseManager::instance().deleteProduct(m_product.id)) {
        QMessageBox::warning(this, "Error", "Failed to delete product.");
        return;
    }

    emit productDeleted(this);
    this->deleteLater();
}

