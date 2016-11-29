#include "person.h"
#include <fstream>

Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}
fstream& operator >> (fstream& in, const Person& rhs)
{
    string cool;
    in >> cool;
    return in;
}

ostream& operator << (ostream& out, const Person& rhs);

ostream& operator << (ostream& out, const Person& rhs)


string Person::get_name()
{
    return _name;
}


ostream& operator << (ofstream& out, const Person& rhs);
{
    out << "Name: " << rhs._firstName << " " << rhs._secondName << " ";
    if(rhs._thirdName != "0")
    {
        out << rhs._thirdName;
    }
    out << endl;
    out << "Gender: " << rhs._gender << endl;
    out << "Born: " << rhs._birthYear << endl;

        if(rhs._deathYear!= 0)
        {
          out << "Died: " << rhs._deathYear << endl;
        }
            else
            {
              out << "Still alive!" << endl;
            }
                return out;
}

ostream& operator << (ostream& out, vector<Person>& rhs)
{
        for(size_t i = 0; i < rhs.size(); i++)
        {
            out << rhs[i];
        }
        return out;
}


string Person::get_name() const
{
    string fullName;
    fullName = _firstName + " " +  _secondName;
    if(_secondName != "0")
    {
        fullName += " " + _thirdName;
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
