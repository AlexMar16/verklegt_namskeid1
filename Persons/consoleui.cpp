#include "consoleui.h"
#include <iostream>

using name


consoleUI::consoleUI()
{

}

void consoleUI::run()
{
    bool going = true;
    while(going)
    {
        cout << "Please enter one of the following commands:" << endl;
        cout << "list - This command will list every single person int he system" << endl;
        cout << "add -This command allows you to add a person to the list" << endl;

        string command;
        cin >> command;
    }

}
