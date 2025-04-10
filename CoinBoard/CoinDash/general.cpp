#include "general.h"


General::General(QWidget *parent)
    : QMainWindow(parent),
    centralWidget(new QWidget(this)),
    mainLayout(new QHBoxLayout),
    currentView(nullptr)

{
    arrowPrice = new QLabel(this);
    arrowChange = new QLabel(this);

    arrowPrice->setPixmap(QPixmap(":/icons/up_arrow.png").scaled(10, 10, Qt::KeepAspectRatio));
    arrowChange->setPixmap(QPixmap(":/icons/up_arrow.png").scaled(10, 10, Qt::KeepAspectRatio));

    arrowPrice->setFixedSize(10, 10);
    arrowPrice->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    arrowChange->setFixedSize(10, 10);
    arrowChange->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    updateArrow(arrowPrice,priceAscendingOrder);
    updateArrow(arrowChange,changeAscendingOrder);




    c_control = new CoinControl(this);
    m_change = new ChangePage();
    m_price = new PricePage();
    m_marketpage = new MarketsPage();
    m_hotpage = new HotPage();

    btnHot = new QPushButton("Hot");
    btnMarketCap = new QPushButton("Market Cap");
    btnPrice = new QPushButton("Price");
    btnChange = new QPushButton("24H Change");

    QString btnStyle = R"(
QPushButton {
    background-color: transparent;
    color: #2C2F33;
    border: none;
    padding: 8px 0px;
    font-size: 18px;
    font-weight: bold;

}

QPushButton:hover {
    color: #3498db;
}

QPushButton:pressed {
    color: #2980b9;
}
)";

    btnHot->setStyleSheet(btnStyle);
    btnMarketCap->setStyleSheet(btnStyle);
    btnPrice->setStyleSheet(btnStyle);
    btnChange->setStyleSheet(btnStyle);

    connect(c_control, &CoinControl::for_general, this, &General::onDataReady);

    connect(btnHot, &QPushButton::clicked, this, &General::Hot_clicked);
    connect(btnMarketCap, &QPushButton::clicked, this, &General::Market_clicked);
    connect(btnPrice, &QPushButton::clicked, this, &General::Price_clicked);
    connect(btnChange, &QPushButton::clicked, this, &General::Change_clicked);

    QHBoxLayout* priceLayout = new QHBoxLayout;
    priceLayout->setSpacing(1);
    priceLayout->setContentsMargins(0, 0, 0, 0);
    priceLayout->addWidget(btnPrice, 0, Qt::AlignRight);
    priceLayout->addWidget(arrowPrice, 0, Qt::AlignLeft);

    QHBoxLayout* changeLayout = new QHBoxLayout;
    changeLayout->setSpacing(1);
    changeLayout->setContentsMargins(0, 0, 0, 0);
    changeLayout->addWidget(btnChange, 0, Qt::AlignRight);
    changeLayout->addWidget(arrowChange, 0, Qt::AlignLeft);


    QWidget* priceWidget = new QWidget;
    priceWidget->setLayout(priceLayout);
    priceWidget->setStyleSheet("background-color: transparent;");

    QWidget* changeWidget = new QWidget;
    changeWidget->setLayout(changeLayout);
    changeWidget->setStyleSheet("background-color: transparent;");

    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(btnHot);
    buttonLayout->addWidget(btnMarketCap);
    buttonLayout->addWidget(priceWidget);
    buttonLayout->addWidget(changeWidget);

    btnWidget = new QWidget;
    btnWidget->setLayout(buttonLayout);
    btnWidget->setStyleSheet("background-color: transparent;");

    currentView = m_hotpage;
    mainLayout->addWidget(currentView);

    fullLayout = new QVBoxLayout;
    fullLayout->addWidget(btnWidget);
    fullLayout->addLayout(mainLayout);

    centralWidget->setStyleSheet("background-color: rgba(255, 255, 255, 240);");
    centralWidget->setLayout(fullLayout);
    setCentralWidget(centralWidget);

    c_control->fetchData();

    updateTime = new QTimer(this);
    connect(updateTime,&QTimer::timeout,c_control, &CoinControl::fetchData);
    connect(updateTime,&QTimer::timeout,c_control,&CoinControl::saveFavoritesToFile);
    updateTime->start(10000);
}

void General::onDataReady(const QList<CryptoData>&) {

    m_hotpage->updateData(c_control->get_HotCoins(), c_control);
    m_price->updateData(c_control->get_PriceCoins(), c_control,priceAscendingOrder);
    m_marketpage->updateData(c_control->get_MarketCoins(), c_control);
    m_change->updateData(c_control->get_ChangeCoins(), c_control,changeAscendingOrder);
    update();
}

#include <QPainter>
void General::updateArrow(QLabel* label, bool ascending) {
    if (!label) return;


    QIcon icon = ascending ? style()->standardIcon(QStyle::SP_ArrowUp)
                           : style()->standardIcon(QStyle::SP_ArrowDown);

    QPixmap pixmap = icon.pixmap(10, 10);
    QPixmap grayPixmap = pixmap;

    QPainter painter(&grayPixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(grayPixmap.rect(), QColor(128, 128, 128));
    painter.end();

    label->setPixmap(grayPixmap);
}


void General::Hot_clicked()
{
    showView(m_hotpage);
}

void General::Market_clicked()
{
    showView(m_marketpage);
}

void General::Price_clicked()
{
    showView(m_price);
    priceAscendingOrder = !priceAscendingOrder;
    m_price->updateData(c_control->get_PriceCoins(),c_control,priceAscendingOrder);
    updateArrow(arrowPrice, priceAscendingOrder);
}

void General::Change_clicked()
{
    showView(m_change);
    changeAscendingOrder = !changeAscendingOrder;
    m_change->updateData(c_control->get_ChangeCoins(),c_control,changeAscendingOrder);
    updateArrow(arrowChange, changeAscendingOrder);
}

General::~General() {
    delete m_change;
    delete m_price;
    delete m_marketpage;
    delete m_hotpage;
    delete c_control;
    delete buttonLayout;
    delete btnWidget;
    delete btnHot;
    delete btnMarketCap;
    delete btnPrice;
    delete btnChange;
    delete fullLayout;
    delete arrowChange;
    delete arrowPrice;
}

void General::showView(QWidget* view)
{
    if (currentView) {
        mainLayout->removeWidget(currentView);
        currentView->hide();
    }
    currentView = view;
    mainLayout->addWidget(currentView);
    currentView->show();
}





















