#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "person.h"
#include "question.h"

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
    vector<Question> _questions;
    void getPersons();
    void getQuestions();
};

#endif // DATAACCESS_H
