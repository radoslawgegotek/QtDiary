#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;

    QList<Entry> m_entriesList;
    QList<Entry>::Iterator iter_entriesList = m_entriesList.begin();
    int indexes[3]{};

    void addToList(Entry& newEntry);
};
#endif // MAINWINDOW_H
