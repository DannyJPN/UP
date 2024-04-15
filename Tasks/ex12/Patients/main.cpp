#include <iostream>

using namespace std;

struct patient
{
    string name,surname,diagnosis;
    long long born_num,insurance_company_number;
};

int main()
{
    const  int size = 5;
    patient patients [size];
    for(int i = 0;i<size;i++)
    {
    cout << "Zadejte prijmeni, jmeno, rodne cislo, nemoc a zdravotni pojistovnu pacienta:"<< endl;
    cin>>patients[i].surname>>patients[i].name>>patients[i].born_num>>patients[i].diagnosis>>patients[i].insurance_company_number;

    }



    for(int i = 0;i<size;i++)
    {
        if(patients[i].diagnosis=="tbc")
        {

            cout<<"Jmeno a prijmeni pacienta s tbc:"<<endl<<patients[i].name<<" "<<patients[i].surname<<endl;
        }
        if(patients[i].insurance_company_number==211)
        {

            cout<<"Jmeno a prijmeni pacientu s pojistovnou 211 je:"<<endl<<patients[i].name<<" "<<patients[i].surname<<endl;
        }


    }
    cout << "Prijmeni vsech pacientu jsou:"<< endl;
    for(int i = 0;i<size;i++)
    {
    cout<<patients[i].surname<<endl;

    }


    return 0;
}
