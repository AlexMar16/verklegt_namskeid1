#include "person.h"
const int COLUMN_WIDTH = 20;
const int FIVE = 5;
const int TWO = 2;

Person::Person()
{
    _birthYear = 0;
    _deathYear = 0;
}

ostream& operator << (ostream& out, const Person& rhs)
{
    const char DASH = '-';
    out << left << setw(FIVE * COLUMN_WIDTH) << setfill(DASH) <<  DASH << endl;
    out << left << setw(TWO * COLUMN_WIDTH) << setfill(SPACE) <<  rhs._fullName;
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << rhs._gender;
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << rhs._birthYear;

    if(rhs._deathYear!= ALIVE)
    {
        out << setw(COLUMN_WIDTH + FIVE) << setfill(SPACE) << rhs._deathYear << endl;
    }
    else
    {
        out << setw(COLUMN_WIDTH + FIVE) << setfill(SPACE) << "Still alive!" << endl;
    }
    return out;
}

ostream& operator << (ostream& out, vector<Person>& rhs)
{
    out << left << setw(TWO * COLUMN_WIDTH) << setfill(SPACE) << "Name";
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << "Gender";
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << "BirthYear";
    out << left << setw(COLUMN_WIDTH + FIVE) << setfill(SPACE) << "Died" << endl;
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
