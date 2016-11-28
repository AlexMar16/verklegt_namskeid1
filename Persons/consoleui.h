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
    void dlist();
    bool displayList();
    friend ostream& operator <<(ostream& out, const vector<Person>& rhs);
 private:
    vector<Person> _printableVector;
    string _command;
};

#endif // CONSOLEUI_H
