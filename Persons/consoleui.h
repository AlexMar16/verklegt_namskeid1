#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "person.h"
#include "computer.h"
#include "PersonService.h"
#include "computerService.h"
#include <iostream>
#include <vector>
#include "dbmanager.h"
using namespace std;

class consoleUI
{
public:
    consoleUI();
    void run();

private:
    vector<int> _printStatus;
    vector<Computer> _printOutComputer;
    vector<Person> _printOutPerson;
    bool _print;
    bool beginningCommand(const string& input);
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
    void statusCommand();
    void commandBox(const string &theRightOne);
    PersonService _turnP;      //The instance we use to communicate with the PersonService layer.
    computerService _turnC;

};

#endif // CONSOLEUI_H
























