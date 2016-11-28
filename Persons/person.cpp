#include "person.h"
#include <fstream>
Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}
ifstream& operator >> (ifstream& in, Person rhs)
{
    in >> rhs._name >> rhs._name1 >> rhs._name2 >> rhs._gender >> rhs._birthYear >> rhs._deathYear;
    return in;
}

string Person::get_name() const
{return _name;}

ofstream& operator << (ofstream& out, Person rhs)
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

