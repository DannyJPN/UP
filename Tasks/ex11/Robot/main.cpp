#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

    const double MPI=3.1415926535897932384626433832795;
int main()
{
    double x,y,fi,delta,v,omega;
    unsigned int num;
    cin>>num;
    if(cin.fail()||(int)num<=0)
    {
        cout<<"Nespravny vstup."<<endl;
        return 1;
    }
cin>>x;
    if(cin.fail())
    {
        cout<<"Nespravny vstup."<<endl;
        return 1;
    }
    cin>>y;
    if(cin.fail())
    {
        cout<<"Nespravny vstup."<<endl;
        return 1;
    }
    cin>>fi;
    if(cin.fail())
    {
        cout<<"Nespravny vstup."<<endl;
        return 1;
    }
    cin>>delta;
    if(cin.fail())
    {
        cout<<"Nespravny vstup."<<endl;
        return 1;
    }

    cin>>v;
    if(cin.fail())
    {
        cout<<"Nespravny vstup."<<endl;
        return 1;
    }

    cin>>omega;
    if(cin.fail())
    {
        cout<<"Nespravny vstup."<<endl;
        return 1;
    }

for(unsigned int i = 0;i<num;i++)
{
x = x + v * delta * cos(fi);
y = y + v * delta * sin(fi);
fi = fi + delta * omega;
while(fi>2*MPI)
    {
    fi-=2*MPI;
    }
while(fi<0)
    {
    fi+=2*MPI;
    }

    cout<<fixed<<setprecision(2)<<"x: "<<x<<", y: "<<y<<", fi: "<<fi<<endl;
}

    return 0;
}
