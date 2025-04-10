#ifndef PRICECOIN_H
#define PRICECOIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Network/cryptofetcher.h"

class PriceCoin : public QWidget {
    Q_OBJECT
public:
    explicit PriceCoin(const CryptoData& coin, QWidget* parent = nullptr);

signals:
    void coinClicked(const QString& symbol);

private:
    QLabel* nameLabel;
    QLabel* priceLabel;
    QPushButton* actionButton;
};

#endif
