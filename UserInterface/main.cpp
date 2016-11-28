#include <QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "Welcome to the database of historical computer scientist's" << endl;
    cout << "Input a certain number based on your action";
    cout << "1. Display the whole list of historical computer scientist's sorted";
    QCoreApplication a(argc, argv);

    return a.exec();
}
