#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    void sort_alphabetically();
    void initalize_list();
    void swap(Person& a, Person& b);

private:
    vector<Person> listV;
};

#endif // SERVICE_H
