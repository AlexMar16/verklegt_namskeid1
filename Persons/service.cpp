#include "service.h"
#include <vector>
#include <iosfwd>
#include <person.h>
#include <iostream>

using namespace std;

service::service(){
    dataAccess temp;
    _listV = temp.getVector();
    _listSearchedPerson = temp.getVector();
    _listSearchedPerson.clear();
    _program = true;
}
void service::swap(Person& a, Person& b)
{
    Person temp = a;
    a = b;
    b = temp;
}

vector<Person> service::getList()
{
   return _listV;
}

vector<Question> service::getListQuestions()
{
    return _listQuestions;
}

void service::displayList()// depending on input from user, do something
{
    if(_command == "a")
    {
        _listV = sortAlphabetically();
    }
    else if(_command == "l")
    {
        _listV = sortAlphabeticallyLast();
    }
    else if(_command == "b")
    {
        _listV = sortBirthYear();
    }
    else if(_command == "d")
    {
        _listV = sortDeath();
    }
    else if(_command == "g")
    {
        _listV = sortGender();
    }
    else if(_command == "quit")
    {
        _program=false;
    }
}

void service::setCommand(string c)
{
    _command = c;
}

vector<Person> service::sortGender()//sorts the females in the list to the top
{
    int counter = 0;
    for(size_t i=0; i< _listV.size(); i++)
    {
        if(_listV[i].getGender() == "female")
        {
           swap(_listV[i], _listV[counter]);
           counter++;
        }
    }
    return _listV;
}
void service::addPerson(Person input)//makes the user capable to add people as long as they're not already on the list
{
    if(!alreadyInDatabase(input.getName()))
    {
        dataAccess addNew;
        _listV.push_back(input);
        addNew.setVector(_listV);
        addNew.addPerson();
    }
}


vector<Person> service::sortAlphabetically()//insertion sort
{
    bool again = true;
    while (again)
    {        
        again = false;
        for (unsigned int i=0; i< _listV.size()-1; i++)
        {
            if (_listV[i].getName() > _listV[i+1].getName())
            {
                swap(_listV[i], _listV[i+1]);
                again = true;
            }
        }
    }
    return _listV;
}

vector<Person> service::sortAlphabeticallyLast()
{
    string nafn1;
    string nafn2;
    bool again = true;
    while (again)
    {
        again = false;
        for (unsigned int i=0; i< _listV.size()-1; i++)
        {
            nafn1= _listV[i].getName();
            nafn2= _listV[i+1].getName();

            if (getLastName(nafn1) > getLastName(nafn2))   //bera saman last name
            {
                swap( _listV[i], _listV[i+1]);
                again = true;
            }
        }
    }
    return _listV;
}

string service::getLastName(const string& nafn)
{

    int Li=0;
    string LastName;
    for (size_t i=0; i<nafn.size(); i++)
    {
        if (nafn[i]==' ')
        {
            Li=i+1;
        }
    }
    for (size_t i=Li; i<nafn.size(); i++)
    {
        LastName += nafn[i];
    }
    return LastName;
}

vector<Person> service::sortBirthYear()
{
        bool again = true;
        while (again)
        {
        again = false;
        for (size_t i=0; i < _listV.size()-1; i++)
        {
            if ( _listV[i].getBirthYear() > _listV[i+1].getBirthYear())            //sama fall og fyrir ofan!!!
            {
                swap(_listV[i], _listV[i+1]);
                again = true;
            }
        }
    }
    return _listV;
}

bool service::alreadyInDatabase(string name)
{
    for (size_t i=0; i< _listV.size(); i++)
    {
        if (_listV[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}

vector<Person> service::findPerson(string name)
{
    _listSearchedPerson.clear();
    for (size_t i=0; i< _listV.size(); i++)
    {
        if (_listV[i].getName().find(name) != string::npos)
        {
            _listSearchedPerson.push_back(_listV[i]);
        }
    }
    return _listSearchedPerson;
}

bool service::lookForPerson(string name)
{
    bool foundname = false;
    for (size_t i=0; i< _listV.size(); i++)
    {
        if (_listV[i].getName().find(name) != string::npos)
        {
            foundname = true;
        }
    }
    return foundname;
}

vector<Person> service::sortDeath()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (unsigned int i=0; i< _listV.size()-1; i++)
        {
            if (_listV[i].getDeathYear() < _listV[i+1].getDeathYear())
            {
                swap(_listV[i], _listV[i+1]);
                again = true;
            }
        }
    }
    return _listV;
}
void service::setProgram(bool input)
{
    _program = input;
}

bool service::getProgram()
{
    return _program;
}



