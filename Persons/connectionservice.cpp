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
        swappedList = false;
        return true;
    }
    else if (GS.toLower(command) == "computer to person")
    {
        swappedList = true;
        swapToFrom();
        return true;
    }
    else
    {
        return false; //einhver að vinna að villuchecki eftir þetta
    }
}

bool connectionService::getSwappedList() const {return swappedList;}


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
