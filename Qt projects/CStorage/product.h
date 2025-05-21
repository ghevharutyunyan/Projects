#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QContextMenuEvent>
#include <QGraphicsDropShadowEffect>
#include "productdatabasemanager.h"


class ProductWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProductWidget(const Product& product,const QString &role, QWidget *parent = nullptr);

    void Edit();
    Product getProduct()const;

signals:
    void productDeleted(ProductWidget* widget);
    void moveUpRequested(ProductWidget* widget);
    void moveDownRequested(ProductWidget* widget);
    void moveToIndexRequested(ProductWidget* widget);

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event)override;

private slots:
    void editTriggered();
    void deleteTriggered();

private:
    QLabel* nameLabel;
    QLabel* idLabel;
    QLabel* priceLabel;

    QHBoxLayout* mainLayout;
    void setupStyle();

    Product m_product;
    QString m_role;
};

#endif // PRODUCTWIDGET_H
