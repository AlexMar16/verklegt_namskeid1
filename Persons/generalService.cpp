#include "generalService.h"

generalService::generalService()
{
    _program = true;
    _dataFound = false;
    _persons = _database.getPVector();
    _computers = _database.getCVector();
    _connections = _database.getCOVector();
    //_connections = _database.getConnections();
    _dataFound = _database.isOpen();
}
string generalService::toLower(const string& toLowerString)    // Makes everything lowercase
{
    string data = toLowerString;
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

void generalService::setProgram(const string& command)
{
    if(command == QUIT)
    {
        _program = false;
    }
}

bool generalService::getProgram() const {return _program;}


bool generalService::dataFound()const {return _dataFound;}

vector<Person> generalService::getOriginalPersons() const {return _persons;}
vector<Computer> generalService::getOriginalComputers() const {return _computers;}
vector<Connection> generalService::getOriginalConnections() const {return _connections;}

bool generalService::quizDuplicatedAnswer(const string& a, const string& b, const string& c, const string& d)
{
    if(a == b || a == c || a == d)
    {
        return true;
    }
    else if (b == c || b == d)
    {
        return true;
    }
    else if (c == d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool generalService::alreadyInDatabase(const string& name)         // Checks if the name exists in the database
{
    for (size_t i = 0; i < _persons.size(); i++)
    {
        if (_persons[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}

void generalService::speakQuestion(const string& input)
{
    string begin = "Set Sapi = Wscript.CreateObject(\"SAPI.SpVoice\")";
    string next = "Sapi.speak ";
    ofstream myFile;
    myFile.open("speak.vbs");

    if(myFile)
    {
        myFile << begin << endl << next << "\"" << input << "\"";
    }
    myFile.close();

    system("speak.vbs");
}

int generalService::findID(const string& name, const bool& swapped)
{
    if(swapped)
    {
        for(size_t i = 0; i < _persons.size(); i++)
        {
            if(toLower(_persons[i].getName()) == toLower(name))
            {
                return _persons[i].getID();
            }
        }
    }
    else
    {
        for(size_t i = 0; i < _computers.size(); i++)
        {
            if(toLower(_computers[i].getName()) == toLower(name))
            {
                return _computers[i].getID();
            }
        }
    }
    return 0;
}

