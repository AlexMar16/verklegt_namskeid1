#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "person.h"
#include <iosfwd>
#include <vector>

using namespace std;

class consoleUI
{
public:
    consoleUI();
    void run();
    void printVector();
 private:
    vector<Person> printableVector;
};

#endif // CONSOLEUI_H
