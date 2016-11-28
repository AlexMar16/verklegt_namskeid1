#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"

class service
{
public:
    service();
    void sort_alphabetically(vector<Person>& list);
    char get_letter(Person p, int nr);

};

#endif // SERVICE_H
