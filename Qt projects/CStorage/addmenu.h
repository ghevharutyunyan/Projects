#ifndef ADDMENU_H
#define ADDMENU_H

#include <QWidget>

namespace Ui {
class addMenu;
}

class addMenu : public QWidget
{
    Q_OBJECT

public:
    explicit addMenu(QWidget *parent = nullptr);
    ~addMenu();

private:
    Ui::addMenu *ui;
};

#endif // ADDMENU_H
