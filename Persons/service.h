#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    bool lookForPerson(const string& name);
    bool getProgram() const;
    Person findPersonExactly(const string& name);
    Person generateQuestion();
    vector<int> properties();
    vector<Person> findPerson(const string& name);
    vector<Person> getList() const;
    void addPerson(const Person& input);
    void removePerson(const Person& input);
    void sortList(const string& command);
    void setProgram(const bool& input);
    void generateOptions(const Person& correct, string& a, string& b, string& c, string& d);
    string getLastName(const string& name) const;
    string toLower(const string &tolowerstring);
    string assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d);
    string genderCheck(const Person& p);
    string aliveCheck(const Person& p);

    bool filefound();
private:
    bool _keepGoing;
    bool _valid;
    bool _program;
    bool alreadyInDatabase(const string &name);
    bool _filefound;
    vector<Person> _listV;
    vector<Person> _listSearchedPerson;
    vector<Person> sortAlphabetically();
    vector<Person> sortBirthYear();
    vector<Person> sortDeath();
    vector<Person> sortGender();
    vector<Person> sortNumerically();
    vector<Person> sortAlphabeticallyLastName();
    void removeFromDatabase(const string& name);
    void swap(Person& a, Person& b);
};

#endif // SERVICE_H
