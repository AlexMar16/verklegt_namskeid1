#ifndef PersonService_H
#define PersonService_H
//#include "person.h"
//#include "computer.h"
#include "generalservice.h"
#include "dbmanager.h"

class PersonService
{
public:
    PersonService();
    bool lookForPerson(const string& name);
    Person findPersonExactly(const string& name);
    Person generateQuestion();
    vector<int> properties();
    vector<Person> findPerson(const string& name);
    vector<Person> getPersonList() const;
    void addPerson(const Person& input);
    void addComputer(const Computer& input);
    void removePerson(const Person& input);
    void sortPersonList(const string& command);
    void generateOptions(const Person& correct, string& a, string& b, string& c, string& d);
    void reverseVector();
    string getLastName(const string& name) const;
    string toLower(const string &tolowerstring);
    string assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d);
    string genderCheck(const Person& p);
    string aliveCheck(const Person& p);

private:
    bool alreadyInDatabase(const string &name);
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

    generalService GS;
};

#endif // PersonService_H
