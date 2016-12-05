#include "consoleui.h"
#include "dbmanager.h"

using namespace std;

int main()
{
    consoleUI program;

    program.run();

    DbManager("/Users/alexgunnarsson/verklegt_namskeid1/ComputerScience.db");
    return 0;
}

