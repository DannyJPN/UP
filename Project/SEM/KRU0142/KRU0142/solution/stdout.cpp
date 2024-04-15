#include <iostream>
#include <fstream>
#include "stdout.hpp"
#include "csharp.hpp"
#include "dateoperations.hpp"
#include "fileoperations.hpp"

using namespace std;
/**
 * @brief File with standard output functions
 * @file stdout.cpp
 * @author Dan Krupa
 */

/**
 * @brief Function that causes printing information about one room in the console.
 * @param oneroom Room info set to be printed.
 */
void WriteRoom(const room oneroom)
{
     cout<<"ID: "<<oneroom.id;
    cout<<"\tFloor: "<<oneroom.floor;
    cout<<"\tNumber: "<<oneroom.number;
    cout<<"\tSeats: "<<oneroom.seats;
    cout<<"\t\tCost: "<<oneroom.cost<<"/day"<<endl;
}
/**
 * @brief Function that causes printing information about one registration in the console.
 * @param onereg Registration info set to be printed.
 */
void WriteReg(const reg onereg)
{
    cout<<"ID: "<<onereg.id;
    cout<<"\tDate: "<<onereg.date<<endl;
}
/**
 * @brief Function that causes printing an entire room database into the console. Overloaded by type.
 * @param vect Array-size struct containing room info.
 */
void WriteVector(const vectorroom vect)
{
    for(unsigned short i = 0;i<vect.size;i++)
    {
   WriteRoom(vect.arroom[i]);

    }
    return;
}
/**
 * @brief Function causing printing of database containing rooms information filtered by several parameters simultaneously.
 * @param rooms Room database.
 * @param regs Registration database.
 * @param values Set of parameter values used for filtering.
 * @param paramcount Number of values used for filtering.
 */
void WriteVectorAdvancedFilter(const vectorroom rooms,const vectorreg regs,string values [],const unsigned short paramcount)
{
   // cout<<paramcount<<"=vals"<<endl;

    for( int i =0;i<paramcount-1;i=i+2)
    {
        values[i]=values[i]==""?"0":values[i];
        values[i+1]=values[i+1]==""?"65535":values[i+1];

        if(ToUShort(values[i])>ToUShort(values[i+1]))
        {
            string p = values[i];
            values[i]=values[i+1];
            values[i+1]=p;
        }
    }







    for(unsigned short i = 0;i<rooms.size;i++)
    {
        if(
           (ToUShort(values[0])<=rooms.arroom[i].id&&ToUShort(values[1])>=rooms.arroom[i].id)
        &&(ToUShort(values[2])<=rooms.arroom[i].floor&&ToUShort(values[3])>=rooms.arroom[i].floor)
        &&(ToUShort(values[4])<=rooms.arroom[i].number&&ToUShort(values[5])>=rooms.arroom[i].number)
        &&(ToUShort(values[6])<=rooms.arroom[i].seats&&ToUShort(values[7])>=rooms.arroom[i].seats)
        &&(ToUShort(values[8])<=rooms.arroom[i].cost&&ToUShort(values[9])>=rooms.arroom[i].cost)
           &&!Registered(regs,rooms.arroom[i].id,values[10])
        )
        {
            WriteRoom(rooms.arroom[i]);
        }



    }
    return;
}
/**
 * @brief Function that causes printing room database filtered and sorted by given parameter into the console. Overloaded by type.
 * @param vect Array-size struct containing room info.
 * @param parameter Parameter by which the database should be filtered and sorted.
 * @param param_value_start Beginning of the interval of values that the given parameter should have to be printed.
 * @param param_value_end Beginning of the interval of values that the given parameter should have to be printed.
  */
void WriteVectorFilter(const vectorroom vect,const string parameter,unsigned short param_value_start, unsigned short param_value_end)
{

            if(param_value_start>param_value_end)
            {
                unsigned short p = param_value_start;
                param_value_start=param_value_end;
                param_value_end=p;
            }

    for(unsigned short i = 0;i<vect.size;i++)
    {
        if(
           (parameter=="id"&&param_value_start<=vect.arroom[i].id&&param_value_end>=vect.arroom[i].id)
        ||(parameter=="floor"&&param_value_start<=vect.arroom[i].floor&&param_value_end>=vect.arroom[i].floor)
        ||(parameter=="number"&&param_value_start<=vect.arroom[i].number&&param_value_end>=vect.arroom[i].number)
        ||(parameter=="seats"&&param_value_start<=vect.arroom[i].seats&&param_value_end>=vect.arroom[i].seats)
        ||(parameter=="cost"&&param_value_start<=vect.arroom[i].cost&&param_value_end>=vect.arroom[i].cost)
        )
        {
            WriteRoom(vect.arroom[i]);
        }



    }
    return;
}
/**
 * @brief Function that causes printing registration database filtered and sorted by given parameter into the console. Overloaded by type.
 * @param vect Array-size struct containing registration info.
 * @param parameter Parameter by which the database should be filtered and sorted.
 * @param param_value_start Beginning of the interval of values that the given parameter should have to be printed.
 * @param param_value_end Beginning of the interval of values that the given parameter should have to be printed.
  */
void WriteVectorFilter( vectorreg vect,const string parameter,string& param_value_start,string& param_value_end)
{
    unsigned short first,last;

    if(parameter=="id")
    {
           first = param_value_start==""?0:ToUShort(param_value_start);
           last = param_value_end==""?65535:ToUShort(param_value_end);
            if(first>last)
            {
                unsigned short p = first;
                first=last;
                last=p;
            }
            Sort(vect,parameter);
    }

    if(parameter=="date")
    {
        param_value_start = param_value_start==""?"1.1.1":param_value_start;
        param_value_end = param_value_end==""?"31.12.65535":param_value_end;

        if(DateCmp(param_value_start,param_value_end)>0)
            {
                string p = param_value_start;
                param_value_start=param_value_end;
                param_value_end=p;
            }
        DateSort(vect);
    }
//cout<<first<<endl<<last<<endl;



    for(unsigned short i = 0;i<vect.size;i++)
    {
        //cout<<"Param: "<<parameter<<"F:"<<first<<"<="<<vect[i].id<<"L: "<<vect[i].id<<endl;
        if(parameter=="id"&&first<=vect.arreg[i].id&&last>=vect.arreg[i].id)
        {
            WriteReg(vect.arreg[i]);
        }
        else if(parameter=="date"&&DateCmp(param_value_start,vect.arreg[i].date)<=0&&DateCmp(param_value_end,vect.arreg[i].date)>=0)
        {
            WriteReg(vect.arreg[i]);
        }




    }
    return;
}
/**
 * @brief Function that causes printing an entire registration database into the console. Overloaded by type.
 * @param vect Array-size struct containing registration info.
 */
void WriteVector(const vectorreg vect)
{
    for(unsigned int i = 0;i<vect.size;i++)
    {
    WriteReg(vect.arreg[i]);
    }
    return;
}
/**
 * @brief Function that causes printing a standard C++ vector content into the console.
 * @param vect Vector to be written.
 */
void WriteVector(const vector<string> vect)
{
    for(unsigned int i = 0;i<vect.size();i++)
    {
    cout<<vect[i]<<",";

    }
    cout<<endl;
    return;
}
/**
 * @brief Function rewriting file containing registration information.
 * @param reglist Registration database.
 * @param autoback Flag determining whether the registration file should be backed up when rewrited. Off by default.
 * @param roomfile  Path to the file containing room data. Used as inter-jump argument,as this function contains CopyFile function.
 * @param roombackup    Path to the file containing backup of room data. Used as inter-jump argument,as this function contains CopyFile function.
 * @param regfile  Path to the file containing registration data.
 * @param regbackup  Path to the file containing backup registration data in case of backup needed.
  */
void WriteRegFile( vectorreg reglist,bool autoback,const string roomfile,const string roombackup,const string regfile,const string regbackup)
{
    Sort(reglist,"id");
    string regheader = "ID mistnosti\tdatum rezervace";
    ofstream oreg(regfile.c_str());
    oreg<<regheader<<endl;
    for(unsigned int i =0;i<reglist.size;i++)
    {

        oreg << reglist.arreg[i].id<<"\t"<<reglist.arreg[i].date<<endl;


    }
    oreg.close();

    if(autoback)
    {
        cout<<"Backing up registration file"<<endl;
        CopyFile(regfile,regbackup,roomfile,roombackup,regfile,regbackup);
        cout<<"Backup completed"<<endl;

    }
    return;
}
