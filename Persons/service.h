#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

//#include <string>

//using namespace std;

class service
{
public:
    service();
    void swap(Person& a, Person& b);
    void setCommand(string command);    
    void addPerson(Person input);
    bool alreadyInDatabase(string name);
    vector<Person> findPerson(string name);
    vector<Person> sortAlphabetically();
    vector<Person> getList();
    vector<Person> sortBirthYear();
    vector<Person> sortDeath();
    vector<Person> sortGender();
    vector<Question> getListQuestions();
    bool lookForPerson(string name);
    vector<Person> sortNumerically();
    void displayList();
    void setProgram(bool input);
    bool getProgram();
    string getLastName(const string& nafn);
    vector<Person> sortAlphabeticallyLast();


private:
    vector<Person> _listV;
    vector<Person> _listSearchedPerson;
    vector<Question> _listQuestions;
    string _command;
    bool _keepGoing;
    bool _valid;
    bool _program;
};

#endif // SERVICE_H
