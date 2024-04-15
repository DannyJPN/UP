#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EASTER_OK                0
#define EASTER_INVALID_FILENAME  1
#define EASTER_INVALID_YEARS     2
#define EASTER_IO_ERROR          3


#endif /* __PROGTEST__ */


const string htmltop =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n"
"<html>\n"
"<head>\n"
"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n"
"<title>C++</title>\n"
"</head>\n"
"<body>\n"
"<table width=\"300\">\n"
"<tr><th width=\"99\">den</th><th width=\"99\">mesic</th><th width=\"99\">rok</th></tr>\n";
const string htmlbottom =
"</table>\n"
"</body>\n"
"</html>\n";

void WriteVect(vector<string> vect)
{
    for(unsigned int i = 0;i<vect.size();i++)
    {
        cout<<vect[i]<<endl;
    }

}
void WriteVect(vector<unsigned int> vect)
{
    for(unsigned int i = 0;i<vect.size();i++)
    {
        cout<<vect[i]<<endl;
    }

}

string Trim(string text)
{
    while(text[0]==' ')
    {
        text = text.substr(1,text.length()-1);
    }
    while(text[text.length()-1]==' ')
    {
        text = text.substr(0,text.length()-1);
    }
    return text;

}

bool IsYear(const string text)
{
    if(text.length()>4)
    {
        return false;
    }
    for(unsigned int i =0;i<text.length();i++)
    {
        if(!isdigit(text[i]))
           {
               return false;
           }
    }
    return true;
}

unsigned int ToNum(const string text)
{
    unsigned int number;
    stringstream memory(text);
    memory>>number;
    return number;
}

vector<string> Split(const string text,const char delim)
{
    vector< int> indexes {-1};
    vector<string> splitted;
    string temp;
    for(unsigned int i =0;i<text.length();i++)
    {
        if(text[i]==delim)
        {
            indexes.push_back(i);
        }
    }
indexes.push_back(text.length());

    for(unsigned int i=0;i<indexes.size()-1;i++)
    {
        temp = Trim(text.substr(indexes.at(i)+1,indexes.at(i+1)-indexes.at(i)-1));
        splitted.push_back(temp);
    }

return splitted;

}
bool IsRange(string range)
{
    int minuscount=0   ;
    int minusindex = -1;
    for(unsigned int i =0;i<range.length();i++)
    {
        if(range[i]=='-')
        {
            minusindex=i;
            minuscount++;
            if(minusindex==0||minusindex==(int)range.length()-1)
            {
                return false;
            }

        }


    }
    if(minuscount!=1)
    {
        return false;
    }
return true;


}

bool IsYearRange(string yearrange)
{
    if(!IsRange(yearrange))
    {
        return false;
    }

vector<string> borders = Split(yearrange,'-');
//WriteVect(borders);
for(unsigned int i =0;i<borders.size();i++)
{
    if(!IsYear(borders[i]))
    {
    return false;
    }

}
if(ToNum(borders[0])>ToNum(borders[1]))
{
    return false;
}




return true;
}




vector <unsigned int> GetYearRange(string text)
{
    vector<unsigned int> range;
    vector<string> borders = Split(text,'-');
        for(unsigned int i = ToNum(borders[0]);i<=ToNum(borders[1]);i++)
        {
            range.push_back(i);
        }
        return range;

}

vector<unsigned int> MajorSplit(string years)
{
    vector<string> parts = Split(years,',');
vector<unsigned int> numparts;
//WriteVect(parts);

for(unsigned int i = 0;i<parts.size();i++)
{
    if(IsYear(parts[i]))
    {
        numparts.push_back(ToNum(parts[i]));
    }
    else if (IsYearRange(parts[i]))
    {
        vector <unsigned int> range = GetYearRange(parts[i]);
        for(unsigned int j = 0;j<range.size();j++)
        {
            numparts.push_back(range[j]);
        }
    }
    else
    {

        numparts.clear();
        return numparts;
    }
}

for(unsigned int i=0;i<numparts.size();i++ )
{

    if(numparts[i]<1582||numparts[i]>2200)
    {
          numparts.clear();
return numparts;
    }
}



return numparts;
}


bool ValidFileName(string filename)
{

    for(unsigned int i =0;i<filename.length();i++)
    {
        if(!isdigit(filename[i])&&!isalpha(filename[i])&&filename[i]!='\\'&&filename[i]!='/'&&filename[i]!='.')
        {
            return false;
        }
    }

    if(filename.length()<5||filename.substr(filename.length()-5,5)!=".html")
    {
        return false;
    }


    return true;
}

struct Date
{
    int day;
    string month;
    int year;
};

Date EasterDate(unsigned int Y)
{
    int A = Y%19;
    int B = Y/100;
    int C = Y%100;
    int D = B/4;
    int E = B%4;
    int F = (B+8)/25;
    int G = (B-F+1)/3;
    int H = (19*A + B - D - G + 15)%30;
    int I = C/4;
    int K = C%4;
    int L = (32 + 2*E + 2*I - H - K)%7;
    int M = (A + 11*H + 22*L)/451;
    int N = (H + L - 7*M + 114)/31;
    int P = (H + L - 7*M + 114)%31;

    Date easter;
    easter.day = P+1;
    easter.year=Y;
    switch(N)
    {
    case 3:
        {
            easter.month="brezen";
            break;
        }

    case 4:
        {
            easter.month="duben";
            break;
        }
    default:
        {
            easter.month = "iny";
            break;
        }

    }

   return easter;






}


string EasterString(Date easter)
{
    stringstream line ;
    line<< "<tr><td>";
    line<<easter.day;
    line<<"</td><td>";
    line<<easter.month;
    line<<"</td><td>";
    line<<easter.year;
    line<<"</td></tr>\n";
    return line.str();
}

int easterReport( const char * years, const char * outFileName )
{
    if(!ValidFileName(outFileName))
    {

        return EASTER_INVALID_FILENAME;
    }
    vector<unsigned int> yeartotal = MajorSplit(years);

    if(yeartotal.size()==0)
    {

        return EASTER_INVALID_YEARS;
    }
    ofstream writer(outFileName);

     if(!writer)
        {
            writer.close();
        return EASTER_IO_ERROR;
        }


    writer<<htmltop;
for(unsigned int i =0;i<yeartotal.size();i++)
{
    writer<<EasterString(EasterDate(yeartotal[i]));
}
writer<<htmlbottom;
writer.close();
return EASTER_OK;

}


#ifndef __PROGTEST__
int main( )
{
    string years= "2000-2003";
  // WriteVect(GetYearRange("2010   -  2050"));
  string filename = "../asdf/out5.html";
cout<<easterReport(years.c_str(),filename.c_str());

    return 0;
}
#endif /* __PROGTEST__ */
