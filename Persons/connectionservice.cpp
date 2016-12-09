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

vector<Connection> connectionService::findConnection(const string &name)      // Finds people and adds them to the vector
{
    _listSearchedConnections.clear();
    generalService GS;
    for (size_t i = 0; i < _listConnections.size(); i++)
    {
        if (GS.toLower(_listConnections[i].getPersonName()).find(GS.toLower(name)) != string::npos)       // Puts both instances to lowercase
        {
            _listSearchedConnections.push_back(_listConnections[i]);       // Puts people in the list who apply to the input
        }
    }

    return _listSearchedConnections;
}

bool connectionService::lookForConnection(const string& name)         // Checks if any part of the name is on the list
{
    generalService GS;
    for (size_t i = 0; i < _listConnections.size(); i++)
    {
        if (GS.toLower(_listConnections[i].getPersonName()).find(GS.toLower(name)) != string::npos)       // Enables us to search in lower case letters.
        {
            return true;
        }
    }
    return false;
}

vector<Connection> connectionService::sortConnectAlphabetically()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listConnections.size() - 1; i++)
        {
            if (_listConnections[i].getPersonName() > _listConnections[i+1].getPersonName())
            {
                swap(_listConnections[i], _listConnections[i+1]);
                again = true;
            }
        }
    }
    return _listConnections;
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
