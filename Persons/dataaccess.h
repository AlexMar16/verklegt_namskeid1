#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "person.h"

using namespace std;


class dataAccess
{
public:
    dataAccess();
    vector<Person> getVector();
    void setVector();
    void addPerson();
    void setVector(vector<Person> input);
private:
    vector<Person> _persons;
    void getPersons();
};

#endif // DATAACCESS_H
