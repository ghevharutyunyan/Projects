QT       += core gui
QT += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = CoinDash
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Network/cryptofetcher.cpp \
    BasePage/basepage.cpp \
    24H_Change/changepage.cpp \
    CoinControl/coincontrol.cpp \
    coinwidget.cpp \
    general.cpp \
    HotPage/hotpage.cpp \
    main.cpp \
    mainwindow.cpp \
    MarketPage/marketspage.cpp \
    PricePage/pricepage.cpp

HEADERS += \
    Network/cryptofetcher.h \
    BasePage/basepage.h \
    24H_Change/changepage.h \
    CoinControl/coincontrol.h \
    coinwidget.h \
    general.h \
    HotPage/hotpage.h \
    mainwindow.h \
    MarketPage/marketspage.h \
    PricePage/pricepage.h

FORMS += \
    24H_Change/changepage.ui \
    general.ui \
    HotPage/hotpage.ui \
    mainwindow.ui \
    MarketPage/marketspage.ui \
    PricePage/pricepage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
