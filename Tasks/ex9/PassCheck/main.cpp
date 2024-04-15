#include <iostream>

using namespace std;

bool Validate(string pass)
{
    if((int)pass.length()<5)
    {
        return false;
    }
    int valids = 0;

for(int i = 0;i<(int)pass.length();i++)
{
    if(isalpha(pass[i]))
    {
        valids++;
  //      cout<<"FOUND: "<<pass[i]<<endl;
        break;
    }
}
for(int i = 0;i<(int)pass.length();i++)
{
    if(isdigit(pass[i]))
    {
        valids++;
//cout<<"FOUND: "<<pass[i]<<endl;
        break;
    }
}
for(int i = 0;i<(int)pass.length();i++)
{
    if((!isalpha(pass[i])&&(!isdigit(pass[i]))))
    {
        valids++;
        //cout<<"FOUND: "<<pass[i]<<endl;
        break;
    }
}
//cout<<valids<<endl;
if(valids<3)
{
    return false;
}
return true;

}



int main()
{
    string password;
    getline(cin,password);
    if(Validate(password))
    {
        cout<<"Heslo splnuje pozadavky."<<endl;
    }
    else
    {
        cout<<"Heslo nesplnuje pozadavky."<<endl;

    }

    return 0;



}
