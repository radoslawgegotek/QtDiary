/********************************************************************************
** Form generated from reading UI file 'createaccount.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNT_H
#define UI_CREATEACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateAccount
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLineEdit *pass_1;
    QLabel *label;
    QLineEdit *newLogin;
    QLineEdit *pass_2;

    void setupUi(QDialog *CreateAccount)
    {
        if (CreateAccount->objectName().isEmpty())
            CreateAccount->setObjectName(QString::fromUtf8("CreateAccount"));
        CreateAccount->resize(400, 300);
        gridLayout = new QGridLayout(CreateAccount);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(CreateAccount);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 1);

        pass_1 = new QLineEdit(CreateAccount);
        pass_1->setObjectName(QString::fromUtf8("pass_1"));
        QFont font;
        font.setPointSize(16);
        pass_1->setFont(font);
        pass_1->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pass_1, 2, 0, 1, 1);

        label = new QLabel(CreateAccount);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Display")});
        font1.setPointSize(22);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        newLogin = new QLineEdit(CreateAccount);
        newLogin->setObjectName(QString::fromUtf8("newLogin"));
        newLogin->setFont(font);

        gridLayout->addWidget(newLogin, 1, 0, 1, 1);

        pass_2 = new QLineEdit(CreateAccount);
        pass_2->setObjectName(QString::fromUtf8("pass_2"));
        pass_2->setFont(font);
        pass_2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pass_2, 3, 0, 1, 1);


        retranslateUi(CreateAccount);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CreateAccount, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CreateAccount, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CreateAccount);
    } // setupUi

    void retranslateUi(QDialog *CreateAccount)
    {
        CreateAccount->setWindowTitle(QCoreApplication::translate("CreateAccount", "Dialog", nullptr));
        pass_1->setPlaceholderText(QCoreApplication::translate("CreateAccount", "Has\305\202o", nullptr));
        label->setText(QCoreApplication::translate("CreateAccount", "Podaj nowy login i has\305\202o", nullptr));
        newLogin->setPlaceholderText(QCoreApplication::translate("CreateAccount", "Login", nullptr));
        pass_2->setPlaceholderText(QCoreApplication::translate("CreateAccount", "Powt\303\263rz has\305\202o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateAccount: public Ui_CreateAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNT_H
