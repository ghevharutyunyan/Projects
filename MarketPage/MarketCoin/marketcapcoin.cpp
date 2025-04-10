#include "MarketPage/MarketCoin/marketcapcoin.h"

MarketCapCoin::MarketCapCoin(const CryptoData& coin, QWidget* parent)
    : QWidget(parent)
{
    QLabel* nameLabel = new QLabel(QString("<b>%1</b>").arg(coin.symbol));
    QLabel* capLabel = new QLabel(QString("Market Cap: $%1").arg(coin.marketCap));

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(nameLabel);
    layout->addStretch();
    layout->addWidget(capLabel);

    setStyleSheet("background-color: #1e1e1e; color: white; padding: 10px; border: 1px solid #444; border-radius: 6px;");
}
