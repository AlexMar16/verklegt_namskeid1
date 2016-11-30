#ifndef SERVICE_H
#define SERVICE_H
#include "dataaccess.h"
#include "person.h"

class service
{
public:
    service();
    void initalize_list(vector<Person>&);
    void swap(Person& a, Person& b);
    void initalize_list();
    void setCommand(string command);    
    void addPerson(Person input);
    bool validList();
    bool validYorN(string YorN);
    bool repeatprogram(string YorN);
    bool findcheck();
    vector<Person> displayList();
    vector<Person> find_person(string name);
    vector<Person> sort_alphabetically();
    vector<Person> get_list();
    vector<Person> sort_BirthYear();
    vector<Person> sort_death();
    vector<Person> sort_gender();
    bool look_for_person(string name);
    vector<Person> sort_numerically();
    vector<Person> displayList(string command);
    void setProgram(bool input);
    bool getProgram();


private:
    vector<Person> listV;
    vector<Person> listsearchedperson;
    string _command;
    bool _keepGoing;
    bool _valid;
    bool _program;
};

#endif // SERVICE_H
