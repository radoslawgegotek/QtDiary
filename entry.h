#ifndef ENTRY_H
#define ENTRY_H

#include "qdatetime.h"

class Entry
{
public:
    Entry(QString, QDateTime);

    QString toString();

    bool operator==(const Entry&);
    bool operator<(const Entry&);
    bool operator!=(const Entry&);

private:
    QString m_entry;
    QDateTime m_dateTime;
};

#endif // ENTRY_H
