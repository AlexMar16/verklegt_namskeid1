#include "consoleui.h"

using namespace std;


consoleUI::consoleUI(){}

void consoleUI::run()
{
    const int ASTERISK_WIDTH = 75;
    const char ASTERISK = '*';
    string command;
    do
    {
        cout << setw(ASTERISK_WIDTH)<< setfill(ASTERISK) <<  "*" << endl << endl;
        cout << "Please enter one of the following commands:" << endl << endl;
        cout << "list  - This command will list every person in the system." << endl;
        cout << "add   - This command allows you to add a person to the list." << endl;
        cout << "find  - This command allows you to find a certain person in the list." << endl;
        cout << "sort  - This command will allow you to sort the scientists." << endl;
        cout << "quiz  - This command lets you take a quiz about the computer scientists." << endl;
        cout << "quit  - This command will quit the program." << endl << endl;
        cout << setw(ASTERISK_WIDTH)<< setfill(ASTERISK) <<  "*" << endl;
        cout << "command: ";
        cin >> command;
        cout << endl;

        _turn.setCommand(command);
        validList(command);
        _turn.displayList();
        _printOut = _turn.getList();
        if(_valid)
        {
            cout << _printOut;
        }
        else if (command != "find" && command != "quit")
        {
            cout << "Invalid command!" << endl << endl;
        }
     }while(_turn.getProgram());
}

void consoleUI::validList(string _command)// depending on input from user, do something
{
    if(_command == "list")
    {
        _valid = true; //dont change list
    }
    else if(_command == "add")
    {

        addCommand();
        _valid = true;
    }
    else if(_command == "sort")// gives you additional options to choose how you would like the list sorted
    {
        sortCommand();
        _valid = true;
    }
    else if (_command == "find")
    {
        findCommand();
        _valid = false;
    }
    else if(_command == "quiz")
    {
        cout << "pre quiz command";
        quizCommand();
        cout << "post quiz command";
        _valid = true;
    }
    else if (_command == "quit")
    {
        _valid = false;
    }
    else
    {
        _valid = false;
    }

}

void consoleUI::quizCommand()
{
    _printQuestion = _turn.getListQuestions();
    cout << "pre print Q";
    cout << _printQuestion[0];
    cout << "post print Q";
}

void consoleUI::sortCommand()
{
    cout << "a - Sort alphabetically. " << endl;
    cout << "b - Sort by year of birth. " << endl;
    cout << "d - Sort by year of death. " << endl;
    cout << "g - Sort by gender. " << endl;
    cout << "l - Sort by last name" << endl;
    cout << "Select sorting method: ";

    string input;
    cin >> input;

    _turn.setCommand(input);// located in service.cpp
}

void consoleUI::addCommand()
{
  string name, gender;
  int birthYear = 0, deathYear = 0, nameCounter = 0;
  Person input;

  cout << "Please enter the following information about the new computer scientist " << endl;
  cout << "in the following order." << endl;
  cout << "Be aware you cannot put letters that are not in the English alphabet." << endl;

  cout << "Name (Minimum two names, Maximum three): ";
  while(nameCounter != 3) //Bæta við virkni, geta haft 2 nöfn.
  {
    cin >> name;
    input.setName(name);
    nameCounter++;
  }

  cout << "Gender (male/female) in lowercase: ";
  cin >> gender;
  input.setGender(gender);

  cout << "Birth year (YYYY): ";
  cin >> birthYear;
  input.setBirthYear(birthYear);

  cout << "Died (0 if still alive): ";
  cin >> deathYear;
  input.setDeathYear(deathYear);

  _turn.addPerson(input);
}

void consoleUI::findCommand()
{
    string toFind;
    cout << "Name to find: ";
    cin >> toFind;
    _printOut = _turn.findPerson(toFind);
    if (_turn.lookForPerson(toFind))
    {
        cout << _printOut;
    }
    else
    {
        cout << "Person not found " << endl;
    }
}
