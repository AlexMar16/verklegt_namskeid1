#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    void initalize_list(vector<Person>&);
    void swap(Person& a, Person& b);
    void initalize_list();
    void setCommand(string command);    
    bool validList();
    vector<Person> displayList();
    vector<Person> sort_alphabetically();
    vector<Person> get_list();
    vector<Person> sort_BirthYear();
    vector<Person> sort_death();
    vector<Person> sort_gender();
    vector<Person> find_person(const string& name);
    vector<Person> sort_numerically();
    vector<Person> displayList(string command);


private:
    vector<Person> listV;
    string _command;
    bool _keepGoing;
    bool _valid;
};

#endif // SERVICE_H
