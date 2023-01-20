#ifndef DATA_H
#define DATA_H

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QtXml>
#include <QMessageBox>

#include "entry.h"


class Entry;

class Data
{
public:
    Data();

    void checkUser(QString&, QString&);
    void createUser(QString&, QString&);
    void addEntryType(QString type);

    void addEntriesToPrint(QString &type, int arg);

    //ustawienie sciezek do plikow i zawartosci
    void setFileEntries(const QString &fileName);
    void writeEntries(const QString &fileName);

    //scroll
    void scrollUP();
    void scrollDOWN();

    //usuwanie
    void deleteCurrent();
    void deleteEntriesFile();

    //dodanie nowego wpisu
    void addNewEntry(Entry &newEntry);

    //geter
    const QVector<Entry> &entrVec() const;
    int getCurrentElement() const;

    bool getUserCorrect() const;
    void setUserCorrect(bool newUserCorrect);


    const QList<Entry> &entriesToPrint() const;

private:
    QFile m_fileEntries;
    QVector<Entry> m_entrVec;
    QList<Entry> m_entriesToPrint;
    int currentElement = 0;
    bool userCorrect = false;

    void addToVec(Entry& newEntry);
};

#endif // DATA_H
