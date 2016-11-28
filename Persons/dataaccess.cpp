#include "dataaccess.h"
#include <fstream>
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
    personFile.open("info.txt");

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
   /* ofstream newPerson;
    newPerson.open("info.txt");

    if(newPerson)
    {
        for(size_t i = 0; i < _persons.size(); i++)
        {
            newPerson << s
        }
    }*/
}
