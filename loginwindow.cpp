#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
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
                            isUserCorrect = true;
                            usersFile.close();
                            return;
                        }
                    }
                }
            }
            usersFile.close();
            QMessageBox::information(this, "Błąd logowania", "Użytkownik nie istnieje");
        }
    }
}

bool LoginWindow::getIsUserCorrect() const
{
    return isUserCorrect;
}

void LoginWindow::on_buttonBox_rejected()
{

}


void LoginWindow::on_newAccount_clicked()
{
    m_creatingAccountWindow = new CreateAccount(nullptr);
    m_creatingAccountWindow->exec();

    delete m_creatingAccountWindow;
}

