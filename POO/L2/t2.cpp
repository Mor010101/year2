#include<iostream>
#include<string.h>
using namespace std;

class forma{
    string denumire;
    int arie;
    public:
        forma(string name, int srf){
            
            denumire=name;
            arie=srf;
        }

        forma(){  }  //blank def constructor

        
        void printForma(){
            cout<<"\nForma cu aria maxima:\n";
            cout<<"Denumire: "<<this->denumire<<"\n";
            cout<<"Arie: "<<this->arie<<"\n";
        }
};

int main()
{
    int i,srf,max_srf=INT32_MIN,max_id;
    string name;
    forma shape[5];
    
    for(i=0;i<5;i++){
        printf("Nume: "); cin>>name;
        printf("Arie: "); cin>>srf;
        
        if(srf>max_srf){
            max_id=i;
            max_srf=srf;
        }

        shape[i] = forma(name,srf);
        
    }
    //cout<<" max= "<<max_id<<"\n";
    shape[max_id].printForma();
    
    return 0;
}