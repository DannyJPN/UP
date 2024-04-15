#include <iostream>
#include <string>
using namespace std;

int main()
{
   long long dec = 0;
   short hex;
   char single = 0;


   cout<<"Zadejte hexadecimalni cislo:"<<endl;
single=cin.get();
if(single==10)
{

cout<<"Nespravny vstup."<<endl;
return 0;

}

while(cin.good()&&single!='\n')
    {
    if(!((single>='0'&&single<='9')||(single>='A'&&single<='F')||(single>='a'&&single<='f')||( single=='\n')))
        {
            cout<<"Nespravny vstup."<<endl;
            return 0;
        }
        else
        {
            if(single>='0'&&single<='9')
                hex = single-48;
            else if(single>='A'&&single<='F')
                hex = single -55;
            else if(single>='a'&&single<='f')
                hex = single -87;


            dec=16*dec+hex;
        }
single=cin.get();

    }

cout<<"Desitkove: "<<dec<<endl;
    return 0;
}
