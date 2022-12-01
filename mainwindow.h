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
    QList<Entry> m_list;
    QList<Entry>::Iterator iter_listOfEntries = m_list.begin();
    QString m_separator;
    void setSeparator();

    void addToList(Entry& newEntry);
};
#endif // MAINWINDOW_H
