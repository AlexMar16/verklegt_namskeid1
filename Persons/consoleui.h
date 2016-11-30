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
    bool validList();
    void addCommand();
private:
    service turn;

};

#endif // CONSOLEUI_H























//Git sucks
