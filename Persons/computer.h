#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

/*const char SPACE = ' '; // All the constants in more than one file.

const string A = "a";
const string B = "b";
const string D = "d";
const string G = "g";
const string L = "l";
const string QUIT = "quit";
*/
class Computer
{
public:
    Computer();
    string getName() const;
    string getType() const;
    int getYearBuilt() const;
    bool getBuilt() const;
    void setName(const string input);
    void setType(const string input);
    void setYearbuild(const int input);
    void setBuilt(const bool input);
    friend ostream& operator << (ostream& out, const Computer& rhs);
    friend ifstream& operator >> (ifstream& in, Computer& rhs);
    friend ostream& operator << (ostream& out, vector<Computer>& rhs);

private:
    string _name;
    string _type;
    int _yearBuilt;
    bool _built;
};

#endif // COMPUTER_H
