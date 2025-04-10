#include "PricePage/PriceCoin/pricecoin.h"
#include <QHBoxLayout>
#include <QDebug>

PriceCoin::PriceCoin(const CryptoData& coin, QWidget* parent)
    : QWidget(parent)
{
    nameLabel = new QLabel(QString("<b>%1 (%2)</b>").arg(coin.name).arg(coin.symbol));
    nameLabel->setTextFormat(Qt::RichText);
    nameLabel->setStyleSheet("QLabel { font-size: 14px; color: #FFD700; }");


    priceLabel = new QLabel(QString("%1 USD").arg(coin.price, 0, 'f', 2));
    priceLabel->setTextFormat(Qt::RichText);
    priceLabel->setStyleSheet("QLabel { font-size: 12px; color: #FFFFFF; }");

    actionButton = new QPushButton();
    actionButton->setStyleSheet(R"(
        QPushButton {
            background-color: #005A9E;
            color: white;
            border-radius: 5px;
            padding: 8px;
        }
        QPushButton:hover {
            background-color: #003E73;
        }
        QPushButton:pressed {
            background-color: #002D5D;
        }
    )");

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(nameLabel);
    layout->addStretch();
    layout->addWidget(priceLabel);
    layout->addWidget(actionButton);


    connect(actionButton, &QPushButton::clicked, this, [this, coin]() {
        emit coinClicked(coin.symbol);
    });
}
