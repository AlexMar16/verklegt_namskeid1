#include "consoleui.h"
#include "person.h"
#include <iostream>

using namespace std;

consoleUI::consoleUI()
{

}

void dlist()
{
    service temp;
    _printableVector = temp.get_list();
    for(size_t i = 0; i < _printableVector.size(); i++)
    {
        cout << _printableVector[i] << endl;
    }
}

int continueprogram(string YorN)//if continue return 1, if exit returnes 2 and if wrong input return 3
{
    if(YorN == "Y" || YorN == "y")
    {
        return 1;
    }
    else if(YorN == "N" || YorN == "n")
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

bool displaylist(string command)// depending on input from user, do something
{
    service temp;
    if(command == "list")
    {
        temp.dlist();
        return false;
    }
    else if(command == "add")
    {
        //Person person(string _name,char _gender int _birthYear, int _deathYear) todo
        return false;
    }
    else if(command == "find")
    {
        string name;
        cout << "enter name to find:";
        cin >> name;
        return false;
    }
    else if(command == "sorta")
    {
        cout << "soarta!" << endl;
        return false;
    }
    else if(command == "sortb")
    {
        cout << "sortb!" << endl;
        return false;
    }
    else if(command == "sortd")
    {
        cout << "sortd!" << endl;
        return false;
    }
    else if(command == "sortg")
    {
        cout << "sortg!" << endl;
        return false;
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        return true;
    }
}

void consoleUI::run()// run command, (the main function)
{
    string command;//user input
    bool programloopbool = true;//main program loop boolean
    while(programloopbool)//while user wants to continue the program
    {
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
        cout << endl;
        }while(displaylist(command));


        string YorN;// yes or no to continue?
        bool switchbool = true;
        do{
            cout << "Would you like to continue? (y/n)";
            cin >> YorN;
            switch (continueprogram(YorN)) {//returns 1 , 2 or 3 based on the input
            case 1://y or Y
                switchbool = false;
                break;
            case 2://n or N
                programloopbool = false;
                switchbool = false;
                break;
            case 3://wronginput
                cout << "Wrong input" << endl;
                break;
            }
        }while(switchbool);

    }

}
