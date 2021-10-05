#include<iostream>
#include<string.h>
using namespace std;

class sofer{
    private:
        int cnp, varsta;
        char nume[20], adresa[100];
    public:
        void setDriver(int id, int age, char name[], char adr[]){
            cnp=id;
            varsta=age;
            strcpy(nume,name);
            strcpy(adresa,adr);
        }

        void printDriver(){
            cout<<"Nume: "<<nume<<"\nCNP: "<<cnp<<"\nVarsta: "<<varsta<<"\nAdresa: "<<adresa;
        }

};

class car{
    private:
        char make[20], model[20];
        int year;
        sofer driver;
    public:
    void setCar(char mk[],char mdl[],int yr, sofer drv){
        strcpy(make,mk);
        strcpy(model,mdl);
        year=yr;
        driver=drv;
    }
    void printCar(){
        cout<<"\n=======car=========\nMarca: "<<make<<"\nModel: "<<model<<"\nAn: "<<year<<"\n======driver=======\n";
        driver.printDriver();
    }
};

void readDriver(sofer &ex){
    int id, age;
    char name[20], adr[100];
    cout<<"Nume: "; cin>>name;
    cout<<"CNP: "; cin>>id;
    cout<<"Varsta: "; cin>>age;
    cout<<"Adresa: "; cin.getline(adr,100); cin.getline(adr,100);
    ex.setDriver(id, age, name, adr);
}

void readCar(car &cex, sofer ex){
    char make[20],model[20];
    int year;
    cout<<"Marca: "; cin.getline(make,20);
    cout<<"Model: "; cin.getline(model,20);
    cout<<"Year: "; cin>>year;
    cex.setCar(make,model,year,ex);
}
int main()
{
    sofer uno;
    car dos;
    readDriver(uno);
    //uno.printDriver();
    readCar(dos,uno);
    dos.printCar();
    return 0;
}