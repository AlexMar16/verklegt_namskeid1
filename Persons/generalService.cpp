#include "generalService.h"

generalService::generalService()
{
    _program = true;
    _dataFound = false;
    _persons = _database.getVector();
    _computers = _database.getCVector();
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
