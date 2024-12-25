#include <iostream>
using namespace std;

class Animal {
public:
	string denumire;
	string rasa;
	int varsta;

	virtual void scoateSunet() {
		cout << "\nAnimalul: " + this->denumire + " scoate sunet";
	}


};

class Pisica :public Animal {
public:
	void scoateSunet() {
		cout << "\nPisica: " + this->denumire + " face miau miau";
	}
};

class Caine :public Animal {
public:
	void scoateSunet() {
		cout << "\nCainili: " + this->denumire + " face ham ham";
	}
};


class ColectieAnimale {
	Animal listaAnimale[10];
	int nrAnimale;
public:
	ColectieAnimale(Animal* _listaAnimale, int _nrAnimale) {
		this->nrAnimale = _nrAnimale;
		for (int i = 0; i < this->nrAnimale; i++)
			this->listaAnimale[i] = _listaAnimale[i];
	}
	void activareAlarma() {
		for (int i = 0; i < this->nrAnimale; i++)
			listaAnimale[i].scoateSunet();
	}
};






class Angajat {
public:
	float salariu = 0;
	virtual float calculsalariu() {
		return this->salariu;
	}
};
class Manager :public Angajat {
public:
	int nrMembriEchipa = 0;
	float calculsalariu() {
		return Angajat::calculsalariu() + 100 * this->nrMembriEchipa;
	}
};

//clasa abstracta
//rol de contract ce conduce la interfata(are doar metode virtuale pure)
class Entitate {public:

	virtual void enerveaza() = 0;//metoda virtuala pura
	virtual void reactioneaza() = 0;
};
class Robot:public Entitate {public:
	void enerveaza() {
		cout << "\nChat gpt piuie in continuu";
	}

	void reactioneaza() {
		cout << "\nChat gpt face pe inabordabilul";
		}
};

class Actor :public Entitate {public:
	void enerveaza() {
		cout << "\nActorul ridica tonul.";
	}
	void reactioneaza() {
		cout << "\nActorul e sarcastic";
	}
};

void scena1_generalizata(Entitate* e1, Entitate* e2) {
	e1->enerveaza();
	e2->reactioneaza();
}

class Persona {
public:
	string nume;
	void enerveaza() {
		cout << "\n" << this->nume << " enerveaza ";
	}
	void reactioneaza() {
		cout << "\n" << this->nume << " reactioneaza";
	}
};
//piesa de teatru
//scena1
//2 personaje care interactioneaza
//implementare care depinde de concret
void scena1(Persona p1, Persona p2) {
	p1.enerveaza();
	p2.reactioneaza();
}

//implementare care depinde de abstract




//c++ 11 (curs 14)
//namespace,headers(curs 14)
//virtualizare(pfoa)->late binding (curs 12)
//clasa abstracta+interfata
//clase template+stl-uri(pfoa iar)
int main() {
	Entitate* ee1 = new Actor();
	Entitate* ee2 = new Robot();
	scena1_generalizata(ee1, ee2);
	scena1_generalizata(ee2, ee2);
	cout << "\n--------------------\n";
	Persona pp1;
	Persona pp2;
	pp1.nume = "rares";
	pp2.nume = "delia";
	scena1(pp1, pp2);
	cout << "\n-------------------------\n";



	Angajat ang1;
	ang1.salariu = 1000;
	Manager m1;
	m1.salariu = 1000;
	m1.nrMembriEchipa = 5;
	cout << "\nSalariu angajat: " << ang1.calculsalariu();
	cout << "\nSalariu manager: " << m1.calculsalariu();
	ang1 = m1;//virtualizarea nu se aplica la obiecte
	//pt ca op= din egal din upcast elimina surplusul clasei derivate
	cout << "\nSalariu angajat(fost manager): " << ang1.calculsalariu();
	Angajat* pang1;
	pang1 = &m1;
	cout << "\nSalariu pointer angajat(fost manager): " << pang1->calculsalariu();


	cout << "\n-----------------------\n";
	Animal a1;
	a1.denumire = "rares";
	//a1.scoateSunet();
	Pisica p1;
	p1.denumire = "pispis";
	//p1.scoateSunet();
	Caine c1;
	c1.denumire = "costica";
	//c1.scoateSunet();
	a1 = p1;//upcast pe obiect
	a1.scoateSunet();
	Animal* pa = new Animal();
	pa->scoateSunet();
	pa = &p1;//upcast pe pointer
	pa->scoateSunet();
	Animal vector[] = { a1,p1,c1 };
	ColectieAnimale colectie1(vector,3);
	//colectie1.activareAlarma();
	return 0;
}