
#include <iostream>
#include <string>
using namespace std;

bool BinaryCheck(string num)
{
    for(unsigned int i = 0;i<num.length();i++)
    {
        if(num[i]!='1'&&num[i]!='0')
        return false;
    }
    return true;
}


int main()
{
    string bin1,bin2;
string check;
    cout<<"Zadejte dve binarni cisla:"<<endl;
    getline(cin,bin1,' ');
    getline(cin,bin2,'\n');

if(!BinaryCheck(bin1)||!BinaryCheck(bin2)||bin2.empty()||bin1.empty())
{
    cout<<"Nespravny vstup."<<endl;
    return 0;
}

if(bin1.length()<bin2.length())
{
    string p = bin1;
    bin1=bin2;
    bin2=p;

}
 for(int j = bin2.length()-1;j>=0;j--)
 {
     bin1[bin1.length()-1-j]+=(bin2[bin2.length()-1-j]-48);
     for(int i = bin1.length()-1-j;i>=0;i--)
    {

     if(bin1[i]>'1')
     {
         bin1[i]='0';
        if(i==0)
        {
         bin1 = "1"+bin1;
        }
        else
        {
         bin1[i-1]++;
        }
     }
else
{
    break;
}
    }


 }

while(bin1[0]=='0'&&bin1.length()!=1)
{
    bin1 = bin1.substr(1);
}


 cout<<"Soucet: "<<bin1<<endl;





    return 0;
}
