#include "consoleui.h"

using namespace std;


consoleUI::consoleUI(){}


void consoleUI::run()
{
    bool valid = true;
    string keepGoingb;
    service turn;
    string command;
    do
    {
        cout << "******************************************************************************" << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "list - This command will list every single person in the system" << endl;
        cout << "add -This command allows you to add a person to the list" << endl;
        cout << "find -This command allows you to find a certain person in the list" << endl;
        cout << "sorta -This command will list every single person in the system sorted alhpabaticly" << endl;
        cout << "sortb -This command will list every single person in the system sorted by date of birth" << endl;
        cout << "sortd -This command will list every single person in the system sorted by date of death" << endl;
        cout << "sortg -This command will list every single person in the system sorted by their gender" << endl;
        cout << "******************************************************************************" << endl;
        cout << "command: ";
        cin >> command;

        turn.setCommand(command);
        cout << endl;



        valid = turn.validList();
        if (command == "add")
        {
            cout << "Please Enter in the following order: ";
            Person inputNew;
            cin >> inputNew;
            turn.addPerson(inputNew);
        }
        if(valid)
        {
            vector<Person> printOut = turn.displayList(command);
            cout << printOut;
        }
        do {
            cout << "If you would like to continue, please enter (y/n): ";
            cin >> keepGoingb;
            if(turn.validYorN(keepGoingb))
            {
                cout << "invalid input!" << endl;
            }
        }while(turn.validYorN(keepGoingb));


     }while(turn.repeatprogram(keepGoingb));
}

