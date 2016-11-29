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
    friend ostream& operator << (ostream& out, const Person& rhs);
    friend fstream& operator >> (fstream& in, Person& rhs);
    friend ostream& operator <<(ostream& out, vector<Person>& rhs);

private:
    string _firstName;
    string _secondName;
    string _thirdName;
    string _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
