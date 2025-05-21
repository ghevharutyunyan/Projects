/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *passwordEdit;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QLineEdit *usernameEdit;
    QSpacerItem *verticalSpacer_3;
    QPushButton *cancelButton;
    QPushButton *loginButton;
    QPushButton *signButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName("loginDialog");
        loginDialog->resize(784, 490);
        loginDialog->setStyleSheet(QString::fromUtf8("\n"
"    border-radius: 15px;\n"
"    background-color: transparent; /* \320\275\320\265 \320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\320\276, \320\275\320\276 \320\277\321\203\321\201\321\202\321\214 \320\261\321\203\320\264\320\265\321\202 */\n"
"\n"
"    background: qlineargradient(\n"
"        spread: pad, x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 rgba(0, 100, 0, 255),\n"
"        stop: 1 rgba(20, 20, 20, 255)\n"
"    );\n"
""));
        loginDialog->setSizeGripEnabled(false);
        loginDialog->setModal(false);
        gridLayout = new QGridLayout(loginDialog);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(9, 9, -1, -1);
        passwordEdit = new QLineEdit(loginDialog);
        passwordEdit->setObjectName("passwordEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy);
        passwordEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);"));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(passwordEdit, 5, 2, 1, 1);

        label = new QLabel(loginDialog);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(106, 82, 177, 0);"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_2 = new QLabel(loginDialog);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(106, 82, 177, 0);"));

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        usernameEdit = new QLineEdit(loginDialog);
        usernameEdit->setObjectName("usernameEdit");
        sizePolicy.setHeightForWidth(usernameEdit->sizePolicy().hasHeightForWidth());
        usernameEdit->setSizePolicy(sizePolicy);
        usernameEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 36, 8);"));

        gridLayout->addWidget(usernameEdit, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 1);

        cancelButton = new QPushButton(loginDialog);
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

        gridLayout->addWidget(cancelButton, 7, 3, 1, 1);

        loginButton = new QPushButton(loginDialog);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(loginButton, 7, 4, 1, 1);

        signButton = new QPushButton(loginDialog);
        signButton->setObjectName("signButton");
        signButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(8, 36, 8);\n"
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
        signButton->setIconSize(QSize(16, 16));

        gridLayout->addWidget(signButton, 7, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        label_3 = new QLabel(loginDialog);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(106, 82, 177, 0);\n"
"color: rgb(65, 139, 42);\n"
"font: 200 italic 24pt \"Ubuntu Sans\";"));

        gridLayout->addWidget(label_3, 0, 0, 1, 3);


        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QCoreApplication::translate("loginDialog", "Dialog", nullptr));
        passwordEdit->setText(QString());
        passwordEdit->setPlaceholderText(QCoreApplication::translate("loginDialog", "Password", nullptr));
        label->setText(QCoreApplication::translate("loginDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">Username</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("loginDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">Password</span></p></body></html>", nullptr));
        usernameEdit->setText(QString());
        usernameEdit->setPlaceholderText(QCoreApplication::translate("loginDialog", "Username", nullptr));
        cancelButton->setText(QCoreApplication::translate("loginDialog", "Cancel", nullptr));
        loginButton->setText(QCoreApplication::translate("loginDialog", "Login", nullptr));
        signButton->setText(QCoreApplication::translate("loginDialog", "Sign in", nullptr));
        label_3->setText(QCoreApplication::translate("loginDialog", "<html><head/><body><p><span style=\" font-size:24pt;\">CStorage</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
