#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_loginWindow = new LoginWindow(nullptr);

    while(!userCorrect)
    {
        int result = m_loginWindow->exec();
        userCorrect = m_loginWindow->getIsUserCorrect();
        if(!result)
            break;
    }

    if(userCorrect)
    {
        readEntries();
        if (m_entrVec.isEmpty())
        {
            QString brakWpisow = QString("<span style=\" color:#ff0000; font: bold;\">%1</span>").arg("Brak wpisów");
            ui->previous->setText(brakWpisow);
            ui->current->setText(brakWpisow);
            ui->next->setText(brakWpisow);
        }
    }
    else
        QTimer::singleShot(0, this, SLOT(close()));

    delete m_loginWindow;
}

MainWindow::~MainWindow()
{
    delete ui;
    m_entrVec.clear();
}

void MainWindow::addToVec(Entry& newEntry)
{
    for(Entry &entry : m_entrVec)
    {
       if(entry == newEntry)
       {
           std::replace(m_entrVec.begin(), m_entrVec.end(), entry, newEntry);
           return;
       }
    }
    m_entrVec.append(newEntry);
    std::sort(m_entrVec.begin(), m_entrVec.end());
}

void MainWindow::writeEntries()
{
    // zapis wpisow do xml

    QDomDocument document;
    QDomElement root = document.createElement("Wpisy");
    document.appendChild(root);

    //zapisanie ostatniego aktualnego indexu wpisu
    QDomElement index = document.createElement("Index");
    index.setAttribute("Current_Index", currentElement);
    root.appendChild(index);

    //zapisanie wpisow
    for(Entry &element : m_entrVec)
    {
        QDomElement entry = document.createElement("Wpis");
        entry.setAttribute("Text", element.entry());
        entry.setAttribute("Date", element.dateTime().toString());
        root.appendChild(entry);
    }

    //zapisanie wszystkiego do pliku
    if(entriesFile.fileName().isEmpty())
        entriesFile.setFileName("wpisy.xml");

    if(entriesFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&entriesFile);
        stream << document.toString();
    }
    entriesFile.close();
}

void MainWindow::readEntries()
{
    QFileInfo file("wpisy.xml");
    QDomDocument document;

    if(file.isFile() && file.exists())
    {
        entriesFile.setFileName("wpisy.xml");

        if(entriesFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            if(document.setContent(&entriesFile))
            {
                QDomElement root = document.firstChildElement();
                QDomNode index = root.firstChildElement();
                QDomElement currIndex = index.toElement();
                currentElement = currIndex.attribute("Current_Index").toInt();

                QDomNodeList entriesList = root.elementsByTagName("Wpis");

                for(int i = 0; i < entriesList.size(); i++)
                {
                    QDomNode entry = entriesList.at(i);
                    QDomElement elEntry = entry.toElement();
                    Entry newEntry(elEntry.attribute("Text"), QDateTime::fromString(elEntry.attribute("Date")));
                    m_entrVec.append(newEntry);
                }
            }
        }
        entriesFile.close();
        printEntries();
    }
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
    if(!m_entrVec.isEmpty())
        writeEntries();
}

void MainWindow::on_addEntry_clicked()
{
    Entry newEntry;
    m_addingDialog = new NewEntryDialog(newEntry, nullptr);

    int result = m_addingDialog->exec();

    if(result)
    {
        addToVec(newEntry);
        currentElement = m_entrVec.indexOf(newEntry);
        printEntries();
        qInfo() << "WYKONANE";
    }
}

void MainWindow::printEntries()
{
    ui->current->setText(m_entrVec[currentElement].toString());

    QString brakWpisow = QString("<span style=\" color:#ff0000; font: bold;\">%1</span>").arg("Brak wpisów");
    QString brakElementu = QString("<span style=\" color:#ff0000;\">%1</span>").arg("Brak elementu");

    if(m_entrVec.isEmpty())
    {
        ui->previous->setText(brakWpisow);
        ui->current->setText(brakWpisow);
        ui->next->setText(brakWpisow);
        return;
    }

    if((currentElement - 1) < 0)
    {
        ui->previous->setText(brakElementu);
    }
    else
    {
        ui->previous->setText(m_entrVec[currentElement - 1].toString());
    }

    if ((currentElement + 1) >= m_entrVec.size())
    {
        ui->next->setText(brakElementu);
    }
    else
    {
        ui->next->setText(m_entrVec[currentElement + 1].toString());
    }
}

void MainWindow::on_nextButton_clicked()
{
    if(currentElement + 1 < m_entrVec.size())
    {
        currentElement++;
        printEntries();
    }
}


void MainWindow::on_previousButton_clicked()
{
    if(currentElement - 1 >= 0)
    {
        currentElement--;
        printEntries();
    }
}

void MainWindow::on_deleteCurrentEntry_clicked()
{
    if(!m_entrVec.isEmpty())
    {
        m_entrVec.erase(m_entrVec.begin() + currentElement);

        if(currentElement - 1 >= 0)
        {
           currentElement--;
           printEntries();
           return;
        }
        else if (currentElement + 1 < m_entrVec.size())
        {
            currentElement++;
            printEntries();
            return;
        }
        printEntries();
    }
}

