#ifndef CONNECTION_H
#define CONNECTION_H
#include <vector>

//b#include "dbmanager.h"
#include <string>

using namespace std;
class Connection
{
public:
    Connection();
    void setComputerName(const string& input);
    void setPersonName(const string& input);
    void setConnectionID(const int& input);
    void setComputerID(const int& input);
    void setPersonID(const int& input);
    int getConnectionID();
    int getComputerID();
    int getPersonID();
    string getComputerName();
    string getPersonName();
    friend ostream& operator << (ostream& out, const Connection& rhs);
    //friend ifstream& operator >> (ifstream& in, Connection& rhs);
    friend ostream& operator << (ostream& out, vector<Connection>& rhs);


private:
    string _computerName;
    string _personName;
    int _ConnectionID;
    int _ComputerID;
    int _PersonID;
};

#endif // CONNECTION_H
