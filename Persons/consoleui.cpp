#include "consoleui.h"

using namespace std;


consoleUI::consoleUI(){
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
        cout << "quiz  - This command lets you take a quiz about the computer scientists." << endl;
        cout << "quit  - This command will quit the program." << endl;
        cout << "**********************************************************************************" << endl;
        cout << "command: ";
        cin >> command;

        turn.setCommand(command);
        cout << endl;


        valid = validList(command);
        turn.displayList(command);
        _printOut = turn.get_list();
        if(valid)
        {
            cout << _printOut;
        }
     }while(turn.getProgram());
}

bool consoleUI::validList(string _command)// depending on input from user, do something
{
    if(_command == "list")
    {
        return true; //dont change list
    }
    else if(_command == "add")
    {

        addCommand();
        return true;
    }
    else if(_command == "sort")
    {
        sortCommand();
        return true;
    }
    else if (_command == "find")
    {
        findCommand();
        return false;
    }
    else if (_command == "quit")
    {
        return false;
    }
    else
    {
        return false;
    }

}

void consoleUI::quizCommand()
{
    //_printQuestion =
    //cout <<
    cout << "lol";
}

void consoleUI::sortCommand()
{
    cout << "a - Sort alphabetically. " << endl;
    cout << "b - Sort by year of birth. " << endl;
    cout << "d - Sort by year of death. " << endl;
    cout << "g - Sort by gender. " << endl;
    cout << "Select sorting method: ";

    string input;
    cin >> input;

    turn.setCommand(input);
}

void consoleUI::addCommand()
{
  Person input;
  cout << "Please enter the following information about the new computer scientist " << endl;
  cout << "in the following order." << endl;
  cout << "Be aware you cannot put letters that are not in the English alphabet." << endl;
  cout << "Name (Minimum two names, Maximum three)" << endl;
  cout << "Gender (male/female) in lowercase." << endl;
  cout << "Birthyear (YYYY)" << endl;
  cout << "Died (0 if still alive)" << endl;
  cin >> input;
  turn.addPerson(input);
}

void consoleUI::findCommand()
{
    string toFind;
    cout << "Name to find: ";
    cin >> toFind;
    _printOut = turn.find_person(toFind);
    if (turn.look_for_person(toFind))
    {
        cout << _printOut;
    }
    else
    {
        cout << "Person not found " << endl;
    }
}
