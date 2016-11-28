#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    void sort_alphabetically(vector<Person>& list);
    char get_letter(Person p, int nr);
    void initalize_list(vector<Person>&);

private:
    vector<Person> listV;
};

#endif // SERVICE_H
