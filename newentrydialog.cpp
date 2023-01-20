#include "newentrydialog.h"
#include "ui_newentrydialog.h"

NewEntryDialog::NewEntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEntryDialog)
{
    ui->setupUi(this);
}

NewEntryDialog::NewEntryDialog(Entry &entry, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEntryDialog),
    m_returnEntry(&entry)
{
    ui->setupUi(this);
    connect(this, SIGNAL(finished(int)), this, SLOT(on_finished(int)));
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

NewEntryDialog::~NewEntryDialog()
{
    delete ui;
}

void NewEntryDialog::on_finished(int arg)
{
    Q_UNUSED(arg);

    if(m_returnEntry != nullptr && !(ui->poleWpisu->toPlainText().isEmpty()) && ui->poleWpisu->toPlainText() != "")
    {
        m_returnEntry->setEntry(ui->poleWpisu->toPlainText());
        m_returnEntry->setDateTime(ui->dateTimeEdit->dateTime());
    }
    deleteLater();
}
