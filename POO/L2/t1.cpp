#include<iostream>
#include<string.h>

using namespace std;

class masina{
    char *culoare;
    int pret,viteza;
        public:
        masina(char *colour, int price, int t_spd){
            culoare= new char[strlen(colour)];
            strcpy(culoare,colour);
            pret=price;
            viteza=t_spd;
        }
        masina(){           //default constructor
            culoare=new char[6];
            strcpy(culoare,"rosie");
            pret=10000;
            viteza=250;
        }
        ~masina(){
            delete culoare;
        }
        void printCar(){
            cout<<"\n==========================\n";
            cout<<"Culoare: "<<culoare<<"\n";
            cout<<"Pret: "<<pret<<"\n";
            cout<<"Viteza: "<<viteza<<"\n";
        }
};

void readCar(char *clr, int *price, int *t_spd)
{
    cout<<"Culoare: "; cin.getline(clr,20);
    cout<<"Pret: "; cin>>*price;
    cout<<"Viteza: "; cin>>*t_spd;
}

int main()
{
    char clr[20];
    int price, t_spd;
    readCar(clr,&price,&t_spd);
    masina car1(clr,price,t_spd),car2;
    car1.printCar();
    car2.printCar();

    return 0;
}