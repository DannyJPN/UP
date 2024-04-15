#include <iostream>
#include <math.h>

using namespace std;

 double factorial(int n)
{
    if(n<=1)
    {
        return 1;
    }
    else
    {
        return round(n*factorial(n-1));
    }
}

double combination(int n,int k)
{
    return round(factorial(n)/(factorial(n-k)*factorial(k)));
}

int main()
{
    int n,k;

    cout<<"Zadejte n a k:"<<endl;
cin>>n>>k;
if(n>=k&&n>=0&&k>=0&&cin.good())
{
cout<<"C = "<<combination(n,k)<<endl;
}
else
{
  cout<<"Nespravny vstup."<<endl;
}

    return 0;
}
