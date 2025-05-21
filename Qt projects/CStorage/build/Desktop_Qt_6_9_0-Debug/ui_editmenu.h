/********************************************************************************
** Form generated from reading UI file 'editmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMENU_H
#define UI_EDITMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menuAdd
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *idEdit;
    QLineEdit *priseEdit;
    QLineEdit *nameEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *menuAdd)
    {
        if (menuAdd->objectName().isEmpty())
            menuAdd->setObjectName("menuAdd");
        menuAdd->resize(498, 300);
        menuAdd->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #3a3a3a;\n"
"    border: 1px solid #5c5c5c;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #4a90e2;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #357ABD;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(menuAdd);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(menuAdd);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label_3);

        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(menuAdd);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(53);
        sizePolicy.setVerticalStretch(84);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        idEdit = new QLineEdit(widget_2);
        idEdit->setObjectName("idEdit");
        idEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));

        horizontalLayout_2->addWidget(idEdit);

        priseEdit = new QLineEdit(widget_2);
        priseEdit->setObjectName("priseEdit");
        priseEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));

        horizontalLayout_2->addWidget(priseEdit);

        nameEdit = new QLineEdit(widget_2);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));

        horizontalLayout_2->addWidget(nameEdit);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(menuAdd);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        cancelButton = new QPushButton(widget_3);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_3->addWidget(cancelButton);

        saveButton = new QPushButton(widget_3);
        saveButton->setObjectName("saveButton");

        horizontalLayout_3->addWidget(saveButton);


        verticalLayout->addWidget(widget_3);


        retranslateUi(menuAdd);

        QMetaObject::connectSlotsByName(menuAdd);
    } // setupUi

    void retranslateUi(QDialog *menuAdd)
    {
        menuAdd->setWindowTitle(QCoreApplication::translate("menuAdd", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("menuAdd", "Select Id", nullptr));
        label_3->setText(QCoreApplication::translate("menuAdd", "Select Price", nullptr));
        label->setText(QCoreApplication::translate("menuAdd", "Select Name", nullptr));
        idEdit->setInputMask(QString());
        cancelButton->setText(QCoreApplication::translate("menuAdd", "Cancel", nullptr));
        saveButton->setText(QCoreApplication::translate("menuAdd", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuAdd: public Ui_menuAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMENU_H
