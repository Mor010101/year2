#include<iostream>
#include<string.h>

using namespace std;

class prof{
    char *name,*departament,*grad;
    int vechime;

    public:
        prof(char *nm, char *dep, char *grd, int ani);
        ~prof();
        void printProf();
};

prof::prof(char *nm, char *dep, char *grd, int ani)
{
    name= new char[strlen(nm)];
    departament= new char[strlen(dep)];
    grad= new char[strlen(grd)];
    vechime = ani;
    strcpy(name,nm);
    strcpy(departament,dep);
    strcpy(grad,grd);
}
prof::~prof()
{
    delete name; delete departament; delete grad;
    printf("~~Cleared Mem~~");
}

void prof::printProf()
{
    cout<<"\n=================\n";
    cout<<"Nume: "; cout<<name<<"\n";
    cout<<"Departament: "; cout<<departament<<"\n";
    cout<<"Grad: "; cout<<grad<<"\n";
    cout<<"An: "; cout<<vechime<<"\n";
}

int main()
{
    char nume[20], departament[20], grad[20];
    int vechime;
    cout<<"Nume: "; cin.getline(nume,20);
    cout<<"Departament: "; cin.getline(departament,20);
    cout<<"Grad: "; cin.getline(grad,20);
    cout<<"An: "; cin>>vechime;
    prof test(nume,departament,grad,vechime);
    test.printProf();

    return 0;

}