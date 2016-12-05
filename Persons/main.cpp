#include "consoleui.h"
#include "dbmanager.h"
#include <Qdebug>
using namespace std;

int main()
{
    consoleUI program;

  //  program.run();

    DbManager test("/Users/alexgunnarsson/verklegt_namskeid1/lala.sqlite");
    test.print();
    return 0;
}

