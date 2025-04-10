#ifndef CRYPTOFETCHER_H
#define CRYPTOFETCHER_H
#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QList>
#include <QPixmap>


class CryptoData {
public:
    QString name;
    QString symbol;
    double price;
    double marketCap;
    double change_24;
    QPixmap image;
};

class CryptoFetcher : public QObject {
    Q_OBJECT

public:
    CryptoFetcher(QObject* parent = nullptr);
    ~CryptoFetcher();
    void onReplyFinished(QNetworkReply *reply);
    void onImageReplyFinished(QNetworkReply* reply);
    void fetch_data();

signals:
    void Data_Ready(QList<CryptoData>&);

private:
    QNetworkAccessManager* i_networkManager;
    QNetworkAccessManager* m_networkManager;
    QMap<QNetworkReply*, int> m_imageRequests;
    QList<CryptoData> m_coins;
};

#endif
