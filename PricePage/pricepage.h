#pragma once
#include "BasePage/basepage.h"
#include "PriceCoin/pricecoin.h"
#include "coinwidget.h"

class PricePage : public BasePage {
    Q_OBJECT


public:
    explicit PricePage(QWidget* parent = nullptr);
    void updateData(const QList<CryptoData>& data,CoinControl* control,bool ascendingOrder);
};
