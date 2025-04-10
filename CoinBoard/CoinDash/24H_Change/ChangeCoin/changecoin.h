#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "Network/cryptofetcher.h"

class ChangeCoin: public QWidget {
    Q_OBJECT

public:
    ChangeCoin(const CryptoData& coin, QWidget* parent = nullptr);
};
