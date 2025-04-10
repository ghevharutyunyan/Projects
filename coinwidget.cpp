#include "coinwidget.h"
#include <QFontDatabase>
CoinWidget::CoinWidget(const CryptoData& coin, CoinControl* control, QWidget* parent)
    : QWidget(parent), isFavorite(false), c_control(control), coinSymbol(coin.symbol),coinPrice(coin.price),coinChange(coin.change_24)
{

setStyleSheet(R"(
    QWidget {
        background-color: rgba(255, 255, 255, 0.8);
        border-radius: 12px;
        padding: 12px;
        margin-bottom: 6px;
    }
    QLabel {
        color: #333333;
        font-size: 16px;

    }
    QPushButton {
        background-color: #F5F5F5;
        color: #333;
        border-radius: 8px;
        padding: 6px 12px;
    }
    QPushButton:hover {
        background-color: #E0E0E0;
    }
    QPushButton:pressed {
        background-color: #CCC;
    }
    QPushButton[role='favorite'] {
        background-color: gold;
        color: #222;
    }
)");

    isFavorite = c_control->isFavorite(coinSymbol);

    imageLabel = new QLabel(this);
    imageLabel->setFixedSize(80, 80);
    imageLabel->setPixmap(coin.image.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));


    QFontDatabase::addApplicationFont(":/resources/fonts/fontawesome.ttf");

    actionButton = new QPushButton();
    actionButton->setFixedSize(30, 30);
    actionButton->setProperty("role", "favorite");

    QFont font("FontAwesome");
    font.setPixelSize(20);
    actionButton->setFont(font);

    actionButton->setText(isFavorite ? QString::fromUtf8("\u2605") : QString::fromUtf8("\u2606"));
    connect(actionButton, &QPushButton::clicked, this, &CoinWidget::Favorite);



    nameLabel = new QLabel(QString("<b>%1</b>").arg(coin.name));
    nameLabel->setTextFormat(Qt::RichText);
    nameLabel->setStyleSheet("color: #000000; font-size: 22px;");

    QLabel* tickerLabel = new QLabel(coinSymbol);
    tickerLabel->setStyleSheet("color: #888888; font-size: 14px;");

    priceLabel = new QLabel(QString("%1 $").arg(formatNumber(coin.price)));
    priceLabel->setStyleSheet(QString("font-size:15px;"));
   priceLabel->setStyleSheet("color: #000000; font-size: 17px;");

    marketCapLabel = new QLabel(QString("Market Cap: %1 $").arg(formatNumber(coin.marketCap)));

    change24hLabel = new QLabel(QString("%1%").arg(formatNumber(coin.change_24)));
    change24hLabel->setStyleSheet(QString("color: %1; font-size: 23px;")
                                      .arg(coinChange >= 0 ? "#00C853" : "#D50000"));


    QVBoxLayout* prchange = new QVBoxLayout();
    prchange->addWidget(change24hLabel);
    prchange->addWidget(priceLabel);

    updateStyle();

    mainLayout = new QHBoxLayout(this);
    topLayout = new QHBoxLayout();
    bottomLayout = new QHBoxLayout();


    QVBoxLayout* textLayout = new QVBoxLayout;
    textLayout->addWidget(nameLabel);
    textLayout->addWidget(tickerLabel);

    mainLayout->addWidget(actionButton);
    mainLayout->addWidget(imageLabel);
    mainLayout->addLayout(textLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(prchange);

    connect(c_control, &CoinControl::favoritesUpdated, this, &CoinWidget::updateFavoriteState);
}

CoinWidget::~CoinWidget(){
    delete mainLayout;
    delete actionButton;
    delete imageLabel;
    delete nameLabel;
    delete priceLabel;
    delete change24hLabel;
    delete marketCapLabel;
    delete topLayout;
    delete bottomLayout;
}

QString CoinWidget::formatNumber(double num) {
    return QLocale(QLocale::English).toString(num, 'f', 2);
}

void CoinWidget::mousePressEvent(QMouseEvent* event) {
    QWidget::mousePressEvent(event);
}
void CoinWidget::updateStyle() {
    actionButton->setText(isFavorite ? QString::fromUtf8("\u2605") : QString::fromUtf8("\u2606"));
    actionButton->setStyleSheet(isFavorite ?
                                    "QPushButton {"
                                    "   font-size: 24px;"
                                    "   color: gold;"
                                    "   background-color: rgba(255, 255, 255, 0.1);"
                                    "   border: 2px solid gold;"
                                    "   border-radius: 8px;"
                                    "   padding: 5px;"
                                    "}" :
                                    "QPushButton {"
                                    "   font-size: 24px;"
                                    "   color: #888;"
                                    "   background-color: rgba(255, 255, 255, 0.1);"
                                    "   border: 1px solid #666;"
                                    "   border-radius: 8px;"
                                    "   padding: 5px;"
                                    "}"
                                );
}


void CoinWidget::Favorite() {
    if (!c_control) return;
    c_control->toggleFavorite(coinSymbol,coinPrice,coinChange);
    isFavorite = c_control->isFavorite(coinSymbol);
    updateStyle();
}



void CoinWidget::updateFavoriteState() {
    isFavorite = c_control->isFavorite(coinSymbol);
    updateStyle();
}



