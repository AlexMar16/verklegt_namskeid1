#include "dbmanager.h"
#include <QVariant>
#include <QDebug>
#include <QSqlError>

DbManager::DbManager(const QString &path)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
}
void DbManager::print() const
{
    QString s = "SELECT * FROM Computers";
    QSqlQuery query(_db);
    cout << query.isSelect() << endl;
    query.exec(s);
    while (query.next())
    {
        string jee = query.value("Name").toString().toStdString();
        cout << jee << endl;
    }
}
