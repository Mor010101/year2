#include<iostream>
#include<string.h>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

class monitor{
    protected:
        string producator;
        int diagonala,pret;
    public:
        monitor();
        monitor(string prod, int diag, int prt){
            this->producator=prod;
            this->diagonala=diag;
            this->pret=prt;
        }
        void printMonitor(){
            cout<<"Producator: "<<this->producator<<"\n";
            cout<<"Diagonala: "<<this->diagonala<<"\n";
            cout<<"Pret: "<<this->pret<<"\n";
        }
        int returnPret(){
            return pret;
        }
        string returnProd(){
            return producator;
        }

};

class LCD : public monitor{
    int t_rasp;
    public:
        LCD();
        LCD(string prod,int diag,int prt, int trsp):monitor(prod,diag,prt){
            this->t_rasp=trsp;
        }
        void printLcd(){
            cout<<"===========LCD==OUT=========\n";
            printMonitor();
            cout<<"Timp Raspuns: "<<this->t_rasp<<"\n";
        }
};

class LED : public monitor{
    bool boxe;
    string f_ecran;
    public:
        LED();
        LED(string prod, int diag, int prt, bool box, string f_en):monitor(prod,diag,prt){
            boxe=box;
            f_ecran=f_en;
        }
        void printLED(){
            cout<<"===========LED==OUT=========\n";
            printMonitor();
            cout<<"Boxe incorporate: ";
                if(this->boxe==true)   cout<<"da\n";
                else    cout<<"nu\n";
            cout<<"Format ecran: "<<this->f_ecran<<"\n";
        }
};


void printListC(list <LCD*> l)
{
    list <LCD*> :: iterator i;
    LCD * c;
    for(i=l.begin(); i!=l.end(); i++){
        c = *i;
        c->printLcd();
    }
        
}

void printListE(list <LED*> l)
{
    list <LED*> :: iterator i;
    LED *c;
    for(i=l.begin(); i!=l.end(); ++i){
        c=*i;
        c->printLED();
    }
        
}

void addLCD(list <LCD*> &l)       //prod, diag, pret, t_rsp
{
    string prod;
    int diag,pret,t_rsp;
    cout<<"\n~~~~~~~~~LCD~~IN~~~~~~~~\n";
    cout<<"Producator: ";   getline(cin,prod);
    transform(prod.begin(), prod.end(), prod.begin(), ::tolower); //converts string to lowercase 
                                                                  //could've used strcasecmp....
    cout<<"Diagonala: ";    cin>>diag;
    cout<<"Pret: ";         cin>>pret;
    cout<<"Timp Raspuns: "; cin>>t_rsp;
    LCD *c = new LCD(prod,diag,pret,t_rsp);
    l.push_front(c);
}

void addLED(list <LED*> &l)       //prod, diag, pret, boxe, f_dsp
{
    char f_dsp[20];
    int diag,pret;
    char boxe;
    string prod;
    LED *c;
    cout<<"\n~~~~~~~~~LED~~IN~~~~~~~~\n";
    cout<<"Producator: ";   getline(cin,prod);
    transform(prod.begin(), prod.end(), prod.begin(), ::tolower); //converts string to lowercase 
                                                                  //could've used strcasecmp....
    cout<<"Diagonala: ";    cin>>diag;
    cout<<"Pret: ";         cin>>pret;
    cout<<"Boxe inc(Y/N): "; cin>>boxe; boxe=tolower(boxe);
        if(boxe == 'y')
            boxe = 1;
        else 
            boxe = 0;
    cout<<"Format Display: "; cin.getline(f_dsp,20); cin.getline(f_dsp,20);
    c = new LED(prod,diag,pret,boxe,f_dsp);
    l.push_front(c);
}

void del_LED(list <LED*> &l)
{
    string pid;
    int prt;
    list <LED*> :: iterator i;
    LED *c;
    
    cout <<"\nSTERGERE\nProducator:";
    getline(cin,pid);
    std :: transform(pid.begin(), pid.end(), pid.begin(), ::tolower);   //could've used strcasecmp....
    const char *temp1= pid.c_str();
    //std :: transform(temp1[0],temp1[strlen(temp1)],temp1[0], ::tolower);
    cout<<"Pret:"; cin>>prt;
    
    for(i=l.begin(); i!=l.end();i++){
        c=*i;
        if(prt == c->returnPret()){
            string prod=c->returnProd();
            const char *temp2 = prod.c_str();
            if (strcmp(temp1,temp2) == 0){
                l.erase(i);
                return;
            }else
                cout<<"Displayul cautat nu exista\n";
        }
        
    }
}

void del_LCD(list <LCD*> &l)
{
    string pid;
    int prt;
    list <LCD*> :: iterator i;
    LCD *c;
    
    cout <<"\nSTERGERE\nProducator:";
    getline(cin,pid);
    std :: transform(pid.begin(), pid.end(), pid.begin(), ::tolower);   //could've used strcasecmp....
    const char *temp1= pid.c_str();
    //std :: transform(temp1[0],temp1[strlen(temp1)],temp1[0], ::tolower);
    cout<<"Pret:"; cin>>prt;
    
    for(i=l.begin(); i!=l.end();i++){
        c=*i;
        if(prt == c->returnPret()){
            string prod=c->returnProd();
            const char *temp2 = prod.c_str();
            if (strcmp(temp1,temp2) == 0){
                l.erase(i);
                return;
            }else
                cout<<"Displayul cautat nu exista\n";
        }
        
    }
}

void searchLED(list <LED*> l)
{
    string pid;
    int prt;
    list <LED*> :: iterator i;
    LED *c;
    
    cout <<"\nCAUTARE\nProducator:";
    getline(cin,pid);
    std :: transform(pid.begin(), pid.end(), pid.begin(), ::tolower);   //could've used strcasecmp....
    const char *temp1= pid.c_str();
    //std :: transform(temp1[0],temp1[strlen(temp1)],temp1[0], ::tolower);
    cout<<"Pret:"; cin>>prt;
    
    for(i=l.begin(); i!=l.end();i++){
        c=*i;
        if(prt == c->returnPret()){
            string prod = c->returnProd();
            const char *temp2 = prod.c_str();
            if (strcmp(temp1,temp2) == 0){
                c->printLED();
                return;
            }else
                cout<<"Displayul cautat nu exista\n";
        }
        
    }
}


void searchLCD(list <LCD*> l)
{
    string pid;
    int prt;
    list <LCD*> :: iterator i;
    LCD *c;
    
    cout <<"\nCAUTARE\nProducator:";
    getline(cin,pid);
    std :: transform(pid.begin(), pid.end(), pid.begin(), ::tolower);   //could've used strcasecmp....
    const char *temp1= pid.c_str();
    //std :: transform(temp1[0],temp1[strlen(temp1)],temp1[0], ::tolower);
    cout<<"Pret:"; cin>>prt;
    
    for(i=l.begin(); i!=l.end();i++){
        c=*i;
        if(prt == c->returnPret()){
            string prod = c->returnProd();
            const char *temp2 = prod.c_str();
            if (strcmp(temp1,temp2) == 0){
                c->printLcd();
                return;
            }else
                cout<<"Displayul cautat nu exista\n";
        }
        
    }
}

void sortLED(list <LED*> &l)
{
    l.sort([](LED *a, LED *b) {return a->returnPret() < b->returnPret(); });
}

void sortLCD(list <LCD*> &l)
{
    l.sort([](LCD *a, LCD *b) {return a->returnPret() < b->returnPret(); });
}

/*
1.Adaugare
2.Afisare
3.Stergere
4.Cautare
5.Ordonare
6.Iesire
*/

int main()
{
    list <LCD*> tel_lcd;
    list <LCD*>::iterator i;
    list <LED*> tel_led;
    char prod[20];
    int diag,pret,t_rsp;
    int opt;
    char type[5];
    do{
        cout<<"\n1.Add display\n2.Show displays\n3.Delete display\n4.Search display\n5.Sort displays\n6.EXIT\n";
        cin>>opt;
        if(opt!=6){
            cout<<"Specify display type(LCD/LED):";
            cin.getline(type,5); cin.getline(type,5);
        }
        switch(opt){
            case 1:
                if(strcasecmp(type,"LCD")==0)
                    addLCD(tel_lcd);
                else
                    addLED(tel_led);
            break;
            case 2:
               
               if(strcasecmp(type,"LCD")==0){
                    printListC(tel_lcd);
               }
                else
                    printListE(tel_led);
            break;
            case 3:
                if(strcasecmp(type,"LCD")==0){
                    del_LCD(tel_lcd);
                }else
                del_LED(tel_led);
            break;
            case 4:
                if(strcasecmp(type,"LCD")==0){
                    searchLCD(tel_lcd);
                }else
                searchLED(tel_led);
            break;
            case 5:
            if(strcasecmp(type,"LCD")==0){
                    sortLCD(tel_lcd);
                    printListC(tel_lcd);
                }else{
                    sortLED(tel_led);
                    printListE(tel_led);
                }
                
            break;
        }
    }while(opt!=6);
    
    
    return 0;
}