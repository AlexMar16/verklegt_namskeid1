#include "generalService.h"

generalService::generalService()
{

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
