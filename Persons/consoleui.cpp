#include "consoleui.h"

using namespace std;


const string REMOVE = "remove";
const string FIND = "find";
const string QUIZ = "quiz";
const string STATUS = "status";
const string EMPTY = "";

consoleUI::consoleUI() {_print = true;}

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
        cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;     // Command box begins.
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
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit   - This command will quit the program. "
             << right << BARRIER << endl;
        cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;      // Command box ends.
        cout << "command: ";

        getline(cin, command);          // Sets the private variable _command in the service class.
        _printOut = _turn.getList();
        if(_turn.fileFound() || QUIT == command)
        {
            printList(command);         // Checks if there is a need for a printout of the list.
        }
        else
        {
            cout << endl << "File not found! " << endl << endl;
        }

        if(_print && _turn.fileFound())
        {
            _printOut = _turn.getList();        // getList() gets the list that's supposed to be printed out.
            cout << _printOut;
        }
        else if (!specialCommand(command) && _turn.fileFound())
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

void consoleUI::printList(const string &_command)       // Print if appropriate.
{
    const string SORT = "sort";
    const string ADD = "add";
    const string LIST = "list";

    if(_command == LIST)            // Print the original list.
    {
        _print = true;
    }
    else if(_command == ADD)        // Tells the user to enter information (names, gender, birth year, death year) about the new scientist.
    {
        _print = true;
        addCommand();
    }
    else if(_command == REMOVE)     // Tells the user to enter the full name of the scientist to be removed from the list.
    {
        _print = false;
        removeCommand();
    }
    else if (_command == FIND)      // Tells the user to enter the name of the scientist to be located in the list.
    {
        _print = false;
        findCommand();
    }
    else if(_command == SORT)       // Gives you additional options to choose how you would like the list sorted
    {
        _print = true;
        sortCommand();
    }
    else if(_command == QUIZ)       // Presents the user with a quiz relating to the birth and death year of a scientist.
    {
        _print = false;
        quizCommand();
    }
    else if (_command == QUIT)      // Quits the program.
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

    while(true)
    {
        cout << "Name: ";
        getline(cin, name);
        if(name == EMPTY)
        {
            cout << "No input!" << endl;
        }
        else
        {
            break;
        }
    }
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
        birthCheck = atoi(birthYear.c_str());       // Removes alphanumeric values from the input.
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
        deathCheck = atoi(deathYear.c_str());       // Removes alphanumeric values from the input.
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
    if(toFind == "dickbutt")
    {
        cout << "                                      PrumpPrum                                         " << endl;                                                                                         cout << "                                  pPrumpPrumpPrumpP                                     " << endl << "                              rumpPrumpPrumpPrumpPrump                                  " << endl << "                      PrumpPrumpPrump           PrumpPru                                " << endl << "                   mpPrumpPrumpP                  rumpPru                               " << endl << "                 mpPrumpPrumpPru                   mpPrum                               " << endl << "                 pPrumpPrumpPrump                   Prump" << endl << "                 PrumpPrumpP rumpPr    umpPrumpPru  mpPru" << endl << "                 mpPrumpPrumpPrumpPr umpPrumpPrumpPr umpP" << endl << "                 rumpPrumpPrumpPru  mpPrumpPrumpPrumpPrum" << endl << "                pPrum  pPrumpPrump  PrumpPrumpPrumpPrumpP" << endl << "               rumpPrumpPrumpPrumpP rumpPrumpPr umpPrumpP" << endl << "              rumpPrumpPrumpPrump   PrumpPrumpPrumpPrumpP" << endl << "             rumpPrumpPrumpPrumpPrumpPrumpPrumpPr  umpPr" << endl << "            umpPr          umpPrumpPrumpPrump     PrumpP" << endl << "           rumpP                      rumpPru     mpPrum" << endl << "          pPrump                                 PrumpP" << endl << "         rumpPr                                 umpPru" << endl << "        mpPrum                                  pPrump" << endl << "        Prump                      Prum        pPrump" << endl << "        Prum                      pPrum pPr   umpPru" << endl << "        mpPr                      umpPrumpPr  umpPr                         umpPrumpP" << endl << "       rumpP                      rumpPrump  Prump                        PrumpPrumpPr" << endl << "       umpPr                     umpPrumpPr umpPr                       umpPru    mpPr" << endl << "       umpPr                     umpPrumpP  rumpP                     rumpPru    mpPru" << endl << "       mpPru                    mpPrumpPr  umpPru                   mpPrump     Prump" << endl << "       Prump                    PrumpPru   mpPrumpPrumpPrumpPru   mpPrump     Prump" << endl << "        Prum                   pPrumpPr    umpPrumpPrumpPrumpPrumpPrump      Prump" << endl << "        Prum                   pPrumpP     rumpP   rumpP   rumpPrumpP      rumpPr" << endl << "        umpP                  rumpPrum      pPr   umpPrumpPrumpPrum      pPrump" << endl << "        Prump               Prump Prump         PrumpPrumpPrumpPru     mpPrump" << endl << "         Prum             pPrum  pPrumpP         rumpPrumpPrumpPrump   PrumpPru" << endl << "         mpPru            mpPrumpPrumpPr                     umpPrump    PrumpPrum" << endl << "          pPrum            pPrumpPrumpP              rump       PrumpP  rump Prump" << endl << "          PrumpP              rump                   Prum        pPrump  PrumpPru" << endl << "           mpPrum                                pPr              umpPr    umpP" << endl << "            rumpPrum                            pPru              mpPru     mpPr" << endl << "               umpPrum                          pPru              mpPrumpPrumpPr" << endl << "     ump        PrumpPrump                       Prum           pPrumpPrumpPrum" << endl << "    pPrumpP    rumpPrumpPrumpPru                  mpP         rumpPru    m" << endl << "   pPrumpPrumpPru mpPrumpPrumpPrumpPrum           pPru    mpPrump" << endl << "    Prum pPrumpPrumpPru    mpPrumpPrumpPru mpPrumpPrumpPrumpPrum" << endl << "     pPru  mpPrumpPru         mpPrumpPrum pPrumpPrumpPrumpPru" << endl << "      mpPr   umpPru         mpPrumpPrump Prump PrumpPrumpP" << endl << "       rumpPrumpP           rumpPrumpPr  umpP" << endl << "        rumpPru              mpPrumpP   rump" << endl << "          Pru                mpPrum    pPru" << endl << "                              mpPrum  pPru" << endl << "                               mpPrumpPru" << endl << "                                 mpPrump" << endl << "                                   Pru  " << endl;
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
    const int NAMES = 0;
    const int DIED = 1;
    const int FEMALES = 2;
    const int MALES = 3;
    cout << "Total names in list       : " << _printStatus[NAMES] << endl;
    cout << "Number of deceased        : " << _printStatus[DIED] << endl;
    cout << "Total females on the list : " << _printStatus[FEMALES] << endl;
    cout << "Total Males on the list   : " << _printStatus[MALES] << endl << endl;
}
