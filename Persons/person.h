#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <vector>
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
    friend ofstream& operator << (ofstream& out, const Person& rhs);
    friend ifstream& operator >> (ifstream& in, Person& rhs);

private:
    string _firstName;
    string _surname;
    string _lastName;
    string _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
