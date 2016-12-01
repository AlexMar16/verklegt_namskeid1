#include "consoleui.h"

using namespace std;


consoleUI::consoleUI(){}

void consoleUI::run()
{
    const int ASTERISK_WIDTH = 80;
    const char ASTERISK = '*';
    const char SPACE = ' ';
    const char BARRIER = '|';
    string command, initial = "| This is a database for famous computer scientists! |";
    cout << setw(initial.size()) << setfill(ASTERISK) << ASTERISK << endl;
    cout << initial << endl;
    do
    {
        cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter one of the following commands:"
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << BARRIER << right << BARRIER<< endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| list   - This command will list every person in the system."
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| sort   - This command will allow you to sort the scientists."
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| find   - This command allows you to find a certain person in the list."
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quiz   - This command lets you take a quiz about the computer scientists."
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| add    - This command allows you to add a person to the list."
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| remove - This command allows you to remove a certain person from the list."
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| status - This command displays info about the list "
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit   - This command will quit the program."
             << right << BARRIER << endl;
        cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;
        cout << "command: ";

        getline(cin, command);                                 //sets the private variable _command in the service class.

        _turn.setCommand(command);//setur command i service.cpp
        printList(command);//checkar hvort input command fra user se legit og setur _valid true eda false
        _printOut = _turn.getList();
        if(_print)

        cout << endl;

        printList(command);                                         // Checks if there is a need for a printout of the list.
        if(_print)
        {
            _printOut = _turn.getList();                            //getList() gets the list that's supposed to be printed out.
            cout << _printOut;
        }
        else if (!specialCommand(command))
        {
            cout << "Invalid command!" << endl << endl;
        }
    } while(_turn.getProgram());
}

bool consoleUI::specialCommand(const string& command)
{
    if (command == "find")
    {
        return true;
    }
    else if(command == "quit")
    {
        return true;
    }
    else if(command == "quiz")
    {
        return true;
    }
    else if(command == "remove")
    {
        return true;
    }
    else if(command == "status")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool consoleUI::sortSpecialCommand(const string& choice)
{
    if(choice == "a")
    {
        return true;
    }
    else if(choice == "b")
    {
        return true;
    }
    else if(choice == "d")
    {
        return true;
    }
    else if(choice == "g")
    {
        return true;
    }
    else if(choice == "l")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void consoleUI::printList(const string &_command)                   // Print if appropriate.
{
    if(_command == "list")
    {
        _print = true;                                              // Print the original list.
    }
    else if(_command == "add")
    {
        addCommand();
        _print = true;
    }
    else if(_command == "remove")
    {
        removeCommand();
        _print = false;
    }
    else if (_command == "find")
    {
        findCommand();
        _print = false;
    }
    else if(_command == "sort")                                     // gives you additional options to choose how you would like the list sorted
    {
        sortCommand();
        _print = true;
    }
    else if(_command == "quiz")
    {
        quizCommand();
        _print = false;
    }
    else if (_command == "quit")
    {
        _turn.setProgram(_print);
        _print = false;
    }
    else if(_command =="status")
    {
        statusCommand();
        _print = false;
    }
    else
    {
        _print = false;
    }
}

void consoleUI::quizCommand()
{
    Person question = _turn.generateQuestion();
    cout << _turn.genderCheck(question) << " was born in " << question.getBirthYear()
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
    {
        cout << endl << "Correct!!!" << endl << endl;
    }
    else
    {
        cout << endl << "Wrong!" << endl << endl;
    }
    cin.ignore();
}

void consoleUI::sortCommand()
{
    cout << "a - Sort alphabetically. "   << endl;
    cout << "b - Sort by year of birth. " << endl;
    cout << "d - Sort by year of death. " << endl;
    cout << "g - Sort by gender. "        << endl;
    cout << "l - Sort by last name"       << endl;

    string choice;
    bool forward = false;

    while(forward == false)
    {
        cout << "Select sorting method: ";
        getline(cin, choice);

        if(sortSpecialCommand(choice))
        {
            cout << "RUNNNING IF STATEMENT" << endl;
            _turn.setCommand(choice);
            _turn.sortList();
            forward = true;
        }
        else
        {
            forward = false;
            cout << "Invalid input!" << endl;
        }
    }
}

void consoleUI::addCommand()
{
    string name, gender, deathYear, birthYear;
    Person input;
    int birthCheck = 0, deathCheck = 0;

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
        };
    }
    input.setBirthYear(birthCheck);

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
    cout << "Search name: ";

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

void consoleUI::statusCommand()
{
    _printStatus = _turn.properties();

    cout << "Total names in list       : " << _printStatus[0] << endl;
    cout << "Number of deceased        : " << _printStatus[1] << endl;
    cout << "Total females on the list : " << _printStatus[2] << endl;
    cout << "Total Males on the list   : " << _printStatus[3] << endl << endl;
}

