#include "question.h"

Question::Question()
{

}

ifstream& operator >> (ifstream& in, Question& rhs)
{
    string name;
    string about;
    string temp;
    //cout << "overload >>";
        while(in >> temp && temp != "~")
        {            
            rhs._answer = rhs._answer + temp + " ";
            //cout << "rhs._answer: " << rhs._answer << endl;
        }
        while(in >> temp && temp != "~")
        {
            rhs._question = rhs._question + temp + " ";
        }
        return in;
}

ostream& operator << (ostream& out, const Question& rhs)
{
    out << "question: " << rhs._question;

    return out;
}

















