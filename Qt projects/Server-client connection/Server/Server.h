#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    void cleanUpSockets();

private slots:
    void onNewConnected();
    void onReadyRead();
    void onClientDisconnected();


private:
    QList<QTcpSocket*> sockets;
    QTcpServer *tcpServer;
};

#endif // SERVER_H
