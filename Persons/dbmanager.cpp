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
    getPersons();
}
void DbManager::print() const
{
    QString s = "SELECT * FROM Computers";
    QSqlQuery query(_db);
    query.exec(s);
    while (query.next())
    {
        string jee = query.value("Name").toString().toStdString();
        cout << jee << endl;
    }
}
void DbManager::getPersons()
{
    QString s = "SELECT * FROM Persons";
    QSqlQuery query(_db);
    query.exec(s);
    Person temp;
    while (query.next())
    {
        string name = query.value("Name").toString().toStdString();
        temp.setName(name);

        string gender = query.value("Gender").toString().toStdString();
        temp.setGender(gender);

        int birthYear = query.value("birthYear").toUInt();
        temp.setBirthYear(birthYear);

        int deathYear = query.value("deathYear").toUInt();
        temp.setDeathYear(deathYear);
    }
}
