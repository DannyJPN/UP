#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a,b,c,x1,x2,D;
cout<<"Zadejte parametry:"<<endl;
cin>>a>>b>>c;
D=pow(b,2)-4*a*c;
if(D<0)
{
	cout<<"Rovnice nemá řešení v R"<<endl;
}
else
{
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	cout<<"Koren 1: "<<x1<<endl<<"Koren 2: "<<x2<<endl;
}


    return 0;
}
