#include "dataaccess.h"

const string FILENAME = "info.txt";

dataAccess::dataAccess()
{
    getPersons();
}

vector<Person> dataAccess::getVector()
{
    return _persons;
}
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



void dataAccess::addPerson()
{
    ofstream newPerson;

    newPerson.open(FILENAME);


    if(newPerson)
    {
        for(size_t i = 0; i < _persons.size(); i++)
        {
            newPerson << _persons[i].getName() << endl << _persons[i].getGender()
                      << endl <<_persons[i].getBirthYear() << endl;
            if(_persons[i].getDeathYear() != '0')
            {
                newPerson << _persons[i].getDeathYear() << endl;
            }
        }
    }

    newPerson.close();
}

void dataAccess::removePerson()
{
    ofstream removePerson;

    removePerson.open(FILENAME);

    if(removePerson)
    {
        for(size_t i = 0; i < _persons.size(); i++)
        {
            removePerson << _persons[i].getName() << endl << _persons[i].getGender()
                      << endl <<_persons[i].getBirthYear() << endl;
            if(_persons[i].getDeathYear() != '0')
            {
                removePerson << _persons[i].getDeathYear() << endl;
            }
        }
    }

    removePerson.close();
}

void dataAccess::setVector(vector<Person> input)
{
    _persons = input;
}
