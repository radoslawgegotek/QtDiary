/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *password;
    QDialogButtonBox *buttonBox;
    QLineEdit *login;
    QPushButton *newAccount;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(400, 300);
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LoginWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Black")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        password = new QLineEdit(LoginWindow);
        password->setObjectName(QString::fromUtf8("password"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Emoji")});
        font1.setPointSize(14);
        password->setFont(font1);
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(LoginWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 1);

        login = new QLineEdit(LoginWindow);
        login->setObjectName(QString::fromUtf8("login"));
        QFont font2;
        font2.setPointSize(14);
        login->setFont(font2);

        gridLayout->addWidget(login, 1, 0, 1, 1);

        newAccount = new QPushButton(LoginWindow);
        newAccount->setObjectName(QString::fromUtf8("newAccount"));

        gridLayout->addWidget(newAccount, 3, 0, 1, 1);


        retranslateUi(LoginWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, LoginWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, LoginWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Podaj login i has\305\202o", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        login->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        newAccount->setText(QCoreApplication::translate("LoginWindow", "Utw\303\263rz nowe konto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
