#include "question.h"

Question::Question()
{

}

ifstream& operator >> (ifstream& in, Question& rhs)
{
    string name;
    string about;
    string temp;
        while(in >> temp && temp != "~")
        {
            rhs._answer = rhs._answer + temp + " ";
        }
        while(in >> temp && temp != "~")
        {
            rhs._question = rhs._question + temp + " ";
        }
        return in;
}

ostream& operator << (ostream& out, const Question& rhs)
{
    out << rhs._question;

    return out;
}
