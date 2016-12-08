#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H
#include "connection.h"
#include "dbmanager.h"

class connectionService
{
public:
    connectionService();
private:
    vector<Connection> _listConnections;
};

#endif // CONNECTIONSERVICE_H
