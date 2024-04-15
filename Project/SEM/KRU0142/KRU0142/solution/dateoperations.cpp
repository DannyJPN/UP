#include <time.h>
#include <vector>
#include <sstream>
#include "csharp.hpp"
#include "dateoperations.hpp"

/**
 * @brief File containing functions for working with date.
 * @file dateoperations.cpp
 * @author Dan Krupa
 */


 /**
 * @brief Function is an analogy to function strcmp. Compares two dates.
 * @param date1 First date to be compared.
 * @param date2 Second date to be compared.
 * @return This function is analogic to strcmp,thus it returns -1 if first date is lower (=earlier),1,if the first date is higher (=later) or 0 if the dates are equal.
 */
short DateCmp(const string date1,const string date2)
{
    vector<string> date1_val = Split(date1,'.');
    vector<string> date2_val = Split(date2,'.');


    short equality=0;
    for(unsigned int i = date1_val.size()-1;(int)i>=0;i--)
    {

        if(ToUShort(date1_val[i])<ToUShort(date2_val[i]))
            equality=-1;
        else if((ToUShort(date1_val[i])>ToUShort(date2_val[i])))
            equality = 1;
        else equality = 0;
        if(equality!=0||i==0)
        {
            return equality;
        }
        equality=0;

    }
return equality;

}
/**
 * @brief Function that gives today's date as a string.
 * @return Returns today's date in European format (DD.MM.YYYY).
 */
string TodayDateStr()
{

time_t timer;
time(&timer);
struct tm* today=localtime(&timer);
string date = "";
stringstream mem;

mem<< (*today).tm_mday<<"."<<(*today).tm_mon+1<<"."<<(*today).tm_year+1900;
return mem.str();

}

 /**
 * @brief Function checks whether string is a valid date in DD.MM.YYYY format.
 * @param text  Text to be evaluated.
 * @return This function returns TRUE if the string is considered valid date,or FALSE when it is not.
 */
bool IsValidDate(const string text)
{


    unsigned short dates [3];
    vector<string> line=  Split(text,'.');
    if(line.size()!=3)
    {

        return false;
    }




    for(unsigned int i =0;i<line.size();i++)
    {
        if(IsUShort(line[i]))
        {

            dates[i]=ToUShort(line[i]);
        }
    }

    const unsigned short monthlengths[12]{31,dates[2]%4==0?(unsigned short)29:(unsigned short)28,31,30,31,30,31,31,30,31,30,31};
    if(dates[2]>0&&dates[2]<=65535&&dates[1]>0&&dates[1]<=12&&dates[0]>0&&dates[0]<=monthlengths[dates[1]-1])
    {

        return true;
    }




    return false;
}
 /**
 * @brief Function checks whether string is a valid present or future date in DD.MM.YYYY format.
 * @param text  Text to be evaluated.
 * @return This function returns 1 if the string is present or future date,0 if it is past date and -1 if it is not a date at all.
 */

short IsFutureOrPresentDate(const string text)
{
    if(IsValidDate(text))
    {
        if(DateCmp(text,TodayDateStr())>=0)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

