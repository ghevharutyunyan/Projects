#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "Network/cryptofetcher.h"
#include "HotPage/hotpage.h"
#include "MarketPage/marketspage.h"
#include "PricePage/pricepage.h"
#include "24H_Change/changepage.h"
#include <QTimer>
#include <QSet>
#include "CoinControl/coincontrol.h"
#include <QIcon>
#include <QStyle>


class General: public QMainWindow {
    Q_OBJECT

public:
    General(QWidget *parent = nullptr);
    ~General();

public:
    void Hot_clicked();
    void Market_clicked();
    void Price_clicked();
    void Change_clicked();

    void updateArrow(QLabel* label, bool ascending);


public slots:
    void onDataReady(const QList<CryptoData>& coins);

private:
    QWidget* centralWidget;
    QHBoxLayout* mainLayout;
    QWidget* currentView;

    QHBoxLayout* buttonLayout;
    QWidget* btnWidget;

    QPushButton* btnHot;
    QPushButton* btnMarketCap;
    QPushButton* btnPrice;
    QPushButton* btnChange;

    QLabel* arrowPrice;
    QLabel* arrowChange;

    ChangePage* m_change;
    PricePage* m_price;
    MarketsPage* m_marketpage;
    HotPage* m_hotpage;
    QVBoxLayout* fullLayout;
    QTimer * updateTime;
private:
    CoinControl* c_control;
    CoinWidget* coin_w;

    //flags
    bool priceAscendingOrder = true;
    bool changeAscendingOrder = true;

    void showView(QWidget* view);
};
