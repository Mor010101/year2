//Am folosit sets in loc de liste stl deoarece sunt mult mai potrivite pentru problema propusa

#include<iostream>
#include<string>
#include<set>
#include<iterator>



class persoana{
    protected:
        std :: string nume, varsta;
    public:
        persoana();
        persoana(std :: string name,std :: string age){
            nume=name;
            varsta=age;
        }

        void printPers() const{
            std :: cout<<"Nume: "<<nume<<"\nVarsta: "<<varsta<<"\n";
        }
        std :: string getName() const{
            return this->nume;
        }
};

class elev{
    protected:
        std :: string n_scoala,clasa;
    public:
        elev();
        elev(std :: string school, std :: string  grade){
            n_scoala=school;
            clasa=grade;
        }

        void PrintElev() const{
            std :: cout<<"Scoala: "<<n_scoala<<"\nClasa: "<<clasa<<"\n";
        }
};

class copil : public elev , public persoana{
        std :: string joc;
    public:
        copil();
        copil(std :: string name, std :: string age, std :: string school, std :: string grade, std :: string  game) : persoana(name,age), elev(school,grade){
            joc=game;
        }

        void printCopil() const{
            std :: cout<<"\n====================\n";
            this->printPers();
            this->PrintElev();
            std :: cout<<"Joc preferat: "<<joc<<"\n";
        }

    bool operator<(const copil& other) const{
        if(this->nume < other.nume)
            return true;
        else
            return false;
    }
};


//gave up on this because overloading operator< was simpler

/*
//new compare function for inserting alphabetically
bool cmp(const copil& a,const copil& b)      
{
    std :: string a_name, b_name;
    a_name = a.getName();
    b_name = b.getName();
    if(a_name != b_name)
        return a_name < b_name;
}

setting the new function as compare fct
std :: set<copil, decltype(cmp)*> s(cmp);
*/


namespace std {
void addSorted(set <copil> *l)
    {
    string name,age,school,grade,game;

    cout<<"Nume: ";
    getline(cin, name); 
    cout<<"Varsta: ";
    getline(cin, age);
    cout<<"Scoala: ";
    getline(cin,school);
    cout<<"Clasa: ";
    getline(cin,grade);
    cout<<"Joc preferat: ";
    getline(cin,game);
   
    copil temp(name,age,school,grade,game);

    l->insert(temp);
    }
}

void printSet(std :: set <copil> l)
{
    const copil *c;
    for(auto const &it :l){
        c= &it;
        c->printCopil();
    }
}


int main()
{
    std :: set <copil> l;

    std :: addSorted(&l);
    std :: addSorted(&l);

    printSet(l);

    return 0;
}