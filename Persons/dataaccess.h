#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "person.h"
#include "quiz.h"

using namespace std;


class dataAccess
{
public:
    dataAccess();
    vector<Person> getVector();
    //vector<Question> getquestionVector();
    void setVector();
    //void setquestionVector(vector<Question> input);
    void addPerson();

    void setVector(vector<Person> input);
private:
    vector<Person> _persons;
    //vector<Question> _questions;
    void getPersons();
    void getQuestions();
};

#endif // DATAACCESS_H
