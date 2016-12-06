#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include "person.h"
#include "computer.h"
using namespace std;

class DbManager
{
public:
    bool isOpen() const;
    DbManager();
    ~DbManager();
    DbManager(const QString& path);
    vector<Person> getVector() const;
    void setVector(const vector<Person>& input);
    void insertIntoComputer(const Computer &input);
    void changeData();
private:
    vector<Person> _persons;
    void getPersons();
    QSqlDatabase _db;
};

#endif // DBMANAGER_H
