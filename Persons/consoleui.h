#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "person.h"
#include "service.h"
#include <iosfwd>
#include <vector>

using namespace std;

class consoleUI
{
public:
    consoleUI();
    void run();
    friend void dlist();

 private:
    vector<Person> _printableVector;
};

#endif // CONSOLEUI_H
