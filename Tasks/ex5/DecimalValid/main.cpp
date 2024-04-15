#include <iostream>

using namespace std;

int main()
{
   double x ;
   cout<<"Zadejte cislo:"<<endl;
   cin>>x;
   if(cin.fail()||cin.peek()!='\n')
    {
        cout<<"Chybne zadani."<<endl;
    }
   else
    {
      cout<<x<<" : Spravne zadane cislo."<<endl;
    }
    return 0;
}
