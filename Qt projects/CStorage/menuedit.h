#ifndef MENUEDIT_H
#define MENUEDIT_H

#include <QDialog>

namespace Ui {
class menuEdit;
}

class menuEdit : public QDialog
{
    Q_OBJECT
public:
    explicit menuEdit(QWidget *parent = nullptr);
    ~menuEdit();

public:
    QString get_name()const;
    int get_id() const;
    double get_price()const;

    void set_name(const QString& value);
    void set_price(double value);
    void set_id(int value);

signals:
    void toAdd();

public:
    Ui::menuEdit *ui;

private:
    QString m_name;
    int m_id;
    double m_price;

private slots:
    void on_editButton_clicked();
    void on_cancelButton_clicked();
};

#endif // EDITMENU_H
