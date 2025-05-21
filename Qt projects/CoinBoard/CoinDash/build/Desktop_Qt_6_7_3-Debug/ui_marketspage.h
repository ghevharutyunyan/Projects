/********************************************************************************
** Form generated from reading UI file 'marketspage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKETSPAGE_H
#define UI_MARKETSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_MarketsPage
{
public:

    void setupUi(QDialog *MarketsPage)
    {
        if (MarketsPage->objectName().isEmpty())
            MarketsPage->setObjectName("MarketsPage");
        MarketsPage->resize(400, 300);

        retranslateUi(MarketsPage);

        QMetaObject::connectSlotsByName(MarketsPage);
    } // setupUi

    void retranslateUi(QDialog *MarketsPage)
    {
        MarketsPage->setWindowTitle(QCoreApplication::translate("MarketsPage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MarketsPage: public Ui_MarketsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKETSPAGE_H
