#ifndef MARKETCAPCOIN_H
#define MARKETCAPCOIN_H
#include <QWidget>
#include "Network/cryptofetcher.h"
#include <QLabel>
#include <QHBoxLayout>

class MarketCapCoin: public QWidget
{
    Q_OBJECT
public:
    MarketCapCoin(const CryptoData& coin,QWidget* parent = nullptr);
};

#endif
