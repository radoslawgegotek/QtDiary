#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QtXml>
#include <QMessageBox>

class App;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr, App *mainApp = nullptr);
    ~LoginWindow();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_newAccount_clicked();

private:
    Ui::LoginWindow *ui;
    App *mainApp;
};

#endif // LOGINWINDOW_H
