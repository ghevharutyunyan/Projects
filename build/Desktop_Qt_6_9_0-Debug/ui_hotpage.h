/********************************************************************************
** Form generated from reading UI file 'hotpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTPAGE_H
#define UI_HOTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotPage
{
public:

    void setupUi(QWidget *HotPage)
    {
        if (HotPage->objectName().isEmpty())
            HotPage->setObjectName("HotPage");
        HotPage->resize(400, 300);

        retranslateUi(HotPage);

        QMetaObject::connectSlotsByName(HotPage);
    } // setupUi

    void retranslateUi(QWidget *HotPage)
    {
        HotPage->setWindowTitle(QCoreApplication::translate("HotPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotPage: public Ui_HotPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTPAGE_H
