#include "person.h"
#include <fstream>

Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}
ifstream& operator >> (ifstream& in, const Person& rhs)
{
    in >> rhs._firstName >> rhs._surname >> rhs._lastName >> rhs._gender >> rhs._birthYear >> rhs._deathYear;
    return in;
}

string Person::get_name()
{
    string fullName;
    fullName = _firstname + " " +  _surname;
    if(_name2 != "0")
    {
        fullName += " " + _lastName;
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
