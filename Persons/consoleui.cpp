#include "consoleui.h"

using namespace std;


consoleUI::consoleUI(){}

void consoleUI::run()
{
    const int ASTERISK_WIDTH = 80;
    const char ASTERISK = '*';
    string command;
    do
    {
        cout << setw(ASTERISK_WIDTH)<< setfill(ASTERISK) <<  "*" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ') << "| Please enter one of the following commands:"
             << right << "|" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ') <<"|" << right << "|"<< endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ')<< "| list   - This command will list every person in the system."
             << right << "|" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ')<< "| sort   - This command will allow you to sort the scientists."
             << right << "|" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ')<< "| find   - This command allows you to find a certain person in the list."
             << right << "|" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ')<< "| quiz   - This command lets you take a quiz about the computer scientists."
             << right << "|" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ')<< "| add    - This command allows you to add a person to the list."
             << right << "|" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ')<< "| remove - This command allows you to remove a certain person from the list."
             << right << "|" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ')<< "| status - This command displays info about the list "
             << right << "|" << endl;
        cout << left << setw(ASTERISK_WIDTH) << setfill(' ') << "| quit   - This command will quit the program."
             << right << "|" << endl;
        cout << setw(ASTERISK_WIDTH)<< setfill(ASTERISK) <<  "*" << endl;
        cout << "command: ";
        getline(cin, command);
        cout << endl;

        _turn.setCommand(command);//setur command i service.cpp
        validList(command);//checkar hvort input command fra user se legit og setur _valid true eda false

        _printOut = _turn.getList();
        if(_valid)
        {
            cout << _printOut;
        }
        else if (!_turn.specialCommand(command))
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
    else if(_command == "remove")
    {
        removeCommand();
        _valid = false;
    }
    else if (_command == "find")
    {
        findCommand();
        _valid = false;
    }
    else if(_command == "sort")// gives you additional options to choose how you would like the list sorted
    {
        _valid = true;
        sortCommand();
    }
    else if(_command == "quiz")
    {
        quizCommand();
        _valid = false;
    }
    else if (_command == "quit")
    {
        _valid = false;
    }
    else if(_command =="status")
    {
        _valid= false;
        statusCommand();

    }
    else
    {
        _valid = false;
    }
}

void consoleUI::quizCommand()
{
    Person question = _turn.generateQuestion();
    cout << _turn.genderCheck(question) <<" was born in " << question.getBirthYear()
         << " and " << _turn.aliveCheck(question) << ", enter (a/b/c/d)" << endl;

    string a, b, c, d;
    _turn.generateOptions(question, a, b, c, d);

    cout << "a)\t" << a << endl;
    cout << "b)\t" << b << endl;
    cout << "c)\t" << c << endl;
    cout << "d)\t" << d << endl;

    string answerString;
    cout << "My answer: ";
    cin >> answerString;

    _turn.assignSelection(answerString, a, b, c, d);

    if (answerString == question.getName())
        cout << endl << "Correct!!!" << endl << endl;
    else
        cout << endl << "Wrong!" << endl << endl;
    cin.ignore();
}

void consoleUI::sortCommand()
{
    cout << "a - Sort alphabetically. " << endl;
    cout << "b - Sort by year of birth. " << endl;
    cout << "d - Sort by year of death. " << endl;
    cout << "g - Sort by gender. " << endl;
    cout << "l - Sort by last name" << endl;

    string input;
    bool forward = false;

    while(forward == false)
    {
        cout << "Select sorting method: ";
        getline(cin, input);

        if(input =="a" || input=="b" || input=="d" || input=="g" || input=="l")
        {
            _turn.setCommand(input);// located in service.cpp
            _turn.sortList();
            forward=true;
        }
        else
        {
            forward=false;
            cout<<"Invalid input!"<<endl;
        }
    }
    getline(cin, input);

    _turn.setCommand(input);// located in service.cpp
}

void consoleUI::addCommand()
{
  string name, gender, deathYear, birthYear;
  Person input;

  cout << "Please enter the following information about the new computer scientist " << endl;
  cout << "in the following order." << endl;
  cout << "Be aware you cannot put letters that are not in the English alphabet." << endl;

  cout << "Name: ";
  getline(cin, name);
  input.setName(name);

  while(true)
  {
      cout << "Gender (male/female) in lowercase: ";
      cin >> gender;
      if (gender == "male" || gender == "female")
      {
          break;
      }
      else
      {
          cout << "Invalid input!" << endl;
      }
  };
  input.setGender(gender);

  int birthCheck = 0;
  while(true)
  {
      cout << "Birth year (YYYY): ";
      cin >> birthYear;
      birthCheck = atoi(birthYear.c_str());
      if (birthCheck > 1750 && birthCheck < 2000)
      {
          break;
      }
      else
      {
          cout << "Invalid input!" << endl;
          cin.clear();
      };
  }
  input.setBirthYear(birthCheck);

  int deathCheck = 0;
  while(true)
  {
      cout << "Died (input any other character if still alive): ";
      cin >> deathYear;
      deathCheck = atoi(deathYear.c_str());
      if ((deathCheck > 1800 && deathCheck < 2100) || deathCheck == 0)
      {
          break;
      }
      else
      {
          cout << "Invalid input!" << endl;
          cin.clear();
      };
  }
  input.setDeathYear(deathCheck);

  cout << endl;

  _turn.addPerson(input);
  cin.ignore();
}

void consoleUI::removeCommand()
{
    string fullName;
    Person input;
    cout << "Enter the full name of the scientist to remove from the database: ";
    getline(cin, fullName);
    input = _turn.findPersonExactly(fullName);
    if (input.getName() == "")
    {
        cout << endl << "Person not found!" << endl;
    }
    else
    {
        cout << endl << fullName << " removed" << endl;
    }
    input = _turn.findPersonExactly(fullName);

    _turn.removePerson(input);
}

void consoleUI::findCommand()
{
    string toFind;
    cout << "Name to find: ";

    getline(cin, toFind);
    cout << endl;
    _printOut = _turn.findPerson(toFind);
    if (_turn.lookForPerson(toFind))
    {
        cout << _printOut;
    }
    else
    {
        cout << "Person not found " << endl << endl;
    }
}

void consoleUI::statusCommand()//prints out number of people that fit to each category
{
    _printStatus = _turn.properties();

   cout<< "Total names in list       : "<< _printStatus[0] << endl;
   cout<< "Number of deceased        : "<< _printStatus[1] << endl;
   cout<< "Total females on the list : "<< _printStatus[2] << endl;
   cout<< "Total Males on the list   : "<< _printStatus[3] << endl << endl;
}

