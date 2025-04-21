#include "ui_editmenu.h"
#include "editmenu.h"
#include "qmessagebox.h"

editMenu::editMenu(ProductWidget* product,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editMenu)
{
    ui->setupUi(this);
    connect(ui->saveButton,&QPushButton::clicked,this,&menuAdd::on_saveButton_clicked);
    connect(ui->cancelButton,&QPushButton::clicked,this,&menuAdd::on_cancelButton_clicked);
}

menuAdd::~menuAdd()
{
    delete ui;
}



void menuAdd::on_saveButton_clicked()
{
    bool ok1,ok2;
    name = ui->nameEdit->text();
    price = ui->priseEdit->text().toDouble(&ok1);
    id = ui->idEdit->text().toInt(&ok2);

    if(!ok1 || !ok2 || name.isEmpty()){
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
    return name;
}

int menuAdd::get_id()const{
    return id;
}

double menuAdd::get_price()const{
    return price;
}
















