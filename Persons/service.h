#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    void swap(Person& a, Person& b);
    void setCommand(string command);    
    void addPerson(Person input);
    void removefromdatabase(string name);
    void removePerson(Person input);
    bool alreadyInDatabase(string name);
    Person findPersonExactly(string name);
    vector<Person> findPerson(string name);
    vector<Person> sortAlphabetically();
    vector<Person> getList();
    vector<Person> sortBirthYear();
    vector<Person> sortDeath();
    vector<Person> sortGender();
    vector<Person> sortNumerically();
    bool lookForPerson(string name);
    void displayList();
    void setProgram(bool input);
    bool getProgram();
    string getLastName(const string& nafn);
    vector<Person> sortAlphabeticallyLast();

    Person generateQuestion();
    void generateOptions(const Person& correct, string& a, string& b, string& c, string& d);
    string assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d);
    string genderCheck(const Person& p);
    string aliveCheck(const Person& p);

private:
    vector<Person> _listV;
    vector<Person> _listSearchedPerson;
    //vector<Question> _listQuestions;
    string _command;
    bool _keepGoing;
    bool _valid;
    bool _program;
    int randomNumberGenerator();
};

#endif // SERVICE_H
