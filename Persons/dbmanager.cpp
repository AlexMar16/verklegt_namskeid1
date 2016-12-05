#include "dbmanager.h"
#include <QVariant>
#include <QDebug>

DbManager::DbManager(const QString &path)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ComputerScience.sqlite";
    _db.setDatabaseName(dbName);
    _db.open();
}
void DbManager::print() const
{
    QString s = "SELECT * FROM Students";
    QSqlQuery query(_db);
    cout << query.isSelect() << endl;
    query.exec(s);
    query.next();
    while (query.next())
    {
        string jee = query.value("Name").toString().toStdString();
        cout << jee << endl << endl;
    }
    cout << "nope" << endl;
}
