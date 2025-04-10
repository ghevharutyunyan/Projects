#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "general.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    usernameLabel = new QLabel("Username:");
    passwordLabel = new QLabel("Password:");

    usernameEdit = new QLineEdit();
    passwordEdit = new QLineEdit();

    passwordEdit->setEchoMode(QLineEdit::Password);

    Login = new QPushButton("Login");

    QHBoxLayout* nameLayout = new QHBoxLayout();
    nameLayout->addWidget(usernameLabel);
    nameLayout->addWidget(usernameEdit);

    QHBoxLayout* passwordLayout = new QHBoxLayout();
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordEdit);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(passwordLayout);
    mainLayout->addWidget(Login);

    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    connect(Login,&QPushButton::clicked,this,&MainWindow::onLoginClicked);

    window = nullptr;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete window;
    delete usernameLabel;
    delete passwordLabel;
    delete usernameEdit;
    delete passwordEdit;
}

void MainWindow::onLoginClicked(){
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if(username == "admin" && password == "1234"){
        QMessageBox::information(this,"Login","Login successful!");

        hide();
        window = new General(this);
        window->show();
    }else{
        QMessageBox::warning(this,"Login","invalid username or password");
    }
}



