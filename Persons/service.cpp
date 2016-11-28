#include "service.h"
#include <vector>
#include <iosfwd>

using namespace std;

service::service()
{

}

vector<Person> service::sort_alphabetically()
{
    bool again = true;
    while (again)
    {
        string save = listV[0].get_name();
        again = false;
        for (unsigned int i=0; i < listV.size()-1; i++)
        {
            again = false;
            if (listV[i].get_name() > listV[i+1].get_name())
            {
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
    }
}

void service::initalize_list()
{
    dataAccess temp;
    listV = temp.getVector();
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

vector<Person> service::sort_BirthYear()
{
    bool again = true;
    while (again)
    {
        string save = listV[0].getBirthYear  ;
        again = false;
        for (size_t i=0; i < listV.size()-1; i++)
        {
            again = false;
            if (listV[i].getBirthYear() > listV[i+1].getBirthYear())
            {
                swap(listV[i], listV[i+1]);
                again = true;
            }
        }
        return listV;
    }
}

vector<Person> service::sort_death()
{

    for(size_t i= 0; i< listV; i++)
    {
        if(_deathYear>0)
        {
           if(listV[i].get_Death()> listV[i+1].get_death())
           {
              swap(listV[i], listV[i+1]);
           }
        }
        return listV;
    }



}

vector<Person> service::sort_gender()
{
    if()

}

bool service::displayList()// depending on input from user, do something
{
    if(_command == "list")
    {
        dlist();
        return false;
    }
    else if(_command == "add")
    {
        //Person person(string _name,char _gender int _birthYear, int _deathYear) todo
        return false;
    }
    else if(_command == "find")
    {
        string name;
        cout << "enter name to find:";
        cin >> name;
        return false;
    }
    else if(_command == "sorta")
    {
        cout << "soarta!" << endl;
        return false;
    }
    else if(_command == "sortb")
    {
        cout << "sortb!" << endl;
        return false;
    }
    else if(_command == "sortd")
    {
        cout << "sortd!" << endl;
        return false;
    }
    else if(_command == "sortg")
    {
        cout << "sortg!" << endl;
        return false;
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        return true;
    }

























































