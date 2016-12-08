#ifndef CONNECTION_H
#define CONNECTION_H

//b#include "dbmanager.h"
#include <string>

using namespace std;
class Connection
{
public:
    Connection();
    void setComputerName(const string& input);
    void setPersonName(const string& input);
    string getComputerName();
    string getPersonName();
private:
    string _computerName;
    string _personName;
};

#endif // CONNECTION_H
