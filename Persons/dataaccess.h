#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "person.h"
#include <vector>

using namespace std;


class dataAccess
{
public:
    dataAccess();
    vector<Person> getVector();
private:
    vector<Person> _persons;
    void getPersons();
};

#endif // DATAACCESS_H
