
#include "telephone2.h"
using namespace std;

//privet form githab site
int main() {



    map<string, string> keyName;
    Telephone myTel;
    Record myRecord;
    int command = 9;

    cout << "---Telephone---" << endl;

    while(command != commandExit)
    {
        showMenu();
        string word;
        command = whatDo(myRecord, word);

        if (command == addRecord)
        {
            //  system("clear");
            if ( !myTel.existName(myRecord.getName()))
            {
                cout << "A new record has been added!" << endl;
                myTel.addRecord(myRecord);
            }
            else
            {
            //    system("clear");
                cout << "Subscriber ("<< myRecord.getName() <<") information already exist!" << endl;
            }

        }
        else if (command == unknownCommand)
        {
            //      system("clear");
            cout << " Unknown command (wrong command format?)"<<endl;
        }
        else if (command == commandExit)
        {
            //      system("clear");
            break;
        }
        else
        {
            //      system("clear");
            string guess, text, name, number = "-";

            if (command == smscallThrowNumber)
                number = word;
            else if (command == smscallThrowName)
            {
                name = word;
                if(myTel.existName(name))
                    number = myTel.getNumber(name);
                else
                    cout<<"Error! Name '"<<name<<"' not in contacts!" << endl;
            }

            if(number != "-")
            {
                while(guess != "sms" && guess != "call")
                {
                    cout << "Enter 'sms' or 'call':";
                    cin >> guess;
                }

                if(guess == "sms")
                {
                    cout << "Enter sms text:";
                    cin.ignore();
                    getline(cin,text);
                    cout<<"SMS text:"<<endl;
                    cout<<"\""<<text<<"\""<<endl;
                    cout<<"Send to "<< number << endl;
                }
                else if (guess == "call")
                {
                    cout<<"CALL number "<< number << endl;
                    cin.ignore();
                }
            }
        }
    }

  //  system("clear");
    cout<<"---Bye, bye!---"<<endl;

    return 0;
}
