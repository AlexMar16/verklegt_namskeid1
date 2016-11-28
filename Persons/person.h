#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;


class Person
{
public:
    Person();
    friend ifstream& operator >> (ifstream& in, Person rhs);
private:
    string _name;
    char _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
