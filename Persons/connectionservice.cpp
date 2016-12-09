#include "connectionservice.h"

connectionService::connectionService()      // Gets the vector containing the appropriate information about the computers or scientists.
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

bool connectionService::personORComputer(const string& command)         // Enables the user to select either a list of scientists
{                                                                       // and their connections to computers or vice versa.
    generalService GS;
    if (GS.toLower(command) == "person to computer" || GS.toLower(command) == "ptc")
    {
        _swappedList = false;
        return true;
    }
    else if (GS.toLower(command) == "computer to person" || GS.toLower(command) == "ctp")
    {
        _swappedList = true;
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
        if (GS.toLower(_listConnections[i].getFromName()).find(GS.toLower(name)) != string::npos)       // Puts both instances to lowercase
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
        if (GS.toLower(_listConnections[i].getFromName()).find(GS.toLower(name)) != string::npos)       // Enables us to search in lower case letters.
        {
            return true;
        }
    }
    return false;
}

vector<Connection> connectionService::sortConnectAlphabetically()       // Sorts the list of scientists or computers alphabetically.
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listConnections.size() - 1; i++)
        {
            if (_listConnections[i].getFromName() > _listConnections[i+1].getFromName())
            {
                swap(_listConnections[i], _listConnections[i+1]);
                again = true;
            }
        }
    }
    return _listConnections;
}


bool connectionService::getSwappedList() const {return _swappedList;}       // Checks if lists have been swapped.


void connectionService::swapToFrom()                             // Swaps the persons list for the computer list.
{
    string temp;
    for (size_t i=0; i<_listConnections.size(); i++)
    {

         temp = _listConnections[i].getFromName();
         string name1 = _listConnections[i].getToName();
        _listConnections[i].setFromName(name1);
        _listConnections[i].setToName(temp);
    }
}

bool connectionService::fromInDatabase(const string& name)  // Checks if the name exists in the database
{
    for (size_t i = 0; i < _listConnections.size(); i++)
    {
        if (_listConnections[i].getFromName() == name)
        {
            return true;
        }
    }
    return false;
}

bool connectionService::toInDatabase(const string& name)  // Checks if the name exists in the database
{
    for (size_t i = 0; i < _listConnections.size(); i++)
    {
        if (_listConnections[i].getToName() == name)
        {
            return true;
        }
    }
    return false;
}

void connectionService::addNewConnection(const string& from, const string& to)   // Function used to add a new connection.
{
    DbManager newConnection;
    generalService getID;
    Connection newC;
    int fromID = getID.findID(from);
    int toID = getID.findID(to);
    cout << "toID" << toID << ", fromID =" << fromID;

    newC.setFromID(fromID);
    newC.setToID(toID);
    newC.setFromName(from);
    newC.setToName(to);
    _listConnections.push_back(newC);
    newConnection.insertIntoConnection(newC, _swappedList);

}

string connectionService::getWhichIsFrom()
{
    if (_swappedList == false)
    {
        return "person";
    }
    else
    {
        return "computer";
    }
}

string connectionService::getWhichIsTo()
{
    if (_swappedList == false)
    {
        return "computer";
    }
    else
    {
        return "person";
    }
}
