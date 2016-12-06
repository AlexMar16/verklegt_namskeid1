#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "person.h"
#include "computer.h"
#include "PersonService.h"
#include "computerService.h"
#include "generalService.h"
#include "dbmanager.h"
using namespace std;

class consoleUI
{
public:
    consoleUI();
    void run();

private:
    generalService _turnG;
    vector<int> _printStatus;
    vector<Computer> _printOutComputer;
    vector<Person> _printOutPerson;
    bool _print;
    bool beginningCommand();
    bool specialCommandPerson(const string& command);
    bool sortSpecialCommandPerson(const string& choice);
    void specialCommandComputer(const string& command);
    void printListPerson(const string& _command);
    void printListComputer(const string& _command);
    void addCommand();
    void addCompCommand();
    void removeCommand();
    void sortCommandPerson();
    void sortCommandComputer();
    void findCommand();
    void quizCommand();
    void statusCommandPerson();
    void statusCommandComputer();
    void firstCommandBox();
    void commandBox();
    PersonService _turnP;      //The instance we use to communicate with the PersonService layer.
    string theRightOne;
    string _command;
    string database;
    computerService _turnC;

};

#endif // CONSOLEUI_H
























