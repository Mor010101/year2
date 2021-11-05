#include<iostream>
#include<string.h>

using namespace std;

class Lista;  //prototipul clasei Lista

class Produse_magazin  //clasa de baza Produse_magazin
{
private:
	int tip_derivat;  //Ex. 1-Scanere, 2-Imprimante
	char *producator; //Ex. Samsung, Hp, Lexmark, etc.
	int cod_produs;   //Ex. 232345, 12423, 23563, etc.
	char *rezolutie;  //Ex. 1200x700, 2000x1000, etc.
	char *dimensiuni; //Ex. 20x30x40, 40x50x50, etc.
	Produse_magazin *urm;  //adresa urm element din lista
public:
	Produse_magazin(int t, char *prod, int cod, char *rez, char *dim)  //constructor clasa de baza
	{
		producator = new char[strlen(prod) + 1]; //alocare memorie pentru variabila producator
		rezolutie = new char[strlen(rez) + 1]; //alocare memorie pentru variabila rezolutie
		dimensiuni = new char[strlen(dim) + 1]; //alocare memorie pentru variabila dimensiune
		tip_derivat = t;
		strcpy(producator, prod);
		cod_produs = cod;
		strcpy(rezolutie, rez);
		strcpy(dimensiuni, dim);
		urm = NULL; //adresa noului nod este initial NULL
	}

	virtual void afisare() //functia de afisare elemente clasa de baza
	{
		cout << "-----------------------------------------\n";
		cout << "Producator: " << producator << endl;
		cout << "Cod produs: " << cod_produs << endl;
		cout << "Rezolutie: " << rezolutie << endl;
		cout << "Dimensiuni: " << dimensiuni << endl;
	}
	friend class Lista; //declararea clasei Lista friend la clasa Produse_magazin, pentru a se avea acces la campurile acesteia
};

class Scanere :public Produse_magazin //prima clasa derivata
{
private:
	char *soft_inclus; //Ex. Canon imageFormula, HP Scanjet Enterprise
	int viteza_scanare; //Ex. 5, 10, 15 
public:
	Scanere(int t, char *prod, int cod, char *rez, char *dim, char *soft, int viteza) :Produse_magazin(t,prod,cod,rez,dim) //constructor clasa derivata
	{
		soft_inclus = new char[strlen(soft) + 1]; //alocare memorie pentru variabila soft_inclus
		strcpy(soft_inclus, soft);
		viteza_scanare = viteza;
	}

	void afisare() //afisare elemente din clasa Scanere
	{
		Produse_magazin::afisare(); //apelare afisare elemente din clasa de baza
		cout << "Soft inclus: " << soft_inclus << endl;
		cout << "Viteza scanare: " << viteza_scanare << endl;
	}
	friend class Lista;
};

class Imprimante :public Produse_magazin // a doua clasa derivata
{
private:
	char *format; //Ex. A3, A3/A4/A5, A4, etc.
	char *tip;    //Ex. Color, Monocrom
public:
	Imprimante(int t, char *prod, int cod, char *rez, char *dim, char *form, char *tp) :Produse_magazin(t, prod, cod, rez, dim) //constructor
	{
		format = new char[strlen(form) + 1];
		tip = new char[strlen(tp) + 1];
		strcpy(format, form);
		strcpy(tip, tp);
	}

	void afisare() //functie afisare
	{
		Produse_magazin::afisare();
		cout << "Format: " << format << endl;
		cout << "Tip: " << tip << endl;
	}
	friend class Lista;
};


class Lista //clasa Lista
{
public:
	Produse_magazin *head; //capul listei
	void adaugare(Produse_magazin *prod); //adaugare in lista
	void afisare_lista(); //afisarea listei
	void afisare_conditionata(char *soft); //afisarea unui anumit produs
	void stergere(char *prod); //stergere din lista
	
};

//adaugare in lista ordonata
void Lista::adaugare(Produse_magazin *a)
{
	Produse_magazin *p; //var p este declarata de tip Produse_magazin

	p = head; //se initializeaza cu capul listei
	if (p) //daca lista nu este vida
	{
		if (strcmp(a->producator, p->producator)<0) //daca nodul care se adauga este mai mic decat primul nod din lista 
		{
			a->urm = head; //noul nod se leaga de primul nod
			head = a; //capul listei devine noul nod
		}
		else
		{
			while (p->urm && strcmp((p->urm)->producator, a->producator)<0)  //se parcurge lista pana cand exista elemente si noul nod nu este mai mare decat nodul curent
				p = p->urm;
			a->urm = p->urm; //se fac legaturile intre noul nod si cele din lista
			p->urm = a;
		}
	}
	else
		head = a; //daca lista este vida, capul este nodul adaugat
}

void Lista::afisare_lista() //afisarea listei
{
	Produse_magazin *a;

	a = head; //se initializeaza cu capul listei

	if (!a) //daca lista este vida
		cout << "Lista este vida!";
	else
		while (a) //cat timp sunt noduri in lista
		{
			a->afisare(); //se apeleaza afisarea corespunzatoare nodului curent
			a = a->urm; //se trece la urm nod in lista
			//getch();
		}
}

void introducere(Lista &l, int x) //introducere info in noduri
{
	int Tip_derivat;  //Ex. 1-Scanere, 2-Imprimante
	char Producator[50]; //Ex. Samsung, Hp, Lexmark, etc.
	int Cod_produs;   //Ex. 232345, 12423, 23563, etc.
	char Rezolutie[50];  //Ex. 1200x700, 2000x1000, etc.
	char Dimensiuni[100]; //Ex. 20x30x40, 40x50x50, etc.
	char Soft_inclus[100]; //Ex. Canon imageFormula, HP Scanjet Enterprise
	int Viteza_scanare; //Ex. 5, 10, 15 
	char Format[20]; //Ex. A3, A3/A4/A5, A4, etc.
	char Tip[20];    //Ex. Color, Monocrom
	Produse_magazin *prodMag;

	cout << "Introduceti producatorul: ";
	cin >> Producator;
	cout << "Introduceti codul de produs: ";
	cin >> Cod_produs;
	cout << "Introduceti rezolutia: ";
	cin >> Rezolutie;
	cout << "Introduceti dimensiunile: ";
	cin >> Dimensiuni;

	if (x == 0) // daca s-a ales adaugarea unui nou Scaner
	{
		Scanere *Sc;
		cout << "Introduceti softul inclus: ";
		cin >> Soft_inclus;
		cout << "Introduceti viteza de scanare: ";
		cin >> Viteza_scanare;
		
		Sc = new Scanere(1, Producator,Cod_produs,Rezolutie, Dimensiuni,Soft_inclus, Viteza_scanare); //apelare constructor cu info citite
		prodMag = Sc; //cast pentru clasa de baza
		l.adaugare(prodMag); //se adauga nodul
	}
	else if (x == 1) //daca s-a ales adaugarea unei pensiuni
	{
		Imprimante *Imprim;

		cout << "Introduceti formatul imprimantei: ";
		cin >> Format;
		cout << "Introduceti tipul imprimantei: ";
		cin >> Tip;
		Imprim = new Imprimante(2, Producator, Cod_produs, Rezolutie, Dimensiuni, Format, Tip);//apelare constructor cu info citite
		prodMag = Imprim;//cast pentru clasa de baza
		l.adaugare(prodMag);//se adauga nodul
	}
}

void Lista::stergere(char *prod) //stergere element din lista
{
	Produse_magazin *p, *q;
	p = q = head;
	if (p)
	{
		while (p && strcmp(p->producator, prod) != 0) //cat timp nu s-a gasit nodul care se doreste a fi sters
		{
			q = p; //se inainteaza in lista cu cei 2 pointeri
			p = p->urm;
		}
		if (p) //daca lista nu este goala
		{
			if (p != q) //daca nu este un singur nod in lista
			{
				q->urm = p->urm; //se realizeaza legaturile dintre nodurile care raman
				delete p; //se sterge nodul dorit
			}
			else
			{
				head = p->urm; //se sterge capul liste daca nodul de sters este capul liste si capul devine urm nod
				delete p;
			}
		}
		else
			cout << "Producatorul nu exista in lista!";
	}
	else
		cout << "Lista este vida!";
}

void Lista::afisare_conditionata(char *soft) //calcularea ofertei cele mai avantajoasa
{
	Produse_magazin *prodMag;
	Scanere *Sc;

	int oferta, min = 32000;
	char num[20];

	prodMag = head;
	if (!prodMag)
		cout << "Lista este vida!";
	else
		while (prodMag) //daca lista nu este vida
		{
			if (prodMag->tip_derivat == 1) //daca nodul este Scanere
			{
				Sc = (Scanere *)prodMag; //se face cast la Scanere pentru a avea acces la informatiile din clasa derivata
				if (strcmp(Sc->soft_inclus, soft) == 0)
					prodMag->afisare();
			}
			prodMag = prodMag->urm; //se inainteaza in lista
		}
}

void main() //programul principal
{
	int opt;
	Lista l;
	l.head = NULL;
	do
	{
		system("CLS");
		//meniu
		cout << "1.Adaugare scanere in lista, ordonat dupa producator.\n";
		cout << "2.Adaugare imprimante in lista, ordonat dupa producator.\n";
		cout << "3.Afisare articole din magazin.\n";
		cout << "4.Afisare scanere cu un anumit Soft_includ citit de la tastatura.\n";
		cout << "5.Stergere articol dupa producator.\n";
		cout << "0.Iesire.\n";
		cout << "Dati optiunea dvs: ";
		cin >> opt;
		//apelare functii in functie de optiunea aleasa
		switch (opt)
		{
		case 1: introducere(l, 0);
			break;
		case 2: introducere(l, 1);
			break;
		case 3: l.afisare_lista();
			break;
		case 4: char soft[100];
			cout << "Introduceti numele softului pentru care se vor afisa scanerele: ";
			cin >> soft;
			l.afisare_conditionata(soft);
			//getc();
			break;
		case 5: char produc[20];
			cout << "Introduceti producatorul care doriti sa il stergeti: ";
			cin >> produc;
			l.stergere(produc);
			cout << "Apasati o tasta pt continuare...";
			//getch();
			break;
		case 0: break;
		default:cout << "Comanda gresita!";
		}
	} while (opt != 0);
}
