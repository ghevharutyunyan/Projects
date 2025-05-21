#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket,&QTcpSocket::connected, this,[=](){
        qDebug() << "Connected to Server";
    });

    connect(socket,&QTcpSocket::errorOccurred, this, [](QAbstractSocket::SocketError socketError){
        qWarning() << "Connection Error:" << socketError;
        switch(socketError){
        case QAbstractSocket::ConnectionRefusedError:
            qWarning() << "Server is not running or refused connection.";
            break;
        case QAbstractSocket::HostNotFoundError:
            qWarning() << "Server not found.Check IP or hostname.";
            break;
        case QAbstractSocket::NetworkError:
            qWarning() << "Network error occured.";
            break;
        default:
            qWarning() << "Unknown socket error.";
        }
    });

    connect(socket,&QTcpSocket::readyRead, this, &MainWindow::onReadyRead);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReadyRead()
{
    QByteArray data = socket->readAll();
    ui->textBrowser->append(QString::fromUtf8(data));
}

void MainWindow::on_connectButton_clicked()
{
    socket->connectToHost("127.0.0.1", 1111);
}

void MainWindow::on_sendButton_clicked()
{
    QString str = ui->lineEdit->text();
    if(!str.isEmpty() && socket->state() == QAbstractSocket::ConnectedState){
        socket->write(str.toUtf8());
    }else{
        qDebug() << "Not connected or empty message ";
    }
    ui->lineEdit->clear();
 }
