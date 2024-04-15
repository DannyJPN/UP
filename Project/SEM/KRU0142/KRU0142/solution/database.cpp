#include "database.hpp"
#include "dateoperations.hpp"


/**
 * @brief File containing functions needed for working with database in the table form.
 * @file database.cpp
 * @author Dan Krupa
 */


const Command Coms []=
{
    {0,"no operation"},
    {1,"register"},
    {2,"showroom"},
    {3,"showroom id"},
    {4,"showroom floor"},
    {5,"showroom number"},
    {6,"showroom seats"},
    {7,"showroom cost"},
    {8,"autobackup"},
    {9,"exit"},
    {10,"showreg"},
    {11,"showreg id"},
    {12,"showreg date"},
    {13,"backup"},
    {14,"backup room"},
    {15,"backup reg"},
    {16,"unregister"},
    {17,"help"},
    {18,"findfreeroom"},
    {19,"showclosereg"}

};

/**
 * @brief Function that sorts the registrations by date in an ascending order.
 * @param reglist   Registration database to be sorted.
 */
void DateSort(vectorreg& reglist)
{
    if(reglist.size<2)
    {
        return ;
    }
    bool ex=true;
    reg helper;
    while(ex)
    {
        ex=false;
        for(unsigned int i = 0;i<reglist.size-1;i++)
        {
            if(DateCmp(reglist.arreg[i].date,reglist.arreg[i+1].date)>0)
            {
            helper = reglist.arreg[i];
            reglist.arreg[i]= reglist.arreg[i+1];
             reglist.arreg[i+1]=helper;
             ex=true;
            }
        }
    }
    return;
}
/**
 * @brief Function that checks whether the given room is already registered on a given day.
 * @param regs     Registration database to be searched.
 * @param id        ID of a room that should be checked.
 * @param date      Date for which the room should be checked.
 * @return Function returns TRUE if the room is registered on given day,and FALSE if it is not registered.
*/

bool Registered(const vectorreg regs,const unsigned short id,const string date)
{

    for(unsigned int i = 0;i<regs.size;i++)
    {
        if((id==regs.arreg[i].id)&&(DateCmp(date,regs.arreg[i].date)==0))
        {
            return true;
        }
    }
    return false;
}
/**
 * @brief Function that checks whether and where the given room exists by its ID.
 * @param rooms     Room database to be searched.
 * @param searchedID   ID of the room that should be found.
 * @return Function returns index of the room in the database if found,else it returns -1.
*/

short FindRoom(const vectorroom rooms,const unsigned short searchedID)
{
    for(unsigned int i =0;i<rooms.size;i++)
    {
        if(rooms.arroom[i].id==searchedID)
            return i;
    }
    return -1;
}
/**
 * @brief Function that checks whether and where the given registration exists by its ID and date.
 * @param regs     Registration database to be searched.
 * @param searchedID   ID of the registered room that should be found.
 * @param searcheddate  Date on which the searched room should be found as registered.
 * @return Function returns index of the registration in the database if found,else it returns -1.
*/

short FindReg(const vectorreg regs,const unsigned short searchedID,const string searcheddate)
{
    for(unsigned int i =0;i<regs.size;i++)
    {
        if(regs.arreg[i].id==searchedID&&regs.arreg[i].date==searcheddate)
            return i;
    }
    return -1;
}

/**
 * @brief Function that transfers a command name to full Command entity so that the execution method can uniquely identify the command.
 * @param com_name     Name of the command.
 * @return Function returns unique system ID of a command.Returns -1 if command does not exist.
*/

Command FindID(const string com_name)
{
    for(unsigned int i = 0;i<sizeof(Coms)/8;i++)
    {
        if(Coms[i].name==com_name)
            return Coms[i];
    }
    Command invalid = {-1,"invalid"};
    return invalid;
}

/**
 * @brief Function that uses BubbleSort algorithm with exchange detection flag to sort a room database in an ascending order.
 * @param roomlist  Database of rooms that is to be sorted.
 * @param param  Name of the parameter by which the database should be sorted.
*/

void Sort(vectorroom& roomlist,string param)
{
    if(roomlist.size<2)
    {
        return ;
    }
    bool ex=true;
    room helper;
    while(ex)
    {ex=false;
        for(unsigned int i = 0;i<roomlist.size-1;i++)
        {
            if(roomlist.arroom[i].id>roomlist.arroom[i+1].id&&param=="id")
            {
            helper = roomlist.arroom[i];
            roomlist.arroom[i]= roomlist.arroom[i+1];
             roomlist.arroom[i+1]=helper;
             ex=true;
            }
            if(roomlist.arroom[i].floor>roomlist.arroom[i+1].floor&&param=="floor")
            {
            helper = roomlist.arroom[i];
            roomlist.arroom[i]= roomlist.arroom[i+1];
             roomlist.arroom[i+1]=helper;
             ex=true;
            }
            if(roomlist.arroom[i].number>roomlist.arroom[i+1].number&&param=="number")
            {
            helper = roomlist.arroom[i];
            roomlist.arroom[i]= roomlist.arroom[i+1];
             roomlist.arroom[i+1]=helper;
             ex=true;
            }
            if(roomlist.arroom[i].seats>roomlist.arroom[i+1].seats&&param=="seats")
            {
            helper = roomlist.arroom[i];
            roomlist.arroom[i]= roomlist.arroom[i+1];
             roomlist.arroom[i+1]=helper;
             ex=true;
            }
            if(roomlist.arroom[i].cost>roomlist.arroom[i+1].cost&&param=="cost")
            {
            helper = roomlist.arroom[i];
            roomlist.arroom[i]= roomlist.arroom[i+1];
             roomlist.arroom[i+1]=helper;
             ex=true;
            }



        }
    }
    return;
}

/**
 * @brief Function that uses BubbleSort algorithm with exchange detection flag to sort a registration database in an ascending order.
 * @param reglist  Database of registrations that is to be sorted.
 * @param param  Name of the parameter by which the database should be sorted.
*/

void Sort(vectorreg& reglist,string param)
{
    if(reglist.size<2)
    {
        return ;
    }
    if(param=="id")
    {

        bool ex=true;
        reg helper;
        while(ex)
        {
            ex=false;
            for(unsigned int i = 0;i<reglist.size-1;i++)
            {
                if(reglist.arreg[i].id>reglist.arreg[i+1].id)
                {
                helper = reglist.arreg[i];
                reglist.arreg[i]= reglist.arreg[i+1];
                reglist.arreg[i+1]=helper;
                ex=true;
                }
            }
        }
    }
    else if(param=="date")
    {
        DateSort(reglist);
    }
    return;
}


/**
 * @brief Function which finds the first following registration from today's date.
 * @param regs  Database of registrations that is to be sorted.
 * @return Returns index of the registration that comes first after today or directly today.If such a registration does not exist,function returns -1.
*/

int FindFirstPresent(vectorreg& regs)
{
    DateSort(regs);
    for(unsigned int i = 0;i<regs.size;i++)
    {
        if(DateCmp(TodayDateStr(),regs.arreg[i].date)<=0)
        {
            return i;
        }
    }
    return -1;
}

