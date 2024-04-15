#include <iostream>
#include <string>
#include <istream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (cin.peek()!='\n'||N<=0||cin.fail())
    {
        cout << "Nespravny vstup." << endl;
        return 0;
    }

    double *prvky1 = new double[N];
    double *prvky2 = new double[N];

    for (int i=0,j=0;i<N;i++)
    {
       j++;
       cin >> prvky1[i];
       if (cin.peek()=='\n'&&(j<N)||(cin.peek()!='\n'&&(j>N-1)))
       {
           cout << "Nespravny vstup." << endl;
           return 0;
           delete[] prvky1;
           delete[] prvky2;
       }
    }

    for (int i=0,j=0;i<N;i++)
    {
       j++;
       cin >> prvky2[i];
       if ((cin.peek()=='\n'&&j<N)||(!(cin.peek()=='\n')&&j>N-1))
       {
           cout << "Nespravny vstup." << endl;
           return 0;
           delete[] prvky1;
           delete[] prvky2;
       }
    }

    double citatel=0, prvniodmocnina=0, druhaodmocnina=0, vysledek;

    for (int i=0;i<N;i++)
    {
        citatel = citatel+(prvky1[i] * prvky2[i]);
        prvniodmocnina = prvniodmocnina+(prvky1[i]*prvky1[i]);
        druhaodmocnina = druhaodmocnina+(prvky2[i]*prvky2[i]);

    }

    vysledek = citatel/((sqrt(prvniodmocnina))*(sqrt(druhaodmocnina)));

    cout << "CSM: " << fixed << setprecision(3) << vysledek << endl;
    delete[] prvky1;
    delete[] prvky2;


    return 0;
}
