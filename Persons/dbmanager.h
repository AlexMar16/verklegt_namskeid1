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
    bool addPerson(const Person& input);
    void print() const;
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
