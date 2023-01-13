#include "entry.h"

Entry::Entry(QString text, QDateTime date)
    :m_entry(text), m_dateTime(date)
{}

Entry::Entry()
{

}

bool Entry::operator==(const Entry& rhs) const
{
    return (this->m_dateTime.date() == rhs.m_dateTime.date() &&
            this->m_dateTime.time() == rhs.m_dateTime.time());
}

bool Entry::operator!=(const Entry& rhs)
{
    return !(*this == rhs);
}

const QDateTime &Entry::dateTime() const
{
    return m_dateTime;
}

const QString &Entry::entry() const
{
    return m_entry;
}

void Entry::setEntry(const QString &newEntry)
{
    m_entry = newEntry;
}

void Entry::setDateTime(const QDateTime &newDateTime)
{
    m_dateTime = newDateTime;
}

bool Entry::operator<(const Entry& rhs)
{
    if(this->m_dateTime.date() > rhs.m_dateTime.date())
        return true;
    if(this->m_dateTime.date() == rhs.m_dateTime.date())
        return (this->m_dateTime.time() > rhs.m_dateTime.time());
    return false;
}

QString Entry::toString() //Formatowanie wpisu do string i bold Daty
{
    QString date = m_dateTime.toString();
    date = (QString("<span style=\"font-weight: bold;\">%1</span>").arg(date));

    return date + "<br>" + m_entry;
}
