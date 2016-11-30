#include "dataaccess.h"
#include <fstream>

dataAccess::dataAccess()
{
    getPersons();
    getQuestions();
}

vector<Person> dataAccess::getVector()
{
    return _persons;
}
vector<Question> dataAccess::getquestionVector()
{
    //cout << "dataaccess get qestion vector " << endl;
    return _questions;
}
void dataAccess::getPersons()
{
    ifstream personFile;

    personFile.open("E:/forrit/Git/verklegt_namskeid1/info.txt");

    if(personFile)
    {
        Person temp;
        while(personFile >> temp)
        {
            _persons.push_back(temp);
        }
    }
}

void dataAccess::getQuestions()
{
    ifstream questionFile;

    //cout << "dataaccess getquestions() " << endl;
    questionFile.open("E:/forrit/Git/verklegt_namskeid1/info.txt");

    if(questionFile)
    {
        //cout << "dataaccess if question file " << endl;
        Question temp;
        while(questionFile >> temp)
        {
            //cout << "dataaccess while questionfle >> temp " << endl;
            _questions.push_back(temp);
        }
    }
}

void dataAccess::addPerson()
{
    ofstream newPerson;

    newPerson.open("C:/Users/Rabo/HR/onn1/Verklegt Namskeid/verklegt_namskeid1/build-Persons-Desktop_Qt_5_7_0_MinGW_32bit-Debug/info.txt");

    if(newPerson)
    {
        for(size_t i = 0; i < _persons.size(); i++)
        {
            newPerson << _persons[i].get_name() << endl << _persons[i].getGender()
                      << endl <<_persons[i].getBirthYear() << endl;
            if(_persons[i].getDeath() != '0')
            {
                newPerson << _persons[i].getDeath() << endl;
            }
        }
    }
}
void dataAccess::setVector(vector<Person> input)
{
    _persons = input;
}
void dataAccess::setquestionVector(vector<Question> input)
{
    _questions = input;
}
