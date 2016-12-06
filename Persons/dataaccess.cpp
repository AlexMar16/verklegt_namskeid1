#include "dataaccess.h"

const string FILENAME = "info.txt";

dataAccess::dataAccess()
{
    _fileFound = false;
    getPersons();
}

bool dataAccess::getFileFound() const {return _fileFound;}

//vector<Person> dataAccess::getVector() const {return gs;}

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
        _fileFound = true;
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
            else
            {
                newPerson << ALIVE << endl;
            }
        }
    }
    newPerson.close();
}

void dataAccess::setVector(vector<Person> input) {_persons = input;}
