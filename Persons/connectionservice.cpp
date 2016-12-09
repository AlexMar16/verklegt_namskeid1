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

vector<Connection> connectionService::findConnection(const string &name)      // Finds people and adds them to the vector
{
    cout << "aaa";
    _listSearchedConnections.clear();
    cout << "bbb";
    generalService GS;
    cout << "ccc";
    cout << _listConnections.size();
    for (size_t i = 0; i < _listConnections.size(); i++)
    {
        if (GS.toLower(_listConnections[i].getPersonName()).find(GS.toLower(name)) != string::npos)       // Puts both instances to lowercase
        {
            _listSearchedConnections.push_back(_listConnections[i]);       // Puts people in the list who apply to the input
        }
    }

    return _listConnections;
}
