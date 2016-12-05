#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <Qstring>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <iostream>
#include "person.h"
using namespace std;

class DbManager
{
public:
    DbManager();
    DbManager(const QString& path);
    void getPersons();
    void print() const;
    vector<Person> getAllPersons();
private:
    QSqlDatabase _db;
};

#endif // DBMANAGER_H
