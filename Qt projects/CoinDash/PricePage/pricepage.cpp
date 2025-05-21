#include "pricepage.h"

PricePage::PricePage(QWidget* parent) : BasePage(parent) {}

void PricePage::updateData(const QList<CryptoData>& coins, CoinControl* control,bool ascendingOrder) {
    clearData();

    QList<CryptoData> sortedCoins = coins;

    if(ascendingOrder){
    std::sort(sortedCoins.begin(),sortedCoins.end(),[](CryptoData& a,CryptoData& b){
        return a.price < b.price;
        });}
    else{
    std::sort(sortedCoins.begin(),sortedCoins.end(),[](CryptoData& a,CryptoData& b){
            return a.price > b.price;});
    }

    for (const auto& coin : sortedCoins) {
        CoinWidget* widget = new CoinWidget(coin, control);
        m_scrollLayout->addWidget(widget);
    }

}


