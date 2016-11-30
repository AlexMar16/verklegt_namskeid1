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
    const char DASH = '-';
    const char SPACE = ' ';
    out << left << setw(70) << setfill(DASH) <<  "-" << endl;
    out << left << setw(30) << setfill(SPACE) <<  rhs._fullName;
    out << left << setw(15) << setfill(SPACE) << rhs._gender;
    out << left << setw(15) << setfill(SPACE) << rhs._birthYear;

        if(rhs._deathYear!= 0)
        {
          out << rhs._deathYear << endl;
        }
            else
            {
              out << setw(20) << setfill(SPACE) << "Still alive!" << endl;
            }
     return out;
}

ostream& operator << (ostream& out, vector<Person>& rhs)
{
    const char SPACE = ' ';
    out << left << setw(30) << setfill(SPACE) <<"Name";
    out << left << setw(15) << setfill(SPACE) <<"Gender";
    out << left << setw(15) << setfill(SPACE) <<"BirthYear";
    out << left << setw(20) << setfill(SPACE) <<"Died" << endl;
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
int Person::getDeath() const //Laga nafn kv Sindri
{
    return _deathYear;
}
