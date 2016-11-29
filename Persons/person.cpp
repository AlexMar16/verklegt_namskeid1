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

ofstream& operator << (ofstream& out, Person rhs)

string Person::get_name() const
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
ofstream& operator << (ofstream& out, Person& rhs)

{
    out <<"Name: "<< rhs._name << " " << rhs._name1;
    if(rhs._name2 != "0")
    {
        out << " " << rhs._name2;
    }
    out << endl;
    out << "Gender: " << rhs._gender << endl;
    out << "Birth Year: " << rhs._birthYear << endl;
    if(rhs._deathYear != 0)
    {
        out << "Died: " << rhs._deathYear << endl;
    }
    return out;
}

