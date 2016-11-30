#include "question.h"

Question::Question()
{

}

ifstream& operator >> (ifstream& in, Question& rhs)
{
    string temp;
    rhs._answer.clear();
        while(in >> temp)
        {
            if(temp != "~")
            {
                rhs._answer  += temp + " ";
            }
            else
            {
                break;
            }
        }
     rhs._question.clear();
        while(in >> temp)
        {
            if(temp != "~")
            {
                rhs._question += temp + " ";
            }
            else
            {
                break;
            }
        }
        //cout << "Name is: " << rhs._answer << "  question is: " << rhs._question << endl;
        return in;
}

ostream& operator << (ostream& out, const Question& rhs)
{
    out << "LOLOL";
    out << "question: " << rhs._question << "asdasd";
    return out;
}

















