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
        string save = listV[0].get_name();
        again = false;
        for (unsigned int i=0; i < listV.size()-1; i++)
        {
            again = false;
            if (listV[i].get_name() > listV[i+1].get_name())
            {
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
    }
}

void service::initalize_list()
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


























































