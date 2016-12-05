#include "consoleui.h"
#include "dbmanager.h"
#include <Qdebug>
using namespace std;

int main()
{
    consoleUI program;

  //  program.run();

    DbManager test("ComputerScience.sqlite");
    test.print();
    return 0;
}

