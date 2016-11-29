#include "person.h"
#include <fstream>

Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}
ifstream& operator >> (ifstream& in, const Person& rhs)
{
    in >> rhs._firstName >> rhs._secondName >> rhs._thirdName >> rhs._gender >> rhs._birthYear >> rhs._deathYear;
    return in;
}
<<<<<<< HEAD

string Person::get_name()
{
    return _name;
}
ofstream& operator << (ofstream& out, Person rhs)
=======
ofstream& operator << (ofstream& out, const Person& rhs);
>>>>>>> aba2a8b3fd31800005e0d9d5922ec88d0c2ed0b5
{
    out << "Name: " << rhs._firstName << " " << rhs._secondName << " ";
    if(_thirdName != 0)
    {
        out << rhs._thirdName;
    }
    out << endl;
    out << "Gender: " << rhs._gender << endl;
    out << "Born: " << rhs._birthYear << endl;
    if(_deathYear!= 0)
    {
        out << "Died: " << rhs._deathYear << endl;
    }
    else
    {
        out << "Still alive!" << endl;
    }
    return out;
}
<<<<<<< HEAD

=======
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
>>>>>>> aba2a8b3fd31800005e0d9d5922ec88d0c2ed0b5
