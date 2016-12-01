#include "dataaccess.h"

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
    personFile.open("C:/Users/Rabo/HR/onn1/Verklegt Namskeid/verklegt_namskeid1/build-Persons-Desktop_Qt_5_7_0_MinGW_32bit-Debug/info.txt");
    if(personFile)
    {
        Person temp;
        while(personFile >> temp)
        {
            _persons.push_back(temp);
        }
    }
}


void dataAccess::addPerson()
{
    ofstream newPerson;

    newPerson.open("info.txt");

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
}
void dataAccess::setVector(vector<Person> input)
{
    _persons = input;
}
