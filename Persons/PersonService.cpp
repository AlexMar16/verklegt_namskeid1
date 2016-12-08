#include "PersonService.h"
#include "person.h"

using namespace std;

PersonService::PersonService()
{
    generalService getVector;
    _listPerson = getVector.getOriginalPersons();
    _personIndex = 0;
}

bool PersonService::alreadyInDatabase(const string& name)         // Checks if the name exists in the database
{
    for (size_t i = 0; i < _listPerson.size(); i++)
    {
        if (_listPerson[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}

bool PersonService::lookForPerson(const string& name)         // Checks if any part of the name is on the list
{
    generalService GS;
    for (size_t i = 0; i < _listPerson.size(); i++)
    {
        if (GS.toLower(_listPerson[i].getName()).find(GS.toLower(name)) != string::npos)       // Enables us to search in lower case letters.
        {
            return true;
        }
    }
    return false;
}

Person PersonService::findPersonExactly(const string& name)
{
    Person PersonFoundExactly;
    for (size_t i = 0; i < _listPerson.size(); i++)
    {
        if (_listPerson[i].getName() == name)
        {
            PersonFoundExactly = _listPerson[i];
        }
    }
    return PersonFoundExactly;
}

string PersonService::getLastName(const string& name) const
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

Person PersonService::generateAnswer()
{
    srand(time(0));
    return _listPerson[rand() % _listPerson.size()]; // Randomizing Answer.
}

string PersonService::assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d)
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

string PersonService::genderCheck(const Person& p)
{
    generalService GS;
    if (GS.toLower(p.getGender()) == MALE)
        return "He";
    else
        return "She";
}

string PersonService::aliveCheck(const Person& p)
{
    if (p.getDeathYear() != ALIVE)
        return "died in " + to_string(p.getDeathYear());     // Converting the integer to a string to return a sentence.
    else
        return "is still alive";
}

vector<int> PersonService::properties()
{
    int nameQuant = 0;
    int deathQuant = 0;
    int MgenderQuant = 0;
    int FgenderQuant = 0;
    vector<int> statusVec;

    for(size_t i = 0; i < _listPerson.size(); i++)
    {
        nameQuant++;

        if(_listPerson[i].getDeathYear() != ALIVE)
        {
            deathQuant++;
        }
    }
    for(size_t k = 0; k < _listPerson.size(); k++)
    {
        if(_listPerson[k].getGender() == FEMALE)
        {
            FgenderQuant++;
        }
    }
    for(size_t z = 0; z < _listPerson.size(); z++)
    {
        if(_listPerson[z].getGender() == MALE)
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

vector<Person> PersonService::getPersonList() const {return _listPerson;}

vector<Person> PersonService::sortGender()        // Sorts the list by gender, beginning with women.
{
    int counter = 0;
    for(size_t i = 0; i < _listPerson.size(); i++)
    {
        if(_listPerson[i].getGender() == FEMALE)
        {
            swap(_listPerson[i], _listPerson[counter]);
            counter++;
        }
    }
    return _listPerson;
}

vector<Person> PersonService::sortAlphabetically()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listPerson.size() - 1; i++)
        {
            if (_listPerson[i].getName() > _listPerson[i+1].getName())
            {
                swap(_listPerson[i], _listPerson[i+1]);
                again = true;
            }
        }
    }
    return _listPerson;
}

vector<Person> PersonService::sortAlphabeticallyLastName()
{
    string name1;
    string name2;
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listPerson.size() - 1; i++)
        {
            name1= _listPerson[i].getName();
            name2= _listPerson[i+1].getName();

            if (getLastName(name1) > getLastName(name2))
            {
                swap( _listPerson[i], _listPerson[i+1]);
                again = true;
            }
        }
    }
    return _listPerson;
}

vector<Person> PersonService::sortBirthYear()
{
    bool again = true;
    while(again)
    {
        again = false;
        for (size_t i = 0; i < _listPerson.size() - 1; i++)
        {
            if ( _listPerson[i].getBirthYear() > _listPerson[i+1].getBirthYear())
            {
                swap(_listPerson[i], _listPerson[i+1]);
                again = true;
            }
        }
    }
    return _listPerson;
}

vector<Person> PersonService::findPerson(const string &name)      // Finds people and adds them to the vector
{
    _listSearchedPerson.clear();
    generalService GS;
    for (size_t i = 0; i < _listPerson.size(); i++)
    {
        if (GS.toLower(_listPerson[i].getName()).find(GS.toLower(name)) != string::npos)       // Puts both instances to lowercase
        {
            _listSearchedPerson.push_back(_listPerson[i]);       // Puts people in the list who apply to the input
        }
    }
    return _listSearchedPerson;
}

bool PersonService::lookForDigits(const int& num)
{
    for (size_t i = 0; i < _listPerson.size(); i++)
    {

        if (_listPerson[i].getBirthYear()== num)
        {
            return true;
        }
        else if(_listPerson[i].getDeathYear()==num)
        {
            return true;
        }
    }
    return false;
}

vector<Person> PersonService::findDigits(const int& num)
{
    _listSearchedDigits.clear();

    for (size_t i = 0; i < _listPerson.size(); i++)
    {
        if (_listPerson[i].getDeathYear()== num || _listPerson[i].getBirthYear()== num)
        {
            _listSearchedDigits.push_back(_listPerson[i]);       // Puts people in the list who apply to the input
        }
    }
    return _listSearchedDigits;

}

vector<Person> PersonService::sortDeath()
{
    bool again = true;
    while (again)
    {
        again = false;
        for (size_t i = 0; i < _listPerson.size() - 1; i++)
        {
            if (_listPerson[i].getDeathYear() > _listPerson[i+1].getDeathYear())      // Seperate the one's who are still alive and those who are not.
            {
                swap(_listPerson[i], _listPerson[i+1]);
                again = true;
            }
        }
    }
    vector<Person> temp;
    for(size_t i = 0; i < _listPerson.size(); i++)           // The one's who have died are put in the variable temp in order.
    {
        if(_listPerson[i].getDeathYear() != ALIVE)
        {
            temp.push_back(_listPerson[i]);
        }
    }
    for(size_t i = 0; i < _listPerson.size(); i++)           // Then we put the one's who are still alive behind them.
    {
        if(_listPerson[i].getDeathYear() == ALIVE)
        {
            temp.push_back(_listPerson[i]);
        }
    }

    return temp;
}

void PersonService::swap(Person& a, Person& b)
{
    Person temp = a;
    a = b;
    b = temp;
}


void PersonService::sortPersonList(const string& command)       // Sort the list according to the input.
{

    if(command == A)
    {
        _listPerson = sortAlphabetically();
    }
    else if(command == L)
    {
        _listPerson = sortAlphabeticallyLastName();
    }
    else if(command == B)
    {
        _listPerson = sortBirthYear();
    }
    else if(command == D)
    {
        _listPerson = sortDeath();
    }
    else if(command == G)
    {
        _listPerson = sortGender();
    }
}

void PersonService::removePerson(const Person &input)         // Makes the user capable to remove people
{
    if(alreadyInDatabase(input.getName()))      // Checks if the name is already in the database.
    {
        DbManager removePerson;
        removeFromDatabase(input.getName());
        removePerson.setVector(_listPerson);
        removePerson.removeFromPersons(input);
    }
}

void PersonService::addPerson(const Person &input)        // Makes the user capable to add people to the list, as long as they're not already on the list
{
    if(!alreadyInDatabase(input.getName()))
    {
        _listPerson.push_back(input);

    }
}

void PersonService::removeFromDatabase(const string &name)        // Takes the list, removes an elemnt then rewrites the info.txt with the list without what was removed
{
    for (size_t i = 0; i < _listPerson.size(); i++)
    {
        if (_listPerson[i].getName() == name)
        {
            _listPerson.erase(_listPerson.begin() + i);
        }
    }
}

void PersonService::generateOptions(const Person& correct, string& a, string& b, string& c, string& d)
{
    const int CASE_0 = 0;
    const int CASE_1 = 1;
    const int CASE_2 = 2;

    generalService GS;
    do
    {
        a = _listPerson[rand() % _listPerson.size()].getName();       // Generating random answers
        b = _listPerson[rand() % _listPerson.size()].getName();
        c = _listPerson[rand() % _listPerson.size()].getName();
        d = _listPerson[rand() % _listPerson.size()].getName();

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
    } while(GS.quizDuplicatedAnswer(a, b, c, d));
}


void PersonService::reverseVector() {reverse(_listPerson.begin(), _listPerson.end());}

Person PersonService::findPersonNumber(string nabn)
{
    for (size_t i=0; i<_listPerson.size(); i++)
    {
        if(_listPerson[i].getName()==nabn)
        {
            _personIndex = i;
        }
    }
    return _listPerson[_personIndex];
}

void PersonService::changePerson(const Person& someGuy)
{
    _listPerson[_personIndex]=someGuy;
}
