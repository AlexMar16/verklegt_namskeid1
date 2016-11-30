#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


class Person
{
public:
    Person();
    string getName() const;
    string getGender() const;
    int getBirthYear() const;
    int getDeathYear() const;
    void setName(const string input);
    void setGender(const string input);
    void setBirthYear(const int input);
    void setDeathYear(const int input);
    friend ostream& operator << (ostream& out, const Person& rhs);
    friend ifstream& operator >> (ifstream& in, Person& rhs);
    friend istream& operator >> (istream& in, Person& rhs);
    friend ostream& operator << (ostream& out, vector<Person>& rhs);
    friend ostream& operator << (ostream& out, const Person& rhs);

private:
    string _fullName;
    string _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
