#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    if (m_entriesList.isEmpty())
    {
        ui->previous->setText("Brak wpisów");
        ui->current->setText("Brak wpisów");
        ui->next->setText("Brak wpisów");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    m_entriesList.clear();
}

void MainWindow::addToList(Entry& newEntry)
{
    iter_entriesList = m_entriesList.begin();
    while(iter_entriesList != m_entriesList.end())
    {
        if(*iter_entriesList == newEntry)
        {
            m_entriesList.replace(std::distance(m_entriesList.begin(),iter_entriesList), newEntry);
            return;
        }
        iter_entriesList++;
    }
    m_entriesList.append(newEntry);
    std::sort(m_entriesList.begin(), m_entriesList.end());
}

void MainWindow::on_addEntry_clicked()
{
    Entry newEntry(ui->entryFieldEdit->toPlainText(), ui->dateTimeEdit->dateTime());
    addToList(newEntry);
    ui->entryFieldEdit->clear();

    ui->current->setText(this->m_entriesList.last().toString());
}
