#include "dbmanager.h"
#include <QVariant>
#include <QDebug>

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        cout << "Error: connection with database fail" << endl;
    }
    else
    {
        cout << "Database: connection ok" << endl;
    }
    print();
}
void DbManager::print() const
{
    QSqlQuery query("SELECT * FROM jee");
    int idName = query.record().indexOf("jee");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << name;
    }
}
