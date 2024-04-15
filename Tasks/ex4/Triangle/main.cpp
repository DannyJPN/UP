#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   double a,b,c,s;

    cout<<"Zadejte delky stran trojuhelnika a, b, c:"<<endl;
    cin>>a>>b>>c;
    s=(a+b+c)/2;
    double S = sqrt(s*(s-a)*(s-b)*(s-c));


    if(a>0&&b>0&&c>0&&S>0)
        {
           cout<<"Obsah trojuhelnika je "<<S<<endl;
        }
    else
        {
            cout<<"Nejedna se o platny trojuhelnik."<<endl;
        }



    return 0;
}
