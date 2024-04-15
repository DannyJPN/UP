#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>
using namespace std;

void WriteArray(double*& x,unsigned int length)
{
    for(unsigned int i =0;i<length;i++)
    {
        cout<<x[i]<<",";
    }
    cout<<endl;
}
double Scalary(double*& a,double*& b,unsigned int length)
{
    double sum=0;
    double one=0;
    for(unsigned int i = 0;i<length;i++)
    {
    one = a[i]*b[i];
    sum+=one;
    }
return sum;


}

double VectorSize(double*& x,unsigned int length)
{
    double veclength=0;
    for(unsigned int i = 0;i<length;i++)
    {
    veclength+=pow(x[i],2);


    }

    return sqrt(veclength);

}







int main()
{

    unsigned int index = 0;
   unsigned int length;
   cin>>length;
   if(cin.fail()||cin.peek()!='\n'||(int)length<=0)
   {
    cout<<"Nespravny vstup."<<endl;
       return 1;
   }
        double* v1 = new double[length];
        double* v2 = new double[length];
        cin.ignore();






while(index<length)
{
    cin>>v1[index];
    index++;
    if(cin.fail()||(cin.peek()!=' '&&cin.peek()!='\n'))
   {
        cout<<"Nespravny vstup."<<endl;
       delete[] v1;delete[] v2;return 1;
   }
}
cin.ignore();
index=0;



while(index<length)
{
    cin>>v2[index];
    index++;
    if(cin.fail()||(cin.peek()!=' '&&cin.peek()!='\n'))
   {
 cout<<"Nespravny vstup."<<endl;
       delete[] v1;delete[] v2;return 1;
   }
}
//WriteArray(v1,length);
//WriteArray(v2,length);
cout<<fixed<<setprecision(3)<<"CSM: "<<Scalary(v1,v2,length)/(VectorSize(v1,length)*VectorSize(v2,length))<<endl;

delete[] v1;delete[] v2;
    return 0;
}
