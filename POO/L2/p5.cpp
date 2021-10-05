#include<iostream>
#include<string.h>
using namespace std;

class student{
    char *name,*role,*adrs;
    int *pCode;

    public:
        student(char nm[],char rol[], char adr[],int cpost){
             name = new char[strlen(nm)];
             role = new char[strlen(rol)];
             adrs = new char[strlen(adr)];
             pCode = new int;
             strcpy(name,nm);
             strcpy(role,rol);
             strcpy(adrs,adr);
             *pCode=cpost;   
        }
        ~student(){
            delete name; delete role; delete adrs; delete pCode;
            cout<<"Cleared mem\n";
        }
        void printStudent(){
            cout<<"\n==================\n";
            cout<<"Nume: "; cout<<name<<"\n";
            cout<<"Rol: "; cout<<role<<"\n";
            cout<<"Adresa: "; cout<<adrs<<"\n";
            cout<<"Cod Postal: "; cout<<*pCode<<"\n";
        }
};

int main()
{
    char nume[20],rol[20],adresa[20];
    int codP;
    cout<<"Nume: "; cin.getline(nume,20);
    cout<<"Rol: "; cin.getline(rol,20);
    cout<<"Adresa: "; cin.getline(adresa,20);
    cout<<"Cod Postal: "; cin>>codP;
    student test(nume,rol,adresa,codP);
    test.printStudent();
    
    return 0;
}