#include<iostream>
#include<string.h>
using namespace std;

class electrocasnic{
    protected:
        string nume;
        int pret;
    public:
        electrocasnic(){}
        electrocasnic(string name, int price){
            this->nume=name;
            this->pret=price;
        }

        void printCasnic();
};

void electrocasnic::printCasnic(){
    cout<<"Nume: "<<this->nume<<"\n";
    cout<<"Pret: "<<this->pret<<"\n";
}

class mixer : public electrocasnic{
    int putere,nr_vit;
    public:
        mixer(){}
        mixer(string name, int price, int power,int spd) : electrocasnic(name,price){
            this->putere=power;
            this->nr_vit=spd;
        }
    void printMixer();
};

class cantar : public electrocasnic{
    int max_kg;
    public:
        cantar(){}
        cantar(string name, int price, int mx_Kg) : electrocasnic(name,price){
            this->max_kg=mx_Kg;
        }
        void printCantar();
};

void mixer::printMixer(){
    cout<<"Nume: "<<this->nume<<"\n";
    cout<<"Pret: "<<this->pret<<"\n";
    cout<<"Putere: "<<this->putere<<"\n";
    cout<<"Nr viteze: "<<this->nr_vit<<"\n";
}

void cantar::printCantar(){
     cout<<"Nume: "<<this->nume<<"\n";
    cout<<"Pret: "<<this->pret<<"\n";
    cout<<"Max kg: "<<this->max_kg<<"\n";
}

int main()
{
    mixer obj1;
    cantar obj2;
    char nume[20];
    int pret,putere,nr_vit;

    cout<<"Nume: "; cin.getline(nume,20);
    cout<<"Pret: "; cin>>pret;
    cout<<"Putere: "; cin>>putere;
    cout<<"Numar vit: "; cin>>nr_vit;

    obj1=mixer(nume,pret,putere,nr_vit);
    
    cout<<"Nume: "; cin.getline(nume,20);
    cout<<"Pret: "; cin>>pret;
    cout<<"Max_Kg: "; cin>>putere;
    obj2=cantar(nume,pret,putere);

    obj1.printMixer();
    obj2.printCantar();
    return 0;
}