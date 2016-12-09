#include "connection.h"
#include "computer.h"
#include "person.h"
const int COLUMN_WIDTH = 30;
const int FIVE = 3;
const int TWO = 2;

Connection::Connection() {}

void Connection::setComputerName(const string& input) {_to = input;}

void Connection::setPersonName(const string& input) {_from = input;}

void Connection::setConnectionID(const int& input) {_ConnectionID = input;}

void Connection::setPersonID(const int& input) {_PersonID = input;}

void Connection::setComputerID(const int& input) {_ComputerID = input;}



string Connection::getComputerName() {return _to;}

string Connection::getPersonName() {return _from;}

int Connection::getConnectionID() {return _ConnectionID;}

int Connection::getPersonID() {return _PersonID;}

int Connection::getComputerID() {return _ComputerID;}

ostream& operator << (ostream& out, const Connection& rhs)
{
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) <<  rhs._from;
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << rhs._to << endl;
    //_lastComputerName= rhs._from;
    return out;
}

ostream& operator << (ostream& out, vector<Connection>& rhs)
{
    const char DASH = '-';
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << "Computer Scientist";
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << "Computer" << endl;
    for(size_t i = 0; i < rhs.size(); i++)
    {
        if(!(i != 0 && rhs[i]._from == rhs[i-1]._from))
        {
            out << left << setw(FIVE * COLUMN_WIDTH + FIVE) << setfill(DASH) <<  DASH << endl;
            out << rhs[i];
        }
        else
        {
            out << left << setw(COLUMN_WIDTH) << setfill(SPACE);
            out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << ""
                << left << rhs[i]._to << endl;
        }

    }
    out << endl;
    return out;
}
