#include "connectionservice.h"

connectionService::connectionService()
{

}
/*
void connectionService::removeFromDatabase(const string &name)
{

}
void connectionService::addConnection(const Connection &input)
{

}
*/

bool connectionService::personORComputer(const string& command)
{
    generalService GS;
    if (GS.toLower(command) == "person to computer")
    {
        _connectFrom = "person";
        return true;
    }
    else if (GS.toLower(command) == "computer to person")
    {
        _connectFrom = "computer";
        return true;
    }
    else
    {
        return false; //einhver að vinna að villuchecki eftir þetta
    }
}
