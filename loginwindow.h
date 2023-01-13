#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QtXml>
#include <QMessageBox>
#include "createaccount.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    bool getIsUserCorrect() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_newAccount_clicked();

private:
    Ui::LoginWindow *ui;
    CreateAccount *m_creatingAccountWindow;
    bool isUserCorrect = false;
};

#endif // LOGINWINDOW_H
