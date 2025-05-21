#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include "Network/cryptofetcher.h"

class BasePage : public QWidget {
    Q_OBJECT
public:
    explicit BasePage(QWidget* parent = nullptr);
    void clearData();
    void addLabel(const QString& text);
    void addwidget(QWidget* widget);

protected:
    QVBoxLayout* m_mainLayout;
    QWidget* m_contentWidget;
    QScrollArea* m_scrollArea;
    QVBoxLayout* m_scrollLayout;
};
