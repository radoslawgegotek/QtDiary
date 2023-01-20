#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include <QtXml>
#include <QMessageBox>

class App;

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = nullptr, App *app = nullptr);
    ~CreateAccount();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CreateAccount *ui;
    App *mainApp = nullptr;
};

#endif // CREATEACCOUNT_H
