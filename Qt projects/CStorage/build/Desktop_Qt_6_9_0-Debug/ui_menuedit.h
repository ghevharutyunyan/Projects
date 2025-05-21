/********************************************************************************
** Form generated from reading UI file 'menuedit.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUEDIT_H
#define UI_MENUEDIT_H

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

class Ui_menuEdit
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *nameEdit;
    QLineEdit *idEdit;
    QLineEdit *priceEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QPushButton *editButton;

    void setupUi(QDialog *menuEdit)
    {
        if (menuEdit->objectName().isEmpty())
            menuEdit->setObjectName("menuEdit");
        menuEdit->resize(529, 284);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuEdit->sizePolicy().hasHeightForWidth());
        menuEdit->setSizePolicy(sizePolicy);
        menuEdit->setStyleSheet(QString::fromUtf8("#menuEdit{\n"
"background-color: rgb(8, 36, 8);\n"
"border-radius:5px;\n"
"border:none;\n"
"}"));
        gridLayout = new QGridLayout(menuEdit);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(16);
        gridLayout->setContentsMargins(-1, 0, 0, 9);
        widget_4 = new QWidget(menuEdit);
        widget_4->setObjectName("widget_4");
        widget_4->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);\n"
"border-radius:5px;"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 3, 0);
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setStyleSheet(QString::fromUtf8("font: 100 italic 24pt \"Ubuntu Sans\";\n"
""));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout->addWidget(widget_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        widget = new QWidget(menuEdit);
        widget->setObjectName("widget");
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);\n"
"border-radius:5px;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 9, 2, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
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
"border-right:2px  solid rgb(61, 56, 70);\n"
"border-radius:0px;\n"
"color: rgb(144, 238, 144);"));

        horizontalLayout->addWidget(label_3);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 600 13pt \"URW Gothic\";\n"
"background-color: rgba(106, 82, 177, 0);\n"
"\n"
"border-radius:0px;\n"
"color: rgb(144, 238, 144);"));

        horizontalLayout->addWidget(label);


        gridLayout->addWidget(widget, 2, 0, 1, 1);

        widget_2 = new QWidget(menuEdit);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(53);
        sizePolicy3.setVerticalStretch(84);
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);\n"
"border-radius:5px;"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
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

        priceEdit = new QLineEdit(widget_2);
        priceEdit->setObjectName("priceEdit");
        priceEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 64, 64);\n"
"    color: rgb(144, 238, 144);\n"
"    border-radius: 5px;\n"
" padding: 3px;"));

        horizontalLayout_2->addWidget(priceEdit);


        gridLayout->addWidget(widget_2, 3, 0, 1, 1);

        widget_3 = new QWidget(menuEdit);
        widget_3->setObjectName("widget_3");
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);\n"
"border-radius:5px;"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 4, 3, 3);
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

        editButton = new QPushButton(widget_3);
        editButton->setObjectName("editButton");
        editButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_3->addWidget(editButton);


        gridLayout->addWidget(widget_3, 4, 0, 1, 1);


        retranslateUi(menuEdit);

        QMetaObject::connectSlotsByName(menuEdit);
    } // setupUi

    void retranslateUi(QDialog *menuEdit)
    {
        menuEdit->setWindowTitle(QCoreApplication::translate("menuEdit", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("menuEdit", "<html><head/><body><p>Editor</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("menuEdit", "Select Name", nullptr));
        label_3->setText(QCoreApplication::translate("menuEdit", "Select ID", nullptr));
        label->setText(QCoreApplication::translate("menuEdit", "Select Price", nullptr));
        idEdit->setInputMask(QString());
        cancelButton->setText(QCoreApplication::translate("menuEdit", "Cancel", nullptr));
        editButton->setText(QCoreApplication::translate("menuEdit", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuEdit: public Ui_menuEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUEDIT_H
