#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;


class Person
{
public:
    Person();
    friend ifstream& operator >> (ifstream& in, Person rhs);
<<<<<<< HEAD
    string get_name();
=======
    friend ofstream& operator << (ofstream& out, Person rhs);
>>>>>>> 4f61e59cd9b8b455590d34716794d1dc4203d1b6
private:
    string _name;
    string _name1;
    string _name2;
    string _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
