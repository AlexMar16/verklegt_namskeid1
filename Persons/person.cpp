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
<<<<<<< HEAD
ostream& operator << (ostream& out, const Person& rhs);
=======
<<<<<<< HEAD
ostream& operator << (ostream& out, const Person& rhs)
=======
<<<<<<< HEAD

string Person::get_name()
{
    return _name;
}
ofstream& operator << (ofstream& out, Person rhs)
=======
ofstream& operator << (ofstream& out, const Person& rhs);
>>>>>>> aba2a8b3fd31800005e0d9d5922ec88d0c2ed0b5
>>>>>>> f4a8f42a7c9f2e431ff3b80fbe698e6106ba6dcc
>>>>>>> 9a2babdae8a5415ef08989ebcd19814165985332
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
<<<<<<< HEAD
    ostream& operator << (ostream& out, vector<Person>& rhs)
    {
        for(size_t i = 0; i < rhs.size(); i++)
        {
            out << rhs[i];
        }
        return out;
    }

=======
<<<<<<< HEAD
string Person::get_name() const
=======
<<<<<<< HEAD

=======
>>>>>>> 9a2babdae8a5415ef08989ebcd19814165985332
string Person::get_name()
>>>>>>> f4a8f42a7c9f2e431ff3b80fbe698e6106ba6dcc
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
>>>>>>> aba2a8b3fd31800005e0d9d5922ec88d0c2ed0b5
