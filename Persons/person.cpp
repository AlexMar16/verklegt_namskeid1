#include "person.h"

Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}
ifstream& operator >> (ifstream& in, const Person& rhs)
{
    in >> rhs._firstName >> rhs._secondName >> rhs._thirdName >> rhs._gender
       >> rhs._birthYear >> rhs._deathYear;
    return in;
}

ostream& operator << (ostream& out, const Person& rhs);
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
    if(_thirdName != "0")
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
