#ifndef QUESTION_H
#define QUESTION_H
#include <fstream>
#include <iostream>
using namespace std;

class Question
{
public:
    Question();
    friend ifstream& operator >> (ifstream& in, Question& rhs);
private:
    string _question;
    string _answer;
};

#endif // QUESTION_H
