#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menuadd.h"
#include "menuedit.h"
#include "productdatabasemanager.h"
#include "QPoint"
#include "product.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(const QString &role,QWidget *parent = nullptr);
    ~MainWindow();

public:
    void showHistoryInMessageBox(const QList<QPair<QString, QString>>& history);

protected:
    void mousePressEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
    void mouseReleaseEvent(QMouseEvent* event)override;

private slots:
    void on_AddButton_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_exportButton_clicked();
    void on_historyButton_clicked();

    void showAllProducts(const QList<Product>& products);
    void onExportFinished(const QString& message);
    void connectProductWidget(ProductWidget* widget);

    void moveProductUp(ProductWidget* widget);
    void moveProductDown(ProductWidget* widget);
    void moveProductTo(ProductWidget* widget);

    void on_filtrByID_clicked();
    void on_filtrByName_clicked();

    void on_hideButton_clicked();
    void on_closeButton_clicked();

private:
    Ui::MainWindow *ui;

    menuAdd* addMenu;
    menuEdit* editMenu;

    QPoint mousePosition;
    bool isMoving = false;

    QString userRole;
};
#endif // MAINWINDOW_H
