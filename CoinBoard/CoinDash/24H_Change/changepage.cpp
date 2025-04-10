#include "changepage.h"

ChangePage::ChangePage(QWidget* parent) : BasePage(parent) {}

void ChangePage::updateData(const QList<CryptoData>& coins, CoinControl* control,bool changeAscendingOrder) {
    clearData();
    QList<CryptoData> sortedCoins = coins;

    if(changeAscendingOrder){
    std::sort(sortedCoins.begin(),sortedCoins.end(),[](CryptoData& a,CryptoData& b){
        return a.change_24 < b.change_24;
        });}else{
        std::sort(sortedCoins.begin(),sortedCoins.end(),[](CryptoData& a,CryptoData& b){
            return a.change_24 > b.change_24;
        });
    }

    for (const auto& coin : sortedCoins) {
        CoinWidget* widget = new CoinWidget(coin, control);
        m_scrollLayout->addWidget(widget);
    }
}
