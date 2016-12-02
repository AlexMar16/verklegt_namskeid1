#include "consoleui.h"

using namespace std;


const string REMOVE = "remove";
const string FIND = "find";
const string QUIZ = "quiz";
const string STATUS = "status";

consoleUI::consoleUI(){}

void consoleUI::run()
{
    const int ASTERISK_WIDTH = 80;
    const char ASTERISK = '*';
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

        getline(cin, command);                                      // Sets the private variable _command in the service class.
        printList(command);                                         // Checks if there is a need for a printout of the list.
        _printOut = _turn.getList();

        if(_print)
        {

            if(!_turn.filefound())
            {
                cout << endl << "File not found! " << endl << endl;
            }

            _printOut = _turn.getList();                            // getList() gets the list that's supposed to be printed out.
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
    if (command == FIND)
    {
        return true;
    }
    else if(command == QUIT)
    {
        return true;
    }
    else if(command == QUIZ)
    {
        return true;
    }
    else if(command == REMOVE)
    {
        return true;
    }
    else if(command == STATUS)
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
    if(choice == A)
    {
        return true;
    }
    else if(choice == B)
    {
        return true;
    }
    else if(choice == D)
    {
        return true;
    }
    else if(choice == G)
    {
        return true;
    }
    else if(choice == L)
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
    const string SORT = "sort";
    const string ADD = "add";
    const string LIST = "list";

    if(_command == LIST)
    {
        _print = true;                                              // Print the original list.
    }
    else if(_command == ADD)
    {
        _print = true;
        addCommand();
    }
    else if(_command == REMOVE)
    {
        _print = false;
        removeCommand();
    }
    else if (_command == FIND)
    {
        _print = false;
        findCommand();
    }
    else if(_command == SORT)                                     // Gives you additional options to choose how you would like the list sorted
    {
        _print = true;
        sortCommand();
    }
    else if(_command == QUIZ)
    {
        _print = false;
        quizCommand();
    }
    else if (_command == QUIT)
    {
        _print = false;
        _turn.setProgram(_print);
    }
    else if(_command == STATUS)
    {
        _print = false;
        statusCommand();
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
    cout << "l - Sort by last name."       << endl;

    string choice;

    while(true)
    {
        cout << "Select sorting method: ";
        getline(cin, choice);

        if(sortSpecialCommand(choice))
        {
            _turn.sortList(choice);
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}

void consoleUI::addCommand()
{
    string name, gender, deathYear, birthYear;
    Person input;
    int birthCheck = 0, deathCheck = 0;
    const int MINIMUM_BIRTH_YEAR = 1750, MAXIMUM_BIRTH_YEAR = 2000;
    const int MINIMUM_DEATH_YEAR = 1800, MAXIMUM_DEATH_YEAR = 2017;

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
        if (gender == MALE || gender == FEMALE)
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
        if (birthCheck > MINIMUM_BIRTH_YEAR && birthCheck < MAXIMUM_BIRTH_YEAR)
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
        if ((deathCheck > MINIMUM_DEATH_YEAR && deathCheck < MAXIMUM_DEATH_YEAR) || deathCheck == 0)
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
    const string EMPTY = "";
    cout << "Enter the full name of the scientist to remove from the database: ";
    getline(cin, fullName);
    input = _turn.findPersonExactly(fullName);

    if (input.getName() == EMPTY)
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
    if(toFind=="dickbutt")
    {
        cout << "                                      PrumpPrum                                         " <<endl;cout << "                                  pPrumpPrumpPrumpP                                     " <<endl;cout << "                              rumpPrumpPrumpPrumpPrump                                  " <<endl;cout << "                      PrumpPrumpPrump           PrumpPru                                " <<endl;cout << "                   mpPrumpPrumpP                  rumpPru                               " <<endl;cout << "                 mpPrumpPrumpPru                   mpPrum                               " <<endl;cout << "                 pPrumpPrumpPrump                   Prump" << endl;cout << "                 PrumpPrumpP rumpPr    umpPrumpPru  mpPru" << endl;cout << "                 mpPrumpPrumpPrumpPr umpPrumpPrumpPr umpP" << endl;cout << "                 rumpPrumpPrumpPru  mpPrumpPrumpPrumpPrum" << endl;cout << "                pPrum  pPrumpPrump  PrumpPrumpPrumpPrumpP" << endl;cout << "               rumpPrumpPrumpPrumpP rumpPrumpPr umpPrumpP" << endl;cout << "              rumpPrumpPrumpPrump   PrumpPrumpPrumpPrumpP" << endl;cout << "             rumpPrumpPrumpPrumpPrumpPrumpPrumpPr  umpPr" << endl;cout << "            umpPr          umpPrumpPrumpPrump     PrumpP" << endl;cout << "           rumpP                      rumpPru     mpPrum" << endl;cout << "          pPrump                                 PrumpP" << endl;cout << "         rumpPr                                 umpPru" << endl;cout << "        mpPrum                                  pPrump" << endl;cout << "        Prump                      Prum        pPrump" << endl;cout << "        Prum                      pPrum pPr   umpPru" << endl;cout << "        mpPr                      umpPrumpPr  umpPr                         umpPrumpP" << endl;cout << "       rumpP                      rumpPrump  Prump                        PrumpPrumpPr" << endl;cout << "       umpPr                     umpPrumpPr umpPr                       umpPru    mpPr" << endl;cout << "       umpPr                     umpPrumpP  rumpP                     rumpPru    mpPru" << endl;cout << "       mpPru                    mpPrumpPr  umpPru                   mpPrump     Prump" << endl;cout << "       Prump                    PrumpPru   mpPrumpPrumpPrumpPru   mpPrump     Prump" << endl;cout << "        Prum                   pPrumpPr    umpPrumpPrumpPrumpPrumpPrump      Prump" << endl;cout << "        Prum                   pPrumpP     rumpP   rumpP   rumpPrumpP      rumpPr" << endl;cout << "        umpP                  rumpPrum      pPr   umpPrumpPrumpPrum      pPrump" << endl;cout << "        Prump               Prump Prump         PrumpPrumpPrumpPru     mpPrump" << endl;cout << "         Prum             pPrum  pPrumpP         rumpPrumpPrumpPrump   PrumpPru" << endl;cout << "         mpPru            mpPrumpPrumpPr                     umpPrump    PrumpPrum" << endl;cout << "          pPrum            pPrumpPrumpP              rump       PrumpP  rump Prump" << endl;cout << "          PrumpP              rump                   Prum        pPrump  PrumpPru" << endl;cout << "           mpPrum                                pPr              umpPr    umpP" << endl;cout << "            rumpPrum                            pPru              mpPru     mpPr" << endl;cout << "               umpPrum                          pPru              mpPrumpPrumpPr" << endl;cout << "     ump        PrumpPrump                       Prum           pPrumpPrumpPrum" << endl;cout << "    pPrumpP    rumpPrumpPrumpPru                  mpP         rumpPru    m" << endl;cout << "   pPrumpPrumpPru mpPrumpPrumpPrumpPrum           pPru    mpPrump" << endl;cout << "    Prum pPrumpPrumpPru    mpPrumpPrumpPru mpPrumpPrumpPrumpPrum" << endl;cout << "     pPru  mpPrumpPru         mpPrumpPrum pPrumpPrumpPrumpPru" << endl;cout << "      mpPr   umpPru         mpPrumpPrump Prump PrumpPrumpP" << endl;cout << "       rumpPrumpP           rumpPrumpPr  umpP" << endl;cout << "        rumpPru              mpPrumpP   rump" << endl;cout << "          Pru                mpPrum    pPru" << endl;cout << "                              mpPrum  pPru" << endl;cout << "                               mpPrumpPru" << endl;cout << "                                 mpPrump" << endl;cout << "                                   Pru  " << endl;
    }
    else
    {
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
}

void consoleUI::statusCommand()
{
    _printStatus = _turn.properties();

    cout << "Total names in list       : " << _printStatus[0] << endl;
    cout << "Number of deceased        : " << _printStatus[1] << endl;
    cout << "Total females on the list : " << _printStatus[2] << endl;
    cout << "Total Males on the list   : " << _printStatus[3] << endl << endl;
}

