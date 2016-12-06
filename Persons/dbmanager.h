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
    vector<Computer>getCVector() const;

    void setVector(const vector<Person>& input);
    void setCVector(const vector<Computer>& input);
    void insertIntoComputer(const Computer &input);
    void changeData();
    void getComputers();


private:
    vector<Person> _persons;
    vector<Computer> _Computer;
    void getPersons();
    QSqlDatabase _db;
};

#endif // DBMANAGER_H
