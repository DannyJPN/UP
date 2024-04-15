#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include "commands.hpp"
#include "database.hpp"
#include "fileoperations.hpp"
#include "csharp.hpp"
#include "dateoperations.hpp"
#include "stdout.hpp"
#include "htmlexp.hpp"


using namespace std;


/**
 * @brief Major function file.Contains core function.
 * @file commands.cpp
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
 * @brief Major,complex function. This is the core of command execution process.
 * @param com   Name of the command inserted by the user.
 * @param autoback  Flag,that decides whether the room and registration databases are automatically backed up when edited. This flag is off by default.
 * @param roomfile  Path to the file that contains room database.
 * @param roombackup  Path to the room database backup file.
 * @param regfile  Path to the file that contains registration database.
 * @param regbackup  Path to the registration database backup file.
 */
void Execute(const string com,bool& autoback,const string roomfile,const string roombackup,const string regfile,const string regbackup)
{



string fileheader;
switch(FindID(com).ID)
{
   case 0:
       {
       //cout<<"nothing"<<endl;
       break;
       };
    case 1:
        {


             cout<<"Registering"<<endl;
             vectorroom roomdatabase = LoadRoomFile(fileheader,roomfile,roombackup,regfile,regbackup);
             short roomindex = FindRoom(roomdatabase,0);

             if(roomindex!=-1&&roomdatabase.size==1)
             {
                cout<<"ERROR File containing room info is damaged."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                break;
             }
             if(roomdatabase.size==0)
             {
                cout<<"File containing room info is empty.\nRegistration process terminated."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                break;
             }



             vectorreg regdatabase = LoadRegFile(fileheader,roomfile,roombackup,regfile,regbackup);
             short regindex = FindReg(regdatabase,0,"0.0.0000");
            if(regindex!=-1&&regdatabase.size==1)
             {
                cout<<"ERROR File containing registration info is damaged."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                break;
             }
             if(regdatabase.size==0)
             {
                cout<<"File containing reg info is empty."<<endl;

             }

            // cout<<fileheader<<endl;
            // WriteVector(regdatabase);
             string IDmem;
             unsigned short ID;
             cout<<"Room ID: ";
             getline(cin,IDmem,'\n');
            if(!IsUShort(IDmem))
            {
                cout<<"Invalid room ID.\nRegistration process terminated."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                break;
            }
            ID = ToUShort(IDmem);


            roomindex = FindRoom(roomdatabase,ID);

            if(roomindex!=-1)
            {
                string date;
                cout<<"Date (DD.MM.YYYY format): ";
                getline(cin,date,'\n');

                if(IsFutureOrPresentDate(date)<=0)
                {
                    cout<<"Invalid date.\nRegistration process terminated."<<endl;
                    delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                    delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                    break;
                }
                 regindex = FindReg(regdatabase,ID,date);
                if(regindex!=-1)
                {
                    cout<<"Room "<<ID<<" is already registered on "<<date<<"."<<endl;
                    delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                    break;

                }
                else
                {
                    reg newreg = {ID,date};

                   PushBack( regdatabase,newreg);
                    Sort(regdatabase,"id");
                    WriteRegFile(regdatabase,autoback,roomfile,roombackup,regfile,regbackup);


                  cout<<"Room "<<ID<<" registered on "<<date<<"."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                }
            }
            else
            {
                cout<<"This room does not exist.\nRegistration process terminated."<<endl;
               delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                break;
            }
             cout<<"Register completed"<<endl;
            break;
        };
    case 2:
        {

            vectorroom roomdatabase = LoadRoomFile(fileheader,roomfile,roombackup,regfile,regbackup);
            short roomindex = FindRoom(roomdatabase,0);
             if(roomindex!=-1&&roomdatabase.size==1)
             {
                cout<<"ERROR File containing room info is damaged."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;

                break;
             }
             if(roomdatabase.size==0)
             {
                cout<<"File containing room info is empty."<<endl;

                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;

                break;
             }
            WriteVector(roomdatabase);
            ExportVector(roomdatabase);
            delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;

            break;
        };
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        {

            stringstream mem(com);
            string commandcore;
            mem>>commandcore;
            string param = com.substr(commandcore.length()+1,com.length()-commandcore.length());

            string firstmem,lastmem;
            unsigned short first,last;
            cout<<"Insert "<<param<<" from: ";
            getline(cin,firstmem,'\n');
            cout<<"Insert "<<param<<" to: ";
            getline(cin,lastmem,'\n');
            if(!IsUShort(firstmem)||!IsUShort(lastmem))
            {
                cout<<"Invalid "<<param<<endl;
                break;
            }

            first=firstmem==""?0:ToUShort(firstmem);
            last=lastmem==""?65535:ToUShort(lastmem);



            vectorroom roomdatabase = LoadRoomFile(fileheader,roomfile,roombackup,regfile,regbackup);
            //cout<<fileheader.substr(0,8)<<"\t"<<fileheader.substr(8,fileheader.length()-8)<<endl;
            Sort(roomdatabase,param);
            WriteVectorFilter(roomdatabase,param,first,last);
            ExportVectorFilter(roomdatabase,param,first,last);
            delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;


            break;
        };
    case 8:
        {
            if(!autoback)
            {
            cout<<"Automatic backup activated"<<endl;
            autoback=true;

            }
            else
            {
            cout<<"Automatic backup deactivated"<<endl;
            autoback=false;

            }

            break;
        };
    case 9:
        {
            cout<<"EXIT"<<endl;
            exit(0);
        };
    case 10:
        {
           vectorreg regdatabase = LoadRegFile(fileheader,roomfile,roombackup,regfile,regbackup);
            short regindex = FindReg(regdatabase,0,"0.0.0000");
             if(regindex!=-1&&regdatabase.size==1)
             {
                cout<<"ERROR File containing reg info is damaged."<<endl;

                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                break;
             }
             if(regdatabase.size==0)
             {
                cout<<"File containing reg info is empty."<<endl;

             }
            WriteVector(regdatabase);
            ExportVector(regdatabase);

            break;

        }
    case 11:
    case 12:
        {
            const string commandcore = "showreg";
            string param = com.substr(commandcore.length()+1,com.length()-commandcore.length()-1);
            string guider = param=="date"?"(DD.MM.YYYY format)":"";
            string firstmem,lastmem;

            cout<<"Insert "<<param<<guider<<" from: ";
            getline(cin,firstmem,'\n');
            cout<<"Insert "<<param<<guider<<" to: ";
            getline(cin,lastmem,'\n');
            if((!IsUShort(firstmem)||!IsUShort(lastmem))&&param=="id")
            {
                cout<<"Invalid "<<param<<endl;
                break;
            }

            if((!IsValidDate(firstmem)||!IsValidDate(lastmem))&&param=="date"&&firstmem!=""&&lastmem!="")
            {
                cout<<"Invalid "<<param<<endl;
                break;
            }




            vectorreg regdatabase = LoadRegFile(fileheader,roomfile,roombackup,regfile,regbackup);
            //cout<<fileheader.substr(0,8)<<"\t"<<fileheader.substr(8,fileheader.length()-8)<<endl;

            WriteVectorFilter(regdatabase,param,firstmem,lastmem);
            ExportVectorFilter(regdatabase,param,firstmem,lastmem);

                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
            break;
        };
    case 13:
        {
           cout<<"Backing up room information file."<<endl;
            CopyFile(roomfile,roombackup,roomfile,roombackup,regfile,regbackup);
            cout<<"Backing up registration information file."<<endl;
            CopyFile(regfile,regbackup,roomfile,roombackup,regfile,regbackup);
             cout<<"Backup completed successfully."<<endl;
             break;
        };
    case 14:
        {
            cout<<"Backing up room information file."<<endl;
            CopyFile(roomfile,roombackup,roomfile,roombackup,regfile,regbackup);
            cout<<"Backup completed successfully."<<endl;
            break;
        };
    case 15:
        {
            cout<<"Backing up registration information file."<<endl;
            CopyFile(regfile,regbackup,roomfile,roombackup,regfile,regbackup);
            cout<<"Backup completed successfully."<<endl;
            break;
        };
    case 16:
        {

             cout<<"Unregistering"<<endl;
             vectorroom roomdatabase = LoadRoomFile(fileheader,roomfile,roombackup,regfile,regbackup);
             short roomindex = FindRoom(roomdatabase,0);
             if(roomindex!=-1&&roomdatabase.size==1)
             {
                cout<<"ERROR File containing room info is damaged."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;

                break;
             }
             if(roomdatabase.size==0)
             {
                cout<<"File containing room info is empty."<<endl;

             }



             vectorreg regdatabase = LoadRegFile(fileheader,roomfile,roombackup,regfile,regbackup);
             short regindex = FindReg(regdatabase,0,"0.0.0000");
            if(regindex!=-1&&regdatabase.size==1)
             {
                cout<<"ERROR File containing registration info is damaged."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                break;
             }
             if(regdatabase.size==0)
             {
                cout<<"File containing reg info is empty."<<endl;

             }

            // cout<<fileheader<<endl;
            // WriteVector(regdatabase);
             string IDmem;
             unsigned short ID;
             cout<<"Room ID: ";
             getline(cin,IDmem,'\n');
            if(!IsUShort(IDmem))
            {
                cout<<"Invalid room ID.\nDeregistration process terminated."<<endl;
               delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                break;
            }
            ID=ToUShort(IDmem);





                string date;
                cout<<"Date (DD.MM.YYYY format): ";
                getline(cin,date,'\n');
                if(!IsValidDate(date))
                {
                    cout<<"Invalid date.\nDeregistration process terminated."<<endl;
                    delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                    break;
                }
                 regindex = FindReg(regdatabase,ID,date);
                if(regindex==-1)
                {
                    cout<<"Room "<<ID<<" is not registered on "<<date<<"."<<endl;
                    delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                    break;

                }
                else
                {


                    Erase(regdatabase,regindex);
                    WriteRegFile(regdatabase,autoback,roomfile,roombackup,regfile,regbackup);


                  cout<<"Room "<<ID<<" deregistered from "<<date<<"."<<endl;
                delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
                }


             cout<<"Register deletion completed"<<endl;
            break;
        };
    case 17:
        {
               cout<<"register\t\tRegisters a new room according to its ID and requested date"<<endl;
               cout<<"showroom\t\tShows a room database "<<endl;
               cout<<"\tid\t\tFilters and sorts output by room ID"<<endl;
               cout<<"\tfloor\t\tFilters and sorts output by floor of room"<<endl;
               cout<<"\tnumber\t\tFilters and sorts output by room number"<<endl;
               cout<<"\tseats\t\tFilters and sorts output by number of seats in the rooms"<<endl;
               cout<<"\tcost\t\tFilters and sorts output by daily cost of the rooms"<<endl;
               cout<<"autobackup\t\tEnables/disables automatic backup of files"<<endl;
               cout<<"exit\t\t\tEnds the program"<<endl;
               cout<<"showreg\t\t\tShows a registration database"<<endl;
               cout<<"\tid\t\tFilters and sorts output by floor of room"<<endl;
               cout<<"\tdate\t\tFilters and sorts output by floor of room"<<endl;
               cout<<"backup\t\t\tBacks up all databases"<<endl;
               cout<<"backuproom\t\tBacks up room database"<<endl;
               cout<<"backupreg\t\tBacks up registration database"<<endl;
               cout<<"unregister\t\tDeletes a registration according to the ID of registered room and the date of registration"<<endl;
               cout<<"help\t\t\tDisplays list of available commands and their meaning"<<endl;
               cout<<"findfreeroom\t\tPrompts the user for criteria of the room and a date and finds all rooms\n\t\t\tfiltered by given criteria  that are free on given day"<<endl;
               cout<<"showclosereg\t\tShows an user-given number of registrations since today"<<endl;

        break;
        }
    case 18:
        {
            cout<<"Starting advanced search manager."<<endl;
            string params[11];

            cout<<"Insert ID from:";
            getline(cin,params[0],'\n');
            if(params[0]!=""&&!IsUShort(params[0]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert ID to:";
            getline(cin,params[1],'\n');
            if(params[1]!=""&&!IsUShort(params[1]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert floor from:";
            getline(cin,params[2],'\n');
            if(params[2]!=""&&!IsUShort(params[2]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert floor to:";
            getline(cin,params[3],'\n');
            if(params[3]!=""&&!IsUShort(params[3]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert number from:";
            getline(cin,params[4],'\n');
            if(params[4]!=""&&!IsUShort(params[4]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert number to:";
            getline(cin,params[5],'\n');
            if(params[5]!=""&&!IsUShort(params[5]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert seats from:";
            getline(cin,params[6],'\n');
            if(params[6]!=""&&!IsUShort(params[6]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert seats to:";
            getline(cin,params[7],'\n');
            if(params[7]!=""&&!IsUShort(params[7]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert cost from:";
            getline(cin,params[8],'\n');
            if(params[8]!=""&&!IsUShort(params[8]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert cost to:";
            getline(cin,params[9],'\n');
            if(params[9]!=""&&!IsUShort(params[9]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }
            cout<<"Insert date (DD.MM.YYYY format):";
            getline(cin,params[10],'\n');
            if(!IsValidDate(params[10]))
            {
                cout<<"Invalid parameter value"<<endl;
                break;
            }




            vectorroom roomdatabase = LoadRoomFile(fileheader,roomfile,roombackup,regfile,regbackup);
            vectorreg regdatabase = LoadRegFile(fileheader,roomfile,roombackup,regfile,regbackup);
            WriteVectorAdvancedFilter(roomdatabase,regdatabase,params,sizeof(params)/sizeof(string));
            ExportVectorAdvancedFilter(roomdatabase,regdatabase,params,sizeof(params)/sizeof(string));
            delete[] roomdatabase.arroom; roomdatabase.arroom=nullptr;
            delete[] regdatabase.arreg; regdatabase.arreg=nullptr;


            break;
        };

    case 19:
        {
            string htmlname;
            unsigned short amount;
            string amountmem;
            cout<<"Specify number of registrations since today: ";
            getline(cin,amountmem,'\n');
            if(!IsUShort(amountmem))
            {
                cout<<"Invalid number"<<endl;
                break;
            }
            amount = ToUShort(amountmem);
            cout<<"Specify export filename:";
            getline(cin,htmlname,'\n');
            if(htmlname.length()<5||htmlname.substr(htmlname.length()-5,5)!=".html")
            {
                htmlname.append(".html");
            }
           htmlname=htmlname==".html"?"../vystupnidata/closeregs.html":htmlname;
           ofstream ohtml(htmlname);
            if(ohtml.fail())
            {
                cout<<"Location unknown"<<endl;
                ohtml.close();
                break;
            }
            vectorreg regdatabase = LoadRegFile(fileheader,roomfile,roombackup,regfile,regbackup);
            ohtml<<htmlpart1<<"Next "<<amount<<" registrations"<<htmlpart2;
            ohtml<<htmlrowstart<<htmlcellstart<<"ID"<<htmlcellend;
            ohtml<<htmlcellstart<<"Date"<<htmlcellend<<htmlrowend;


            int firstpresent = FindFirstPresent(regdatabase);
            for( int i =firstpresent;i<firstpresent+amount&&i<regdatabase.size;i++)
            {
                WriteReg(regdatabase.arreg[i]);
                ohtml<<RegHtml(regdatabase.arreg[i])<<endl;
            }
             ohtml<<htmlpart3<<endl;
                  ohtml.close();
                delete[] regdatabase.arreg; regdatabase.arreg=nullptr;
            break;
        }





    default:
        {
        cout<<"Unknown command"<<endl;
        break;
        }


}
return;






}

