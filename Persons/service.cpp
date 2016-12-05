#include "service.h"
#include "person.h"

using namespace std;

service::service(){    
     DbManager temp("ComputerScience.sqlite");
    _listV = temp.getVector();
    _listSearchedPerson = temp.getVector();
    _listSearchedPerson.clear();
    _program = true;
    _fileFound = temp.isOpen();
}

bool service::alreadyInDatabase(const string& name)         // Checks if the name exists in the database
{
    for (size_t i = 0; i < _listV.size(); i++)
    {
        if (_listV[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}

bool service::lookForPerson(const string& name)         // Checks if any part of the name is on the list
{
    for (size_t i = 0; i < _listV.size(); i++)
    {
        if (toLower(_listV[i].getName()).find(toLower(name)) != string::npos)       // Enables us to search in lower case letters.
        {
            return true;
        }
    }
    return false;
}

bool service::getProgram() const {return _program;}

Person service::findPersonExactly(const string& name)
{
    Person PersonFoundExactly;
    for (size_t i = 0; i < _listV.size(); i++)
    {
        if (_listV[i].getName() == name)
        {
            PersonFoundExactly = _listV[i];
        }
    }
    return PersonFoundExactly;
}

Person service::generateQuestion()
{
    srand(time(0));
    return _listV[rand() % _listV.size()]; // Randomizing questions.
}

string service::getLastName(const string& name) const
{
    int spaceCounter = 0;
    string LastName;

    for (size_t i = 0; i < name.size(); i++)
    {
        if (name[i] == SPACE)
        {
            spaceCounter = i + 1;
        }
    }
    for (size_t i = spaceCounter; i < name.size(); i++)
    {
        LastName += name[i];
    }
    return LastName;
}

string service::assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d)
{
    const string A = "a";
    const string B = "b";
    const string C = "c";
    const string D = "d";

    if (answer == A)
    {
        answer = a;
    }
    else if (answer == B)
    {
        answer = b;
    }
    else if (answer == C)
    {
        answer = c;
    }
    else if (answer == D)
    {
        answer = d;
    }
    else
    {
        answer = "0";
    }

    return answer;
}

string service::genderCheck(const Person& p)
{
    if (p.getGender() == MALE)
        return "He";
    else
        return "She";
}

string service::aliveCheck(const Person& p)
{
    if (p.getDeathYear() != ALIVE)
        return "died in " + to_string(p.getDeathYear());     // Converting the integer to a string to return a sentence.
    else
        return "is still alive";
}

string service::toLower(const string& toLowerString)    // Makes everything lowercase
{
    string data = toLowerString;
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

vector<int> service::properties()
{
    int nameQuant = 0;
    int deathQuant = 0;
    int MgenderQuant = 0;
    int FgenderQuant = 0;
    vector<int> statusVec;

    for(size_t i = 0; i < _listV.size(); i++)
    {
        nameQuant++;

        if(_listV[i].getDeathYear() != ALIVE)
        {
            deathQuant++;
        }
    }
    for(size_t k = 0; k < _listV.size(); k++)
    {
        if(_listV[k].getGender() == FEMALE)
        {
            FgenderQuant++;
        }
    }
    for(size_t z = 0; z < _listV.size(); z++)
    {
        if(_listV[z].getGender() == MALE)
        {
            MgenderQuant++;
        }
    }

    statusVec.push_back(nameQuant);
    statusVec.push_back(deathQuant);
    statusVec.push_back(FgenderQuant);
    statusVec.push_back(MgenderQuant);

    return statusVec;
}

vector<Person> service::getList() const {return _listV;}

vector<Person> service::sortGender()        // Sorts the list by gender, beginning with women.
{
    int counter = 0;
    for(size_t i = 0; i < _listV.size(); i++)
    {
        if(_listV[i].getGender() == FEMALE)
        {
            swap(_listV[i], _listV[counter]);
            counter++;
        }
    }
    return _listV;
}

vector<Person> service::sortAlphabetically()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listV.size() - 1; i++)
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

vector<Person> service::sortAlphabeticallyLastName()
{
    string name1;
    string name2;
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listV.size() - 1; i++)
        {
            name1= _listV[i].getName();
            name2= _listV[i+1].getName();

            if (getLastName(name1) > getLastName(name2))
            {
                swap( _listV[i], _listV[i+1]);
                again = true;
            }
        }
    }
    return _listV;
}

vector<Person> service::sortBirthYear()
{
    bool again = true;
    while(again)
    {
        again = false;
        for (size_t i = 0; i < _listV.size() - 1; i++)
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

vector<Person> service::findPerson(const string &name)      // Finds people and adds them to the vector
{
    _listSearchedPerson.clear();
    for (size_t i = 0; i < _listV.size(); i++)
    {
        if (toLower(_listV[i].getName()).find(toLower(name)) != string::npos)       // Puts both instances to lowercase
        {
            _listSearchedPerson.push_back(_listV[i]);       // Puts people in the list who apply to the input
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
        for (size_t i = 0; i < _listV.size() - 1; i++)
        {
            if (_listV[i].getDeathYear() > _listV[i+1].getDeathYear())      // Seperate the one's who are still alive and those who are not.
            {
                swap(_listV[i], _listV[i+1]);
                again = true;
            }
        }
    }
    vector<Person> temp;
    for(size_t i = 0; i < _listV.size(); i++)           // The one's who have died are put in the variable temp in order.
    {
        if(_listV[i].getDeathYear() != ALIVE)
        {
            temp.push_back(_listV[i]);
        }
    }
    for(size_t i = 0; i < _listV.size(); i++)           // Then we put the one's who are still alive behind them.
    {
        if(_listV[i].getDeathYear() == ALIVE)
        {
            temp.push_back(_listV[i]);
        }
    }

    return temp;
}

void service::swap(Person& a, Person& b)
{
    Person temp = a;
    a = b;
    b = temp;
}
bool service::fileFound()const {return _fileFound;}

void service::sortList(const string& command)       // Sort the list according to the input.
{

    if(command == A)
    {
        _listV = sortAlphabetically();
    }
    else if(command == L)
    {
        _listV = sortAlphabeticallyLastName();
    }
    else if(command == B)
    {
        _listV = sortBirthYear();
    }
    else if(command == D)
    {
        _listV = sortDeath();
    }
    else if(command == G)
    {
        _listV = sortGender();
    }
    else if(command == QUIT)
    {
        _program = false;
    }

}


/*void service::addPerson(const Person &input)        // Makes the user capable to add people to the list, as long as they're not already on the list
{
    if(!alreadyInDatabase(input.getName()))
    {
        dataAccess addNew;
        _listV.push_back(input);
        addNew.setVector(_listV);
        addNew.changeFile();
    }
}

void service::removePerson(const Person &input)         // Makes the user capable to remove people
{
    if(alreadyInDatabase(input.getName()))      // Checks if the name is already in the database.
    {
        dataAccess addNew;
        removeFromDatabase(input.getName());
        addNew.setVector(_listV);
        addNew.changeFile();
    }
}*/

void service::removeFromDatabase(const string &name)        // Takes the list, removes an elemnt then rewrites the info.txt with the list without what was removed
{
    for (size_t i = 0; i < _listV.size(); i++)
    {
        if (_listV[i].getName() == name)
        {
            _listV.erase(_listV.begin() + i);
        }
    }
}

void service::generateOptions(const Person& correct, string& a, string& b, string& c, string& d)
{
    const int CASE_0 = 0;
    const int CASE_1 = 1;
    const int CASE_2 = 2;

    a = _listV[rand() % _listV.size()].getName();       // Generating random answers
    b = _listV[rand() % _listV.size()].getName();
    c = _listV[rand() % _listV.size()].getName();
    d = _listV[rand() % _listV.size()].getName();

    int random = rand() % 4;
    if(random == CASE_0)
    {
        a = correct.getName();      // Assigning the correct answer to one of the answers
    }
    else if(random == CASE_1)
    {
        b = correct.getName();
    }
    else if(random == CASE_2)
    {
        c = correct.getName();
    }
    else
    {
        d = correct.getName();
    }
}


void service::setProgram(const bool& input) {_program = input;}

void service::reverseVector() {reverse(_listV.begin(), _listV.end());}
