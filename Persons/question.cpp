#include "question.h"

Question::Question()
{

}

ifstream& operator >> (ifstream& in, Question& rhs)
{
    string temp;
    int counter = 0;
        while(temp != "~")
        {
            if(temp == "~")
            {
                //rhs._answer.clear();
                //break;
            }
            else
            {
                rhs._answer  += temp + " ";
                //cout << "rhs._answer: " << rhs._answer << endl;
                //cout << counter << endl;
                counter++;
            }
        }

        while(temp != "~")
        {
            if(temp == "~")
            {
                //rhs._question.clear();
                //break;
            }
            else
            {
                rhs._question += temp + " ";
                //cout << "rhs._question: " << rhs._question << endl;
                //cout << counter << endl;
                counter++;
            }
        }
        return in;
}

ostream& operator << (ostream& out, const Question& rhs)
{
    out << "LOLOL";
    out << "question: " << rhs._question << rhs._answer<< "asdasd";
    return out;
}

















