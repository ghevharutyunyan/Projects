#include "menuedit.h"
#include "ui_menuedit.h"
#include "qmessagebox.h"
#include "QRegularExpression"
#include <QRegularExpressionValidator>

menuEdit::menuEdit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menuEdit)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    ui->widget_4->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    this->setStyleSheet("QWidget {"
                        "  background-color: rgb(8, 36, 8);"
                        "  border-radius: 5px;"
                        "  border: none;"
                        "}");

    ui->label_4->setStyleSheet( "QLabel {"
                               "    font: 100 italic 24pt \"Ubuntu Sans\";"
                               "    background-color: rgb(8, 36, 8);"
                               "}");

    connect(ui->editButton,&QPushButton::clicked,this,&menuEdit::on_editButton_clicked);
    connect(ui->cancelButton,&QPushButton::clicked,this,&menuEdit::on_cancelButton_clicked);

    QRegularExpression regex("^[a-zA-Z]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->nameEdit->setValidator(validator);
}

menuEdit::~menuEdit()
{
    delete ui;
}

void menuEdit::on_editButton_clicked()
{
    bool ok1,ok2;
    m_name = ui->nameEdit->text();
    m_price = ui->priceEdit->text().toDouble(&ok1);
    m_id = ui->idEdit->text().toInt(&ok2);

    if(!ok1 || !ok2 || m_name.isEmpty()){
        QMessageBox::warning(this, "Error", "Incorrect input data.");
        return;
    }

    accept();
}

void menuEdit::on_cancelButton_clicked()
{
    reject();
}

QString menuEdit::get_name() const {
    return m_name;
}

int menuEdit::get_id() const {
    return m_id;
}

double menuEdit::get_price() const {
    return m_price;
}



void menuEdit::set_name(const QString& value) {
    ui->nameEdit->setText(value);
}

void menuEdit::set_price(double value) {
    ui->priceEdit->setText(QString::number(value));
}

void menuEdit::set_id(int value) {
    ui->idEdit->setText(QString::number(value));
}


