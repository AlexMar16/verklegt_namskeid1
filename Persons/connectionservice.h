#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H
#include "connection.h"
#include "generalService.h"
#include "dbmanager.h"

class connectionService
{
public:
    connectionService();
   // void connectionService::removeFromDatabase(const string &name);
   // void connectionService::addConnection(const Connection &input);
    bool personORComputer(const string& command);
    vector<Connection> getConnectionList() const;
private:
    vector<Connection> _listConnections;
    string _connectFrom;
};

#endif // CONNECTIONSERVICE_H
