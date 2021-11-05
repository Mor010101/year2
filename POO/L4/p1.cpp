#include<iostream>

using namespace std;


class jucator{
    int varsta;
    string nume;
    public:
        jucator();
        jucator(string name, int age){
            nume=name;
            varsta=age;
        }
    friend class tenisman;
};

class tenisman : protected jucator{
    int wins;
    public:
        tenisman();
        
        tenisman(string name, int age, int vict):jucator(name,age){
            wins=vict;
        }
};

int main()
{
    tenisman *vect;
    int opt,wins,age,k=1;
    char name[20];
    do{
        cout<<"0.Iesire\n1.Adaugare\n2.Cautare nume\n3.Stergere(nr turnee)\n4.Afisare\nOPT=";
        cin>>opt;
        switch(opt){
            case 1:
                vect = new tenisman[k];
                k++;
                
        }
    }while(opt!=0);

}