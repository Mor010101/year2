#include<iostream>
#include<string.h>
using namespace std;

class carte{
    private:
        char titlu[20],autor[20],editura[20];
        int an_p;
    public:
        carte(char title[],char auth[],char publ[], int year);
        void printCarte();
};

carte::carte(char title[],char auth[],char publ[], int year)
{
    strcpy(titlu,title);
    strcpy(autor,auth);
    strcpy(editura,publ);
    an_p=year;
}

void carte::printCarte()
{
    cout<<"\n=========================\n";
    cout<<"Titlu: "; cout<<titlu<<"\n";
    cout<<"Autor: "; cout<<autor<<"\n";
    cout<<"Editura: "; cout<<editura<<"\n";
    cout<<"An: "; cout<<an_p<<"\n";
} 

int main()
{
    char titlu[20],autor[20],editura[20];
    int an_p;
    
    cout<<"Titlu: "; cin.getline(titlu,20);
    cout<<"Autor: "; cin.getline(autor,20);
    cout<<"Editura: "; cin.getline(editura,20);
    cout<<"An: "; cin>>an_p;
    carte prima(titlu,autor,editura,an_p);
    prima.printCarte();

    return 0;
}