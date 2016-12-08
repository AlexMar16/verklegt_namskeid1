#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <algorithm>


using namespace std;

const char SPACE = ' '; // All the constants in more than one file.
const int ALIVE = 0;
const string MALE = "Male";
const string FEMALE = "Female";
const string A = "a";
const string B = "b";
const string D = "d";
const string G = "g";
const string L = "l";
const string QUIT = "quit";

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
    friend ostream& operator << (ostream& out, vector<Person>& rhs);

private:
    string _fullName;
    string _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
