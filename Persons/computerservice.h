#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "dbmanager.h"
#include "computer.h"
#include "generalclass.h"

class computerService
{
public:
    computerService();
    bool lookForComputer(const string& name);
    Computer findComputerExactly(const string& name);
    //Computer generateQuestion();
    vector<int> computerProperties();
    vector<Computer> findComputer(const string& name);
    vector<Computer> getComputerList() const;
    void addComputer(const Computer& input);
    void removeComputer(const Computer& input);
    void sortList(const string& command);
    //void generateOptions(const Computer& correct, string& a, string& b, string& c, string& d);
    void reverseVector();
    //string assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d);

private:
    bool alreadyInDatabase(const string &name);
    vector<Computer> _listComputer;
    vector<Computer> _listSearchedComputer;
    vector<Computer> sortAlphabetically();
    vector<Computer> sortBuilt();
    vector<Computer> sortType();
    vector<Computer> sortCreationYear();
    void removeFromDatabase(const string& name);
    void swap(Computer& a, Computer& b);
};

#endif // COMPUTERSERVICE_H

