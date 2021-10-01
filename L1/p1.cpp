#include <iostream>

using namespace std;

int main()
{
    char nume[20],prenume[20],adresa[100];
    int varsta, tel;
    cout<<"Nume: "; cin>>nume;
    cout<<"Prenume: "; cin>>prenume;
    cout<<"Adresa: "; cin.getline(adresa,100); cin.getline(adresa,100);  //primul getline citeste caracterul asociat lui enter
    cout<<"Varsta: "; cin>>varsta;
    cout<<"Telefon: "; cin>>tel;
    cout<<"\n";
    cout<<nume<<" "<<prenume<<"\n"<<adresa<<"\n"<<varsta<<" 0"<<tel;
    return 0;
}