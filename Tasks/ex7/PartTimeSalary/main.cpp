#include <iostream>

using namespace std;

int main()
{
   cout<<"Zadej pocet navstevniku:"<<endl;
   unsigned int visitors;
      cin>>visitors;
   if(cin.fail()||(int)visitors<0||cin.peek()!='\n')
   {
   cout<<"Nespravny vstup."<<endl;
   return 0;
   }
double turnover = 0.07*visitors*50;

unsigned short salary_per_hour=70;
/*for(int i = 2000;i<turnover;i+=500)
{
    if(i>3500)break;
    salary_per_hour +=10;

}*/
if(turnover<2000) salary_per_hour=70;
else if (turnover>=2000&&turnover<2500) salary_per_hour=80;

else if (turnover>=2500&&turnover<3000) salary_per_hour=90;

else if (turnover>=3000&&turnover<3500) salary_per_hour=100;
else salary_per_hour=110;
unsigned int salary = 8*salary_per_hour;
cout<<"Brigadnik vydela: "<<salary<<" Kc"<<endl;

    return 0;
}
