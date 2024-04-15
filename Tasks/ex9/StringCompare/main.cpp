#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;



int main()
{
    string a,b,c;
    cout << "Zadejte 3 slova:" << endl;
    getline(cin,a,' ');
    getline(cin,b,' ');
    getline(cin,c,'\n');

    for(int i = 0;i<(int)a.length();i++)
    {
        a[i]=tolower(a[i]);
    }
    for(int i = 0;i<(int)b.length();i++)
    {
        b[i]=tolower(b[i]);
    }
    for(int i = 0;i<(int)c.length();i++)
    {
        c[i]=tolower(c[i]);
    }



    if(a.empty()||b.empty()||c.empty())
    {
        cout<<"Nespravny vstup."<<endl;
        return 0;
    }


    if(strcmp(a.c_str(),b.c_str())==0)
    {
        cout<<"Slovo1 a slovo2 jsou stejna."<<endl;
    }
    else
    {
        cout<<"Slovo1 a slovo2 nejsou stejna."<<endl;
    }


    if(strcmp(a.c_str(),c.c_str())==0)
    {
        cout<<"Slovo1 a slovo3 jsou stejna."<<endl;
    }
    else
    {
        cout<<"Slovo1 a slovo3 nejsou stejna."<<endl;
    }

    if(strcmp(c.c_str(),b.c_str())==0)
    {
        cout<<"Slovo2 a slovo3 jsou stejna."<<endl;
    }
    else
    {
        cout<<"Slovo2 a slovo3 nejsou stejna."<<endl;
    }

    cout<<"Pocet znaku ve slovo1 je: "<<a.length()<<endl;
    cout<<"Pocet znaku ve slovo2 je: "<<b.length()<<endl;
    cout<<"Pocet znaku ve slovo3 je: "<<c.length()<<endl;


    return 0;
}
