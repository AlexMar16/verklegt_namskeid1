#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "person.h"
#include "service.h"
#include <iostream>
#include <vector>

using namespace std;

class consoleUI
{
public:
    consoleUI();
    void run();
    void validList(string _command);
    void addCommand();
    void removeCommand();
    void sortCommand();
    void findCommand();
    void quizCommand();
    void statusCommand();
private:
    service _turn;
    vector<Person> _printOut;
    vector<int> _printStatus;
    bool _valid;
};

#endif // CONSOLEUI_H
























