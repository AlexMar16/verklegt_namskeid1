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
        return true;
    }
    else if (GS.toLower(command) == "computer to person")
    {
        swapToFrom();
        return true;
    }
    else
    {
        return false; //einhver að vinna að villuchecki eftir þetta
    }
}

void connectionService::swapToFrom()
{
    string temp;
    for (size_t i=0; i<_listConnections.size(); i++)
    {

         temp = _listConnections[i].getPersonName();
         string name1 = _listConnections[i].getComputerName();
        _listConnections[i].setPersonName(name1);
        _listConnections[i].setComputerName(temp);
    }
}
