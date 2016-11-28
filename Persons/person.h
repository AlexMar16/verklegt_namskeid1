#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;


class Person
{
public:
    Person();
    friend ifstream& operator >> (ifstream& in, Person rhs);
    string get_name() const;
    string getGender() const;
    int getBirthYear() const;
    int getDeath() const;
    friend ofstream& operator << (ofstream& out, Person rhs);
private:
    string _name;
    string _name1;
    string _name2;
    string _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
