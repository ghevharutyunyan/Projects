#pragma once
#include "BasePage/basepage.h"
#include "coinwidget.h"

class ChangePage : public BasePage {
    Q_OBJECT
public:
    explicit ChangePage(QWidget* parent = nullptr);
    void updateData(const QList<CryptoData>& data,CoinControl* control,bool ascendingOrder);
};

