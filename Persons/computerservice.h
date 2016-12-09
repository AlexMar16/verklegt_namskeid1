#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "dbmanager.h"
#include "computer.h"

class computerService
{
public:
    computerService();
    bool lookForComputer(const string& name);
    bool getProgram() const;
    bool dataFound() const;
    bool lookForDigits(const int& num);
    Computer findComputerExactly(const string& name);
    Computer generateQuestion();
    Computer generateAnswer();
    Computer findComputerNumber(string name);
    vector<int> computerProperties();
    vector<Computer> findComputer(const string& name);
    vector<Computer> getList() const;
    void addComputer(const Computer& input);
    void removeComputer(const Computer& input);
    void sortList(const string& command);
    void setProgram(const bool& input);
    void generateOptions(const Computer& correct, string& a, string& b, string& c, string& d);
    void reverseVector();
    void sortComputerList(const string& command);
    void changeComputer(const Computer& input);
    string getLastName(const string& name) const;
    string toLower(const string &tolowerstring);
    string assignSelection(string& answer, const string& a, const string& b, const string& c, const string& d);
    string genderCheck(const Computer& p);
    string aliveCheck(const Computer& p);
    string typeCheck(const Computer& c);
    string builtCheck(const Computer& c);
    int _computerIndex;
    vector<Computer> findDigits(const int& num);
    vector<Computer> getComputerList()const;
    vector<Computer> sortCreationYear();

private:
    bool _keepGoing;
    bool _valid;
    bool _program;
    bool alreadyInDatabase(const string &name);
    bool _dataFound;
    vector<Computer> _listComputer;
    vector<Computer> _listSearchedDigits;
    vector<Computer> _listSearchedComputer;
    vector<Computer> sortAlphabetically();
    vector<Computer> sortBuilt();
    vector<Computer> sortType();
    void removeFromDatabase(const string& name);
    void swap(Computer& a, Computer& b);
};

#endif // COMPUTERSERVICE_H

