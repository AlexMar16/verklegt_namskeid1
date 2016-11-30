#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "person.h"
#include "service.h"
#include <iostream>
#include <vector>
#include "question.h"

using namespace std;

class consoleUI
{
public:
    consoleUI();
    void run();
    bool validList(string _command);
    void addCommand();
    void sortCommand();
    void findCommand();
private:
    service turn;
    vector<Person> _printOut;

};

#endif // CONSOLEUI_H























//Git sucks
