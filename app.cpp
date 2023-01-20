#include "app.h"
#include "data.h"

App::App(QObject *parent)
    : QObject{parent}
{
    dataLayer = new Data;
}

void App::setGui(MainWindow *newGui)
{
    gui = newGui;
}

void App::loadEntriesFromFile(const QString &fileName)
{
    dataLayer->setFileEntries(fileName);
    emit showEntries(dataLayer->entrVec(),dataLayer->entriesToPrint(), dataLayer->getCurrentElement());
}

void App::writeEntriesTofile(const QString &fileName)
{
    dataLayer->writeEntries(fileName);
}

void App::scrollEntriesUp()
{
    dataLayer->scrollUP();
    emit showEntries(dataLayer->entrVec(),dataLayer->entriesToPrint(), dataLayer->getCurrentElement());
}

void App::scrollEntriesDown()
{
    dataLayer->scrollDOWN();
    emit showEntries(dataLayer->entrVec(),dataLayer->entriesToPrint(), dataLayer->getCurrentElement());
}

void App::deleteCurrentEntry()
{
    dataLayer->deleteCurrent();
    emit showEntries(dataLayer->entrVec(),dataLayer->entriesToPrint(), dataLayer->getCurrentElement());
}

void App::addNewEntry()
{
    Entry newEntry;
    m_addingDialog = new NewEntryDialog(newEntry, nullptr);

    int result = m_addingDialog->exec();

    if(result && newEntry.entry() != "")
    {
        dataLayer->addNewEntry(newEntry);
        emit showEntries(dataLayer->entrVec(),dataLayer->entriesToPrint(), dataLayer->getCurrentElement());
    }
}

void App::checkUser(QString login, QString password)
{
    dataLayer->checkUser(login, password);
}

void App::createNewAccount()
{
    m_creatingAccountWindow = new CreateAccount(nullptr, this);
    m_creatingAccountWindow->exec();

    delete m_creatingAccountWindow;
}

void App::createUser(QString login, QString password)
{
    dataLayer->createUser(login, password);
}

void App::addEntryToType(QString type)
{
    dataLayer->addEntryType(type);
}

void App::checkedBoxesChage(QString type, int arg)
{
    dataLayer->addEntriesToPrint(type, arg);
    emit showEntries(dataLayer->entrVec(), dataLayer->entriesToPrint(), dataLayer->getCurrentElement());
}

bool App::loginUser()
{
    m_loginWindow = new LoginWindow(nullptr, this);

    while(!dataLayer->getUserCorrect())
    {
        int result = m_loginWindow->exec();

        if(!result)
            return false;

        if(!dataLayer->getUserCorrect())
            QMessageBox::information(m_loginWindow, "Błąd", "Błędny login lub hasło");
    }

    delete m_loginWindow;
    return true;
}

bool App::isEntriesEmpty()
{
    return dataLayer->entrVec().isEmpty();
}

void App::deleteEntriesFile()
{
    dataLayer->deleteEntriesFile();
}
