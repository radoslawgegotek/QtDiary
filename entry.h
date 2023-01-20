#ifndef ENTRY_H
#define ENTRY_H

#include "qdatetime.h"

class Entry
{
public:
    Entry(QString, QDateTime);
    Entry();

    QString toString();


    bool operator==(const Entry&) const;
    bool operator<(const Entry&) const;
    bool operator!=(const Entry &);

    const QDateTime &dateTime() const;
    const QString &entry() const;

    void setEntry(const QString &newEntry);

    void setDateTime(const QDateTime &newDateTime);

    const QString &type() const;
    void setType(const QString &newType);

private:
    QString m_entry;
    QDateTime m_dateTime;
    QString m_type;
};

#endif // ENTRY_H
