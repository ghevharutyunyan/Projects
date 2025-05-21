#ifndef COINCONTROL_H
#define COINCONTROL_H
#include <QList>
#include <QObject>
#include "QNetworkReply"
#include "Network/cryptofetcher.h"
#include <QFile>

class CoinControl: public QObject
{
    Q_OBJECT
public:
    CoinControl(QObject* parent = nullptr);
public:
    QList<CryptoData> get_HotCoins();
    QList<CryptoData> get_MarketCoins();
    QList<CryptoData> get_PriceCoins();
    QList<CryptoData> get_ChangeCoins();

    void toggleFavorite(const QString& symbol,const double price,const double change);
    bool isFavorite(const QString& symbol)const;
    void saveFavoritesToFile();
    void fetchData();

public slots:
    void updateCoins(const QList<CryptoData>& coins);
signals:
    void favoritesUpdated();
    void for_general(const QList<CryptoData>&);


private:
    QHash<QString, QPair<QPair<double, double>, QString>> favoriteCoins;
    QList<CryptoData> m_coins;
    CryptoFetcher* m_network;
};

#endif
