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
    bool isOpen() const;
    DbManager();
    DbManager(const QString& path);
    vector<Person> getVector() const;
    void print() const;
private:
    vector<Person> _persons;
    void getPersons();
    QSqlDatabase _db;
};

#endif // DBMANAGER_H
