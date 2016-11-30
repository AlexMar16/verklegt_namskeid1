#include "consoleui.h"

using namespace std;


consoleUI::consoleUI(){
}


void consoleUI::addCommand()
{
  Person input;
  cout << "Please enter the following information about the new scientist " << endl;
  cout << "in the following order." << endl;
  cout << "Be aware you cannot put letters that are not in the English alphabet." << endl;
  cout << "Name (Minimum two names, Maximum three)" << endl;
  cout << "Gender (male/female) in lowercase." << endl;
  cout << "Birthyear (YYYY)" << endl;
  cout << "Died (0 if still alive)" << endl;
  cin >> input;
  turn.addPerson(input);
}

void consoleUI::run()
{
    bool valid = true;
    string keepGoingb;
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
        cout << "quit - This command will quit this program" << endl;
        cout << "******************************************************************************" << endl;
        cout << "command: ";
        cin >> command;

        turn.setCommand(command);
        cout << endl;



        valid = turn.validList();
        if (command == "add")
        {
            addCommand();
        }
        if (turn.findcheck())
        {
            string toFind;
            cout << "Name to find: ";
            cin >> toFind;
            vector<Person> printOut = turn.find_person(toFind);
            if (turn.look_for_person(toFind))
            {
                cout << printOut;
            }
        }
        if(valid)
        {
            vector<Person> printOut = turn.displayList(command);
            cout << printOut;
        }
     }while(turn.getProgram());
}

