#include "basepage.h"

BasePage::BasePage(QWidget* parent) : QWidget(parent) {
    m_mainLayout = new QVBoxLayout(this);
    m_scrollArea = new QScrollArea(this);
    m_contentWidget = new QWidget(this);
    m_scrollLayout = new QVBoxLayout(m_contentWidget);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setWidget(m_contentWidget);
    m_scrollArea->setStyleSheet(
        "QScrollArea {"
        "    background-color: white;"
        "    border: 1px solid #ddd;"
        "    border-radius: 8px;"
        "    padding: 5px;"
        "}"

        "QScrollBar:vertical {"
        "    width: 12px;"                     // Ширина вертикал
        "    background: #f0f0f0;"
        "    border-radius: 6px;"               //
        "    margin: 0px 2px 0px 2px;"          // Отступы от б
        "}"

        "QScrollBar::handle:vertical {"
        "    background: #888;"
        "    border-radius: 6px;"
        "    min-height: 40px;"
        "}"

        "QScrollBar::handle:vertical:hover {"
        "    background: #555;"                 // Цвет ползунка при наведении
        "}"

        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "    background: none;"                 // Убираем фон для кнопок
        "    border: none;"                     // Убираем границу
        "}"

        "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
        "    background: none;"                 // Убираем фон для стрелок
        "    border: none;"                     // Убираем границу для стрелок
        "}"

        "QScrollBar::vertical:hover {"
        "    background: #e0e0e0;"             // Более яркий фон при наведении
        "}"

        "QScrollBar:horizontal {"
        "    height: 12px;"                     // Высота горизонтального скроллбара
        "    background: #f0f0f0;"             // Светлый фон
        "    border-radius: 6px;"               // Скругленные углы
        "    margin: 2px 0px 2px 0px;"          // Отступы от верхних и нижних элементов
        "}"

        "QScrollBar::handle:horizontal {"
        "    background: #888;"                 // Цвет самого ползунка для горизонтального скролла
        "    border-radius: 6px;"               // Скругленные углы у ползунка
        "    min-width: 40px;"                  // Минимальная ширина ползунка
        "}"

        "QScrollBar::handle:horizontal:hover {"
        "    background: #555;"                 // Цвет ползунка при наведении
        "}"
        );



    m_mainLayout->addWidget(m_scrollArea);
    setLayout(m_mainLayout);
}

void BasePage::clearData() {
    QLayoutItem* child;
    while ((child = m_scrollLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
    }
}



