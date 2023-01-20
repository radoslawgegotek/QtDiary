#ifndef APP_H
#define APP_H

#include <QObject>
#include <QMessageBox>

#include "createaccount.h"
#include "entry.h"
#include "loginwindow.h"
#include "newentrydialog.h"

class MainWindow;
class Entry;
class Data;

class App : public QObject
{
    Q_OBJECT
public:
    explicit App(QObject *parent = nullptr);

    void setGui(MainWindow *newGui);

    //services methods
    void loadEntriesFromFile(const QString &fileName);
    void writeEntriesTofile(const QString &fileName);
    void scrollEntriesUp();
    void scrollEntriesDown();
    void deleteCurrentEntry();
    void addNewEntry();
    void checkUser(QString login, QString password);
    void createNewAccount();
    void createUser(QString login, QString password);
    void addEntryToType(QString type);
    void checkedBoxesChage(QString type, int arg);

    bool loginUser();

    bool isEntriesEmpty();
    void deleteEntriesFile();

signals:
    void showEntries(QVector<Entry>,QList<Entry>,int);

private:
    MainWindow *gui = nullptr;
    Data *dataLayer = nullptr;
    NewEntryDialog *m_addingDialog;
    LoginWindow *m_loginWindow;
    CreateAccount *m_creatingAccountWindow;
};

#endif // APP_H
