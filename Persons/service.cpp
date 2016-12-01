#include "service.h"
#include <person.h>
#include <algorithm>

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

void service::sortList()// depending on input from user, do something
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

vector<int> service::properties()// The "status" command activates this function
{
    int nameQuant=0;
    int deathQuant=0;
    int MgenderQuant=0;
    int FgenderQuant=0;

    vector<int> StatusVec;


    for(size_t i=0; i< _listV.size(); i++)//goes through everything in the vector
    {
        nameQuant++;

        if(_listV[i].getDeathYear() != 0)
        {
         deathQuant++;
        }
    }
    for(size_t k= 0; k<_listV.size(); k++)
    {
        if(_listV[k].getGender()=="female")
        {
        FgenderQuant++;
        }
    }
    for(size_t z = 0; z < _listV.size(); z++)
    {
        if(_listV[z].getGender()=="male")
        {
        MgenderQuant++;
        }
    }


    _statusVec.push_back(nameQuant);
    _statusVec.push_back(deathQuant);
    _statusVec.push_back(FgenderQuant);
    _statusVec.push_back(MgenderQuant);


    return _statusVec;// returns the vector to consoleui.cpp
}

void service::setCommand(string c)//set the input command from user in a variable
{
    _command = c;
}

vector<Person> service::sortGender()//sorts the females in the list to the top
{
    int counter = 0;
    for(size_t i=0; i< _listV.size(); i++)
    {
        if(_listV[i].getGender() == "female")//if female push it to the top of the list
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

void service::removePerson(Person input)//makes the user capable to remove people
{
    if(alreadyInDatabase(input.getName()))//check if its in the list
    {
        dataAccess addNew;
        removefromdatabase(input.getName());
        addNew.setVector(_listV);
        addNew.addPerson();
    }
}
void service::removefromdatabase(string name)//takes the list, removes an elemnt then rewrites the info.txt with the list without what was removed
{
    for (size_t i=0; i< _listV.size(); i++)
    {
        if (_listV[i].getName() == name)
        {
            _listV.erase(_listV.begin()+i);
        }
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

string service::getLastName(const string& nafn)//nær í seinasta orðið í setningu eða seinast nafnið í nafna tilvikum
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
            if ( _listV[i].getBirthYear() > _listV[i+1].getBirthYear())
            {
                swap(_listV[i], _listV[i+1]);
                again = true;
            }
        }
    }
    return _listV;
}

bool service::alreadyInDatabase(string name)//checkar hvort nafnið sé til í databasinum
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
bool service::lookForPerson(string name)//checkar hvort eh partur af nafni sé til í listanum
{
    bool foundname = false;
    for (size_t i=0; i< _listV.size(); i++)
    {
        if (tolower(_listV[i].getName()).find(tolower(name)) != string::npos)
        {
            foundname = true;
        }
    }
    return foundname;
}

vector<Person> service::findPerson(string name)//finnur personunar og addar þeim í vector
{
    _listSearchedPerson.clear();
    for (size_t i=0; i< _listV.size(); i++)
    {
        if (tolower(_listV[i].getName()).find(tolower(name)) != string::npos)//setur bæði í lower þannig að aLeN finnur Alen
        {
            _listSearchedPerson.push_back(_listV[i]);//setur persons í lista sem að hafa input notenda í nafninu
        }
    }
    return _listSearchedPerson;
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
Person service::findPersonExactly(string name)
{
    Person Personfoundexactly;
    for (size_t i=0; i< _listV.size(); i++)
    {
        if (_listV[i].getName() == name)
        {
            Personfoundexactly = _listV[i];
        }
    }
    return Personfoundexactly;
}

Person service::generateQuestion()
{
    srand(time(0));
    return _listV[rand()%_listV.size()];
}

void service::generateOptions(const Person& correct, string& a, string& b, string& c, string& d)
{
    a = _listV[rand()%_listV.size()].getName(); //generating random answers
    b = _listV[rand()%_listV.size()].getName();
    c = _listV[rand()%_listV.size()].getName();
    d = _listV[rand()%_listV.size()].getName();

    int random = rand() % 4;
    if(random == 0)
        a = correct.getName();      //assigning the correct answer to one of the answers
    else if(random == 1)
        b = correct.getName();
    else if(random == 2)
        c = correct.getName();
    else
        d = correct.getName();
}

void service::setProgram(bool input)
{
    _program = input;
}

string service::assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d)
{
    if (answer == "a")
        answer = a;
    else if (answer == "b")
        answer = b;
    else if (answer == "c")
        answer = c;
    else if (answer == "d")
        answer = d;
    else
        answer = "0";

    return answer;
}

string service::genderCheck(const Person& p)
{
    if (p.getGender() == "male")
        return "He";
    else
        return "She";
}

string service::aliveCheck(const Person& p)
{
    if (p.getDeathYear() != 0)
        return "and died in " + to_string(p.getDeathYear()); //converting int to string to return it as one
    else
        return "and is still alive";
}
int service::YorN(string YorNinput)
{
    if(YorNinput == "y" || YorNinput == "Y")
    {
        return 1;
    }
    if(YorNinput == "n" || YorNinput == "N")
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

bool service::getProgram()
{
    return _program;
}



string service::tolower(string tolowerstring)//to lower
{
    string data = tolowerstring;
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

