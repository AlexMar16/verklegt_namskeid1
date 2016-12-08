#include "connection.h"

Connection::Connection() {}

void Connection::setComputerName(const string& input) {_computerName = input;}

void Connection::setPersonName(const string& input) {_personName = input;}

void Connection::setConnectionID(const int& input) {_ConnectionID = input;}

void Connection::setPersonID(const int& input) {_PersonID = input;}

void Connection::setComputerID(const int& input) {_ComputerID = input;}



string Connection::getComputerName() {return _computerName;}

string Connection::getPersonName() {return _personName;}

int Connection::getConnectionID() {return _ConnectionID;}

int Connection::getPersonID() {return _PersonID;}

int Connection::getComputerID() {return _ComputerID;}

