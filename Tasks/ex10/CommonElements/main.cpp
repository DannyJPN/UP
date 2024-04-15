
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

bool Find(int* p,int searched,int length)
{
    for(int i = 0;i<length;i++)
    {
        //cout<<p[i]<<"=="<<searched<<"=>"<<(p[i]==searched)<<endl;
        if(p[i]==searched)
        {
        return true;
        }
    }
    return false;
}

void Write(int*p,int length)
{
    for(int i = 0;i<length;i++)
    {
        if(i!=0) cout<<", ";
        cout<<p[i];

    }
    //cout<<endl;
}


int main()
{

    unsigned int length1,length2,index=0;
cout<<"Zadejte pocet prvku mnoziny A:"<<endl;
cin>>length1;
if(cin.peek()!='\n'||cin.fail()||(int)length1<=0)
    {
    cout<<"Nespravny vstup."<<endl;
    return 1;
    }
int* v1 = new int[length1];
cout<<"Zadejte prvky mnoziny A:"<<endl;
while(index<length1)
{
    cin>>v1[index];

    if(cin.fail()||(cin.peek()!=' '&&cin.peek()!='\n')||(index>0&&Find(v1,v1[index],index-1)))
   {
        cout<<"Nespravny vstup."<<endl;
       delete[] v1;
       return 1;
   }
   index++;
}
cin.ignore();
index=0;





cout<<"Zadejte pocet prvku mnoziny B:"<<endl;
cin>>length2;
if(cin.peek()!='\n'||cin.fail()||(int)length2<=0)
    {
    cout<<"Nespravny vstup."<<endl;
    delete[] v1;
    return 1;
    }
int* v2 = new int[length2];
cout<<"Zadejte prvky mnoziny B:"<<endl;
while(index<length2)
{
    cin>>v2[index];


    if(cin.fail()||(cin.peek()!=' '&&cin.peek()!='\n')||(index>0&&Find(v2,v2[index],index-1)))
   {
        cout<<"Nespravny vstup."<<endl;
       delete[] v1;
       delete[] v2;

       return 1;
   }
   index++;
}
cin.ignore();
index=0;
//Write(v1,length1);
//Write(v2,length2);
int validlength=length1<length2?length2:length1;
int* common = new int[validlength];

cout<<"Prunik mnozin:"<<endl<<"{";

        for(unsigned int i = 0;i<length1;i++)
        {

            if(Find(v2,v1[i],length2))
            {

                    common[index++]=v1[i];
            }
        }
        Write(common,index);
    cout<<"}"<<endl;
       delete[] v1;
       delete[] v2;
       delete[] common;
       return 0;
}
