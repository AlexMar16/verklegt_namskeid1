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
<<<<<<< HEAD
    vector<Person> find_person(string name);

=======
    vector<Person> find_person(string& name);
>>>>>>> 9a2babdae8a5415ef08989ebcd19814165985332

private:
    vector<Person> listV;
    string _command;
    bool _keepGoing;
    bool _valid;
};

#endif // SERVICE_H
