#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    void initalize_list();
    void swap(Person& a, Person& b);
    void setCommand(string command);
    bool displayList();
    bool validList();
    vector<Person> sort_alphabetically();
    vector<Person> get_list();
    vector<Person> sort_BirthYear();
    vector<Person> sort_death();
    vector<Person> sort_gender();


private:
    vector<Person> listV;
    string _command;
    bool _keepGoing;
};

#endif // SERVICE_H
