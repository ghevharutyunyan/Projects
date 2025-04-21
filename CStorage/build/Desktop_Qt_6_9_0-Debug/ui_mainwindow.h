/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *exportButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *historyButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *AddButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *hideButton;
    QPushButton *closeButton;
    QLineEdit *lineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *filtrByName;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *filtrByID;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1258, 725);
        MainWindow->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    spread: pad, x1: 0, y1: 0, x2: 1, y2: 0,\n"
"    stop:  0 rgb(0, 100, 0)    /* \320\227\320\265\320\273\321\221\320\275\321\213\320\271 */\n"
"    stop: 1 rgb(20, 20, 20)       /* \320\242\321\221\320\274\320\275\320\276-\320\267\320\265\320\273\321\221\320\275\321\213\320\271 */\n"
");\n"
"border-radius:5px;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        exportButton = new QPushButton(widget_5);
        exportButton->setObjectName("exportButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exportButton->sizePolicy().hasHeightForWidth());
        exportButton->setSizePolicy(sizePolicy);
        exportButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #2f4f2f;\n"
"       \n"
"\n"
"	color: rgb(192, 191, 188);\n"
"        border: 1px solid #4caf50;\n"
"        border-radius: 8px;\n"
"        padding: 5px 10px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"        background-color: #3e8e41;\n"
"    }"));

        horizontalLayout_5->addWidget(exportButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        historyButton = new QPushButton(widget_5);
        historyButton->setObjectName("historyButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(historyButton->sizePolicy().hasHeightForWidth());
        historyButton->setSizePolicy(sizePolicy1);
        historyButton->setStyleSheet(QString::fromUtf8("background-color: rgba(106, 82, 177, 0);\n"
"image: url(:/Downloads/icons8-\320\270\321\201\321\202\320\276\321\200\320\270\321\217-64.png);"));

        horizontalLayout_5->addWidget(historyButton);


        gridLayout->addWidget(widget_5, 2, 0, 1, 4);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgb(0, 0, 0);\n"
"border-radius:15px;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1240, 432));
        scrollAreaWidgetContents->setMinimumSize(QSize(1229, 0));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 4, -1, -1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 6, 0, 1, 4);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName("widget_6");
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgba(106, 82, 177, 0)"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        AddButton = new QPushButton(widget_6);
        AddButton->setObjectName("AddButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy2);
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #2f4f2f;\n"
"	color: rgb(192, 191, 188);\n"
"        border: 1px solid #4caf50;\n"
"        border-radius: 8px;\n"
"        padding: 5px 10px;\n"
"    }\n"
"QPushButton:hover {\n"
"        background-color: #3e8e41;\n"
"    }"));

        horizontalLayout_6->addWidget(AddButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout->addWidget(widget_6, 3, 0, 1, 4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(9, 66, 9);\n"
"         font: 500 17pt \"Ubuntu Sans\";\n"
"	background-color: rgba(106, 82, 177, 0);\n"
"    }\n"
"\n"
""));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(9, 0, 0, 17);
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: rgb(65, 139, 42);\n"
"background-color: rgba(106, 82, 177, 0);\n"
"font: 200 italic 24pt \"Ubuntu Sans\";"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        hideButton = new QPushButton(widget_2);
        hideButton->setObjectName("hideButton");
        hideButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        hideButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"image: url(:/Downloads/free-icon-minus-sign-8212743.png);\n"
"background-color: rgb(13, 17, 13);\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: rgb(30, 40, 30); \n"
"}"));

        horizontalLayout_2->addWidget(hideButton);

        closeButton = new QPushButton(widget_2);
        closeButton->setObjectName("closeButton");
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(13, 16, 13);\n"
"image: url(:/Downloads/free-icon-cross-10728089.png);\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(30, 40, 30); \n"
"}"));

        horizontalLayout_2->addWidget(closeButton);


        gridLayout->addWidget(widget_2, 1, 0, 1, 4);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy4);
        lineEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lineEdit->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"        background-color: #263d26;\n"
"        color: #ffffff;\n"
"        border: 1px solid #4caf50;\n"
"        border-radius: 6px;\n"
"        padding: 4px;\n"
"    }\n"
""));

        gridLayout->addWidget(lineEdit, 4, 2, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);
        widget->setMinimumSize(QSize(0, 0));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"border-top: 2px solid  #263d26;\n"
"border-radius:0px;\n"
"}\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3{\n"
"border-right:2px  solid rgb(61, 56, 70);\n"
"background-color: rgba(106, 82, 177, 0);\n"
"border-radius:0px;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 600 14pt \"URW Gothic\";\n"
"background-color: rgba(106, 82, 177, 0);\n"
"color: rgb(144, 238, 144);\n"
"border-radius:0px;"));

        horizontalLayout_3->addWidget(label_3);

        filtrByName = new QPushButton(widget_3);
        filtrByName->setObjectName("filtrByName");
        sizePolicy.setHeightForWidth(filtrByName->sizePolicy().hasHeightForWidth());
        filtrByName->setSizePolicy(sizePolicy);
        filtrByName->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	image: url(:/Downloads/free-icon-arrows-up-and-down-filled-triangles-58942.png);\n"
"	background-color: rgba(106, 82, 177, 0);\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(30, 40, 30); \n"
"}\n"
""));

        horizontalLayout_3->addWidget(filtrByName);


        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("#widget_4{\n"
"border-right:2px  solid rgb(61, 56, 70);\n"
"	background-color: rgba(106, 82, 177, 0);\n"
"border-radius:0px;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 600 14pt \"URW Gothic\";\n"
"background-color: rgba(106, 82, 177, 0);\n"
"\n"
"color: rgb(144, 238, 144);\n"
"border-radius:0px;"));

        horizontalLayout_4->addWidget(label_4);

        filtrByID = new QPushButton(widget_4);
        filtrByID->setObjectName("filtrByID");
        sizePolicy.setHeightForWidth(filtrByID->sizePolicy().hasHeightForWidth());
        filtrByID->setSizePolicy(sizePolicy);
        filtrByID->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	image: url(:/Downloads/free-icon-arrows-up-and-down-filled-triangles-58942.png);\n"
"	background-color: rgba(106, 82, 177, 0);\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(30, 40, 30); \n"
"}\n"
""));

        horizontalLayout_4->addWidget(filtrByID);


        horizontalLayout->addWidget(widget_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy6);
        label_5->setStyleSheet(QString::fromUtf8("font: 600 14pt \"URW Gothic\";\n"
"background-color: rgba(106, 82, 177, 0);\n"
"\n"
"color: rgb(144, 238, 144)"));

        horizontalLayout->addWidget(label_5);


        gridLayout->addWidget(widget, 5, 0, 1, 4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Export ", nullptr));
        historyButton->setText(QString());
        AddButton->setText(QCoreApplication::translate("MainWindow", "Add ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">Products</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CStorage", nullptr));
        hideButton->setText(QString());
        closeButton->setText(QString());
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search product ( name or ID ) ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        filtrByName->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        filtrByID->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
