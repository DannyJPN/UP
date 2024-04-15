#include <iostream>
#include <math.h>
using namespace std;

bool Prime(int n)
{
    if (n <=1)
    {
        return false;
    }

    for(int i = 2;i <=sqrt(n);i++)
        {
        if(n%i==0)
            {
                return false;
            }
        }


    return true;
}


int main()
{
    int lowborder;
    int highborder;


   cout<<"Zadejte interval:"<<endl;
   cin>>lowborder>>highborder;
   if(cin.fail()||lowborder>highborder)
   {
       cout<<"Nespravny vstup."<<endl;
       return 0;
   }

for(int i = lowborder<0?0:lowborder;i<=highborder;i++)
{
    if(Prime(i))
    {
       cout<<i<<","<<endl;
    }

}


    return 0;
}


