#include "service.h"
#include <vector>
#include <iosfwd>
#include <person.h>
#include <iostream>

using namespace std;

service::service(){
    dataAccess temp;
    listV = temp.getVector();
    listsearchedperson = temp.getVector();
    listsearchedperson.clear();
    _program = true;
}
void service::swap(Person& a, Person& b)
{
    Person temp = a;
    a = b;
    b = temp;
}

vector<Person> service::get_list()
{
   return listV;
}

vector<Person> service::displayList(string command)// depending on input from user, do something
{
    if(_command == "list")
    {
        return listV;
    }
    else if(_command == "sorta")
    {
        return sort_alphabetically();
    }
    else if(_command == "sortb")
    {
        return sort_BirthYear();
    }
    else if(_command == "sortd")
    {
        return sort_death();
    }
    else if(_command == "sortg")
    {
        return sort_gender();
    }
}

bool service::validList()// depending on input from user, do something
{
    if(_command == "list")
    {
        return true; //dont change list
    }
    else if(_command == "add")
    {
        //Person person(string _name,char _gender int _birthYear, int _deathYear) todo
        return true;
    }
    else if(_command == "sorta")
    {

        return true;
    }
    else if(_command == "sortb")
    {
        return true;
    }
    else if(_command == "sortd")
    {
        return true;
    }
    else if(_command == "sortg")
    {
        return true;
    }
    else if (_command == "quit")
    {
        _program = false;
        return false;
    }
    else
    {
        return false;
    }

}

bool service::repeatprogram(string YorN)
{
    if(YorN == "y" || YorN == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool service::validYorN(string YorN)
{
    if(YorN == "y" || YorN == "y" || YorN == "N" || YorN == "n")
    {
        return false;
    }
    else
    {
        return true;
    }
}


void service::setCommand(string c)
{
    _command = c;
}

vector<Person> service::sort_gender()
{
    int counter = 0;
    for(size_t i=0; i< listV.size(); i++)
    {
        if(listV[i].getGender() == "female")
        {
           swap(listV[i], listV[counter]);
           counter++;
        }
    }
    return listV;
}
void service::addPerson(Person input)
{
    dataAccess addNew;
    listV.push_back(input);
    addNew.setVector(listV);
    addNew.addPerson();
}


vector<Person> service::sort_alphabetically()
{
    bool again = true;
    while (again)
    {
        string save = listV[0].get_name();
        again = false;
        for (unsigned int i=0; i<listV.size()-1; i++)
        {
            if (listV[i].get_name() > listV[i+1].get_name())
            {
                //swap(list[i].get_name(), list[i+1].get_name());
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
    }
    return listV;
}


vector<Person> service::sort_numerically()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i=0; i<listV.size()-1; i++)
        {
            if (listV[i].getBirthYear() > listV[i+1].getBirthYear())
            {
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
    }
    return listV;
}

vector<Person> service::sort_BirthYear()
{
        bool again = true;
        while (again)
        {
       // string save = listV[0].getBirthYear;
        again = false;
        for (size_t i=0; i < listV.size()-1; i++)
        {
            if (listV[i].getBirthYear() > listV[i+1].getBirthYear())
            {
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
    }
    return listV;
}

vector<Person> service::find_person(string name)
{
    for (size_t i=0; i<listV.size(); i++)
    {
        if (listV[i].get_name().find(name) != string::npos)
        {
            listsearchedperson.push_back(listV[i]);
        }
    }
    return listsearchedperson;
}

bool service::look_for_person(string name)
{
    bool foundname = false;
    for (size_t i=0; i<listV.size(); i++)
    {
        if (listV[i].get_name().find(name) != string::npos)
        {
            foundname = true;
        }
    }
    return foundname;
}

bool service::findcheck()
{
    if(_command == "find")
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<Person> service::sort_death()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (unsigned int i=0; i<listV.size()-1; i++)
        {
            if (listV[i].getDeath() < listV[i+1].getDeath())
            {
                //swap(list[i].get_name(), list[i+1].get_name());
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
    }
    return listV;
}
void service::setProgram(bool input)
{
    _program = input;
}

bool service::getProgram()
{
    return _program;
}



