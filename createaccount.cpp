#include "createaccount.h"
#include "ui_createaccount.h"

CreateAccount::CreateAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAccount)
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
            QString login = ui->newLogin->text();
            QString pass = ui->pass_1->text();

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
                            if(login == user.attribute("Login") && pass == user.attribute("Password"))
                            {
                                usersFile.close();
                                QMessageBox::information(this, "Błąd tworzenia użytkownika", "Użytkownik już istnieje");
                                return;
                            }
                        }
                        usersFile.close();

                        usersFile.open(QIODevice::WriteOnly | QIODevice::Text);
                        QDomElement newUser = document.createElement("User");
                        newUser.setAttribute("Login", login);
                        newUser.setAttribute("Password", pass);
                        root.appendChild(newUser);

                        QTextStream stream(&usersFile);
                        stream << document.toString();
                    }
                }
                usersFile.close();
            }
        }
        else
            QMessageBox::information(this, "Błąd tworzenia użytkownika", "Za mało podanych informacji");
    }
    else
        QMessageBox::information(this, "Błąd tworzenia użytkownika", "Za mało podanych informacji");
}

