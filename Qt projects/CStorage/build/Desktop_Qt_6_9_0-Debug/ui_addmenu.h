/********************************************************************************
** Form generated from reading UI file 'addmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMENU_H
#define UI_ADDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addMenu
{
public:
    QWidget *widget;
    QLabel *label;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QWidget *widget_3;
    QLabel *label_2;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *addMenu)
    {
        if (addMenu->objectName().isEmpty())
            addMenu->setObjectName("addMenu");
        addMenu->resize(400, 300);
        widget = new QWidget(addMenu);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 401, 61));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 141, 18));
        label->setStyleSheet(QString::fromUtf8("font: 600 12pt \"URW Bookman\";\n"
"color: rgb(94, 92, 100);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 30, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(94, 92, 100);"));
        scrollArea = new QScrollArea(addMenu);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 60, 401, 241));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 399, 239));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName("widget_2");
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 120, 41));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 81, 16));
        textBrowser = new QTextBrowser(widget_2);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(60, 100, 256, 192));

        verticalLayout->addWidget(widget_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(addMenu);

        QMetaObject::connectSlotsByName(addMenu);
    } // setupUi

    void retranslateUi(QWidget *addMenu)
    {
        addMenu->setWindowTitle(QCoreApplication::translate("addMenu", "Form", nullptr));
        label->setText(QCoreApplication::translate("addMenu", "Add new Product", nullptr));
        pushButton->setText(QCoreApplication::translate("addMenu", "Add", nullptr));
        label_2->setText(QCoreApplication::translate("addMenu", "<html><head/><body><p><span style=\" font-size:9pt;\">Product Name</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addMenu: public Ui_addMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMENU_H
