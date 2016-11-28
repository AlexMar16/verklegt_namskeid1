#include "person.h"
#include <fstream>
Person::Person()
{
    _gender = 0;
    _birthYear = 0;
    _deathYear = 0;
}
ifstream& operator >> (ifstream& in, Person rhs)
{
    in >> rhs._name >> rhs._gender >> rhs._birthYear >> rhs._deathYear;
    return in;
}
