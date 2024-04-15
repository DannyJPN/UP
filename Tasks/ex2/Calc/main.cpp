#include <iostream>

using namespace std;

int main()
{
    double x,y;
    cout<< "Zadej 1. cislo:"<<endl;
    cin>>x;
    cout<< "Zadej 2. cislo:"<<endl;
    cin>>y;
    cout<< "Zadali jste:"<<endl<<x<<" a "<<y<<endl;
    cout<<x<<" + "<<y<<" = "<<x+y<<endl;
    cout<<x<<" - "<<y<<" = "<<x-y<<endl;
    cout<<x<<" * "<<y<<" = "<<x*y<<endl;
    cout<<x<<" / "<<y<<" = "<<x/y<<endl;

    return 0;
}
