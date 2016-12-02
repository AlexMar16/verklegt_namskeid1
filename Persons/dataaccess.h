#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "person.h"

using namespace std;


class dataAccess
{
public:
    dataAccess();
    vector<Person> getVector() const;
    bool getfilefound();
    void setVector();
    void changeFile();
    void setVector(vector<Person> input);
private:
    bool _fileFound;
    vector<Person> _persons;
    void getPersons();
    void getQuestions();    
};

#endif // DATAACCESS_H
