#include <iostream>

using namespace std;

int main()
{
    string name;
    int number;
    const int constant =3;
    cout<<"Zadej svoje jmeno (bez diakritiky): ";
    getline(cin,name);
    cout<<"Zadej cele cislo: ";
    cin>>number;
    cout<<"Ahoj, "<<name<<"."<<endl;
    cout<<number<<" x "<<constant<<" = "<<number*constant<<endl;
    cout<<number<<" / "<<constant<<" = "<<number/constant<<endl;



    return 0;
}
