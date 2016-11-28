#include "consoleui.h"
#include <iostream>

using namespace std;


consoleUI::consoleUI()
{

}
/*
void dlist(string stuff)
{
    //notum kannski
}
*/
void displaylist(string command)
{
    if(command == "list")
    {
        cout << "List! " << endl;
    }
    else if(command == "add")
    {
        cout << "ADd!" << endl;
    }
    else if(command == "find")
    {
        cout << "find!" << endl;
    }
    else if(command == "sorta")
    {
        cout << "soarta!" << endl;
    }
    else if(command == "sortb")
    {
        cout << "sortb!" << endl;
    }
    else if(command == "sortd")
    {
        cout << "sortd!" << endl;
    }
    else if(command == "sortg")
    {
        cout << "sortg!" << endl;
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
    }
}

void consoleUI::run()
{
    string command;
    bool going = true;

    while(going)
    {
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
        displaylist(command);





    }

}
