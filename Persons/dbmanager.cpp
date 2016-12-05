#include "dbmanager.h"
#include <QVariant>

DbManager::DbManager(){}

DbManager::DbManager(const QString &path)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    getPersons();
}
DbManager::~DbManager()
{
    _db.close();
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
        _persons.push_back(temp);
    }
}
vector<Person> DbManager::getVector() const {return _persons;}

bool DbManager::isOpen() const {return _db.isOpen();}
