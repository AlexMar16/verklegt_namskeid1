#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include "person.h"
#include "computer.h"
#include "connection.h"
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
    void insertIntoPerson(const Person &input);
    void removeFromComputers(const Computer &input);
    void removeFromPersons(const Person &input);

    void changeData();
    void getComputers();
    void getConnections();
    void changePerson(const Person& input, const int personIndex);
    void changeComputer(const Computer& input, const int computerIndex);

private:
    vector<Person> _persons;
    vector<Computer> _computers;
    vector<Connection> _connections;
    void getPersons();
    QSqlDatabase _db;
};

#endif // DBMANAGER_H

