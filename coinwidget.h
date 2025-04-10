#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "CoinControl/coincontrol.h"
#include "QMouseEvent"
#include "QPalette"

class CoinWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CoinWidget(const CryptoData& coin,CoinControl* control, QWidget* parent = nullptr);
    ~CoinWidget();
    void mousePressEvent(QMouseEvent* event);
    void updateStyle();
public:
    void Favorite();
    QString formatNumber(double num);
    void updateFavoriteState();

private:
    QLabel* nameLabel;
    QLabel* priceLabel;
    QLabel* marketCapLabel;
    QLabel* change24hLabel;
    QLabel* imageLabel;
    QPushButton* actionButton;
    bool isFavorite;
private:
    CoinControl* c_control;
    QString coinSymbol;
    double coinPrice;
    double coinChange;
    QString date;
    QHBoxLayout* bottomLayout;
    QHBoxLayout* mainLayout;
    QHBoxLayout* topLayout;

};
