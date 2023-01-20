#include "mainwindow.h"
#include "app.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, App *app)
    : QMainWindow(parent)
    , mainApp(app)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainApp->setGui(this);

    connect(app,SIGNAL(showEntries(QVector<Entry>,QList<Entry>,int)),this,SLOT(on_showEntries(QVector<Entry>,QList<Entry>,int)));


    if(mainApp->loginUser())
    {
        mainApp->loadEntriesFromFile("wpisy.xml");
    }
    else
        QTimer::singleShot(0, this, SLOT(close()));

    ui->EntryTypes->addItem("smutne");
    ui->EntryTypes->addItem("radosne");
    ui->EntryTypes->addItem("neutralne");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    int keyKode = event->key();
    //qDebug() << keyKode;

    if(keyKode == Qt::Key_Up)
    {
        this->on_previousButton_clicked();
    }
    else if (keyKode == Qt::Key_Down)
    {
        this->on_nextButton_clicked();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    if(!mainApp->isEntriesEmpty())
        mainApp->writeEntriesTofile("wpisy.xml");
    else
        mainApp->deleteEntriesFile();
}

void MainWindow::on_addEntry_clicked()
{
    mainApp->addNewEntry();
}

void MainWindow::on_nextButton_clicked()
{
    mainApp->scrollEntriesUp();
}

void MainWindow::on_previousButton_clicked()
{
    mainApp->scrollEntriesDown();
}

void MainWindow::on_deleteCurrentEntry_clicked()
{
    mainApp->deleteCurrentEntry();
}

void MainWindow::on_showEntries(QVector<Entry> entries, QList<Entry> listEntry, int currEl)
{
    QString brakWpisow = QString("<span style=\" color:#ff0000; font: bold;\">%1</span>").arg("Brak wpisów");
    QString brakElementu = QString("<span style=\" color:#ff0000;\">%1</span>").arg("Brak elementu");

    if(entries.isEmpty() && listEntry.isEmpty())
    {
        ui->previous->setText(brakWpisow);
        ui->next->setText(brakWpisow);
        ui->current->setText(brakWpisow);
        return;
    }


    if(!listEntry.isEmpty())
    {
        ui->current->setText(listEntry[currEl].toString());
        if((currEl - 1) < 0)
            ui->previous->setText(brakElementu);
        else
            ui->previous->setText(listEntry[currEl - 1].toString());

        if ((currEl + 1) >= listEntry.size())
            ui->next->setText(brakElementu);
        else
            ui->next->setText(listEntry[currEl + 1].toString());
    }
    else
    {
        //qInfo() << currEl;
        ui->current->setText(entries[currEl].toString());
        if((currEl - 1) < 0)
            ui->previous->setText(brakElementu);
        else
            ui->previous->setText(entries[currEl - 1].toString());

        if ((currEl + 1) >= entries.size())
            ui->next->setText(brakElementu);
        else
            ui->next->setText(entries[currEl + 1].toString());
    }
}


void MainWindow::on_chooseFile_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Wybierz plik ze wspomnieniami"),
                                                        "./",
                                                        tr("XML (*.xml)"));
    mainApp->loadEntriesFromFile(fileName);
}


void MainWindow::on_writeToFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Zapisz jako"),
                               "./",
                               tr("XML (*.xml)"));

    if(!mainApp->isEntriesEmpty())
        mainApp->writeEntriesTofile(fileName);
}


void MainWindow::on_addEntryType_clicked()
{
    QString type = ui->EntryTypes->currentText();
    mainApp->addEntryToType(type);
    QMessageBox::information(this, "Dodane","Rodzaj wspomnienia dodany");
}


void MainWindow::on_radosne_stateChanged(int arg1)
{
    mainApp->checkedBoxesChage("radosne", arg1);
    if(!arg1) {
        ui->smutne->setEnabled(true);
        ui->neutralne->setEnabled(true);
    }
    else{
        ui->smutne->setEnabled(false);
        ui->neutralne->setEnabled(false);
    }
}


void MainWindow::on_neutralne_stateChanged(int arg1)
{
    mainApp->checkedBoxesChage("neutralne", arg1);
    if(!arg1) {
        ui->radosne->setEnabled(true);
        ui->smutne->setEnabled(true);
    }
    else{
        ui->smutne->setEnabled(false);
        ui->radosne->setEnabled(false);
    }
}

void MainWindow::on_smutne_stateChanged(int arg1)
{
    mainApp->checkedBoxesChage("smutne", arg1);
    if(!arg1) {
        ui->neutralne->setEnabled(true);
        ui->radosne->setEnabled(true);
    }
    else{
        ui->radosne->setEnabled(false);
        ui->neutralne->setEnabled(false);
    }
}

