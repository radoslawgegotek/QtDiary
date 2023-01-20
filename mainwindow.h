#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QtXml>
#include <QFileDialog>
#include <QMessageBox>
#include "entry.h"


class App;
class Entry;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, App *app = nullptr);
    ~MainWindow();


private slots:
    void on_addEntry_clicked();
    void on_nextButton_clicked();
    void on_previousButton_clicked();
    void on_deleteCurrentEntry_clicked();

    //sloty z klasa app
    void on_showEntries(QVector<Entry> entries, QList<Entry> listEntry, int currEl);

    void on_chooseFile_clicked();

    void on_writeToFile_clicked();

    void on_addEntryType_clicked();

    void on_radosne_stateChanged(int arg1);

    void on_neutralne_stateChanged(int arg1);

    void on_smutne_stateChanged(int arg1);

private:
    void keyPressEvent(QKeyEvent*) override;
    void closeEvent(QCloseEvent*) override;

    App *mainApp = nullptr;
    Ui::MainWindow *ui;
    bool userCorrect = false;
};
#endif // MAINWINDOW_H
