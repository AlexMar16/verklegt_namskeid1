#include "computer.h"
#include "person.h"
const int COLUMN_WIDTH = 30;
const int FIVE = 3;
const int TWO = 2;

Computer::Computer()
{
    _yearBuilt = 0;
}
ifstream& operator >> (ifstream& in, Computer& rhs)
{
    getline(in, rhs._name);
    getline(in, rhs._type);
    in >> rhs._yearBuilt;
    rhs._built = true;//Todo útfæra að hægt sé að ráða hvort talvan hafi verið smíðuð eða ekki
    in.ignore();

    return in;
}

ostream& operator << (ostream& out, const Computer& rhs)
{
    const char DASH = '-';
    out << left << setw(FIVE * COLUMN_WIDTH + FIVE) << setfill(DASH) <<  DASH << endl;
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) <<  rhs._name;
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << rhs._type;
    out << left << setw(15) << setfill(SPACE) << rhs._yearBuilt;

    if(rhs._built == "Yes")
    {
        out << setw(15) << setfill(SPACE) << rhs._built << endl;
    }
    else
    {
        out << setw(15) << setfill(SPACE) << "Never built!" << endl;
    }
    return out;
}

ostream& operator << (ostream& out, vector<Computer>& rhs)
{
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << "Name";
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << "Type";
    out << left << setw(15) << setfill(SPACE) << "Year built";
    out << left << setw(COLUMN_WIDTH) << setfill(SPACE) << "Built" << endl;
    for(size_t i = 0; i < rhs.size(); i++)
    {
        out << rhs[i];
    }
    out << endl;
    return out;
}

//Get functions
string Computer::getName() const {return _name;}

string Computer::getType() const {return _type;}

int Computer::getYearBuilt() const {return _yearBuilt;}

string Computer::getBuilt() const {return _built;}



//Set functions
void Computer::setName(const string input) {_name = input;}

void Computer::setType(const string input){_type = input;}

void Computer::setYearbuild(const int input){_yearBuilt = input;}

void Computer::setBuilt(const string input){_built = input;}
