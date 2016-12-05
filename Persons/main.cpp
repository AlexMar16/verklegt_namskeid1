#include "consoleui.h"
#include "dbmanager.h"

using namespace std;

int main()
{
    consoleUI program;

  //  program.run();

    DbManager test("/Users/alexgunnarsson/verklegt_namskeid1/ComputerScience.db");
    test.print();
    return 0;
}

