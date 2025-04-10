#include "hotpage.h"

HotPage::HotPage(QWidget* parent)
    : BasePage(parent){}

void HotPage::updateData(const QList<CryptoData>& coins, CoinControl* control) {
    clearData();
    for (const auto& coin : coins) {
        CoinWidget* widget = new CoinWidget(coin, control);
        m_scrollLayout->addWidget(widget);
    }
}


