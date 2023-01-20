#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "app.h"

LoginWindow::LoginWindow(QWidget *parent, App *app) :
    QDialog(parent),
    ui(new Ui::LoginWindow),
    mainApp(app)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_buttonBox_accepted()
{
    if(!(ui->login->text().isEmpty() && ui->password->text().isEmpty()))
    {
        QString login = ui->login->text();
        QString password = ui->password->text();
        mainApp->checkUser(login, password);
    }
}

void LoginWindow::on_buttonBox_rejected()
{
    return;
}


void LoginWindow::on_newAccount_clicked()
{
    mainApp->createNewAccount();
}
