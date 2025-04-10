#include "HotPage/HotCoin/hotcoin.h"
#include <QHBoxLayout>

HotCoin::HotCoin(const CryptoData& coin, QWidget* parent)
    : QWidget(parent),isFavorite(false)
{
    nameLabel = new QLabel(QString("<b>%1 (%2)</b>").arg(coin.name).arg(coin.symbol));
    nameLabel->setTextFormat(Qt::RichText);

    priceLabel = new QLabel(QString("%1 USD").arg(coin.supply));
    priceLabel->setTextFormat(Qt::RichText);

    actionButton = new QPushButton();


    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(nameLabel);
    layout->addStretch();
    layout->addWidget(priceLabel);
    layout->addWidget(actionButton);



    setStyleSheet(R"(
    QWidget {
        background-color: #222;
        color: white;
        padding: 10px;
        border: 1px solid #444;
        border-radius: 8px;
    }
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

    //connect(actionButton, &QPushButton::clicked, this, [this, coin]() {
    //    emit coinClicked(coin.symbol);
    //});
}

void HotCoin::mousePress(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){
        isFavorite = !isFavorite;
        updateStyle();
        emit favoriteChanged(nameLabel->text(),isFavorite);
    }

    QWidget::mousePressEvent(event);
}




























