#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    loginDialog login;
    if (login.exec() == QDialog::Accepted) {
        QString role = login.getUserRole();

        MainWindow w(role);
        w.show();
        return a.exec();
    }

    return 0;
}
