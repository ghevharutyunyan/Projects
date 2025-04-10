#include "24H_Change/ChangeCoin/changecoin.h"

ChangeCoin::ChangeCoin(const CryptoData& coin, QWidget* parent)
    : QWidget(parent)
{
    QLabel* nameLabel = new QLabel(QString("<b>%1</b>").arg(coin.symbol));

    double change = coin.change_24;
    QLabel* changeLabel = new QLabel(QString("%1%").arg(QString::number(change, 'f', 2)));

    QString color = (change >= 0) ? "lightgreen" : "red";
    changeLabel->setStyleSheet(QString("color: %1;").arg(color));

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(nameLabel);
    layout->addStretch();
    layout->addWidget(changeLabel);

    setStyleSheet("background-color: #1e1e1e; color: white; padding: 10px; border: 1px solid #444; border-radius: 6px;");
}
