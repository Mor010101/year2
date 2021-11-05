#include<iostream>
#include<string.h>
using namespace std;


class mamifer{
    protected:
        char *type;
    public:
        mamifer(char *tip){
            type=new char[strlen(tip)];
            strcpy(type,tip);
        }
        ~mamifer(){
            delete type;
        }
};

class cangur : public mamifer {
    int num;
    public:
        cangur();
        
        cangur(char *type, int n) : mamifer(type){  
            num=n;
        }
        
        //~cangur(); //automatically calls '~mamifer' dtor
        
        void printCa(){
            cout<<"Type= "<<type<<"\n";
            cout<<"Number= "<<num<<"\n";
        }

};

void readEither(char *type, int &n){
    cout<<"Tip: ";
    cin.getline(type,20);
    cout<<"Nr: ";
    cin>>n;
}

int main()
{
    cangur obj1;
    char type[20];
    int n;
    readEither(type,n);
    obj1=cangur(type,n);
    obj1.printCa();
    return 0;

}