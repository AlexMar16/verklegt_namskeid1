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
const string ELECTRONIC = "Electronic";
const string MECHANICAL = "Mechanical";
const string ELECTROMECHANICAL = "Electro-Mechanical";
const string TRANSISTOR = "Transistor";
const string TRANSISTORMICROCHIP = "Transistor/Microchip";
const string SUPERCOMPUTER = "Supercomputer";
const string QUANTUMCOMPUTER = "Quantum computer";

class Computer
{
public:
    Computer();
    string getName() const;
    string getType() const;
    int getYearBuilt() const;
    int getID() const;
    string getBuilt() const;
    void setName(const string input);
    void setType(const string input);
    void setYearbuild(const int input);
    void setBuilt(const string input);
    void setID(const int& input);


    friend ostream& operator << (ostream& out, const Computer& rhs);
    friend ifstream& operator >> (ifstream& in, Computer& rhs);
    friend ostream& operator << (ostream& out, vector<Computer>& rhs);

private:
    string _name;
    string _type;
    int _yearBuilt;
    int _ID;
    string _built;

};

#endif // COMPUTER_H
