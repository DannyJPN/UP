#include <iostream>

using namespace std;

int main()
{
 int length ;
   cout<<"Zadejte pocet schodu:"<<endl;
   cin>>length;
   if(cin.fail()||length<=0)
   {
       cout<<"Nespravny vstup."<<endl;
   }
   else
    {
        for(int i =0;i<length;i++)
            {
                for(int j = 0;j<i;j++)
                {
                    cout<<"X";
                }
            cout<<"_"<<endl;
            }
    }

    return 0;
}
