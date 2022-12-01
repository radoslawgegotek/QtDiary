#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    setSeparator();
}

MainWindow::~MainWindow()
{
    delete ui;
    m_list.clear();
}

void MainWindow::addToList(Entry& newEntry)
{
    iter_listOfEntries = m_list.begin();
    while(iter_listOfEntries != m_list.end())
    {
        if(*iter_listOfEntries == newEntry)
        {
            m_list.replace(std::distance(m_list.begin(),iter_listOfEntries), newEntry);
            return;
        }
        iter_listOfEntries++;
    }
    m_list.append(newEntry);
    std::sort(m_list.begin(), m_list.end());
}

void MainWindow::on_addEntry_clicked()
{
    ui->showRecentEntries->clear();
    Entry newEntry(ui->entryFieldEdit->toPlainText(), ui->dateTimeEdit->dateTime());
    addToList(newEntry);

    for(Entry item : m_list)
    {
        ui->showRecentEntries->append(item.toString());
        if(m_list.size() > 1)
        {
            ui->showRecentEntries->append(m_separator);
        }
    }

}

void MainWindow::setSeparator()
{
    for(int i = 0; i < ui->showRecentEntries->size().rwidth()/5.10; i++)
    {
        m_separator.append('-');
    }
}
