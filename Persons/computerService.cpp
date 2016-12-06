#include "computerService.h"
#include "service.h"
#include "Computer.h"
#include "computer.h"

using namespace std;

computerService::computerService(){
     DbManager temp("ComputerScience.sqlite");
    _listComputer = temp.getCVector();
    _listSearchedComputer = temp.getCVector();
    _listSearchedComputer.clear();
    _program = true;
    _dataFound = temp.isOpen();
}

bool computerService::alreadyInDatabase(const string& name)         // Checks if the name exists in the database
{
    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (_listComputer[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}
/*
bool service::lookForComputer(const string& name)         // Checks if any part of the name is on the list
{
    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (toLower(_listComputer[i].getName()).find(toLower(name)) != string::npos)       // Enables us to search in lower case letters.
        {
            return true;
        }
    }
    return false;
} */

bool computerService::getProgram() const {return _program;}

Computer computerService::findComputerExactly(const string& name)
{
    Computer ComputerFoundExactly;
    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (_listComputer[i].getName() == name)
        {
            ComputerFoundExactly = _listComputer[i];
        }
    }
    return ComputerFoundExactly;
}
/*
Computer computerService::generateQuestion()
{
    srand(time(0));
    return _listComputer[rand() % _listComputer.size()]; // Randomizing questions.
}
string computerService::assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d)
{
    const string A = "a";
    const string B = "b";
    const string C = "c";
    const string D = "d";

    if (answer == A)
    {
        answer = a;
    }
    else if (answer == B)
    {
        answer = b;
    }
    else if (answer == C)
    {
        answer = c;
    }
    else if (answer == D)
    {
        answer = d;
    }
    else
    {
        answer = "0";
    }

    return answer;
}

string computerService::aliveCheck(const Computer& p)
{
    if (p.getDeathYear() != ALIVE)
        return "died in " + to_string(p.getDeathYear());     // Converting the integer to a string to return a sentence.
    else
        return "is still alive";
}*/

string computerService::toLower(const string& toLowerString)    // Makes everything lowercase
{
    string data = toLowerString;
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

vector<int> computerService::computerProperties()
{
    const string ELECTRONIC = "Electronic";
    const string MECHANICAL = "Mechanical";
    const string ELECTROMECHANICAL = "Electro-Mechanical";
    const string TRANSISTOR = "Transistor";
    const string TRANSISTORMICROCHIP = "Transistor/Microchip";
    const string SUPERCOMPUTER = "Supercomputer";
    const string QUANTUMCOMPUTER = "Quantum computer";

    int nameQuant = 0;

    int typeElecQuant = 0;
    int typeMechQuant = 0;
    int typeElecMechQuant = 0;
    int typeTransQuant = 0;
    int typeTransMicroQuant = 0;
    int typeSuperQuant = 0;
    int typeQuantumQuant = 0;

    int builtQuant = 0;
    vector<int> statusVec;

    for(size_t i = 0; i < _listComputer.size(); i++)
    {
        nameQuant++;

        if(_listComputer[i].getType()== ELECTRONIC)
        {
            typeElecQuant++;
        }
        else if(_listComputer[i].getType()== MECHANICAL)
        {
            typeMechQuant++;
        }
        else if(_listComputer[i].getType()== ELECTROMECHANICAL)
        {
            typeElecMechQuant++;
        }
        else if(_listComputer[i].getType()== TRANSISTOR)
        {
            typeTransQuant++;
        }
        else if(_listComputer[i].getType()== TRANSISTORMICROCHIP)
        {
            typeTransMicroQuant++;
        }
        else if(_listComputer[i].getType()== SUPERCOMPUTER)
        {
            typeSuperQuant++;
        }
        else if(_listComputer[i].getType()== QUANTUMCOMPUTER)
        {
            typeQuantumQuant++;
        }
    }

    for(size_t z = 0; z < _listComputer.size(); z++)
    {
        if(_listComputer[z].getBuilt() == "Yes")
        {
            builtQuant++;
        }
    }

    statusVec.push_back(nameQuant);
    statusVec.push_back(typeElecQuant);
    statusVec.push_back(typeMechQuant);
    statusVec.push_back(typeElecMechQuant);
    statusVec.push_back(typeTransQuant);
    statusVec.push_back(typeTransMicroQuant);
    statusVec.push_back(typeSuperQuant);
    statusVec.push_back(typeQuantumQuant);
    statusVec.push_back(builtQuant);

    return statusVec;
}

vector<Computer> computerService::getComputerList() const {return _listComputer;}
/*
vector<Computer> computerService::sortType()        // Sorts the list by gender, beginning with women.
{
    int counter = 0;
    for(size_t i = 0; i < _listComputer.size(); i++)
    {
        if(_listComputer[i].getType() == FEMALE)
        {
            swap(_listComputer[i], _listComputer[counter]);
            counter++;
        }
    }
    return _listComputer;
}

vector<Computer> computerService::sortAlphabetically()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listComputer.size() - 1; i++)
        {
            if (_listComputer[i].getName() > _listComputer[i+1].getName())
            {
                swap(_listComputer[i], _listComputer[i+1]);
                again = true;
            }
        }
    }
    return _listComputer;
}

vector<Computer> computerService::sortAlphabeticallyLastName()
{
    string name1;
    string name2;
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listComputer.size() - 1; i++)
        {
            name1= _listComputer[i].getName();
            name2= _listComputer[i+1].getName();

            if (getLastName(name1) > getLastName(name2))
            {
                swap( _listComputer[i], _listComputer[i+1]);
                again = true;
            }
        }
    }
    return _listComputer;
}

vector<Computer> computerService::sortBirthYear()
{
    bool again = true;
    while(again)
    {
        again = false;
        for (size_t i = 0; i < _listComputer.size() - 1; i++)
        {
            if ( _listComputer[i].getBirthYear() > _listComputer[i+1].getBirthYear())
            {
                swap(_listComputer[i], _listComputer[i+1]);
                again = true;
            }
        }
    }
    return _listComputer;
}

vector<Computer> computerService::findComputer(const string &name)      // Finds people and adds them to the vector
{
    _listSearchedComputer.clear();
    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (toLower(_listComputer[i].getName()).find(toLower(name)) != string::npos)       // Puts both instances to lowercase
        {
            _listSearchedComputer.push_back(_listComputer[i]);       // Puts people in the list who apply to the input
        }
    }
    return _listSearchedComputer;
}

vector<Computer> computerService::sortDeath()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listComputer.size() - 1; i++)
        {
            if (_listComputer[i].getDeathYear() > _listComputer[i+1].getDeathYear())      // Seperate the one's who are still alive and those who are not.
            {
                swap(_listComputer[i], _listComputer[i+1]);
                again = true;
            }
        }
    }
    vector<Computer> temp;
    for(size_t i = 0; i < _listComputer.size(); i++)           // The one's who have died are put in the variable temp in order.
    {
        if(_listComputer[i].getDeathYear() != ALIVE)
        {
            temp.push_back(_listComputer[i]);
        }
    }
    for(size_t i = 0; i < _listComputer.size(); i++)           // Then we put the one's who are still alive behind them.
    {
        if(_listComputer[i].getDeathYear() == ALIVE)
        {
            temp.push_back(_listComputer[i]);
        }
    }

    return temp;
}

void computerService::swap(Computer& a, Computer& b)
{
    Computer temp = a;
    a = b;
    b = temp;
}
bool computerService::dataFound()const {return _dataFound;}

void computerService::sortList(const string& command)       // Sort the list according to the input.
{

    if(command == A)
    {
        _listComputer = sortAlphabetically();
    }
    else if(command == B)
    {
        _listComputer = sortBuilt();
    }
    else if(command == T)
    {
        _listComputer = sortType();
    }
    else if(command == QUIT)
    {
        _program = false;
    }

}

*/
void computerService::addComputer(const Computer &input)        // Makes the user capable to add people to the list, as long as they're not already on the list
{
    if(!alreadyInDatabase(input.getName()))
    {
        DbManager addNewComputer;
        _listComputer.push_back(input);
        addNewComputer.setCVector(_listComputer);
        addNewComputer.changeData();
    }
}

void computerService::removeComputer(const Computer &input)         // Makes the user capable to remove people
{
    if(alreadyInDatabase(input.getName()))      // Checks if the name is already in the database.
    {
        DbManager removeComputer;
        removeFromDatabase(input.getName());
        removeComputer.setCVector(_listComputer);
        removeComputer.changeData();
    }
}

void computerService::removeFromDatabase(const string &name)        // Takes the list, removes an elemnt then rewrites the info.txt with the list without what was removed
{
    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (_listComputer[i].getName() == name)
        {
            _listComputer.erase(_listComputer.begin() + i);
        }
    }
}

void computerService::generateOptions(const Computer& correct, string& a, string& b, string& c, string& d)
{
    const int CASE_0 = 0;
    const int CASE_1 = 1;
    const int CASE_2 = 2;

    a = _listComputer[rand() % _listComputer.size()].getName();       // Generating random answers
    b = _listComputer[rand() % _listComputer.size()].getName();
    c = _listComputer[rand() % _listComputer.size()].getName();
    d = _listComputer[rand() % _listComputer.size()].getName();

    int random = rand() % 4;
    if(random == CASE_0)
    {
        a = correct.getName();      // Assigning the correct answer to one of the answers
    }
    else if(random == CASE_1)
    {
        b = correct.getName();
    }
    else if(random == CASE_2)
    {
        c = correct.getName();
    }
    else
    {
        d = correct.getName();
    }
}


void computerService::setProgram(const bool& input)
{
    _program = input;
    DbManager quit;
    quit.~DbManager();
}

void computerService::reverseVector() {reverse(_listComputer.begin(), _listComputer.end());}
