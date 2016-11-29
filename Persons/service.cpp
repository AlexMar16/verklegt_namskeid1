#include "service.h"
#include <vector>
#include <iosfwd>
#include <person.h>
#include <iostream>
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
                //swap(list[i].get_name(), list[i+1].get_name());
                cout << list[i].get_name();
                cout << list[i+1].get_name();
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

void service::swap(string& a, string& b)
{
    string temp = a;
    a = b;
    b = temp;
}
