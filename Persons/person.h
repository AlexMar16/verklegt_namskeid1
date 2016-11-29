#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

using namespace std;


class Person
{
public:
    Person();    
    string get_name() const;
    string getGender() const;
    int get_birth() const;
    int getBirthYear() const;
    int getDeath() const;
    friend ofstream& operator << (ofstream& out, Person rhs);
    friend ifstream& operator >> (ifstream& in, const Person& rhs);

private:
    string _name;
    string _name1;
    string _name2;
    string _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
