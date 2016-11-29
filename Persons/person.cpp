#include "person.h"

Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}
ifstream& operator >> (ifstream& in, Person& rhs)
{
    string first, second, third;
    in >> first >> second >> third;
    if(third != "male" && third != "female")
    {
        rhs._fullName = first + " " + second + " " + third;
        in  >> rhs._gender >> rhs._birthYear >> rhs._deathYear;
    }
    else
    {
        rhs._fullName = first + " " + second;
        rhs._gender = third;
        in >> rhs._birthYear >> rhs._deathYear;
    }
    return in;
}

istream& operator >> (istream& in, Person& rhs)
{
    string first, second, third;
    in >> first >> second >> third;
    if(third != "male" && third != "female")
    {
        rhs._fullName = first + " " + second + " " + third;
        in  >> rhs._gender >> rhs._birthYear >> rhs._deathYear;
    }
    else
    {
        rhs._fullName = first + " " + second;
        rhs._gender = third;
        in >> rhs._birthYear >> rhs._deathYear;
    }
    return in;
}

ostream& operator << (ostream& out, const Person& rhs)
{
    out << endl;
    out << "Name: " << rhs._fullName<< endl;
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
    return _fullName;
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
