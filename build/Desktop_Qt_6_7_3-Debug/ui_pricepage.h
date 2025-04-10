/********************************************************************************
** Form generated from reading UI file 'pricepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRICEPAGE_H
#define UI_PRICEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_PricePage
{
public:

    void setupUi(QDialog *PricePage)
    {
        if (PricePage->objectName().isEmpty())
            PricePage->setObjectName("PricePage");
        PricePage->resize(400, 300);

        retranslateUi(PricePage);

        QMetaObject::connectSlotsByName(PricePage);
    } // setupUi

    void retranslateUi(QDialog *PricePage)
    {
        PricePage->setWindowTitle(QCoreApplication::translate("PricePage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PricePage: public Ui_PricePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRICEPAGE_H
