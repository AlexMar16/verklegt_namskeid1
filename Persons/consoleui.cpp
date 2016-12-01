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
        cout << "sort  - This command will allow you to sort the scientists." << endl;
        cout << "find  - This command allows you to find a certain person in the list." << endl;
        cout << "quiz  - This command lets you take a quiz about the computer scientists." << endl;
        cout << "add   - This command allows you to add a person to the list." << endl;
        cout << "remove- This command allows you to find a certain person in the list." << endl;
        cout << "quit  - This command will quit the program." << endl << endl;
        cout << setw(ASTERISK_WIDTH)<< setfill(ASTERISK) <<  "*" << endl;
        cout << "command: ";
        cin >> command;
        cout << endl;

        _turn.setCommand(command);//setur command i service.cpp
        validList(command);//checkar hvort input command fra user se legit og setur _valid true eda false
        _turn.sortList();
        _printOut = _turn.getList();
        if(_valid)
        {
            cout << _printOut;
        }
        else if (!_turn.specialCommand(command)) // Gera fall sem checkar a tessu
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
    else
    {
        _valid = false;
    }
}

void consoleUI::quizCommand()
{
    Person question = _turn.generateQuestion();
    //cout << "We are asking about " << question.getName() << endl;
    cout << _turn.genderCheck(question) <<" was born in " << question.getBirthYear()
         << " and " << _turn.aliveCheck(question) << endl;

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
    if(input != "a" && input != "b" && input != "d" && input != "g" && input != "l")
    {
        _valid = false;
    }

    _turn.setCommand(input);// located in service.cpp
}

void consoleUI::addCommand()
{
  string name, gender, deathYear;
  int birthYear = 0, nameCounter = 0;
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

  while(true)
  {
      cout << "Gender (male/female/other) in lowercase: ";
      cin >> gender;
      if (gender == "male" || gender == "female" || gender == "other")
      {
          break;
      }
      else
      {
          cout << "Invalid input!" << endl;
          cin.clear();
          cin.ignore();
      }
  };
  input.setGender(gender);

  while(true)
  {
      cout << "Birth year (YYYY): ";
      cin >> birthYear;
      if (birthYear > 1750 && birthYear < 2000)
      {
          break;
      }
      else
      {
          cout << "Invalid input!" << endl;
          cin.clear();
          cin.ignore();
      };
  }
  input.setBirthYear(birthYear);

  int deathCheck = 0;
  while(true)
  {
      cout << "Died (0 if still alive): ";
      cin >> deathYear;
      deathCheck = atoi(deathYear.c_str());
      //deathCheck = stoi (deathYear,&sz);

     /* if(deathYear == "0")
      {
          deathYear == "0000";
      }

      if (deathYear.length() == 4)
      {
          char str[]="1776ad";
          char inArray[] = deathYear;
      }*/
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

  _turn.addPerson(input);
}



void consoleUI::removeCommand()
{
    string fullName;
    Person input;
    int nameCounter = 0;
    cout << "Enter the full name of the scientist to remove from the database: ";
    cin.ignore();
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

    //input.setDeathYear(deathYear);

    //_turn.addPerson(input);
}

void consoleUI::findCommand()
{
    string toFind;
    cout << "Name to find: ";
    cin.ignore();
    getline(cin, toFind);
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

void consoleUI::statusCommand()//prints out number of people that fit to each category
{
    _printStatus = _turn.properties();

   cout<< "Total names in list       : "<< _printStatus[0] << endl;
   cout<< "Number of deceased        : "<< _printStatus[1] << endl;
   cout<< "Total females on the list : "<< _printStatus[2] <<endl;
   cout<< "Total Males on the list   : "<< _printStatus[3] <<endl << endl;

}

