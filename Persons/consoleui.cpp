#include "consoleui.h"
#include "person.h"
#include <iostream>

using namespace std;

consoleUI::consoleUI(){}

void consoleUI::run()
{
    service turn;
    string command;
    bool programloopbool = true;
    do{
    cout << "******************************************************************************" << endl;
    cout << "Please enter one of the following commands:" << endl;
    cout << "list - This command will list every single person in the system" << endl;
    cout << "add -This command allows you to add a person to the list" << endl;
    cout << "find -This command allows you to find a certain person in the list" << endl;
    cout << "sorta -This command will list every single person in the system sorted alhpabaticly" << endl;
    cout << "sortb -This command will list every single person in the system sorted by date of birth" << endl;
    cout << "sortd -This command will list every single person in the system sorted by date of death" << endl;
    cout << "sortg -This command will list every single person in the system sorted by their gender" << endl;
    cout << "******************************************************************************" << endl;
    cout << "command: ";
    cin >> command;
    turn.setCommand(command);
    cout << endl;
    }while(turn.displayList());
}
