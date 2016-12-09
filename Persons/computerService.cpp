#include "computerService.h"
#include "generalservice.h"
#include "computer.h"

using namespace std;

computerService::computerService(){         //constructor taking vector of computer from general service
    generalService getVector;
    _listComputer = getVector.getOriginalComputers();
}

bool computerService::alreadyInDatabase(const string& name)         // Checks if the name exists in the database
{
    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (_listComputer[i].getName() == name)         //if input = name in database
        {
            return true;
        }
    }
    return false;
}

bool computerService::lookForComputer(const string& name)         // Checks if any part of the name is on the list
{
    generalService GS;
    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (GS.toLower(_listComputer[i].getName()).find(GS.toLower(name)) != string::npos)       // Enables us to search in lower case letters.
        {
            return true;
        }
    }
    return false;
}

Computer computerService::findComputerExactly(const string& name)       //used if only one computer is found exactly
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

Computer computerService::generateAnswer()
{
    srand(time(0));
    return _listComputer[rand() % _listComputer.size()]; // Randomizing questions.
}

string computerService::builtCheck(const Computer& c)
{
    if (c.getBuilt() == "Yes")
        return "built in " + to_string(c.getYearBuilt());     // Converting the integer to a string to return a sentence.
    else
        return "designed in " + to_string(c.getYearBuilt());
}

string computerService::typeCheck(const Computer& c)            //gets the type from the computer
{
    return c.getType();
}

vector<int> computerService::computerProperties()           //status of computer, counts how many types of certain computers exist
{
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

    for(size_t z = 0; z < _listComputer.size(); z++)            //counts how many where build
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

vector<Computer> computerService::sortType()            //sort the computer by their type
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listComputer.size() - 1; i++)
        {
            if (_listComputer[i].getType() < _listComputer[i+1].getType())
            {
                swap(_listComputer[i], _listComputer[i+1]);
                again = true;
            }
        }
    }
    return _listComputer;
}

vector<Computer> computerService::sortAlphabetically()          //sort the computer by the alphabetical
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

vector<Computer> computerService::sortBuilt()           //sorts computer if they were built or not
{
    vector<Computer> temp;
    for (size_t i = 0; i < _listComputer.size() - 1; i++)
    {
        if ( _listComputer[i].getBuilt() == "Yes")
        {
            temp.push_back(_listComputer[i]);
        }
    }
    for (size_t i = 0; i < _listComputer.size() - 1; i++)
    {
        if ( _listComputer[i].getBuilt() == "No" || _listComputer[i].getBuilt() == "no")
        {
            temp.push_back(_listComputer[i]);
        }
    }
    _listComputer = temp;
    return _listComputer;
}


vector<Computer> computerService::sortCreationYear()//sorts computer by their year of creation
{
    bool again = true;
    while(again)
    {
        again = false;
        for (size_t i = 0; i < _listComputer.size() - 1; i++)
        {
            if ( _listComputer[i].getYearBuilt() < _listComputer[i+1].getYearBuilt())
            {
                swap(_listComputer[i], _listComputer[i+1]);
                again = true;
            }
        }
    }
    return _listComputer;
}

vector<Computer> computerService::findComputer(const string &name)
{
    generalService GS;
    _listSearchedComputer.clear();
    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (GS.toLower(_listComputer[i].getName()).find(GS.toLower(name)) != string::npos)       // Puts both instances to lowercase
        {
            _listSearchedComputer.push_back(_listComputer[i]);
        }
    }
    return _listSearchedComputer;
}

void computerService::swap(Computer& a, Computer& b)
{
    Computer temp = a;
    a = b;
    b = temp;
}

void computerService::sortComputerList(const string& command)       // Sort the list according to the input.
{

    if(command == A)
    {
        _listComputer = sortAlphabetically();
    }
    else if(command == B)
    {
        _listComputer = sortBuilt();
    }
    else if(command == "y") //LAGA!!!
    {
        _listComputer = sortCreationYear();
    }
    else if(command == "t") //LAGA!!
    {
        _listComputer = sortType();
    }
}

void computerService::addComputer(const Computer &input)        // Makes the user capable to add people to the list, as long as they're not already on the list
{
    if(!alreadyInDatabase(input.getName()))
    {
        DbManager addNewComputer;
        _listComputer.push_back(input);
        addNewComputer.setCVector(_listComputer);
        addNewComputer.insertIntoComputer(input);
    }
}

void computerService::removeComputer(const Computer &input)         // Makes the user capable to remove people
{
    if(alreadyInDatabase(input.getName()))      // Checks if the name is already in the database.
    {
        DbManager removeComputer;
        removeFromDatabase(input.getName());
        removeComputer.setCVector(_listComputer);
        removeComputer.removeFromComputers(input);
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

    generalService GS;
    do
    {
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
    } while(GS.quizDuplicatedAnswer(a, b, c, d));
}

void computerService::reverseVector() {reverse(_listComputer.begin(), _listComputer.end());}

bool computerService::lookForDigits(const int& num)
{

    for (size_t i = 0; i < _listComputer.size(); i++)
    {

        if (_listComputer[i].getYearBuilt()== num)
        {
            return true;
        }

    }
    return false;
}

vector<Computer> computerService::findDigits(const int& num)
{
    _listSearchedDigits.clear();

    for (size_t i = 0; i < _listComputer.size(); i++)
    {
        if (_listComputer[i].getYearBuilt()== num)
        {
            _listSearchedDigits.push_back(_listComputer[i]);       // Puts people in the list who apply to the input
        }
    }
    return _listSearchedDigits;

}

Computer computerService::findComputerNumber(string name)
{

    for (size_t i=0; i<_listComputer.size(); i++)
    {
        if(_listComputer[i].getName()==name)
        {
            _computerIndex = i;
        }
    }
    return _listComputer[_computerIndex];
}

void computerService::changeComputer(const Computer& input)
{
    DbManager modifyComputer;
    modifyComputer.changeComputer(input, _computerIndex);
    _listComputer[_computerIndex] = input;
    modifyComputer.setCVector(_listComputer);
}

