#include "data.h"

Data::Data()
{

}

void Data::checkUser(QString &login, QString &password)
{
    QFileInfo file("users.xml");
    QDomDocument document;
    QFile usersFile;

    if(file.isFile() && file.exists())
    {
        usersFile.setFileName("users.xml");

        if(usersFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            if(document.setContent(&usersFile))
            {
                QDomElement root = document.firstChildElement();
                QDomNodeList usersList = root.elementsByTagName("User");

                for(int i = 0; i < usersList.size(); i++)
                {
                    QDomElement user = usersList.at(i).toElement();
                    if(login == user.attribute("Login") && password == user.attribute("Password"))
                    {
                        userCorrect = true;
                        usersFile.close();
                        return;
                    }
                }
            }
        }
        usersFile.close();
    }
}

void Data::createUser(QString &login, QString &password)
{
    QFileInfo file("users.xml");
    QDomDocument document;
    QFile usersFile;

    if(file.isFile() && file.exists())
    {
        usersFile.setFileName("users.xml");

        if(usersFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            if(document.setContent(&usersFile))
            {
                QDomElement root = document.firstChildElement();
                QDomNodeList usersList = root.elementsByTagName("User");

                for(int i = 0; i < usersList.size(); i++)
                {
                    QDomElement user = usersList.at(i).toElement();
                    if(login == user.attribute("Login") && password == user.attribute("Password"))
                    {
                        usersFile.close();
                        QMessageBox::information(nullptr,"Błąd", "Użytkownik już istnieje");
                        return;
                    }
                }
                usersFile.close();

                usersFile.open(QIODevice::WriteOnly | QIODevice::Text);
                QDomElement newUser = document.createElement("User");
                newUser.setAttribute("Login", login);
                newUser.setAttribute("Password", password);
                root.appendChild(newUser);

                QTextStream stream(&usersFile);
                stream << document.toString();
            }
        }
        usersFile.close();
    }
}

void Data::addEntryType(QString type)
{
    m_entrVec[currentElement].setType(type);
}

void Data::addEntriesToPrint(QString &type, int add)
{
    if(add)
    {
        for(Entry &element : m_entrVec)
        {
            if(element.type() == type)
            {
                m_entriesToPrint.append(element);
                currentElement = 0;
            }
        }
    }
    else
    {
        for(auto i = m_entriesToPrint.cbegin(); i < m_entriesToPrint.cend(); i++)
        {
            if(i->type() == type)
            {
                m_entriesToPrint.erase(i);
            }
        }
        currentElement = 0;
    }
}

void Data::setFileEntries(const QString &fileName)
{
    QFileInfo file(fileName);
    QDomDocument document;

    if(!m_entrVec.isEmpty())
        m_entrVec.clear();

    if(file.isFile() && file.exists())
    {
        m_fileEntries.setFileName(fileName);

        if(m_fileEntries.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            if(document.setContent(&m_fileEntries))
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
                    newEntry.setType(elEntry.attribute("Type"));
                    m_entrVec.append(newEntry);
                }
            }
        }
        m_fileEntries.close();
    }
}

void Data::writeEntries(const QString &fileName)
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
        entry.setAttribute("Type", element.type());
        root.appendChild(entry);
    }

    //zapisanie wszystkiego do pliku
    m_fileEntries.setFileName(fileName);


    if(m_fileEntries.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&m_fileEntries);
        stream << document.toString();
    }
    m_fileEntries.close();
}

void Data::scrollUP()
{
    if(m_entriesToPrint.isEmpty())
    {
        if(currentElement + 1 < m_entrVec.size())
        {
            currentElement++;
        }
    }
    else
    {
        if(currentElement + 1 < m_entriesToPrint.size())
        {
            currentElement++;
        }
    }
}

void Data::scrollDOWN()
{
    if(currentElement - 1 >= 0)
    {
        currentElement--;
    }
}

void Data::deleteCurrent()
{
    if(!m_entrVec.isEmpty())
    {
        m_entrVec.erase(m_entrVec.begin() + currentElement);

        if(currentElement - 1 >= 0)
        {
           currentElement--;
           qInfo() << m_entrVec.size();
           return;
        }
        else if (currentElement + 1 < m_entrVec.size())
        {
            currentElement++;
            qInfo() << m_entrVec.size();
            return;
        }
    }
}

void Data::deleteEntriesFile()
{
    m_fileEntries.remove();
}

void Data::addNewEntry(Entry &newEntry)
{
    addToVec(newEntry);
    currentElement = m_entrVec.indexOf(newEntry);
}

const QVector<Entry> &Data::entrVec() const
{
    return m_entrVec;
}

int Data::getCurrentElement() const
{
    return currentElement;
}

bool Data::getUserCorrect() const
{
    return userCorrect;
}

void Data::setUserCorrect(bool newUserCorrect)
{
    userCorrect = newUserCorrect;
}

const QList<Entry> &Data::entriesToPrint() const
{
    return m_entriesToPrint;
}

void Data::addToVec(Entry &newEntry)
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
