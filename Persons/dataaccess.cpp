#include "dataaccess.h"

const string FILENAME = "inso.txt";

dataAccess::dataAccess()
{
    getPersons();
}

vector<Person> dataAccess::getVector() const {return _persons;}

void dataAccess::getPersons()
{
    ifstream personFile;
    personFile.open(FILENAME);
    if(personFile)
    {
        Person temp;
        while(personFile >> temp)
        {
            _persons.push_back(temp);
        }
    }
    personFile.close();
}

void dataAccess::changeFile()
{
    ofstream newPerson;
    newPerson.open(FILENAME);
    if(newPerson)
    {
        for(size_t i = 0; i < _persons.size(); i++)
        {
            newPerson << _persons[i].getName() << endl << _persons[i].getGender()
                      << endl <<_persons[i].getBirthYear() << endl;
            if(_persons[i].getDeathYear() != ALIVE)
            {
                newPerson << _persons[i].getDeathYear() << endl;
            }
        }
    }
    newPerson.close();
}

void dataAccess::setVector(vector<Person> input)
{
    _persons = input;
}
