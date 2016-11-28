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
        string save = list[0].get_name();
        again = false;
        for (unsigned int i=0; i < list.size()-1; i++)
        {
            again = false;
            if (list[i].get_name() > list[i+1].get_name())
            {
                swap(save, list[i+1].get_name());
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
