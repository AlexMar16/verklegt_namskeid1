#include "service.h"
#include <vector>
#include <iosfwd>

using namespace std;

service::service()
{

}

void service::sort_alphabetically()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (unsigned int i=0; i<listV.size()-1; i++)
        {
            if (listV[i].get_name() > listV[i+1].get_name())
            {
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
    }
}

void service::sort_numerically()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (unsigned int i=0; i<listV.size()-1; i++)
        {
            if (listV[i].get_name() > listV[i+1].get_name())
            {
                swap(listV[i], listV[i+1]);
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
string Person::get_name() const
{return _name;}
