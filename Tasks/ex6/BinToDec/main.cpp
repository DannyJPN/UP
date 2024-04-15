#include <iostream>
#include <string>
using namespace std;

int main()
{
   long long dec = 0;
   long long bin =0;
   char single = 0 ;


   cout<<"Zadej cislo ve dvojkove soustave:"<<endl;
single=cin.get();
if(single==10)
{

cout<<"Nespravny vstup."<<endl;
return 0;

}

while(cin.good()&&single!='\n')
    {
    if(!(single=='1'||single=='0'||single=='\n'))
        {
            cout<<"Nespravny vstup."<<endl;
            return 0;
        }
        else
        {
    bin = single=='1'?1:0;

            dec=2*dec+bin;
        }
single=cin.get();

    }

cout<<"Desitkove cislo je: "<<dec<<endl;
    return 0;
}
