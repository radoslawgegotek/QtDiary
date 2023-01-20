#include "createaccount.h"
#include "ui_createaccount.h"
#include "app.h"

CreateAccount::CreateAccount(QWidget *parent, App *app) :
    QDialog(parent),
    ui(new Ui::CreateAccount),
    mainApp(app)
{
    ui->setupUi(this);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_buttonBox_accepted()
{
    if(!(ui->newLogin->text().isEmpty() && ui->pass_1->text().isEmpty() && ui->pass_2->text().isEmpty()))
    {
        if((ui->pass_1->text() == ui->pass_2->text()) && ui->pass_1->text() != "")
        {
            mainApp->createUser(ui->newLogin->text(), ui->pass_1->text());
        }
        else
            QMessageBox::information(this, "Błąd tworzenia użytkownika", "Za mało podanych informacji");
    }
    else
        QMessageBox::information(this, "Błąd tworzenia użytkownika", "Za mało podanych informacji");
}

