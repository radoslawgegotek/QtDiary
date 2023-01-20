/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *main;
    QGridLayout *gridLayout_2;
    QFrame *inputConteiner;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QComboBox *EntryTypes;
    QPushButton *writeToFile;
    QPushButton *deleteCurrentEntry;
    QPushButton *chooseFile;
    QPushButton *addEntry;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *addEntryType;
    QFrame *outputConteiner;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *previous;
    QTextEdit *current;
    QTextEdit *next;
    QFrame *EntryType;
    QHBoxLayout *horizontalLayout;
    QCheckBox *radosne;
    QCheckBox *neutralne;
    QCheckBox *smutne;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        main = new QFrame(centralwidget);
        main->setObjectName(QString::fromUtf8("main"));
        main->setFrameShape(QFrame::StyledPanel);
        main->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(main);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        inputConteiner = new QFrame(main);
        inputConteiner->setObjectName(QString::fromUtf8("inputConteiner"));
        inputConteiner->setEnabled(true);
        inputConteiner->setFrameShape(QFrame::StyledPanel);
        inputConteiner->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(inputConteiner);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        EntryTypes = new QComboBox(inputConteiner);
        EntryTypes->setObjectName(QString::fromUtf8("EntryTypes"));

        gridLayout->addWidget(EntryTypes, 0, 1, 1, 1);

        writeToFile = new QPushButton(inputConteiner);
        writeToFile->setObjectName(QString::fromUtf8("writeToFile"));

        gridLayout->addWidget(writeToFile, 0, 5, 1, 1);

        deleteCurrentEntry = new QPushButton(inputConteiner);
        deleteCurrentEntry->setObjectName(QString::fromUtf8("deleteCurrentEntry"));

        gridLayout->addWidget(deleteCurrentEntry, 0, 7, 1, 1);

        chooseFile = new QPushButton(inputConteiner);
        chooseFile->setObjectName(QString::fromUtf8("chooseFile"));

        gridLayout->addWidget(chooseFile, 0, 4, 1, 1);

        addEntry = new QPushButton(inputConteiner);
        addEntry->setObjectName(QString::fromUtf8("addEntry"));
        addEntry->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(addEntry, 0, 11, 1, 1);

        previousButton = new QPushButton(inputConteiner);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        gridLayout->addWidget(previousButton, 0, 8, 1, 1);

        nextButton = new QPushButton(inputConteiner);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        gridLayout->addWidget(nextButton, 0, 9, 1, 1);

        addEntryType = new QPushButton(inputConteiner);
        addEntryType->setObjectName(QString::fromUtf8("addEntryType"));

        gridLayout->addWidget(addEntryType, 0, 0, 1, 1);


        gridLayout_2->addWidget(inputConteiner, 0, 0, 1, 1);

        outputConteiner = new QFrame(main);
        outputConteiner->setObjectName(QString::fromUtf8("outputConteiner"));
        outputConteiner->setFrameShape(QFrame::StyledPanel);
        outputConteiner->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(outputConteiner);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        previous = new QTextEdit(outputConteiner);
        previous->setObjectName(QString::fromUtf8("previous"));
        previous->setReadOnly(true);

        verticalLayout_2->addWidget(previous);

        current = new QTextEdit(outputConteiner);
        current->setObjectName(QString::fromUtf8("current"));
        current->setReadOnly(true);

        verticalLayout_2->addWidget(current);

        next = new QTextEdit(outputConteiner);
        next->setObjectName(QString::fromUtf8("next"));
        next->setReadOnly(true);

        verticalLayout_2->addWidget(next);

        EntryType = new QFrame(outputConteiner);
        EntryType->setObjectName(QString::fromUtf8("EntryType"));
        EntryType->setFrameShape(QFrame::StyledPanel);
        EntryType->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(EntryType);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radosne = new QCheckBox(EntryType);
        radosne->setObjectName(QString::fromUtf8("radosne"));

        horizontalLayout->addWidget(radosne);

        neutralne = new QCheckBox(EntryType);
        neutralne->setObjectName(QString::fromUtf8("neutralne"));

        horizontalLayout->addWidget(neutralne);

        smutne = new QCheckBox(EntryType);
        smutne->setObjectName(QString::fromUtf8("smutne"));

        horizontalLayout->addWidget(smutne);


        verticalLayout_2->addWidget(EntryType);


        gridLayout_2->addWidget(outputConteiner, 1, 0, 1, 1);


        verticalLayout->addWidget(main);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        writeToFile->setText(QCoreApplication::translate("MainWindow", "Zapisz", nullptr));
        deleteCurrentEntry->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 \305\233rodkowy wpis", nullptr));
        chooseFile->setText(QCoreApplication::translate("MainWindow", "Wybierz inny plik", nullptr));
        addEntry->setText(QCoreApplication::translate("MainWindow", "Dodaj wpis", nullptr));
        previousButton->setText(QCoreApplication::translate("MainWindow", "G\303\263ra", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "D\303\263\305\202", nullptr));
        addEntryType->setText(QCoreApplication::translate("MainWindow", "Dodaj akt. wspomienie do", nullptr));
        radosne->setText(QCoreApplication::translate("MainWindow", "Radosne", nullptr));
        neutralne->setText(QCoreApplication::translate("MainWindow", "Neutralne", nullptr));
        smutne->setText(QCoreApplication::translate("MainWindow", "Smutne", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
