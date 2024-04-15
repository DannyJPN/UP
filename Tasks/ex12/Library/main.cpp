#include <iostream>

using namespace std;

struct book
{
    string name,author_surname,author_name,type;
    int year,price,ID;
};

int main()
{
    const  int size = 5;
    book books [size];
    for(int i = 0;i<size;i++)
    {
    cout << "Zadej nazev knihy, prijmeni autora, jmeno autora, zanr knihy, rok vydani, cenu a id:"<< endl;
    cin>>books[i].name>>books[i].author_surname>>books[i].author_name>>books[i].type>>books[i].year>>books[i].price>>books[i].ID;

    }

    cout<<"Romany jsou:"<<endl;

    for(int i = 0;i<size;i++)
    {
        if(books[i].type=="roman")
        {
            cout<<books[i].name<<endl;
        }
    }
    cout<<endl<<"Knihy s cenou mensi nez 300,- Kc jsou:"<<endl;
    for(int i = 0;i<size;i++)
    {
        if(books[i].price<300)
        {
            cout<<books[i].name<<endl;
        }
    }
    cout<<endl<<"Prijmeni vsech autoru jsou:"<<endl;
    for(int i = 0;i<size;i++)
    {
            cout<<books[i].author_surname<<endl;

    }


    return 0;
}
