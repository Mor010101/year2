#include<iostream>
#include<string.h>

using namespace std;

class jucarie{
    public:
        string nume, material, culoare;
        jucarie(){}
        jucarie(string name, string mat, string colr){
            nume=name;
            material=mat;
            culoare=colr;
        }
};

class j_boy : protected jucarie{
    protected:
        int w,h,l;
    public:
        j_boy(){}
        j_boy(string name, string mat, string colr, int width, int length, int height):jucarie(name,mat,colr){
            w=width;
            l=length;
            h=height;
        }
};

class car : public j_boy{
    int max_spd;
    public:
        car(){}
        car(string name, string mat, string colr, int width, int length, int height, int m_spd):j_boy( name,  mat,  colr,  width,  length,  height){    //this seems utterly stupid
            max_spd=m_spd;
        }
};

int main()
{
    car masina[20];
    char nume[20],material[20],culoare[20];
    int l,w,h,v_max,opt;
    do{
        cout<<"Selectati optiunea: \n0.Iesire\n1.Add entry\n2.Afisare\n3.Cautare dupa nume\n4.Stergere dupa vit max\n";
        switch(opt){
            case 1:
        }
    }while(opt!=0);


}