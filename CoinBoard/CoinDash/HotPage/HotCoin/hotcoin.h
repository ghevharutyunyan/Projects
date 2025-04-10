#ifndef HOTCOIN_H
#define HOTCOIN_H
#include <QWidget>
#include "Network/cryptofetcher.h"
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>

class HotCoin:public QWidget
{
    Q_OBJECT
public:
    HotCoin(const CryptoData &coin,QWidget* parent = nullptr);

signals:
    void mousePress(QMouseEvent* event);
    void favoriteChanged(const QString& symbol, bool isFavorite);


private:
    QLabel* nameLabel;
    QLabel* priceLabel;
    QPushButton* actionButton;
    bool isFavorite;
    void updateStyle();
};

#endif
