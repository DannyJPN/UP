#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "fileoperations.hpp"
#include "csharp.hpp"
#include "dateoperations.hpp"
#include "fileoperations.hpp"

using namespace std;

/**
 * @brief File operations sourcecode file
 * @file fileoperations.cpp
 * @author Dan Krupa
 */



/**
 * @brief Function verifying that the given file exists or can be created at given location.
 * @param filepath  Path to the file which is to be verified.
 * @return Function returns TRUE if the filepath is valid or FALSE if it is invalid.
 */
bool VerifyFile(const string filepath)
{
ifstream ifiletest(filepath);


    if(ifiletest.good())
    {
        ifiletest.close();
        return true;
    }
    ofstream ofiletest(filepath);
    if(ofiletest.good())
    {
        ofiletest.close();
        return true;
    }
    ifiletest.close();
    ofiletest.close();

    return false;
}

/**
 * @brief Function that creates a copy of a CSV file in different location while verifying their identity from the register system view. The identity of src and dest changes the function behavior if the src file was deleted during the program run.
 * @param src  Path to the file which is to be copied.
 * @param dest  Path to the file into which the src is to be copied.
 * @param roomfile  Path to the file containing room data. Its purpose is to verify whether src or dest is this file.
 * @param roombackup    Path to the file containing backup of room data. Its purpose is to verify whether src or dest is this file.
 * @param regfile  Path to the file containing registration data. Its purpose is to verify whether src or dest is this file.
 * @param regbackup  Path to the file containing backup registration data. Its purpose is to verify whether src or dest is this file.
 */


void CopyFile(const string src,const string dest,const string roomfile,const string roombackup,const string regfile,const string regbackup)
{

    ifstream iback(src.c_str());
    if(!iback)
    {

        ofstream otemp(dest.c_str());
        if(dest==roomfile)
        {
            cout<<"Room backup file not found.\nCreating blank list"<<endl;

            otemp<<"ID\tpatro\tcislo mistnosti\tkapacita sedadel\tcena za den rezervace"<<endl;

        }
        else if(dest==regfile)
        {
            cout<<"Registration backup file not found.\nCreating blank list"<<endl;

            otemp<<"ID mistnosti\tdatum rezervace"<<endl;


        }
        else if(dest == roombackup||dest==regbackup)
        {
            cout<<"No backup found"<<endl;
        }
        else
        {
            cout<<"Unknown file"<<endl;
        }

        otemp.close();
        return;
    }
    ofstream oback(dest.c_str());
    string file;

    while(iback.peek()!=EOF)
    {
        getline(iback,file,'\n');
        oback<<file<<endl;

    }
    iback.close();
    oback.close();

return;
}

/**
 * @brief Function that loads up the content of registration data file.
 * @param header    Used for extracting the file header that is not to be part of database.Previously used to be written in front of it.
 * @param roomfile  Path to the file containing room data. Used as inter-jump argument,as this function contains CopyFile function.
 * @param roombackup    Path to the file containing backup of room data. Used as inter-jump argument,as this function contains CopyFile function.
 * @param regfile  Path to the file containing registration data.
 * @param regbackup  Path to the file containing backup registration data in case of reloading from backup needed.
 * @return Function returns structure vectorreg,simulating real vector,containing registration data.
 */


vectorreg LoadRegFile(string& header,const string roomfile,const string roombackup,const string regfile,const string regbackup)
{

    vectorreg x;
    reg onereg;
    string one;

    ifstream ireg(regfile.c_str());
    if(!ireg)
    {
     cout<<"The reglist was not found."<<endl<<"Attempting to regenerate the file from backup."<<endl;
     CopyFile(regbackup,regfile,roomfile,roombackup,regfile,regbackup);
     ireg.open(regfile.c_str());
    }
    getline(ireg,header,'\n');
    //cout<<one.substr(0,8)<<"\t"<<one.substr(8,one.length()-8)<<endl;
             while(ireg.peek()!=EOF)
             {
                getline(ireg,one,'\n');
                vector<string> helper = Split(one,'\t');

                if(helper.size()!=2||!IsUShort(helper[0])||!IsValidDate(helper[1]))
                {
                    ireg.close();
                    //delete[] x.arreg;
                    x.size =0;

                   PushBack(x,{0,"0.0.0000"});
                    return x;
                }
                onereg.id=ToUShort(helper[0]);
                onereg.date=helper[1];

                PushBack(x,onereg);

             }
    ireg.close();

Sort(x,"id");

return x;
}

/**
 * @brief Function that loads up the content of room database file.
 * @param header    Used for extracting the file header that is not to be part of database.Previously used to be written in front of it.
 * @param roomfile  Path to the file containing room data.
 * @param roombackup    Path to the file containing backup of room data in case of reloading from backup needed.
 * @param regfile  Path to the file containing registration data.  Used as inter-jump argument,as this function contains CopyFile function.
 * @param regbackup  Path to the file containing backup registration data.  Used as inter-jump argument,as this function contains CopyFile function.
 * @return Function returns structure vectorroom,simulating real vector,containing room database.
 */


vectorroom LoadRoomFile(string& header,const string roomfile,const string roombackup,const string regfile,const string regbackup)
{



    vectorroom x;
    room oneroom;
    string one;

    ifstream iroom(roomfile.c_str());
    if(!iroom)
    {
     cout<<"The room list was not found."<<endl<<"Attempting to regenerate the file from backup."<<endl;
    CopyFile(roombackup,roomfile,roomfile,roombackup,regfile,regbackup);
    cout<<"Backup file successfully renewed"<<endl;
     iroom.open(roomfile.c_str());
    }
    getline(iroom,header,'\n');

             while(iroom.peek()!=EOF)
             {

                getline(iroom,one,'\n');

                if(UShortLineLength(one)!=5)
                {

                    iroom.close();
                    //delete[] x.arroom;
                    x.size=0;
                    PushBack(x,{0,0,0,0,0});
                    return x;
                }

                stringstream memory(one);
                memory>>oneroom.id;
                memory>>oneroom.floor;
                memory>>oneroom.number;
                memory>>oneroom.seats;
                memory>>oneroom.cost;

                PushBack(x,oneroom);
                memory.ignore();
             }
    iroom.close();

Sort(x,"id");

return x;
}

