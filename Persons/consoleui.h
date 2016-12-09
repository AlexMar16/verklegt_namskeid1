#ifndef CONSOLEUI_H
#define CONSOLEUI_H
//#include "person.h"
//#include "computer.h"
#include "PersonService.h"
#include "computerService.h"
#include "generalService.h"
#include "connectionservice.h"
//#include "dbmanager.h"


using namespace std;

class consoleUI
{
public:
    consoleUI();
    void run();

private:
    generalService _turnG;
    vector<int> _printStatus;
    vector<Computer> _printOutComputer;
    vector<Person> _printOutPerson;
    vector<Connection> _printOutConnection;

    bool _print;
    bool checkfoundPerson( const string& toFind);
    void checkModifyPerson(const string& toModify);
    void checkModifyComputer(const string& toModify);
    bool beginningCommand();
    bool specialCommandPerson();
    bool sortSpecialCommandPerson(const string& choice);
    bool specialCommandComputer(const string& command);
    bool specialCommandConnect();
    void printListPerson();
    void printListComputer();
    void addCommand();
    void addCompCommand();
    void removeCommandPerson();
    void sortCommandPerson();
    void sortCommandComputer();
    bool is_digits(const string& numbers);
    void findCommandPerson();
    void findCommandComputer();
    void quizCommand();
    void statusCommandPerson();
    void statusCommandComputer();
    void removeCommandComputer();
    void firstCommandBox();
    void commandBox();
    void printList();
    void printListConnect();
    void print();
    void commandBoxConnect();
    void commandBoxConnectptc();
    void findconnection();
    PersonService _turnP;      //The instance we use to communicate with the PersonService layer.
    string _theRightOne;
    string _command;
    string _database;
    string toLower(const string& toLowerString);
    computerService _turnC;
    connectionService _turnCon;

    bool connectSubCommand();
    void commandBoxSubConnect();


    void modifyCommandPerson();
    void personValidation(Person &input);
    void modifyCommandComputer();
    void computerValidation(Computer& input);
    void addConnection();

    void emailCommand();


};

#endif // CONSOLEUI_H
























