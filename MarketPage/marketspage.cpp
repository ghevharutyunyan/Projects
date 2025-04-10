#include "marketspage.h"

MarketsPage::MarketsPage(QWidget* parent) : BasePage(parent) {}

void MarketsPage::updateData(const QList<CryptoData>& coins, CoinControl* control) {
    clearData();
    for (const auto& coin : coins) {
        CoinWidget* widget = new CoinWidget(coin, control);
        m_scrollLayout->addWidget(widget);
    }
}
