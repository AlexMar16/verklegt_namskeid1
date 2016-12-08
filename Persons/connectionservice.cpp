#include "connectionservice.h"

connectionService::connectionService()
{
    generalService getVector;
    _listConnections = getVector.getOriginalConnections();
}
/*
void connectionService::removeFromDatabase(const string &name)
{

}
void connectionService::addConnection(const Connection &input)
{

}
*/
vector<Connection> connectionService::getConnectionList() const {return _listConnections;}

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

