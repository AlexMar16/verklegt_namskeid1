#include "consoleui.h"


using namespace std;


const string REMOVE = "remove";
const string FIND = "find";
const string QUIZ = "quiz";
const string STATUS = "status";
const string EMPTY = "";
const string BACK = "back";
const int ASTERISK_WIDTH = 80;
const char ASTERISK = '*';
const char BARRIER = '|';

consoleUI::consoleUI() {_print = true;}

void consoleUI::commandBox(const string& theRightOne)
{
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;     // Command box begins.
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter one of the following commands:"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << BARRIER << right << BARRIER<< endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| list   - This command will list every "+theRightOne+" in the system."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| sort   - This command will allow you to sort the"+ theRightOne+ "s."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| find   - This command allows you to find a certain"+theRightOne+" in the list."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quiz   - This command lets you take a quiz about the computer scientists."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| add    - This command allows you to add a "+theRightOne+" to the list."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| remove - This command allows you to remove a certain "+theRightOne+" from the list."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| status - This command displays info about the list "
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| addcomp- This command adds an computer to the database(testing atm)"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| removec- This command adds an computer to the database(testing atm)"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit   - This command will quit the program. "
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;      // Command box ends.
    cout << "command: ";

}

void consoleUI::run()
{
    string command, database, initial = "| This is a database for famous computer scientists and historical computers! |";
    do
    {
        cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;
        cout << initial << endl << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter the following commands to examine this database!"
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| person   - This command will gain you access to the person table."
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| computer   - This command will gain you access to the computer table"
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| connect   - This command will gain you access to connections of both."
             << right << BARRIER << endl;
        cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Pick a database: "
             << right << BARRIER << endl;
        getline(cin, database);
        beginningCommand(database);
        string theRightOne;
        if(database== "person")
        {
            theRightOne= "person";
        }
        else if(database=="computer")
        {
            theRightOne="computer";
        }

        cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;
        if(beginningCommand(database))
        {
        do
        {
            commandBox(theRightOne);
            getline(cin, command);          // Sets the private variable _command in the service class.
            if(database == "person")
            _printOutPerson = _turnP.getPersonList();
            _printOutComputer = _turnC.getComputerList();
            if((_turnP.dataFound() || QUIT == command)&& theRightOne=="person")
            {
                printListPerson(command);         // Checks if there is a need for a printout of the list.
            }
            else if((_turnP.dataFound() || QUIT == command)&& theRightOne=="computer")
            {
                printListComputer(command);
            }
            else
            {
                cout << endl << "File not found! " << endl << endl;
            }


            if(_print && _turnP.dataFound()&& database=="person")
            {
                _printOutPerson = _turnP.getPersonList();// getList() gets the list that's supposed to be printed out.
                cout << _printOutPerson;
            }
           // todo ! else if()thegar vector er kominn, gera ad printcomputer vector
            else if (!specialCommandPerson(command) && _turnP.dataFound())
            {
                cout << "Invalid command!" << endl << endl;
            }

        } while(_turnP.getProgram());
        }
    } while(command == BACK || !(beginningCommand(database)));
}
bool consoleUI::beginningCommand(const string& input)
{
    if(input == "person")
    {
        return true;
    }
    else if(input =="computer")
    {
        return true;
    }
    else if(input =="connect")
    {
        return true;
    }
    else
    {
        return false;
    }
}





void consoleUI::quizCommand()
{
    Person question = _turnP.generateQuestion();
    cout << _turnP.genderCheck(question) << " was born in " << question.getBirthYear()
         << " and " << _turnP.aliveCheck(question) << ", enter (a/b/c/d)" << endl;

    string a, b, c, d;
    _turnP.generateOptions(question, a, b, c, d);

    cout << "a)\t" << a << endl;
    cout << "b)\t" << b << endl;
    cout << "c)\t" << c << endl;
    cout << "d)\t" << d << endl;

    string answerString;
    cout << "My answer: ";
    cin >> answerString;

    _turnP.assignSelection(answerString, a, b, c, d);

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

    _turnP.addPerson(input);
    cin.ignore();
}

void consoleUI::addCompCommand()
{
    string name, type, yearBuilt, wasitbuilt, built;
    Computer input;
    int birthCheck = 0, deathCheck = 0;
    const int MINIMUM_Built_YEAR = 1500, MAXIMUM_Built_YEAR = 2030;

    cout << "Please enter the following information about the new Computer " << endl;
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
        cout << "Type of computer: ";
        getline(cin, type);
        if(type == EMPTY)
        {
            cout << "No input!" << endl;
        }
        else
        {
            break;
        }
    }
    input.setType(type);


    while(true)
    {
        cout << "Was the computer ever built? (y/n)" << endl;
        cin >> wasitbuilt;
        if(wasitbuilt == "Y" || wasitbuilt == "y" || wasitbuilt == "yes")
        {
            built = "yes";
            break;
        }
        else if (wasitbuilt == "n" || wasitbuilt == "N" || wasitbuilt == "no")
        {
            built = "no";
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
    input.setBuilt(built);
    if(built == "yes")
    {
        while(true)
        {
            cout << "Build year (YYYY): ";
            cin >> yearBuilt;
            birthCheck = atoi(yearBuilt.c_str());       // Removes alphanumeric values from the input.
            if (birthCheck > MINIMUM_Built_YEAR && birthCheck < MAXIMUM_Built_YEAR)
            {
                break;
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
        }
        input.setYearbuild(birthCheck);
    }


    cout << endl;

    _turnP.addComputer(input);
    cin.ignore();
}
void consoleUI::removeCommand()
{
    string fullName;
    Person input;
    cout << "Enter the full name of the scientist to remove from the database: ";
    getline(cin, fullName);
    input = _turnP.findPersonExactly(fullName);

    if (input.getName() == EMPTY)
    {
        cout << endl << "Person not found!" << endl;
    }
    else
    {
        cout << endl << fullName << " removed" << endl;
    }

    input = _turnP.findPersonExactly(fullName);
    //_turnP.removePerson(input);
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
        _printOutPerson = _turnP.findPerson(toFind);
        if (_turnP.lookForPerson(toFind))
        {
            cout << "Person found! " << endl;
            cout << _printOutPerson;
        }
        else
        {
            cout << "Person not found " << endl << endl;
        }
    }
}

void consoleUI::statusCommand()
{
    _printStatus = _turnP.properties();
    const int NAMES = 0;
    const int DIED = 1;
    const int FEMALES = 2;
    const int MALES = 3;
    cout << "Total names in list       : " << _printStatus[NAMES] << endl;
    cout << "Number of deceased        : " << _printStatus[DIED] << endl;
    cout << "Total females on the list : " << _printStatus[FEMALES] << endl;
    cout << "Total Males on the list   : " << _printStatus[MALES] << endl << endl;
}

//person

bool consoleUI::specialCommandPerson(const string& command)
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
    else if(command == BACK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool consoleUI::sortSpecialCommandPerson(const string& choice)
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

void consoleUI::sortCommandPerson()
{
    const string ASC = "asc";
    const string DESC = "desc";

    cout << "a - Sort alphabetically. "   << endl;
    cout << "b - Sort by year of birth. " << endl;
    cout << "d - Sort by year of death. " << endl;
    cout << "g - Sort by gender. "        << endl;
    cout << "l - Sort by last name."       << endl;

    string choice;
    string upOrDown;

    while(true)
    {
        cout << "Select sorting method: ";
        getline(cin, choice);

        if(sortSpecialCommandPerson(choice))
        {
            _turnP.sortList(choice);
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }

    cout << endl;
    cout << "asc - Show list in ascending order." << endl;
    cout << "desc - Show list in descending order." << endl << endl;

    while(true)
    {
        cout << "Select list representation: ";
        getline(cin, upOrDown);

        if(upOrDown == DESC)
        {
            _turnP.reverseVector();
            break;
        }
        else if(upOrDown != ASC)
        {
            cout << "Invalid input!" << endl;
        }
        else
        {
            break;
        }
    }
}


void consoleUI::printListPerson(const string &_command)       // Print if appropriate.
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
        sortCommandPerson();
    }
    else if(_command == QUIZ)       // Presents the user with a quiz relating to the birth and death year of a scientist.
    {
        _print = false;
        quizCommand();
    }
    else if (_command == QUIT)      // Quits the program.
    {
        _print = false;
        _turnP.setProgram(_print);
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

//computer




void consoleUI::sortCommandComputer()
{
    const string ASC = "asc";
    const string DESC = "desc";

    cout << "a - Sort alphabetically. "   << endl;
    cout << "y - Sort by year built. " << endl;
    cout << "t - Sort by type. " << endl;
    cout << "b - To see if the computer was built. "        << endl;

    string choice;
    string upOrDown;

    while(true)
    {
        cout << "Select sorting method: ";
        getline(cin, choice);

        if(sortSpecialCommandPerson(choice))
        {
            //_turnP2.sortList(choice);
            // þegar computerservice er up and running fara sort föllin þar inn og kallað í þau hér !
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }

    cout << endl;
    cout << "asc - Show list in ascending order." << endl;
    cout << "desc - Show list in descending order." << endl << endl;

    while(true)
    {
        cout << "Select list representation: ";
        getline(cin, upOrDown);

        if(upOrDown == DESC)
        {
           // _turnP2.reverseVector(); uncommenta thegar vector er kominn
            break;
        }
        else if(upOrDown != ASC)
        {
            cout << "Invalid input!" << endl;
        }
        else
        {
            break;
        }
    }

    //todo láta ganga upp
}


void consoleUI::specialCommandComputer(const string &_command)
{
    if(_command == "a")
    {
       //alphabet sort fall fyrir computer
    }
    if(_command=="y")
    {
        //yearbuilt sort fall fyrir computer
    }
    if(_command=="t")
    {
        //type sort fall fyrir computer
    }
    else if(_command =="b")
    {
        //var tolvan byggd ?
    }
    else
    {
        //printvectorFyrirCompuer= false
    }
}

void consoleUI::printListComputer(const string &_command)
{
    const string SORT = "sort";
    const string ADD = "addcomp";
    const string LIST = "list";

    if(_command == LIST)            // Print the original list.
    {
        _print = true;
    }

    else if(_command == ADD)
    {
        _print = true;
        addCompCommand();
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
    else if(_command == SORT)
    {
        _print = true;
        sortCommandComputer();
    }
    else if(_command == QUIZ)
    {
        _print = false;
        quizCommand();
    }
    else if (_command == QUIT)
    {
        _print = false;
        //_turnP.setProgram(_print);
    }
    else if(_command == STATUS)
    {
        _print = false;
        //setja videigandi
    }
    else
    {
        _print = false;
    }

}

