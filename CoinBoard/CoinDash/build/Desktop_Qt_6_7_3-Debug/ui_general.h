/********************************************************************************
** Form generated from reading UI file 'general.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERAL_H
#define UI_GENERAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_General
{
public:

    void setupUi(QDialog *General)
    {
        if (General->objectName().isEmpty())
            General->setObjectName("General");
        General->resize(557, 593);

        retranslateUi(General);

        QMetaObject::connectSlotsByName(General);
    } // setupUi

    void retranslateUi(QDialog *General)
    {
        General->setWindowTitle(QCoreApplication::translate("General", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class General: public Ui_General {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERAL_H
