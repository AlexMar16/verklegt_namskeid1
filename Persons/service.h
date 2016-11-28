#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    vector<Person> sort_alphabetically();
    void initalize_list();
    void swap(Person& a, Person& b);
    vector<Person> get_list();
    vector<Person> sort_BirthYear();
    vector<Person> sort_death();
    vector<Person> sort_gender();


private:
    vector<Person> listV;
};

#endif // SERVICE_H
