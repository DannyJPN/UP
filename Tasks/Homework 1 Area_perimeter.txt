#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void)
{
	char shapetype;
	double squareside,rectangle_a,rectangle_b,radius;
	cout<<"Zadejte rovinny obrazec, jehoz obsah a obvod chcete spocitat: a - ctverec, b - obdelnik, c - kruh"<<endl;
	cin>>shapetype;
	if(cin.fail())
	{
		cout<<"Nespravny vstup."<<endl;
	}
	switch(shapetype)
	{
	case 'a':
		{
			cout<<"Zadejte stranu ctverce:"<<endl;
			cin>>squareside;
			if(cin.fail()||(!cin.fail()&&squareside<=0))
			{
				cout<<"Nespravny vstup."<<endl;
			}
			else
			{
				cout<<"Obsah ctverce je: "<<fixed<<setprecision(4)<<pow(squareside,2)<<endl;
				cout<<"Obvod ctverce je: "<<fixed<<setprecision(4)<<4*squareside<<endl;

			}
			break;
		};
	case 'b':
		{
			cout<<"Zadejte strany obdelniku:"<<endl;
			cin>>rectangle_a>>rectangle_b;
			if(cin.fail()||(!cin.fail()&&(rectangle_a<=0||rectangle_b<=0)))
			{
				cout<<"Nespravny vstup."<<endl;
			}
			else
			{
				cout<<"Obsah obdelniku je: "<<fixed<<setprecision(4)<<rectangle_a*rectangle_b<<endl;
				cout<<"Obvod obdelniku je: "<<fixed<<setprecision(4)<<2*(rectangle_a+rectangle_b)<<endl;

			}
			break;
		};
	case 'c':
		{
			cout<<"Zadejte polomer kruznice:"<<endl;
			cin>>radius;
			if(cin.fail()||(!cin.fail()&&radius<=0))
			{
				cout<<"Nespravny vstup."<<endl;
			}
			else
			{
				cout<<"Obsah kruznice je: "<<fixed<<setprecision(4)<<M_PI*pow(radius,2)<<endl;
				cout<<"Obvod kruznice je: "<<fixed<<setprecision(4)<<2*M_PI*radius<<endl;

			}
			break;
		};
	default:
		{
			cout<<"Nespravny vstup."<<endl;			
			break;
		};



	}


return 0;

}
