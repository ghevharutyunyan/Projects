#ifndef MENUADD_H
#define MENUADD_H

#include <QDialog>

namespace Ui {
class menuAdd;
}

class menuAdd : public QDialog
{
    Q_OBJECT

public:
    explicit menuAdd(QWidget *parent = nullptr);
    ~menuAdd();

public:
    QString get_name()const;
    int get_id() const;
    double get_price()const;

signals:
    void toAdd();

public:
    Ui::menuAdd *ui;

private:
    QString m_name;
    int m_id;
    double m_price;

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
};

#endif // MENUADD_H
