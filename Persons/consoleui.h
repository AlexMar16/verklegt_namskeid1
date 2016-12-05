#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "person.h"
#include "service.h"
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
    vector<Person> _printOut;
    bool _print;
    bool specialCommand(const string& command);
    bool sortSpecialCommand(const string& choice);
    void printList(const string& _command);
    void addCommand();
    void removeCommand();
    void sortCommand();
    void findCommand();
    void quizCommand();
    void statusCommand();
    service _turn;      //The instance we use to communicate with the service layer.
};

#endif // CONSOLEUI_H
























