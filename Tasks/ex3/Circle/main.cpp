#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double ax,bx,ay,by;


cout<<"Zadejte souradnice bodu A a B:"<<endl;
cin>>ax>>ay;
cin>>bx>>by;
cout<<"X-ova souradnice stredu S je: "<<(ax+bx)/2<<endl;
cout<<"Y-ova souradnice stredu S je: "<<(ay+by)/2<<endl;
cout<<"Smerovy vektor u ma delku: "<<sqrt(pow(bx-ax,2)+pow(by-ay,2))<<endl;
cout<<"Polomer kruznice r ma hodnotu: "<<sqrt(pow(bx-ax,2)+pow(by-ay,2))/2<<endl;



    return 0;
}
