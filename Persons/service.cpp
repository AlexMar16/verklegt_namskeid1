#include "service.h"
#include <vector>
#include <iosfwd>

using namespace std;

service::service()
{

}

void service::sort_alphabetically(vector<Person>& list)
{
    bool again = true;
    while (again)
    {
        again = false;
        for (unsigned int i=0; i<list.size()-1; i++)
        {
            again = false;
            if (list[i].get_name() > list[i+1].get_name())
            {
                swap(list[i], list[i+1]);
                again = true;
            }
        }
    }
}

void service::initalize_list(vector<Person>& listV)
{
    dataAccess temp;
    listV = temp.getVector();
}

void service::swap(Person& a, Person& b)
{
    Person temp = a;
    a = b;
    b = temp;
}

void Person::get_list()
{
   return listV;

}


























































