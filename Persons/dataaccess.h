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
    void changeFile();
    void setVector(vector<Person> input);
private:
    vector<Person> _persons;
    void getPersons();
    void getQuestions();
};

#endif // DATAACCESS_H
