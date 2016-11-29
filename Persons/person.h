#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;


class Person
{
public:
    Person();
    friend ifstream& operator >> (ifstream& in, const Person& rhs);
    string get_name() const;
<<<<<<< HEAD
    int get_birth() const;
    friend ofstream& operator << (ofstream& out, Person rhs);
=======
    string getGender() const;
    int getBirthYear() const;
    int getDeath() const;
    friend ofstream& operator << (ofstream& out, Person& rhs);
>>>>>>> 9e6f16749b527d7465dde0f025a62925340afb08
private:
    string _name;
    string _name1;
    string _name2;
    string _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
