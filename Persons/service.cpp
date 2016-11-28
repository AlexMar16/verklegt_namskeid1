#include "service.h"
#include <vector>
#include <iosfwd>

using namespace std;

service::service()
{

}

void service::sort_alphabetically(vector<Person>& list)
{
  /*  char letter;
    for (int i=0; i < list.size(); i++)
    {
        letter = list[i].name;
    }*/

}

char service::get_letter(Person p, int nr)
{

    return 0;//p._name.at(nr);
}

void service::initalize_list(vector<Person>&)
{
    dataAccess temp;
     listV = temp.getVector();
}
