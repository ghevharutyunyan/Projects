#pragma once
#include "BasePage/basepage.h"
#include "coinwidget.h"

class MarketsPage : public BasePage {
    Q_OBJECT
public:
    explicit MarketsPage(QWidget* parent = nullptr);
    void updateData(const QList<CryptoData>& data,CoinControl* control);
};
