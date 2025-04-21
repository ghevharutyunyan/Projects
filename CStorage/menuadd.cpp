#include "menuadd.h"
#include "ui_menuadd.h"
#include "qmessagebox.h"
#include "qregularexpression.h"
#include "QRegularExpressionValidator"

menuAdd::menuAdd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menuAdd)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    connect(ui->saveButton,&QPushButton::clicked,this,&menuAdd::on_saveButton_clicked);
    connect(ui->cancelButton,&QPushButton::clicked,this,&menuAdd::on_cancelButton_clicked);

    QRegularExpression regex("^[a-zA-Z]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->nameEdit->setValidator(validator);
}

menuAdd::~menuAdd()
{
    delete ui;
}

void menuAdd::on_saveButton_clicked()
{
    bool ok1,ok2;
    m_name = ui->nameEdit->text();
    m_price = ui->priseEdit->text().toDouble(&ok1);
    m_id = ui->idEdit->text().toInt(&ok2);

    if(!ok1 || !ok2 || m_name.isEmpty()){
        QMessageBox::warning(this, "Error", "Incorrect input data.");
        return;
    }
    accept();
}

void menuAdd::on_cancelButton_clicked()
{
    reject();
}

QString menuAdd::get_name()const{
    return m_name;
}

int menuAdd::get_id()const{
    return m_id;
}

double menuAdd::get_price()const{
    return m_price;
}



