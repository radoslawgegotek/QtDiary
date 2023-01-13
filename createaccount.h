#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include <QtXml>
#include <QMessageBox>

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = nullptr);
    ~CreateAccount();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CreateAccount *ui;
};

#endif // CREATEACCOUNT_H
