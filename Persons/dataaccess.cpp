#include "dataaccess.h"

dataAccess::dataAccess()
{
    getPersons();
    //getQuestions();
}

vector<Person> dataAccess::getVector()
{
    return _persons;
}
void dataAccess::getPersons()
{
    ifstream personFile;
    personFile.open("C:/Users/Sindri/verklegt_namskeid1/verklegt_namskeid1/Persons/info.txt");
    if(personFile)
    {
        Person temp;
        while(personFile >> temp)
        {
            _persons.push_back(temp);
        }
    }
}

/*void dataAccess::getQuestions()
{
    ifstream questionFile;
    questionFile.open(
"study.txt");
    if(questionFile)
    {
        Question temp;
        while(questionFile >> temp && !questionFile.eof()) //Var ad lesa inn eitt auka tomt gildi svo eg baetti vid eof. kv sindri
        {
            _questions.push_back(temp);
        }
    }
}*/

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
