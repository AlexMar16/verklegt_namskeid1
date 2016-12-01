#include "person.h"

Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}
ifstream& operator >> (ifstream& in, Person& rhs)
{
    getline(in, rhs._fullName);
    getline(in, rhs._gender);
    in >> rhs._birthYear;
    in >> rhs._deathYear;
    in.ignore();

    return in;
}

ostream& operator << (ostream& out, const Person& rhs)
{
    const char DASH = '-';
    const char SPACE = ' ';
    out << left << setw(75) << setfill(DASH) <<  "-" << endl;
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
    out << endl;
    return out;
}
//Get functions
string Person::getName() const {return _fullName;}
string Person::getGender() const {return _gender;}
int Person::getBirthYear() const {return _birthYear;}
int Person::getDeathYear() const {return _deathYear;}
//Set functions
void Person::setName(const string input) {_fullName = input;}
void Person::setGender(const string input){_gender = input;}
void Person::setBirthYear(const int input){_birthYear = input;}
void Person::setDeathYear(const int input){_deathYear = input;}
