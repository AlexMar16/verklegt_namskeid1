#ifndef CONNECTION_H
#define CONNECTION_H
#include <vector>

//#include "dbmanager.h"
#include <string>

using namespace std;
class Connection
{
public:
    Connection();
    void setToName(const string& input);
    void setFromName(const string& input);
    void setConnectionID(const int& input);
    void setToID(const int& input);
    void setFromID(const int& input);
    int getConnectionID() const;
    int getToID() const;
    int getFromID() const;
    string getToName();
    string getFromName();
    friend ostream& operator << (ostream& out, const Connection& rhs);
    //friend ifstream& operator >> (ifstream& in, Connection& rhs);
    friend ostream& operator << (ostream& out, vector<Connection>& rhs);


private:
    string _from;
    string _to;
    int _ConnectionID;
    int _ToID;
    int _FromID;
};

#endif // CONNECTION_H
