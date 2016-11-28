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
    friend ostream& operator <<(ostream& out, const vector<Person>& rhs);
};

#endif // CONSOLEUI_H
