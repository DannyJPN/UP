#include <iostream>
#include <fstream>
#include <sstream>
#include "htmlexp.hpp"
#include "csharp.hpp"
#include "dateoperations.hpp"



using namespace std;

/**
 * @brief File operations sourcecode file
 * @file fileoperations.cpp
 * @author Dan Krupa
 */



const string htmlpart1 = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\"><html lang=\"cs\">  <head>    <meta http-equiv=\"content-type\" content=\"text/html; charset=windows-1250\">    <meta name=\"generator\" content=\"PSPad editor, www.pspad.com\">    <title>";
const string htmlpart2 = "</title>  </head>  <body>          <table border=\"5\" bordercolor=\"#000000\" cellpadding=\"10\">";
const string htmlrowstart = "<tr valign=\"middle\" align=\"center\">";
const string htmlcellstart = "<td align=\"center\" valign=\"middle\">";
const string htmlrowend = "</tr>";
const string htmlcellend = "</td>";
const string htmlpart3 = "</table>  </body></html>";


/**
 * @brief Overloaded function serving for exporting content of an array using the array-size structure into an HTML file.
 * @param vect  Array-size struct to be exported
 */
void ExportVector(const vectorroom vect)
{
    string htmlname;
    cout<<"Specify registration export filename:";
            getline(cin,htmlname,'\n');
            if(htmlname.length()<5||htmlname.substr(htmlname.length()-5,5)!=".html")
            {
                htmlname.append(".html");
            }
           htmlname=htmlname==".html"?"../vystupnidata/rooms.html":htmlname;
           ofstream ohtml(htmlname);
            if(ohtml.fail())
            {
                cout<<"Location unknown"<<endl;
                ohtml.close();
                return;
            }
                    ohtml<<htmlpart1<<"Rooms"<<htmlpart2;
                    ohtml<<htmlrowstart<<htmlcellstart<<"ID"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Floor"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Number"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Seats"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Cost/day"<<htmlcellend;

                    ohtml<<htmlrowend;

                    for(unsigned int i = 0;i<vect.size;i++)
                    {
                        ohtml<<RoomHtml(vect.arroom[i])<<endl;
                    }
                    ohtml<<htmlpart3<<endl;
                  ohtml.close();
}
/**
 * @brief Overloaded function serving for exporting content of an array using the array-size structure into an HTML file.
 * @param vect  Array-size struct to be exported
 */
void ExportVector(const vectorreg vect)
{
    string htmlname;
    cout<<"Specify registration export filename:";
            getline(cin,htmlname,'\n');
            if(htmlname.length()<5||htmlname.substr(htmlname.length()-5,5)!=".html")
            {
                htmlname.append(".html");
            }
           htmlname=htmlname==".html"?"../vystupnidata/registrations.html":htmlname;
           ofstream ohtml(htmlname);
            if(ohtml.fail())
            {
                cout<<"Location unknown"<<endl;
                ohtml.close();
                return;
            }
                    ohtml<<htmlpart1<<"Registrations"<<htmlpart2;
                    ohtml<<htmlrowstart<<htmlcellstart<<"ID"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Date"<<htmlcellend<<htmlrowend;

                    for(unsigned int i = 0;i<vect.size;i++)
                    {
                        ohtml<<RegHtml(vect.arreg[i])<<endl;
                    }
                    ohtml<<htmlpart3<<endl;
                  ohtml.close();
}

/**
 * @brief Overloaded function serving for exporting part of the content of an array using the array-size structure filtered and sorted by certain parameter into an HTML file.
 * @param vect  Array-size struct to be exported
 * @param parameter Parameter by which the array should be filtered and sorted.
 * @param param_value_start Beginning of the interval of values that the given parameter should have to be exported.
 * @param param_value_end Beginning of the interval of values that the given parameter should have to be exported.
 */
void ExportVectorFilter(const vectorreg vect,const string parameter,string& param_value_start,string& param_value_end)
{
    string htmlname;
       cout<<"Specify registration export filename:";
            getline(cin,htmlname,'\n');
            if(htmlname.length()<5||htmlname.substr(htmlname.length()-5,5)!=".html")
            {
                htmlname.append(".html");
            }
           htmlname=htmlname==".html"?"../vystupnidata/registrations-"+parameter+".html":htmlname;
           ofstream ohtml(htmlname);
            if(ohtml.fail())
            {
                cout<<"Location unknown"<<endl;
                ohtml.close();
                return;
            }
ohtml<<htmlpart1<<"Registrations filtered by "<<parameter<<htmlpart2;
                    ohtml<<htmlrowstart<<htmlcellstart<<"ID"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Date"<<htmlcellend<<htmlrowend;




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
    }
//cout<<first<<endl<<last<<endl;



    for(unsigned short i = 0;i<vect.size;i++)
    {
        //cout<<"Param: "<<parameter<<"F:"<<first<<"<="<<vect.arreg[i].id<<"L: "<<vect.arreg[i].id<<endl;
        if(parameter=="id"&&first<=vect.arreg[i].id&&last>=vect.arreg[i].id)
        {

            ohtml<<RegHtml(vect.arreg[i])<<endl;
        }
        else if(parameter=="date"&&DateCmp(param_value_start,vect.arreg[i].date)<=0&&DateCmp(param_value_end,vect.arreg[i].date)>=0)
        {

            ohtml<<RegHtml(vect.arreg[i])<<endl;
        }




    }
      ohtml<<htmlpart3<<endl;
                  ohtml.close();
    return;
}

/**
 * @brief Overloaded function serving for exporting part of the content of an array using the array-size structure filtered and sorted by certain parameter into an HTML file.
 * @param vect  Array-size struct to be exported
 * @param parameter Parameter by which the array should be filtered and sorted.
 * @param param_value_start Beginning of the interval of values that the given parameter should have to be exported.
 * @param param_value_end Beginning of the interval of values that the given parameter should have to be exported.
 */
void ExportVectorFilter(const vectorroom vect,const string parameter,unsigned short param_value_start, unsigned short param_value_end)
{
    string htmlname;
cout<<"Specify registration export filename:";
            getline(cin,htmlname,'\n');
            if(htmlname.length()<5||htmlname.substr(htmlname.length()-5,5)!=".html")
            {
                htmlname.append(".html");
            }
           htmlname=htmlname==".html"?"../vystupnidata/rooms-"+parameter+".html":htmlname;
           ofstream ohtml(htmlname);
            if(ohtml.fail())
            {
                cout<<"Location unknown"<<endl;
                ohtml.close();
                return;
            }
                    ohtml<<htmlpart1<<"Rooms filtered by "<<parameter<<htmlpart2;
                    ohtml<<htmlrowstart<<htmlcellstart<<"ID"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Floor"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Number"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Seats"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Cost/day"<<htmlcellend;

                    ohtml<<htmlrowend;


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
          ohtml<<RoomHtml(vect.arroom[i])<<endl;
        }



    }
    ohtml<<htmlpart3<<endl;
                  ohtml.close();
    return;
}

/**
 * @brief Function generating one HTML line of room database.
 * @param oneroom Room object to be transscripted.
 * @return Returns HTML table line containing one room info set.
 */
string RoomHtml(const room oneroom)
{
    stringstream line;
    line<<htmlrowstart<<endl;
    line<<htmlcellstart<<oneroom.id<<htmlcellend;
    line<<htmlcellstart<<oneroom.floor<<htmlcellend;
    line<<htmlcellstart<<oneroom.number<<htmlcellend;
    line<<htmlcellstart<<oneroom.seats<<htmlcellend;
    line<<htmlcellstart<<oneroom.cost<<htmlcellend<<endl;
line<<htmlrowend<<endl;
    return line.str();
}

/**
 * @brief Function generating one HTML line of registration database.
 * @param oneroom Registration object to be transscripted.
 * @return Returns HTML table line containing one registration info set.
 */
string RegHtml(const reg onereg)
{
    stringstream line;
    line<<htmlrowstart<<endl;
    line<<htmlcellstart<<onereg.id<<htmlcellend;
    line<<htmlcellstart<<onereg.date<<htmlcellend<<endl;
    line<<htmlrowend<<endl;
    return line.str();
}

/**
 * @brief Function generating HTML file containing rooms information filtered by several parameters simultaneously.
 * @param rooms Room database.
 * @param regs Registration database.
 * @param values Set of parameter values used for filtering.
 * @param paramcount Number of values used for filtering.
 */
void ExportVectorAdvancedFilter(const vectorroom rooms,const vectorreg regs,string values [],const unsigned short paramcount)
{


     string htmlname;
cout<<"Specify registration export filename:";
            getline(cin,htmlname,'\n');
            if(htmlname.length()<5||htmlname.substr(htmlname.length()-5,5)!=".html")
            {
                htmlname.append(".html");
            }
           htmlname=htmlname==".html"?"../vystupnidata/rooms_free_on_"+values[10]+".html":htmlname;
           ofstream ohtml(htmlname);
            if(ohtml.fail())
            {
                cout<<"Location unknown"<<endl;
                ohtml.close();
                return;
            }
                    ohtml<<htmlpart1<<"Rooms free on "<<values[10]<<htmlpart2;
                    ohtml<<htmlrowstart<<htmlcellstart<<"ID"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Floor"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Number"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Seats"<<htmlcellend;
                    ohtml<<htmlcellstart<<"Cost/day"<<htmlcellend;

                    ohtml<<htmlrowend;


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
            ohtml<<RoomHtml(rooms.arroom[i])<<endl;
        }



    }ohtml<<htmlpart3<<endl;
                  ohtml.close();
    return;
}
