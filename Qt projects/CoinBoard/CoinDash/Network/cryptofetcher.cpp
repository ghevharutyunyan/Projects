#include "Network/cryptofetcher.h"
#include <QDebug>

CryptoFetcher::CryptoFetcher(QObject* parent):QObject(parent) {
    i_networkManager = new QNetworkAccessManager(this);
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager,&QNetworkAccessManager::finished,this,&CryptoFetcher::onReplyFinished);
    connect(i_networkManager,&QNetworkAccessManager::finished,this,&CryptoFetcher::onImageReplyFinished);

}

void CryptoFetcher::fetch_data(){
    QUrl url("https://api.coingecko.com/api/v3/coins/markets?vs_currency=usd");
    QNetworkRequest request(url);
    m_networkManager->get(request);
}

void CryptoFetcher::onReplyFinished(QNetworkReply *reply) {

    QByteArray responseData = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(responseData);

    if (!doc.isArray()) {
        qDebug() << "Invalid JSON structure or empty response.";
        reply->deleteLater();
        return;
    }

    QJsonArray jsarray = doc.array();
    if (jsarray.isEmpty()) {
        qDebug() << "Received empty data array.";
        reply->deleteLater();
        return;
    }

    m_imageRequests.clear();


    QHash<QString, int> map;
    for (int i = 0; i < m_coins.size(); ++i) {
        map[m_coins[i].name] = i;
    }

    for (const auto &value : jsarray) {
        QJsonObject obj = value.toObject();
        QString coinName = obj["name"].toString();

        if (map.contains(coinName)) {
            int index = map[coinName];
            double newPrice = obj["current_price"].toDouble();
            double newMarketCap = obj["market_cap"].toDouble();
            double newChange24 = obj["price_change_percentage_24h"].toDouble();
            if (m_coins[index].price != newPrice) {
                m_coins[index].price = newPrice;
            }
            if (m_coins[index].marketCap != newMarketCap) {
                m_coins[index].marketCap = newMarketCap;
            }
            if (m_coins[index].change_24 != newChange24) {
                m_coins[index].change_24 = newChange24;
            }
        } else {

            CryptoData coin;
            QString imageurl = obj["image"].toString();
            coin.name = coinName;
            coin.symbol = obj["symbol"].toString().toUpper();
            coin.price = obj["current_price"].toDouble();
            coin.marketCap = obj["market_cap"].toDouble();
            coin.change_24 = obj["price_change_percentage_24h"].toDouble();

            m_coins.append(coin);
            QUrl imageUrl(imageurl);
            QNetworkRequest imgRequest(imageUrl);
            QNetworkReply* imgReply = i_networkManager->get(imgRequest);
            m_imageRequests[imgReply] = m_coins.size() - 1;
        }
    }

    reply->deleteLater();
}


void CryptoFetcher::onImageReplyFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        int index = m_imageRequests.value(reply, -1);
        if (index != -1) {
            QByteArray imgData = reply->readAll();
            QPixmap image;
            if (image.loadFromData(imgData)) {
                m_coins[index].image = image;
            } else {
                qDebug() << "Failed to load image for" << m_coins[index].name;
            }


        }
    } else {
        qDebug() << "Image download error:" << reply->errorString();
    }

    m_imageRequests.remove(reply);
    reply->deleteLater();


    if (m_imageRequests.isEmpty()) {
        emit Data_Ready(m_coins);
    }
}


CryptoFetcher::~CryptoFetcher(){
    delete m_networkManager;
    delete i_networkManager;

}































