#include "Server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::onNewConnected);
    tcpServer->listen(QHostAddress::Any, 1111);
}
Server::~Server(){
    tcpServer->close();
    delete tcpServer;
    cleanUpSockets();
}


void Server::onNewConnected(){
    QTcpSocket* newSocket = tcpServer->nextPendingConnection();
    sockets.append(newSocket);

    qDebug() << "New Client connected: " << newSocket->peerAddress().toString();

    connect(newSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(newSocket, &QTcpSocket::disconnected, this, &Server::onClientDisconnected);
}

void Server::onReadyRead(){
    QTcpSocket *newSocket = qobject_cast<QTcpSocket*>(sender());
    if(!newSocket) return;

    QByteArray data = newSocket->readAll();
    for(QTcpSocket* client:sockets){
        if(client && newSocket != nullptr){
            newSocket->write("From Server: " + data);
        }

    }
}

void Server::onClientDisconnected(){
    QTcpSocket *deleteSocket = qobject_cast<QTcpSocket*>(sender());
    if(!deleteSocket)return;

    sockets.removeAll(deleteSocket);
    deleteSocket->deleteLater();
}

void Server::cleanUpSockets(){
    for(QTcpSocket* socket : std::exchange(sockets,{})){
        if(socket->isOpen()){
            socket->disconnectFromHost();
            socket->waitForDisconnected(1000);
        }
        delete socket;
    }
}











