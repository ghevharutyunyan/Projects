#include "coincontrol.h"

CoinControl::CoinControl(QObject* parent):QObject(parent) {
    m_network = new CryptoFetcher(this);
    connect(m_network, &CryptoFetcher::Data_Ready, this, &CoinControl::updateCoins);
}

void CoinControl::fetchData(){
    m_network->fetch_data();
}

QList<CryptoData> CoinControl::get_HotCoins(){
    QList<CryptoData> copy_coins = m_coins;
    return copy_coins;
}


QList<CryptoData> CoinControl::get_MarketCoins(){
    QList<CryptoData> copy_coins = m_coins;
    std::sort(copy_coins.begin(), copy_coins.end(), [](const CryptoData& a, const CryptoData& b) {
        return a.marketCap > b.marketCap;});
    return copy_coins;
}

QList<CryptoData> CoinControl::get_PriceCoins(){
   /* QList<CryptoData> copy_coins = m_coins;
    std::sort(copy_coins.begin(), copy_coins.end(), [](const CryptoData& a, const CryptoData& b) {
        return a.price > b.price;});*/
    return m_coins;
}

QList<CryptoData> CoinControl::get_ChangeCoins(){
    QList<CryptoData> copy_coins = m_coins;
    std::sort(copy_coins.begin(), copy_coins.end(), [](const CryptoData& a, const CryptoData& b) {
        return a.change_24 > b.change_24;});
    return copy_coins;
}

void CoinControl::updateCoins(const QList<CryptoData>& coins) {
    m_coins = coins;
    emit for_general(m_coins);
}

bool CoinControl::isFavorite(const QString& symbol) const {
    return favoriteCoins.contains(symbol);
}

void CoinControl::saveFavoritesToFile() {
    if (favoriteCoins.isEmpty()) {
        return;
    }

    QFile file("favorites.txt");

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Error opening file: " << file.errorString();
        return;
    }

    QTextStream out(&file);
    for (auto it = favoriteCoins.begin(); it != favoriteCoins.end(); ++it) {
        out << "Name:" << it.key()
        << " Price:" << it.value().first.first
        << " 24H_Change:" << it.value().first.second
        << " Date:" << it.value().second << "\n";
    }

    file.close();
}

void CoinControl::toggleFavorite(const QString& symbol,const double price,const double change) {
    if (favoriteCoins.contains(symbol)) {
        favoriteCoins.remove(symbol);
    } else {
        QString currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        favoriteCoins.insert(symbol, QPair<QPair<double, double>, QString>(QPair<double, double>(price, change), currentDate));
    }

emit favoritesUpdated();
}





