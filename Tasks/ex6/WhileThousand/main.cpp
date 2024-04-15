#include <iostream>

using namespace std;

int main()
{
   double sum = 0;
   double current = 0;
   cout<<"Zadavejte cisla, posledni bude 1000:"<<endl;
   do
    {
    cin>>current;
   sum+=current;
    }while(current!=1000);
   cout<<"Vysledek souctu cisel je: "<<sum<<endl;



    return 0;
}
