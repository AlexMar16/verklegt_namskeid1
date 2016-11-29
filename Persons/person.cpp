#include "person.h"
#include <fstream>

Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}
ifstream& operator >> (ifstream& in, const Person& rhs)
{
    in << rhs._name << rhs._name1 >> rhs._name2 >> rhs._gender >> rhs._birthYear >> rhs._deathYear;
    return in;
}

/*string Person::get_name() const
{return _name;}*/


string Person::get_name()
{
    string fullName;
    fullName = _name + " " +  _name1;
    if(_name2 != "0")
    {
        fullName += " " + _name2;
    }
    return fullName;
}
string Person::getGender() const
{
    return _gender;
}
 int Person::getBirthYear() const
{
    return _birthYear;
}
int Person::getDeath() const
{
    return _deathYear;
}
