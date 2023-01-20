#ifndef NEWENTRYDIALOG_H
#define NEWENTRYDIALOG_H

#include <QDialog>
#include "entry.h"

namespace Ui {
class NewEntryDialog;
}

class NewEntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewEntryDialog(QWidget *parent = nullptr);
    explicit NewEntryDialog(Entry &entry, QWidget *parent = nullptr);
    ~NewEntryDialog();

private slots:
    void on_finished(int);

private:
    Ui::NewEntryDialog *ui;
    Entry *m_returnEntry;
};

#endif // NEWENTRYDIALOG_H
