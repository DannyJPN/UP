#include <iostream>

#include "commands.hpp"
#include "security.hpp"
#include "fileoperations.hpp"
#include "csharp.hpp"





using namespace std;


/**
 * @brief Main sourcecode file
 * @file main.cpp
 * @author Dan Krupa
 * @mainpage KRU0142 - Registracni system
 */


/** @fn int main()
 *  @brief Main function. Acquires data file names from the user.Calls authentication function. Gets user command and calls execution function.
 */

int main()
{

bool autoback = false;
string command;
string prompt;
 string def_roomfile ="../vstupnidata/roomfile.csv";
 string def_roombackup = "../vstupnidata/backup/roombackup.csv";
 string def_regfile ="../vystupnidata/regfile.csv";
 string def_regbackup = "../vstupnidata/backup/regbackup.csv";
 string roomfile,roombackup,regfile,regbackup ;

while(!Authenticate(prompt))
{
    cout<<"Password/username incorrect"<<endl;
}
cout<<"Specify file with room information:";
getline(cin,roomfile,'\n');
if(roomfile.length()<4||roomfile.substr(roomfile.length()-4,4)!=".csv")
{
    roomfile.append(".csv");
}

cout<<"Specify file with room backup information:";
getline(cin,roombackup,'\n');
if(roombackup.length()<4||roombackup.substr(roombackup.length()-4,4)!=".csv")
{
    roombackup.append(".csv");
}

cout<<"Specify file with registration information:";
getline(cin,regfile,'\n');
if(regfile.length()<4||regfile.substr(regfile.length()-4,4)!=".csv")
{
    regfile.append(".csv");
}

cout<<"Specify file with registration backup information:";
getline(cin,regbackup,'\n');
if(regbackup.length()<4||regbackup.substr(regbackup.length()-4,4)!=".csv")
{
    regbackup.append(".csv");
}


if(roomfile==".csv"||!VerifyFile(roomfile))
{
    cout<<"Room information file does not exist. Using default system file."<<endl;
    roomfile = def_roomfile;
}
if(roombackup==".csv"||!VerifyFile(roombackup))
{
    cout<<"Room information backup file does not exist. Using default system file."<<endl;
    roombackup = def_roombackup;
}
if(regfile==".csv"||!VerifyFile(regfile))
{
    cout<<"Registration information file does not exist. Using default system file."<<endl;
    regfile = def_regfile;
}
if(regbackup==".csv"||!VerifyFile(regbackup))
{
    cout<<"Registration information backup file does not exist. Using default system file."<<endl;
    regbackup=def_regbackup;
}




cout<<"\nType commands or type HELP to display the available command set"<<endl;
while(true)
{
    cout<<prompt<<" ";
    getline(cin,command,'\n');
    if(command=="")
        command= "no operation";
    ToLower(command);
    Execute(command,autoback,roomfile,roombackup,regfile,regbackup);


    command = "no operation";
}
cout<<"Logging off the registration system"<<endl;

    return 0;
}
