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

// TO FAST TRAVEL:

    // to computer functions   = ctrl+f -> //computer
    // to person functions     = ctrl=f -> //person
    // to connection functions = ctrl+f -> //connect

void consoleUI::run()
{
    do
    {
        firstCommandBox();
        if(beginningCommand() && _turnG.dataFound())
        {
            do
            {
                if(_database == "person" || _database == "computer" || _database == "c" || _database == "p")
                {
                    commandBox();
                    printList();
                    print();
                }
                else
                {
                    do{commandBoxConnect();
                        if(_turnCon.personORComputer(_command))
                        {
                            _turnCon.sortConnectAlphabetically();  // Sort alphabetically function
                            do
                            {
                                commandBoxConnectptc();
                                if(_command == "showall")
                                {
                                    _printOutConnection = _turnCon.getConnectionList();
                                    cout << _printOutConnection;
                                }
                                else if(_command == "find")
                                {
                                    findconnection();
                                }
                                else if(_command == "add")
                                {

                                }
                                else if (_command == "remove")
                                {
                                    //vantar
                                }
                            }while(_command != BACK && _command != QUIT);
                            if(_turnCon.getSwappedList())
                            {
                                _turnCon.swapToFrom();
                            }
                        }
                    } while(_command != BACK && _command != QUIT);
                }
            }while(_command != BACK && _command != QUIT);
            _turnG.setProgram(_command);
        }
        else if(_database != QUIT && _command != QUIT)
        {
            cout << endl << "The database " << _database << " was not found" << endl;
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
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| person   - This command will gain you access to the person table."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| computer - This command will gain you access to the computer table"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| connect  - This command will gain you access to connections of both."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit     - This command will quit the program. "
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;
    cout << "Pick a database: ";
    getline(cin, _database);
    _database = _turnG.toLower(_database);
    beginningCommand();
    _turnG.setProgram(_database);
    if(_database == "person" || _database == "p")
    {
        _theRightOne = "person";
    }
    else if(_database == "computer" || _database == "c")
    {
        _theRightOne = "computer";
    }
}

bool consoleUI::beginningCommand() //checks if the command was valid
{
    if(_database == "person" || _database == "p")
    {
        return true;
    }
    else if(_database == "computer" || _database == "c")
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

void consoleUI::commandBox()// the right one either sets it's value to "person" or "computer"
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
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| modify - This command allows you to modify a certain "+_theRightOne+" in the list."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| status - This command displays info about the list "
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| back   - This command will allow you to choose another database. "
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| email  - This command will allow you to send email via smtp server. "
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit   - This command will quit the program. "
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;      // Command box ends.
    cout << "command: ";
    getline(cin, _command);          // Sets the private variable _command in the service class.
    _command = _turnG.toLower(_command);
}

void consoleUI::commandBoxConnect()
{
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;     // Command box begins.
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter one of the following commands:"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << BARRIER << right << BARRIER<< endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| person to computer - This command will print a specific connection."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| computer to person - This command will print all connections."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| back               - This command will allow you to choose another database."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit               - This command will quit the program."
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;      // Command box ends.
    cout << "command: ";
    getline(cin, _command);
    _command = _turnG.toLower(_command);
}

void consoleUI::commandBoxConnectptc()
{
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;     // Command box begins.
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter one of the following commands:"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << BARRIER << right << BARRIER<< endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| showall - This command will show all connection."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| find    - This command will show a specific connections."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| back    - This command will allow you to choose another database."
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit    - This command will quit the program."
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;      // Command box ends.
    cout << "command: ";
    getline(cin, _command);
    _command = toLower(_command);
}

void consoleUI::commandBoxSubConnect()
{
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) <<  ASTERISK << endl;     // Command box begins.
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| Please enter one of the following commands:"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << BARRIER << right << BARRIER<< endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| specific - This command will print a specific connection"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| all      - This command will print all connections"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| add      - This command allows you to add a connection"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| remove   - This command allows you to remove a connection"
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| back     - This command will allow you to choose another database. "
         << right << BARRIER << endl;
    cout << left  << setw(ASTERISK_WIDTH) << setfill(SPACE) << "| quit     - This command will quit the program. "
         << right << BARRIER << endl;
    cout << setw(ASTERISK_WIDTH) << setfill(ASTERISK) << ASTERISK << endl;      // Command box ends.
    cout << "command: ";
    getline(cin, _command);
}

void consoleUI::quizCommand()
{
    string a, b, c, d, answerName;
    if (_database == "person" || _database == "p")
    {
        Person questionP = _turnP.generateAnswer();
        string question = _turnP.genderCheck(questionP) + " was born in " + to_string(questionP.getBirthYear())
             + " and " + _turnP.aliveCheck(questionP) + ", enter (a/b/c/d)";
        cout << question << endl;
        _turnG.speakQuestion(question);
        _turnP.generateOptions(questionP, a, b, c, d);
        answerName = questionP.getName();
    }
    else
    {
        Computer questionC = _turnC.generateAnswer();
        string cQuestion = "This " + _turnC.typeCheck(questionC) + " computer was " + _turnC.builtCheck(questionC)
             + ", enter (a/b/c/d)";
        cout << cQuestion << endl;
        _turnG.speakQuestion(cQuestion);
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
        _turnG.speakQuestion("Correct");
    }
    else
    {
        cout << endl << "Wrong!" << endl << endl;
        _turnG.speakQuestion("Wrong");
    }
    cin.ignore();
}


void consoleUI::emailCommand()
{
    system("email.vbs");
}

//person

string consoleUI::toLower(const string& toLowerString)    // Makes everything lowercase
{
    string data = toLowerString;
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

void consoleUI::addCommand()
{
    bool notAlpha=false;
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
        name[0] = toupper(name[0]);         // Makes the first letter of the name uppercase

        for(size_t i=0; i< name.size(); i++)
        {
            if(!isalpha(name[i])&& !" ")        // We use the " " so the function does not complain when space is used
            {
               notAlpha=true;
            }
        }

        if(name == EMPTY || notAlpha)
        {
            cout << "Letters in English alphabet only allowed! " << endl;
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
        name[0] = toupper(name[0]);
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

    while(true)
    {
        cout << "Year designed (YYYY): ";
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
}

void consoleUI::removeCommandPerson()
{
    string fullName;
    string sure;
    cout << "Enter the name of the scientist to remove from the database: ";
    while(true)
    {
    getline(cin, fullName);
    fullName = _turnG.toLower(fullName);

    _printOutPerson = _turnP.findPerson(fullName);
    checkModifyPerson(fullName);

    if (_printOutPerson.size() == 1)
    {
        cout << _printOutPerson;
        cout << endl << "You found a person to remove!" << endl;
        Person id = _turnP.findPersonNumber(_printOutPerson[0].getName());
        cout << "Are you absolutely sure you want to delete this person?, type \"YES I AM\" exactly to continue:";
        getline(cin, sure);
        if (sure == "YES I AM")
        {
            _turnP.removePerson(id);
            break;
        }
        else
        {
            cout << "You have cancelled the removal, good for you!" << endl;
            break;
        }
    }
    else
    {
        cout << endl << "Please be more specific" << endl;
    }
    }
}

void consoleUI::findCommandPerson()         //allowes the user to search for a name or a year
{
    string toFind;
    cout << "Search name/year: ";

    getline(cin, toFind);
    cout << endl;


    if(toFind == "dickbutt"  || toFind== "")        // Our Easteregg
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

void consoleUI::modifyCommandPerson()       //allowes the user to modify instences that are already in the database
{
    string toModify;
    cout << "Search for a person to modify: ";

    while(true)
    {
        getline(cin, toModify);
        toModify = _turnG.toLower(toModify);

        _printOutPerson = _turnP.findPerson(toModify);
        checkModifyPerson(toModify);
        if (_turnP.lookForPerson(toModify))
        {
            cout << _printOutPerson;
        }
        if (_printOutPerson.size() == 1) //here the magic happens
        {
            cout << "Hooray you found a person to modify! " << endl;
            Person id = _turnP.findPersonNumber(_printOutPerson[0].getName());
            personValidation(id);
            _turnP.changePerson(id);
            break;
        }
        else if (_printOutPerson.size() == 0)
        {
            cout << "Person not found!" << endl;
            cout << "Please try again: ";
        }
        else
        {
            cout << "Please be more specific: ";
        }
    }
}

void consoleUI::findconnection()
{
    string tofind;
    cout << "Search for a person to see his connections: ";

        getline(cin, tofind);
        //toModify = toLower(toModify);
        _printOutConnection = _turnCon.findConnection(tofind);
        checkfoundPerson(tofind);
        if (_turnCon.lookForConnection(tofind))
        {
            cout << _printOutConnection;
        }
        else
        {
            cout << "Please be more specific: ";
        }
}

void consoleUI::checkModifyPerson( const string& toModify)          // Checks if the person is on the list.
{
    for(size_t i = 0; i < _printOutPerson.size(); i++)
    {
        if( toLower(_printOutPerson[i].getName()) == toLower(toModify))
        {
            vector<Person> temp;
            temp.push_back(_printOutPerson[i]);
            _printOutPerson = temp;
        }
    }
}

bool consoleUI::checkfoundPerson( const string& toFind)         // Checks if the person is in the list.
{
    for(size_t i = 0; i < _printOutConnection.size(); i++)
    {
        if( toLower(_printOutConnection[i].getPersonName()) == toLower(toFind))
        {
            vector<Connection> temp;
            temp.push_back(_printOutConnection[i]);
            _printOutConnection = temp;
            return true;
        }
    }
    return false;
}

void consoleUI::personValidation(Person &input)       // This function goes with the modify function and checks if the name,year and gender is valid
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
        cout << "Gender (male/female): ";
        cin >> gender;
        gender = _turnG.toLower(gender);
        if (_turnG.toLower(gender) == _turnG.toLower(MALE) || _turnG.toLower(gender) == _turnG.toLower(FEMALE))
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
        birthYear= _turnG.toLower(birthYear);
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
        deathYear = _turnG.toLower(deathYear);
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

void consoleUI::statusCommandPerson()           // This function displays total count of items in the list.
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

bool consoleUI::specialCommandPerson()      // Checks if command is valid
{
    string findIt = "find";


    if (_command == findIt)
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

void consoleUI::sortCommandPerson()         // Sorts the list.
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
        choice = _turnG.toLower(choice);

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
        upOrDown = _turnG.toLower(upOrDown);

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
    else if(_command == "email")
    {
        _print = false;
        emailCommand();
    }
    else
    {
        _print = false;
    }
}

//computer

bool consoleUI::is_digits(const string &numbers)        // This is a function we use to check if input was digits
{
    return numbers.find_first_not_of("0123456789") == std::string::npos;
}

void consoleUI::checkModifyComputer( const string& toModify)
{
    for(size_t i = 0; i < _printOutComputer.size(); i++)
    {
        if( _printOutComputer[i].getName() == toModify)
        {
            vector<Computer> temp;
            temp.push_back(_printOutComputer[i]);
            _printOutComputer = temp;
        }
    }
}

void consoleUI::removeCommandComputer()     // This function first finds out if the computer is in the list and then removes it
{
    string fullName;
    string sure;
    cout << "Enter the name of the computer to remove from the database: ";
    while(true)
    {
    getline(cin, fullName);
    fullName = _turnG.toLower(fullName);

    _printOutComputer = _turnC.findComputer(fullName);
    checkModifyComputer(fullName);

    if (_printOutComputer.size() == 1)
    {
        cout << _printOutComputer;
        cout << endl << "You found a computer to remove!" << endl;
        Computer id = _turnC.findComputerNumber(_printOutComputer[0].getName());
        cout << "Are you absolutely sure you want to delete this computer?, type \"YES I AM\" exactly to continue:";
        getline(cin, sure);
        if (sure == "YES I AM")
        {
            _turnC.removeComputer(id);
            break;
        }
        else
        {
            cout << "You have cancelled the removal, good for you!" << endl;
            break;
        }
    }
    else
    {
        cout << "Please be more specific" << endl;
    }
    }
}

void consoleUI::findCommandComputer()       // This function finds the computer
{
    string toFind;

    cout << "Search computer: ";

    getline(cin, toFind);
    toFind = _turnG.toLower(toFind);
    cout << endl;
    if(toFind == "dickbutt" || toFind== "")
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

void consoleUI::statusCommandComputer()         // This function displays the total count of items in the list.
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

void consoleUI::sortCommandComputer()           // Sorts items in computer list
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
        choice = _turnG.toLower(choice);

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
        upOrDown = _turnG.toLower(upOrDown);

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

bool consoleUI::specialCommandComputer(const string &_command)      // Checks if input was valid
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
    else if(_command == MODIFY)
    {
        _print = false;
        modifyCommandComputer();
    }
    else if(_command == "email")
    {
        _print = false;
        emailCommand();
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
    if(_print  && (_database=="person" || _database == "p"))
    {
        _printOutPerson = _turnP.getPersonList();           // getList() gets the list that's supposed to be printed out.
        cout << _printOutPerson;
    }
    else if(_print && (_database=="computer" || _database == "c"))
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
        toFind = _turnG.toLower(toFind);
        cout << endl;
        _printOutComputer = _turnC.findComputer(toFind);
        checkModifyComputer(toFind);
        if (_turnC.lookForComputer(toFind))
        {
            cout << _printOutComputer;
        }
        if (_printOutComputer.size() == 1)
        {
            cout << "Hooray you found a computer to modify!" << endl;
            Computer id = _turnC.findComputerNumber(_printOutComputer[0].getName());
            computerValidation(id);
            _turnC.changeComputer(id);
            break;
        }
        else if (_printOutComputer.size() == 0)
        {
            cout << "Computer not found!" << endl;
            cout << "Please try again: ";
        }
        else
        {
            cout << "Please be more specific: ";
        }
    }
}

void consoleUI::computerValidation(Computer& input)         // Finds the computer in the database, allowes the user to modify it.
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
        type = _turnG.toLower(type);
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

    while(true)
    {
        cout << "Year (YYYY): ";
        cin >> yearBuilt;
        yearBuilt = _turnG.toLower(yearBuilt);
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

    while(true)
    {
        cout << "Was the computer ever built? (y/n): ";
        cin >> wasitbuilt;
        wasitbuilt = _turnG.toLower(wasitbuilt);
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

//connect

bool consoleUI::connectSubCommand()     // Checks if input was valid
{
    int stoppari;
    if(_command == "specific")
    {
        cout << "Specific";
        cin >> stoppari;
        return true;
    }
    else if(_command == "all")
    {
        cout << "all";
        cin >> stoppari;
        return true;
    }
    else if(_command == "add")
    {
        cout << "add";
        cin >> stoppari;
        return true;
    }
    else if(_command == "remove")
    {
        cout << "remove";
        cin >> stoppari;
        return true;
    }
    else if(_command == "back")
    {
        return true;
    }
    else if(_command == "quit")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool consoleUI::specialCommandConnect()
{
    string everyone;


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



