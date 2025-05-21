#include "logindialog.h"
#include "ui_logindialog.h"
#include "qmessagebox.h"
#include "QMouseEvent"
#include "productdatabasemanager.h"

loginDialog::loginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
}

loginDialog::~loginDialog()
{
    delete ui;
}

QString loginDialog::getUserRole() const {
    return userRole;
}

void loginDialog::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    QString role = ProductDatabaseManager::instance().authenticateUser(username, password);

    if (role == "admin" || role == "user") {
        userRole = role;
        emit loginSuccessful(role, username);
        accept();
    } else {
        QMessageBox::warning(this, "Login:", "Incorrect username or password");
    }
}

void loginDialog::on_signButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (ProductDatabaseManager::instance().registerUser(username, password)) {
        QMessageBox::information(this, "Register", "Registration done successfully!");
    } else {
        QMessageBox::warning(this, "Register", "Error: user already exists");
    }
}

void loginDialog::on_cancelButton_clicked()
{
    reject();
}


