//
// Created by Sg on 09.07.2022.
//
#include "telephone2.h"

using namespace std;
bool trueTelephone(string& telephone)
{
    if(telephone.length() != 12)
        return false;
    if(telephone[0] != '+' || telephone[1] != '7')
        return false;
    for(char c: telephone)
        if(c != '+' && !isdigit(c))
            return false;

    return true;
}
bool trueName(string& name)
{
    if(name.length() < 2 )
        return false;
    for(char c: name)
        if(!isalpha(c))
            return false;

    return true;
}
void showMenu()
{
    cout<<"Valid command format: 1 '+7<10 numbers> name (min 2 alpha)' for add record;" << endl;
    cout<<"                      2 '+7<10 numbers>' or 'name' for call or sms;" << endl;
    cout<<"                      4 '-1' for exit." << endl;
}
int whatDo(Record& myRecord, string &word)
{
    cout<<"Enter command:";
    string in, word1, word2;
    getline(cin,in);

    if(in.find(' ') != string::npos)
    {
        word1 = in.substr(0,in.find(' '));
        word2 = in.substr(in.find(' ')+1,in.length());
    }
    else
        word1 = in;

    if(trueTelephone(word1) && trueName(word2))
    {
        myRecord.setName(word2);
        myRecord.setTelephone(word1);
        return addRecord;
    }
    else if (word2.empty() && trueTelephone(word1))
    {
        word = word1;
        return smscallThrowNumber;
    }

    else if (word2.empty() && trueName(word1))
    {
        word = word1;
        return smscallThrowName;
    }
    else if(word1 == "-1")
        return commandExit;
    else
    {
        return unknownCommand;
    }

}


string Record::getName() const {
    string s = this->name;
    return s;
}

string Record::getTelephone() const {
    return telephone;
}

void Record::setName(string &s) {
    name = s;
}

void Record::setTelephone(string &s) {
    telephone = s;
}

void Telephone::addRecord(const Record& r) {
    keyName.insert(pair<string,Record>(r.getName(),r));
}

bool Telephone::existName(const string &name) const {
    if(keyName.count(name) == 0)
        return false;
    else
        return true;
}

string Telephone::getNumber(string& name) {
    return keyName[name].getTelephone();
}
