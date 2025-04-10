#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "general.h"

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();

private:
    Ui::MainWindow *ui;
    General *window;
    QLabel* usernameLabel;
    QLabel* passwordLabel;
    QPushButton* Login;
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;

};
#endif // MAINWINDOW_H
