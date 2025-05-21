#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMainWindow>


namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();
public:
    QString getUserRole() const;

signals:
    void loginSuccessful(const QString& role,const QString& username);

private slots:
    void on_loginButton_clicked();
    void on_cancelButton_clicked();
    void on_signButton_clicked();

private:
    Ui::loginDialog *ui;
    QString userRole;

    bool isMoving = false;
    QPoint mousePosition;
};

#endif // LOGINDIALOG_H
