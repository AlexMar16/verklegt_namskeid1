#include "connection.h"

Connection::Connection() {}

void Connection::setComputerName(const string& input) {_computerName = input;}

void Connection::setPersonName(const string& input) {_personName = input;}

string Connection::getComputerName() {return _computerName;}

string Connection::getPersonName() {return _personName;}
