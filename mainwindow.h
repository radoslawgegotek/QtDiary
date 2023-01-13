#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QtXml>
#include "newentrydialog.h"
#include "loginwindow.h"
#include "entry.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_addEntry_clicked();
    void on_nextButton_clicked();
    void on_previousButton_clicked();
    void on_deleteCurrentEntry_clicked();

private:
    void printEntries();
    void addToVec(Entry& newEntry);
    void writeEntries();
    void readEntries();

    void keyPressEvent(QKeyEvent*) override;
    void closeEvent(QCloseEvent*) override;

    Ui::MainWindow *ui;
    NewEntryDialog *m_addingDialog;
    LoginWindow *m_loginWindow;
    QVector<Entry> m_entrVec;
    QFile entriesFile;
    int currentElement = 0;
    bool userCorrect = false;
};
#endif // MAINWINDOW_H
