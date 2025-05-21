/********************************************************************************
** Form generated from reading UI file 'menuadd.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUADD_H
#define UI_MENUADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menuAdd
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *nameEdit;
    QLineEdit *idEdit;
    QLineEdit *priseEdit;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *menuAdd)
    {
        if (menuAdd->objectName().isEmpty())
            menuAdd->setObjectName("menuAdd");
        menuAdd->resize(509, 300);
        menuAdd->setStyleSheet(QString::fromUtf8("#menuAdd{\n"
"background-color: rgb(8, 36, 8);\n"
"border-radius:5px;\n"
"}"));
        gridLayout = new QGridLayout(menuAdd);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(-1, 0, 0, -1);
        widget_2 = new QWidget(menuAdd);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(53);
        sizePolicy.setVerticalStretch(25);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(8, 36, 8);\n"
"border-radius:15px;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(2, 2, 12, 2);
        nameEdit = new QLineEdit(widget_2);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 64, 64);\n"
"    color: rgb(144, 238, 144);\n"
"    border-radius: 5px;\n"
" padding: 3px;"));

        horizontalLayout_2->addWidget(nameEdit);

        idEdit = new QLineEdit(widget_2);
        idEdit->setObjectName("idEdit");
        idEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 64, 64);\n"
"    color: rgb(144, 238, 144);\n"
"    border-radius: 5px;\n"
" padding: 3px;"));

        horizontalLayout_2->addWidget(idEdit);

        priseEdit = new QLineEdit(widget_2);
        priseEdit->setObjectName("priseEdit");
        priseEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 64, 64);\n"
"    color: rgb(144, 238, 144);\n"
"    border-radius: 5px;\n"
" padding: 3px;"));

        horizontalLayout_2->addWidget(priseEdit);


        gridLayout->addWidget(widget_2, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(40, 70, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        widget_3 = new QWidget(menuAdd);
        widget_3->setObjectName("widget_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);\n"
"border-radius:5px;"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        cancelButton = new QPushButton(widget_3);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #2f4f2f;\n"
"       \n"
"	color: rgb(192, 191, 188);\n"
"        border: 1px solid #4caf50;\n"
"        border-radius: 8px;\n"
"        padding: 5px 10px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"        background-color: #3e8e41;\n"
"    }"));

        horizontalLayout_3->addWidget(cancelButton);

        saveButton = new QPushButton(widget_3);
        saveButton->setObjectName("saveButton");
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #2f4f2f;\n"
"       \n"
"	color: rgb(192, 191, 188);\n"
"        border: 1px solid #4caf50;\n"
"        border-radius: 8px;\n"
"        padding: 5px 10px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"        background-color: #3e8e41;\n"
"    }"));

        horizontalLayout_3->addWidget(saveButton);


        gridLayout->addWidget(widget_3, 6, 0, 1, 1);

        widget = new QWidget(menuAdd);
        widget->setObjectName("widget");
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);\n"
"border-radius:5px;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(9, 9, -1, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 600 13pt \"URW Gothic\";\n"
"background-color: rgba(106, 82, 177, 0);\n"
"border-right:2px  solid rgb(61, 56, 70);\n"
"border-radius:0px;\n"
"color: rgb(144, 238, 144);"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 600 13pt \"URW Gothic\";\n"
"background-color: rgba(106, 82, 177, 0);\n"
"border-right:2px  solid rgb(61, 56, 70);\n"
"border-radius:0px;\n"
"color: rgb(144, 238, 144);"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 600 13pt \"URW Gothic\";\n"
"background-color: rgba(106, 82, 177, 0);\n"
"border-radius:0px;\n"
"color: rgb(144, 238, 144);"));

        horizontalLayout->addWidget(label_3);


        gridLayout->addWidget(widget, 4, 0, 1, 1);

        widget_4 = new QWidget(menuAdd);
        widget_4->setObjectName("widget_4");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy2);
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);\n"
"border-radius:5px;"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 11, 0);
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setStyleSheet(QString::fromUtf8("font: 100 italic 22pt \"Ubuntu Sans\";\n"
"background-color: rgb(8, 36, 8);\n"
"border-radius:5px;"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout->addWidget(widget_4, 1, 0, 1, 1);


        retranslateUi(menuAdd);

        QMetaObject::connectSlotsByName(menuAdd);
    } // setupUi

    void retranslateUi(QDialog *menuAdd)
    {
        menuAdd->setWindowTitle(QCoreApplication::translate("menuAdd", "Dialog", nullptr));
        idEdit->setInputMask(QString());
        cancelButton->setText(QCoreApplication::translate("menuAdd", "Cancel", nullptr));
        saveButton->setText(QCoreApplication::translate("menuAdd", "Add", nullptr));
        label->setText(QCoreApplication::translate("menuAdd", "Select Name", nullptr));
        label_2->setText(QCoreApplication::translate("menuAdd", "Select Id", nullptr));
        label_3->setText(QCoreApplication::translate("menuAdd", "Select Price", nullptr));
        label_4->setText(QCoreApplication::translate("menuAdd", "Add Product", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuAdd: public Ui_menuAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUADD_H
