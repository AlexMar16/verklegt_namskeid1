#include "service.h"
#include <vector>
#include <iosfwd>

using namespace std;

service::service()
{

}

vector<Person> service::sort_alphabetically()
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

vector<Person> service::get_list()
{
   return listV;
}

vector<Person> service::sort_BirthYear()
{
    bool again = true;
    while (again)
    {
        string save = listV[0].getBirthYear  ;
        again = false;
        for (size_t i=0; i < listV.size()-1; i++)
        {
            again = false;
            if (listV[i].getBirthYear() > listV[i+1].getBirthYear())
            {
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
    }
}

vector<Person> service::sort_death()
{

    for(size_t i= 0; i< listV; i++)
    {
        if(_deathYear>0)
        {
           if(listV[i].get_Death()> listV[i+1].get_death())
           {
              swap(listV[i], listV[i+1]);
           }
        }
    }

    return listV;

}



























































