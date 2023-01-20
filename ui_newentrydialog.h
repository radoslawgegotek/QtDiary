/********************************************************************************
** Form generated from reading UI file 'newentrydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWENTRYDIALOG_H
#define UI_NEWENTRYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NewEntryDialog
{
public:
    QGridLayout *gridLayout;
    QTextEdit *poleWpisu;
    QDialogButtonBox *buttonBox;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *NewEntryDialog)
    {
        if (NewEntryDialog->objectName().isEmpty())
            NewEntryDialog->setObjectName(QString::fromUtf8("NewEntryDialog"));
        NewEntryDialog->resize(400, 297);
        gridLayout = new QGridLayout(NewEntryDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        poleWpisu = new QTextEdit(NewEntryDialog);
        poleWpisu->setObjectName(QString::fromUtf8("poleWpisu"));

        gridLayout->addWidget(poleWpisu, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(NewEntryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(NewEntryDialog);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 0, 0, 1, 1);


        retranslateUi(NewEntryDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewEntryDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewEntryDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewEntryDialog);
    } // setupUi

    void retranslateUi(QDialog *NewEntryDialog)
    {
        NewEntryDialog->setWindowTitle(QCoreApplication::translate("NewEntryDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewEntryDialog: public Ui_NewEntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWENTRYDIALOG_H
