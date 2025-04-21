#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "qmessagebox.h"
#include "product.h"
#include "exportworker.h"
#include "QInputDialog"
#include "qtextedit.h"


MainWindow::MainWindow(const QString& role,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,userRole(role)

{
    ui->setupUi(this);

    if(userRole == "user"){
        ui->AddButton->setEnabled(false);
        ui->exportButton->setEnabled(false);
        ui->historyButton->setEnabled(false);
    }

    ui->verticalLayout->setAlignment(Qt::AlignTop);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    ProductDatabaseManager::instance().createTable();
    auto all = ProductDatabaseManager::instance().getAllProducts();
    showAllProducts(all);

    ui->AddButton->setIcon(QIcon(":/Downloads/free-icon-plus-3388962.png"));
    ui->AddButton->setLayoutDirection(Qt::RightToLeft);
    ui->exportButton->setIcon(QIcon(":/Downloads/free-icon-export-8828334.png"));
    ui->exportButton->setLayoutDirection(Qt::RightToLeft);
    ui->lineEdit->addAction(QIcon(":/Downloads/free-icon-search-4024513.png"), QLineEdit::LeadingPosition);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton &&
        ui->widget_2->geometry().contains(event->pos()))
    {
        isMoving = true;
        mousePosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }else{
        isMoving = false;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    if (isMoving && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - mousePosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {
    isMoving = false;
    QMainWindow::mouseReleaseEvent(event);
}


void MainWindow::on_exportButton_clicked()
{
    QString filter = "CSV (*.csv);;Excel (*.xlsx)";
    QString selectedFilter;
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Save As",
        "products",
        filter,
        &selectedFilter
    );

    if (filePath.isEmpty()) return;

    ExportFormat format;

    if (selectedFilter.contains("CSV") && !filePath.endsWith(".csv")) {
        filePath += ".csv";
        format = ExportFormat::CSV;
    } else if (selectedFilter.contains("Excel") && !filePath.endsWith(".xlsx")) {
        filePath += ".xlsx";
        format = ExportFormat::XLSX;
    } else {
        if (filePath.endsWith(".csv"))
            format = ExportFormat::CSV;
        else
            format = ExportFormat::XLSX;
    }

    if (QFile::exists(filePath)) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(
            this,
            "Confirmation",
            "File already exists. Overwrite?",
            QMessageBox::Yes | QMessageBox::No
            );
        if (reply != QMessageBox::Yes) {
            return;
        }
    }

    ExportWorker* worker = new ExportWorker(filePath, format);
    connect(worker, &ExportWorker::exportFinished, this, &MainWindow::onExportFinished);
    connect(worker, &ExportWorker::finished, worker, &QObject::deleteLater);
    worker->start();
}


void MainWindow::onExportFinished(const QString& message)
{
    QMessageBox::information(this, "Export", message);
    ProductDatabaseManager::instance().insertHistory(message);
}

void MainWindow::connectProductWidget(ProductWidget* widget) {
    connect(widget, &ProductWidget::moveUpRequested, this, &MainWindow::moveProductUp);
    connect(widget, &ProductWidget::moveDownRequested, this, &MainWindow::moveProductDown);
    connect(widget, &ProductWidget::moveToIndexRequested, this, &MainWindow::moveProductTo);
    connect(widget, &ProductWidget::productDeleted, this, [=](ProductWidget* w){
        ui->verticalLayout->removeWidget(w);
        w->deleteLater();
    });
}

void MainWindow::on_AddButton_clicked()
{
    menuAdd *addMenu = new menuAdd(this);

    if (addMenu->exec() == QDialog::Accepted) {
        QString name = addMenu->get_name().trimmed();
        int NewId = addMenu->get_id();
        double Price = addMenu->get_price();

        if (name.isEmpty()) {
            QMessageBox::warning(this, "Error", "Name cannot be empty");
            delete addMenu;
            return;
        }

        QList<Product> existing = ProductDatabaseManager::instance().filtred_by_Id(NewId);
        if (!existing.isEmpty()) {
            QMessageBox::warning(this, "Error", "A product with this ID already exists");
            delete addMenu;
            return;
        }

        Product NewProduct{name, NewId, Price, 0};
        if (ProductDatabaseManager::instance().insertProduct(NewProduct)) {
            auto* NewProductWidget = new ProductWidget(NewProduct, userRole);
            ui->verticalLayout->addWidget(NewProductWidget);
            connectProductWidget(NewProductWidget);
            ProductDatabaseManager::instance().insertHistory("Product added " + name);
        } else {
            QMessageBox::critical(this, "Error", "Failed to add product to database");
        }
    }
    delete addMenu;
}




void MainWindow::moveProductUp(ProductWidget* widget){
    int index = ui->verticalLayout->indexOf(widget);
    if(index > 0){
        auto aboveObject = qobject_cast<ProductWidget*>(ui->verticalLayout->itemAt(index - 1)->widget());
        if(!aboveObject)return;

        ProductDatabaseManager::instance().swapProductsPosition(widget->getProduct().id,aboveObject->getProduct().id);
        ui->verticalLayout->removeWidget(widget);
        ui->verticalLayout->insertWidget(index - 1,widget);
        ProductDatabaseManager::instance().insertHistory("Moved up: " + widget->getProduct().name);
    }
}

void MainWindow::moveProductDown(ProductWidget* widget){
    int index = ui->verticalLayout->indexOf(widget);
    int count = ui->verticalLayout->count();

    if(index < count - 1){
        auto belowObject = qobject_cast<ProductWidget*>(ui->verticalLayout->itemAt(index + 1)->widget());
        if(!belowObject)return;

        ProductDatabaseManager::instance().swapProductsPosition(widget->getProduct().id,belowObject->getProduct().id);
        ui->verticalLayout->removeWidget(widget);
        ui->verticalLayout->insertWidget(index + 1,widget);
        ProductDatabaseManager::instance().insertHistory("Moved down: " + widget->getProduct().name);
    }
}

void MainWindow::moveProductTo(ProductWidget* widget){
    int currentIndex = ui->verticalLayout->indexOf(widget);
    bool ok;
    int count = ui->verticalLayout->count();
    int targetIndex = QInputDialog::getInt(this,"Move to...","Input index (0 - " + QString::number(count - 1) + "):",currentIndex,0,count - 1,1,&ok);

    if(!ok || targetIndex == currentIndex)return;

    ui->verticalLayout->removeWidget(widget);
    ui->verticalLayout->insertWidget(targetIndex,widget);
    for(int i = 0; i < ui->verticalLayout->count();++i){
        if (auto* w = qobject_cast<ProductWidget*>(ui->verticalLayout->itemAt(i)->widget())) {
            ProductDatabaseManager::instance().updateProductPosition(w->getProduct().id, i);
        }
    }
    ProductDatabaseManager::instance().insertHistory("Moved to index: " + QString::number(targetIndex) + " - " + widget->getProduct().name);
}

void MainWindow::showAllProducts(const QList<Product>& products){
    QLayoutItem *item;
    while((item = ui->verticalLayout->takeAt(0)) !=nullptr){
        if(item->widget()){
            delete item->widget();
        }
        delete item;
    }

    for(const Product& p:products){
        ProductWidget* NewWidget = new ProductWidget(p,userRole,this);
        connectProductWidget(NewWidget);
        ui->verticalLayout->addWidget(NewWidget);
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString input = arg1.trimmed();
    if(input.isEmpty()){
        showAllProducts(ProductDatabaseManager::instance().getAllProducts());
        return;
    }
    bool ok;
    int id = input.toInt(&ok);

    QList<Product> result;
    if(ok){
        result = ProductDatabaseManager::instance().filtred_by_Id(id);
    }else{
        result = ProductDatabaseManager::instance().filtred_by_Name(input);
    }
    showAllProducts(result);
    ProductDatabaseManager::instance().insertHistory("Search: " + arg1);
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::on_hideButton_clicked()
{
    this->hide();
}

void MainWindow::showHistoryInMessageBox(const QList<QPair<QString, QString>>& history) {
    QString historyText;
    for (const auto& entry : history) {
        historyText += QString("[%1] %2\n").arg(entry.second).arg(entry.first);
    }


    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("History");
    dialog->resize(600, 400);

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QLabel *label = new QLabel("Here is the history:\nScroll to view the complete history.");
    layout->addWidget(label);

    QTextEdit *textEdit = new QTextEdit();
    textEdit->setPlainText(historyText);
    textEdit->setReadOnly(true);
    layout->addWidget(textEdit);

    QPushButton *okButton = new QPushButton("OK");
    QObject::connect(okButton, &QPushButton::clicked, dialog, &QDialog::accept);
    layout->addWidget(okButton, 0, Qt::AlignRight);

    dialog->exec();
}

void MainWindow::on_historyButton_clicked()
{
    QList<QPair<QString,QString>> history = ProductDatabaseManager::instance().getLastHistory(100);
    showHistoryInMessageBox(history);
}

void MainWindow::on_filtrByID_clicked()
{
    static bool sortedById = false;
    QList<Product> products;
    if(!sortedById){
        products = ProductDatabaseManager::instance().getAllProductsSortedById();
    }else{
        products = ProductDatabaseManager::instance().getAllProducts();
    }
    sortedById = !sortedById;
    showAllProducts(products);
}


void MainWindow::on_filtrByName_clicked()
{
    static bool sortedByName = false;
    QList<Product> products;
    if(!sortedByName){
        products = ProductDatabaseManager::instance().getAllProductsSortedByName();
    }else{
        products = ProductDatabaseManager::instance().getAllProducts();
    }
    sortedByName = !sortedByName;
    showAllProducts(products);
}


