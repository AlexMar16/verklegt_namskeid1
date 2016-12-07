#ifndef GENERALSERVICE_H
#define GENERALSERVICE_H
#include "person.h"
#include "computer.h"
#include "dbmanager.h"

class generalService
{
public:
    generalService();
    string toLower(const string& toLowerString);
    void setProgram(const string& command);
    bool getProgram() const;
    void closeDatabase();
    bool dataFound() const;
private:
    bool _program;
    bool _dataFound;
    vector<Person> _persons;
    vector<Computer> _computers;
    DbManager _database;

};

#endif // GENERALSERVICE_H
