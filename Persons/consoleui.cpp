#include "consoleui.h"
#include <cctype>



using namespace std;

const string MODIFY = "modify";
const string REMOVE = "remove";
const string FIND = "find";
const string QUIZ = "quiz";
const string STATUS = "status";
const string EMPTY = "";
const string ALL = "all";
const string ADD = "add";
const string BACK = "back";
const int ASTERISK_WIDTH = 80;
const char ASTERISK = '*';
const char BARRIER = '|';

consoleUI::consoleUI() {_print = true;}

void consoleUI::run()
{
    do
    {
        firstCommandBox();
        if(beginningCommand())
        {
            do
            {
                if(_database == "person" || _database == "computer")
                {
                commandBox();
                printList();
                print();
                }
                else
                {
                commandBoxConnect();
                 //setja foll
                }
            }while(_command != BACK && _command != QUIT);
            _turnG.setProgram(_command);
        }
    }while(_turnG.getProgram());
}

void consoleUI::firstCommandBox()
{
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| This is a database for famous computer scientists and historical computers!"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter the following commands to examine this database!"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << BARRIER << right << BARRIER<< endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| person    - This command will gain you access to the person table."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| computer  - This command will gain you access to the computer table"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| connect   - This command will gain you access to connections of both."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit      - This command will quit the program. "
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;
    cout << "Pick a database: ";
    getline(cin, _database);
    beginningCommand();
    _turnG.setProgram(_database);
    if(_database == "person")
    {
        _theRightOne = "person";
    }
    else if(_database == "computer")
    {
        _theRightOne = "computer";
    }
}

void consoleUI::commandBox()
{
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;     // Command box begins.
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter one of the following commands:"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << BARRIER << right << BARRIER<< endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| list   - This command will list every "+_theRightOne+" in the system."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| sort   - This command will allow you to sort the "+ _theRightOne+ "s."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| find   - This command allows you to find a certain "+_theRightOne+" in the list."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quiz   - This command lets you take a quiz about the computer scientists."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| add    - This command allows you to add a "+_theRightOne+" to the list."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| remove - This command allows you to remove a certain "+_theRightOne+" from the list."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| status - This command displays info about the list "
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| back   - This command will allow you to choose another database. "
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit   - This command will quit the program. "
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;      // Command box ends.
    cout << "command: ";
    getline(cin, _command);          // Sets the private variable _command in the service class.
}

void consoleUI::commandBoxConnect()
{
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;     // Command box begins.
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter one of the following commands:"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << BARRIER << right << BARRIER<< endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| all   - This command will print all connections"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| add        - This command allows you to add a connection"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| remove     - This command allows you to add a connection"
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;      // Command box ends.
    cout << "command: ";
    getline(cin, _command);
}

bool consoleUI::specialCommandConnect()
{
   if(_command == ALL)
   {
       return true;
   }
   else if(_command == ADD)
   {
       return true;
   }
   else if(_command == REMOVE)
   {
       return true;
   }
   else
   {
       return false;
   }
}

bool consoleUI::beginningCommand()
{
    if(_database == "person")
    {
        return true;
    }
    else if(_database == "computer")
    {
        return true;
    }
    else if(_database == "connect")
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
    string a, b, c, d, answerName;
    if (_database == "person")
    {
        Person questionP = _turnP.generateAnswer();
        cout << _turnP.genderCheck(questionP) << " was born in " << questionP.getBirthYear()
             << " and " << _turnP.aliveCheck(questionP) << ", enter (a/b/c/d)" << endl;
        _turnP.generateOptions(questionP, a, b, c, d);
        answerName = questionP.getName();
    }
    else
    {
        Computer questionC = _turnC.generateAnswer();
        cout << "This " << _turnC.typeCheck(questionC) << " computer was " << _turnC.builtCheck(questionC)
             << ", enter (a/b/c/d)" << endl;
        _turnC.generateOptions(questionC, a, b, c, d);
        answerName = questionC.getName();
    }
    cout << "a)\t" << a << endl;
    cout << "b)\t" << b << endl;
    cout << "c)\t" << c << endl;
    cout << "d)\t" << d << endl;

    string userAnswer;
    cout << "My answer: ";
    cin >> userAnswer;

    _turnP.assignSelection(userAnswer, a, b, c, d);

    if (userAnswer == answerName)
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
        cout << "Gender (male/female): ";
        cin >> gender;
        if (_turnG.toLower(gender) == "male")
        {
            gender = MALE;
            break;
        }
        else if (_turnG.toLower(gender) == "female")
        {
            gender = FEMALE;
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
        if ((deathYear >= birthYear && deathCheck > MINIMUM_DEATH_YEAR && deathCheck < MAXIMUM_DEATH_YEAR) || deathCheck == 0 )
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

    _turnG.addPerson(input);
    _turnP.addPerson(input);
    cin.ignore();
}

void consoleUI::addCompCommand()
{
    string name, type, yearBuilt, wasitbuilt, built;
    Computer input;
    int birthCheck = 0;
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
        else if (_turnG.toLower(type) == "mechanical")
        {
            type = MECHANICAL;
            break;
        }
        else if (_turnG.toLower(type) == "electronic")
        {
            type = ELECTRONIC;
            break;
        }
        else if (_turnG.toLower(type) == "electro-mechanical")
        {
            type = ELECTROMECHANICAL;
            break;
        }
        else if (_turnG.toLower(type) == "transistor")
        {
            type = TRANSISTOR;
            break;
        }
        else if (_turnG.toLower(type) == "transistor/microchip")
        {
            type = TRANSISTORMICROCHIP;
            break;
        }
        else if (_turnG.toLower(type) == "supercomputer")
        {
            type = SUPERCOMPUTER;
            break;
        }
        else if (_turnG.toLower(type) == "quantum computer")
        {
            type = QUANTUMCOMPUTER;
            break;
        }
        else
        {
            cout << "Invalid type!" << endl;
        }
    }
    input.setType(type);

    //if(built == "yes" || built == "no")
    //{
        while(true)
        {
            cout << "Year (YYYY): ";
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
    //}

    while(true)
    {
        cout << "Was the computer ever built? (y/n)" << endl;
        cin >> wasitbuilt;
        if(wasitbuilt == "Y" || wasitbuilt == "y" || wasitbuilt == "Yes" || wasitbuilt == "yes")
        {
            built = "Yes";
            break;
        }
        else if (wasitbuilt == "N" || wasitbuilt == "n" || wasitbuilt == "No" || wasitbuilt == "no")
        {
            built = "No";
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
    input.setBuilt(built);

    cout << endl;

    _turnC.addComputer(input);
    cin.ignore();
}
void consoleUI::removeCommandPerson()
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
    _turnP.removePerson(input);
}

bool consoleUI::is_digits(const string &numbers)
{
    return numbers.find_first_not_of("0123456789") == std::string::npos;
}
//connection








//person

void consoleUI::findCommandPerson()
{
    string toFind;


    cout << "Search name/year: ";

    getline(cin, toFind);
    cout << endl;


    if(toFind == "dickbutt")
    {
        cout << "                                      PrumpPrum                                         " << endl;                                                                                         cout << "                                  pPrumpPrumpPrumpP                                     " << endl << "                              rumpPrumpPrumpPrumpPrump                                  " << endl << "                      PrumpPrumpPrump           PrumpPru                                " << endl << "                   mpPrumpPrumpP                  rumpPru                               " << endl << "                 mpPrumpPrumpPru                   mpPrum                               " << endl << "                 pPrumpPrumpPrump                   Prump" << endl << "                 PrumpPrumpP rumpPr    umpPrumpPru  mpPru" << endl << "                 mpPrumpPrumpPrumpPr umpPrumpPrumpPr umpP" << endl << "                 rumpPrumpPrumpPru  mpPrumpPrumpPrumpPrum" << endl << "                pPrum  pPrumpPrump  PrumpPrumpPrumpPrumpP" << endl << "               rumpPrumpPrumpPrumpP rumpPrumpPr umpPrumpP" << endl << "              rumpPrumpPrumpPrump   PrumpPrumpPrumpPrumpP" << endl << "             rumpPrumpPrumpPrumpPrumpPrumpPrumpPr  umpPr" << endl << "            umpPr          umpPrumpPrumpPrump     PrumpP" << endl << "           rumpP                      rumpPru     mpPrum" << endl << "          pPrump                                 PrumpP" << endl << "         rumpPr                                 umpPru" << endl << "        mpPrum                                  pPrump" << endl << "        Prump                      Prum        pPrump" << endl << "        Prum                      pPrum pPr   umpPru" << endl << "        mpPr                      umpPrumpPr  umpPr                         umpPrumpP" << endl << "       rumpP                      rumpPrump  Prump                        PrumpPrumpPr" << endl << "       umpPr                     umpPrumpPr umpPr                       umpPru    mpPr" << endl << "       umpPr                     umpPrumpP  rumpP                     rumpPru    mpPru" << endl << "       mpPru                    mpPrumpPr  umpPru                   mpPrump     Prump" << endl << "       Prump                    PrumpPru   mpPrumpPrumpPrumpPru   mpPrump     Prump" << endl << "        Prum                   pPrumpPr    umpPrumpPrumpPrumpPrumpPrump      Prump" << endl << "        Prum                   pPrumpP     rumpP   rumpP   rumpPrumpP      rumpPr" << endl << "        umpP                  rumpPrum      pPr   umpPrumpPrumpPrum      pPrump" << endl << "        Prump               Prump Prump         PrumpPrumpPrumpPru     mpPrump" << endl << "         Prum             pPrum  pPrumpP         rumpPrumpPrumpPrump   PrumpPru" << endl << "         mpPru            mpPrumpPrumpPr                     umpPrump    PrumpPrum" << endl << "          pPrum            pPrumpPrumpP              rump       PrumpP  rump Prump" << endl << "          PrumpP              rump                   Prum        pPrump  PrumpPru" << endl << "           mpPrum                                pPr              umpPr    umpP" << endl << "            rumpPrum                            pPru              mpPru     mpPr" << endl << "               umpPrum                          pPru              mpPrumpPrumpPr" << endl << "     ump        PrumpPrump                       Prum           pPrumpPrumpPrum" << endl << "    pPrumpP    rumpPrumpPrumpPru                  mpP         rumpPru    m" << endl << "   pPrumpPrumpPru mpPrumpPrumpPrumpPrum           pPru    mpPrump" << endl << "    Prum pPrumpPrumpPru    mpPrumpPrumpPru mpPrumpPrumpPrumpPrum" << endl << "     pPru  mpPrumpPru         mpPrumpPrum pPrumpPrumpPrumpPru" << endl << "      mpPr   umpPru         mpPrumpPrump Prump PrumpPrumpP" << endl << "       rumpPrumpP           rumpPrumpPr  umpP" << endl << "        rumpPru              mpPrumpP   rump" << endl << "          Pru                mpPrum    pPru" << endl << "                              mpPrum  pPru" << endl << "                               mpPrumpPru" << endl << "                                 mpPrump" << endl << "                                   Pru  " << endl;
    }
    else if(is_digits(toFind))
    {
        int toFindDigits= stoi(toFind);
        _printOutPerson = _turnP.findDigits(toFindDigits);

        if (_turnP.lookForDigits(toFindDigits))
        {
            cout << "Person found! " << endl;
            cout << _printOutPerson;
        }
        else
        {
            cout << "Person not found " << endl << endl;
        }

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

void consoleUI::modifyCommandPerson()
{
    string toModify;

    cout << "Search for a person to modify: ";



    while(true)
    {
        getline(cin, toModify);

        _printOutPerson = _turnP.findPerson(toModify);

        if (_turnP.lookForPerson(toModify))
        {
            cout << _printOutPerson;
        }
        if (_printOutPerson.size()==1) //here the magic happens
        {
            cout << "Hooray you found a person to modify! " << endl;
            Person id = _turnP.findPersonNumber(_printOutPerson[0].getName()); //bý bara til fkn copy af kallinum sem eg vill breyta, vil breyta actual gæjanum!
            personValidation(id);
            _turnP.changePerson(id);
            break;
        }
        else
        {
            cout << "please be more specific: " << endl;
        }
    }

}

void consoleUI::personValidation(Person &input)
{
    string name, gender, deathYear, birthYear;
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
        if ((deathYear >= birthYear && deathCheck > MINIMUM_DEATH_YEAR && deathCheck < MAXIMUM_DEATH_YEAR) || deathCheck == 0 )
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
    cin.ignore();
}

void consoleUI::statusCommandPerson()
{
    _printStatus = _turnP.properties();
    const int NAMES = 0;
    const int DIED = 1;
    const int FEMALES = 2;
    const int MALES = 3;
    cout << "Total names in list       : " << _printStatus[NAMES] << endl;
    cout << "Number of deceased        : " << _printStatus[DIED] << endl;
    cout << "Total females on the list : " << _printStatus[FEMALES] << endl;
    cout << "Total males on the list   : " << _printStatus[MALES] << endl << endl;
}

bool consoleUI::specialCommandPerson()
{
    if (_command == FIND)
    {
        return true;
    }
    else if(_command == QUIT)
    {
        return true;
    }
    else if(_command == QUIZ)
    {
        return true;
    }
    else if(_command == REMOVE)
    {
        return true;
    }
    else if(_command == STATUS)
    {
        return true;
    }
    else if(_command == BACK)
    {
        return true;
    }
    else if(_command == MODIFY)
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
            _turnP.sortPersonList(choice);
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


void consoleUI::printListPerson()       // Print if appropriate.
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
        removeCommandPerson();
    }
    else if (_command == FIND)      // Tells the user to enter the name of the scientist to be located in the list.
    {
        _print = false;
        findCommandPerson();
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
    }
    else if(_command == STATUS)
    {
        _print = false;
        statusCommandPerson();
    }
    else if(_command == MODIFY)
    {
        _print = false;
        modifyCommandPerson();
    }
    else
    {
        _print = false;
    }
}

//computer

void consoleUI::removeCommandComputer()
{
    string fullName;
    Computer input;
    cout << "Enter the full name of the computer to remove from the database: ";
    getline(cin, fullName);
    input = _turnC.findComputerExactly(fullName);

    if (input.getName() == EMPTY)
    {
        cout << endl << "Computer not found!" << endl;
    }
    else
    {
        cout << endl << fullName << " removed" << endl;
    }

    input = _turnC.findComputerExactly(fullName);
    _turnC.removeComputer(input);
}

void consoleUI::findCommandComputer()
{
    string toFind;

    cout << "Search computer: ";

    getline(cin, toFind);
    cout << endl;
    if(toFind == "dickbutt")
    {
        cout << "                                      PrumpPrum                                         " << endl;                                                                                         cout << "                                  pPrumpPrumpPrumpP                                     " << endl << "                              rumpPrumpPrumpPrumpPrump                                  " << endl << "                      PrumpPrumpPrump           PrumpPru                                " << endl << "                   mpPrumpPrumpP                  rumpPru                               " << endl << "                 mpPrumpPrumpPru                   mpPrum                               " << endl << "                 pPrumpPrumpPrump                   Prump" << endl << "                 PrumpPrumpP rumpPr    umpPrumpPru  mpPru" << endl << "                 mpPrumpPrumpPrumpPr umpPrumpPrumpPr umpP" << endl << "                 rumpPrumpPrumpPru  mpPrumpPrumpPrumpPrum" << endl << "                pPrum  pPrumpPrump  PrumpPrumpPrumpPrumpP" << endl << "               rumpPrumpPrumpPrumpP rumpPrumpPr umpPrumpP" << endl << "              rumpPrumpPrumpPrump   PrumpPrumpPrumpPrumpP" << endl << "             rumpPrumpPrumpPrumpPrumpPrumpPrumpPr  umpPr" << endl << "            umpPr          umpPrumpPrumpPrump     PrumpP" << endl << "           rumpP                      rumpPru     mpPrum" << endl << "          pPrump                                 PrumpP" << endl << "         rumpPr                                 umpPru" << endl << "        mpPrum                                  pPrump" << endl << "        Prump                      Prum        pPrump" << endl << "        Prum                      pPrum pPr   umpPru" << endl << "        mpPr                      umpPrumpPr  umpPr                         umpPrumpP" << endl << "       rumpP                      rumpPrump  Prump                        PrumpPrumpPr" << endl << "       umpPr                     umpPrumpPr umpPr                       umpPru    mpPr" << endl << "       umpPr                     umpPrumpP  rumpP                     rumpPru    mpPru" << endl << "       mpPru                    mpPrumpPr  umpPru                   mpPrump     Prump" << endl << "       Prump                    PrumpPru   mpPrumpPrumpPrumpPru   mpPrump     Prump" << endl << "        Prum                   pPrumpPr    umpPrumpPrumpPrumpPrumpPrump      Prump" << endl << "        Prum                   pPrumpP     rumpP   rumpP   rumpPrumpP      rumpPr" << endl << "        umpP                  rumpPrum      pPr   umpPrumpPrumpPrum      pPrump" << endl << "        Prump               Prump Prump         PrumpPrumpPrumpPru     mpPrump" << endl << "         Prum             pPrum  pPrumpP         rumpPrumpPrumpPrump   PrumpPru" << endl << "         mpPru            mpPrumpPrumpPr                     umpPrump    PrumpPrum" << endl << "          pPrum            pPrumpPrumpP              rump       PrumpP  rump Prump" << endl << "          PrumpP              rump                   Prum        pPrump  PrumpPru" << endl << "           mpPrum                                pPr              umpPr    umpP" << endl << "            rumpPrum                            pPru              mpPru     mpPr" << endl << "               umpPrum                          pPru              mpPrumpPrumpPr" << endl << "     ump        PrumpPrump                       Prum           pPrumpPrumpPrum" << endl << "    pPrumpP    rumpPrumpPrumpPru                  mpP         rumpPru    m" << endl << "   pPrumpPrumpPru mpPrumpPrumpPrumpPrum           pPru    mpPrump" << endl << "    Prum pPrumpPrumpPru    mpPrumpPrumpPru mpPrumpPrumpPrumpPrum" << endl << "     pPru  mpPrumpPru         mpPrumpPrum pPrumpPrumpPrumpPru" << endl << "      mpPr   umpPru         mpPrumpPrump Prump PrumpPrumpP" << endl << "       rumpPrumpP           rumpPrumpPr  umpP" << endl << "        rumpPru              mpPrumpP   rump" << endl << "          Pru                mpPrum    pPru" << endl << "                              mpPrum  pPru" << endl << "                               mpPrumpPru" << endl << "                                 mpPrump" << endl << "                                   Pru  " << endl;
    }
    else if(is_digits(toFind))
    {
        int toFindDigits= stoi(toFind);

        _printOutComputer = _turnC.findDigits(toFindDigits);
        if (_turnC.lookForDigits(toFindDigits))
        {
           cout << "Computer found! " << endl;
           cout << _printOutComputer;
        }
        else
        {
            cout << "Computer not found " << endl << endl;
        }

    }
    else
    {
        _printOutComputer = _turnC.findComputer(toFind);
        if (_turnC.lookForComputer(toFind))
        {
            cout << "Computer found! " << endl;
            cout << _printOutComputer;
        }
        else
        {
            cout << "Computer not found " << endl << endl;
        }
    }
}


void consoleUI::statusCommandComputer()
{
    _printStatus = _turnC.computerProperties();
    int nameQuant= 0;
    int typeElecQuant=1;
    int typeMechQuant=2;
    int typeElecMechQuant=3;
    int typeTransQuant=4;
    int typeTransMicroQuant=5;
    int typeSuperQuant=6;
    int typeQuantumQuant=7;
    int builtQuant=8;


    cout<<"Total computers in list          : " << _printStatus[nameQuant]<<endl;
    cout<<"Electronical computers           : " << _printStatus[typeElecQuant]<<endl;
    cout<<"Mechanical computers             : " << _printStatus[typeMechQuant]<<endl;
    cout<<"Electro-Mechanical computers     : " << _printStatus[typeElecMechQuant]<<endl;
    cout<<"Transistor computers             : " << _printStatus[typeTransQuant]<<endl;
    cout<<"Transistor/Microchip computers   : " << _printStatus[typeTransMicroQuant]<<endl;
    cout<<"Super computers                  : " << _printStatus[typeSuperQuant]<<endl;
    cout<<"Quantum computers                : " << _printStatus[typeQuantumQuant]<<endl;
    cout<<"Computers that were built        : " << _printStatus[builtQuant]<<endl;




}
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

        if(specialCommandComputer(choice))
        {
            _turnC.sortComputerList(choice);
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
            _turnC.reverseVector();
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


bool consoleUI::specialCommandComputer(const string &_command)
{
    if(_command == "a")
    {
        return true;
    }
    if(_command=="y")
    {
        return true;
    }
    if(_command=="t")
    {
        return true;
    }
    else if(_command =="b")
    {
        return true;
    }
    else
    {
       return false;
    }
}

void consoleUI::printListComputer()
{
    const string SORT = "sort";
    const string ADD = "add";
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
        removeCommandComputer();
    }
    else if (_command == FIND)
    {
        _print = false;
        findCommandComputer();
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
    }
    else if(_command == STATUS)
    {
        _print = false;
        statusCommandComputer();
    }
    else
    {
        _print = false;
    }

}

void consoleUI::printList()
{
    if((_turnG.dataFound() || QUIT == _command)&& _theRightOne=="person")
    {
        printListPerson();         // Checks if there is a need for a printout of the list.
    }
    else if((_turnG.dataFound() || QUIT == _command)&& _theRightOne=="computer")
    {
        printListComputer();
    }
    else
    {
        cout << endl << "Database could not be accessed! " << endl << endl;
    }
}

void consoleUI::print()
{
    if(_print  && _database=="person")
    {
        _printOutPerson = _turnP.getPersonList();// getList() gets the list that's supposed to be printed out.
        cout << _printOutPerson;
    }
    else if(_print && _database=="computer")
    {
        _printOutComputer = _turnC.getComputerList(); // todo setja inn dataFound lika
        cout << _printOutComputer;
    }
    else if (!specialCommandPerson() && _turnG.dataFound())
    {
        cout << "Invalid command!" << endl << endl;
    }
}

void consoleUI::modifyCommandComputer()
{
    string toFind;

    cout << "Search for a computer to modify: ";
    while(true)
    {
        getline(cin, toFind);
        cout << endl;

        _printOutComputer = _turnC.findComputer(toFind);
        if (_turnC.lookForComputer(toFind))
        {
            cout << _printOutComputer;
        }
        if (_printOutComputer.size()==1)
        {
            cout << "Hooray you found a computer to modify!" << endl;
            Computer id = _turnC.findComputerNumber(_printOutComputer[0].getName());
            computerValidation(id);
            _turnC.changeComputer(id);
            break;
        }
        else
        {
            cout << "Please be more specific: " << endl << endl;
        }
    }

}

void consoleUI::computerValidation(Computer& input)
{
    string name, type, yearBuilt, wasitbuilt, built;
    int birthCheck = 0;
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
        else if (_turnG.toLower(type) == "mechanical")
        {
            type = MECHANICAL;
            break;
        }
        else if (_turnG.toLower(type) == "electronic")
        {
            type = ELECTRONIC;
            break;
        }
        else if (_turnG.toLower(type) == "electro-mechanical")
        {
            type = ELECTROMECHANICAL;
            break;
        }
        else if (_turnG.toLower(type) == "transistor")
        {
            type = TRANSISTOR;
            break;
        }
        else if (_turnG.toLower(type) == "transistor/microchip")
        {
            type = TRANSISTORMICROCHIP;
            break;
        }
        else if (_turnG.toLower(type) == "supercomputer")
        {
            type = SUPERCOMPUTER;
            break;
        }
        else if (_turnG.toLower(type) == "quantum computer")
        {
            type = QUANTUMCOMPUTER;
            break;
        }
        else
        {
            cout << "Invalid type!" << endl;
        }
    }
    input.setType(type);

    //if(built == "Yes")
    //{
        while(true)
        {
            cout << "Year (YYYY): ";
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
    //}

    while(true)
    {
        cout << "Was the computer ever built? (y/n)" << endl;
        cin >> wasitbuilt;
        if(wasitbuilt == "Y" || wasitbuilt == "y" || wasitbuilt == "Yes" || wasitbuilt == "yes")
        {
            built = "Yes";
            break;
        }
        else if (wasitbuilt == "N" || wasitbuilt == "n" || wasitbuilt == "No" || wasitbuilt == "no")
        {
            built = "No";
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
    input.setBuilt(built);


    cout << endl;
    cin.ignore();
}
