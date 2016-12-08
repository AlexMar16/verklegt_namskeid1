#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "dbmanager.h"
#include "generalclass.h"

class computerService
{
public:
    computerService();
    bool lookForComputer(const string& name);
    bool lookForDigits(const int& num);
    Computer findComputerExactly(const string& name);
    vector<int> computerProperties();
    vector<Computer> findComputer(const string& name);
    vector<Computer> findDigits(const int& num);
    vector<Computer> getComputerList() const;
    void addComputer(const Computer& input);
    void removeComputer(const Computer& input);
    void sortComputerList(const string& command);
    Computer generateAnswer();
    string builtCheck(const Computer& c);
    void generateOptions(const Computer& correct, string& a, string& b, string& c, string& d);
    string typeCheck(const Computer& c);
    //void generateOptions(const Computer& correct, string& a, string& b, string& c, string& d);
    void reverseVector();
    //string assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d);

    Computer findComputerNumber(string name);
    void changeComputer(const Computer& somecomp);

private:
    bool alreadyInDatabase(const string &name);
    vector<Computer> _listComputer;
    vector<Computer> _listSearchedComputer;
    vector<Computer> _listSearchedDigits;
    vector<Computer> sortAlphabetically();
    vector<Computer> sortBuilt();
    vector<Computer> sortType();

    vector<Computer> sortCreationYear();
    void removeFromDatabase(const string& name);
    void swap(Computer& a, Computer& b);

    int _computerIndex;
};

#endif // COMPUTERSERVICE_H

