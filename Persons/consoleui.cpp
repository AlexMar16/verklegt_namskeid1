#include "consoleui.h"

using namespace std;


consoleUI::consoleUI(){
}


void consoleUI::addCommand()
{
  Person input;
  cout << "Please enter the following information about the new scientist " << endl;
  cout << "in the following order." << endl;
  cout << "Be aware you cannot put letters that are not in the English alphabet." << endl;
  cout << "Name (Minimum two names, Maximum three)" << endl;
  cout << "Gender (male/female) in lowercase." << endl;
  cout << "Birthyear (YYYY)" << endl;
  cout << "Died (0 if still alive)" << endl;
  cin >> input;
  turn.addPerson(input);
}

void consoleUI::run()
{
    bool valid = true;
    string keepGoingb;
    string command;
    do
    {
        cout << "**********************************************************************************" << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << endl;
        cout << "list  - This command will list every person in the system." << endl;
        cout << "add   - This command allows you to add a person to the list." << endl;
        cout << "find  - This command allows you to find a certain person in the list." << endl;
        cout << "sort  - This command will allow you to sort the scientists." << endl;
        cout << "quit  - This command will quit the program" << endl;
        cout << "**********************************************************************************" << endl;
        cout << "command: ";
        cin >> command;

        turn.setCommand(command);
        cout << endl;



        valid = turn.validList();

        //if (turn.add_check())

        if (false)

        {
            addCommand();
        }
        if (false)
        {
            string toFind;
            cout << "Name to find: ";
            cin >> toFind;
            vector<Person> printOut = turn.find_person(toFind);
            if (turn.look_for_person(toFind))
            {
                cout << printOut;
            }
            else
            {
                cout << "Person not found " << endl;
            }
        }
        if(valid)
        {
            vector<Person> printOut = turn.displayList(command);
            cout << printOut;
        }
     }while(turn.getProgram());
}

bool service::validList()// depending on input from user, do something
{
    if(_command == "list")
    {
        return true; //dont change list
    }
    else if(_command == "add")
    {
        //Person person(string _name,char _gender int _birthYear, int _deathYear) todo
        return true;
    }
    else if(_command == "sorta")
    {

        return true;
    }
    else if(_command == "sortb")
    {
        return true;
    }
    else if(_command == "sortd")
    {
        return true;
    }
    else if(_command == "sortg")
    {
        return true;
    }
    else if (_command == "quit")
    {
        _program = false;
        return false;
    }
    else
    {
        return false;
    }

}
