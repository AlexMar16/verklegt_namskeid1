#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    void sort_alphabetically(vector<Person>& list);
    void initalize_list(vector<Person>&);
    void swap(string& a, string& b);

private:
    vector<Person> listV;
};

#endif // SERVICE_H
