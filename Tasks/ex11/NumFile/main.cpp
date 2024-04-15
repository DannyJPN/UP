#ifndef __PROGTEST__
#include <iostream>
#include <cstdlib>

#include <fstream>
#include <vector>
#endif /* __PROGTEST__ */

using namespace std;
#define ERROR 0
#define OK    1




bool IsNum(const string text)
{
    if((text[0]!='-'&&!isdigit(text[0]))||text=="-")
    {
        return false;
    }

    for(unsigned int i =1;i<text.length();i++)
    {
        if(!isdigit(text[i]))
           {
               return false;
           }
    }
    return true;
}


int evenOdd ( const char * srcFileName, const char * dstFileName )
 {
   ifstream infile(srcFileName);
   if(!infile.is_open())
   {

       return ERROR;
   }


   ofstream offile(dstFileName);
if(!offile.is_open())
{

       return ERROR;
}




string x;

while(infile>>x)
   {

        if(!IsNum(x))
       {
           infile.close();
           offile.close();
           return ERROR;
       }

       if(atoi(x.c_str())%2==0)
       {
        offile<<x<<endl;;

       }

   }
infile.close();

infile.open(srcFileName);


while(infile>>x)
   {

        if(!IsNum(x))
       {
           infile.close();
           offile.close();
           return ERROR;
       }

       if(atoi(x.c_str())%2!=0)
       {
        offile<<x<<endl;;

       }

   }
infile.close();
offile.close();




return OK;



 }

#ifndef __PROGTEST__
int main ( )
 {
int x= evenOdd("test.txt","output.txt");
cout<<x<<endl;
return x;
 }
#endif /* __PROGTEST__ */








