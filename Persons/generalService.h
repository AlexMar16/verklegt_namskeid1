#ifndef GENERALSERVICE_H
#define GENERALSERVICE_H
//#include "person.h"
//#include "computer.h"
#include "dbmanager.h"

class generalService
{
public:
    generalService();
    string toLower(const string& toLowerString);
    void setProgram(const string& command);
    bool getProgram() const;
    bool dataFound() const;
    vector<Person> getOriginalPersons() const;
    vector<Computer> getOriginalComputers() const;
    vector<Connection> getOriginalConnections() const;
    bool quizDuplicatedAnswer(const string& a, const string& b, const string& c, const string& d);
    bool alreadyInDatabase(const string& name);
    void speakQuestion(const string& input);
    int findID(const string& name, const bool &swapped);

private:
    bool _program;
    bool _dataFound;
    vector<Person> _persons;
    vector<Computer> _computers;
    vector<Connection> _connections;
    DbManager _database;
};

#endif // GENERALSERVICE_H
