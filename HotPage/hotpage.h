#pragma once
#include "BasePage/basepage.h"
#include "coinwidget.h"


class HotPage : public BasePage {
    Q_OBJECT
public:
    explicit HotPage(QWidget* parent = nullptr);
    void updateData(const QList<CryptoData>& data,CoinControl* control);
};
