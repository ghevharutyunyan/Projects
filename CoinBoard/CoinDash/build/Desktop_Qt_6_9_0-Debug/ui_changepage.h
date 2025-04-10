/********************************************************************************
** Form generated from reading UI file 'changepage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPAGE_H
#define UI_CHANGEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ChangePage
{
public:

    void setupUi(QDialog *ChangePage)
    {
        if (ChangePage->objectName().isEmpty())
            ChangePage->setObjectName("ChangePage");
        ChangePage->resize(400, 300);

        retranslateUi(ChangePage);

        QMetaObject::connectSlotsByName(ChangePage);
    } // setupUi

    void retranslateUi(QDialog *ChangePage)
    {
        ChangePage->setWindowTitle(QCoreApplication::translate("ChangePage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePage: public Ui_ChangePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPAGE_H
