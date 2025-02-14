#include <iostream>
using namespace std;

//cheltuielile dintr-o companie
//interfata unei clase ->colectia de metode get si set
//clasa tip interfata
//interfata are doar metode virtuale pure
//are doar metode virtuale pure
//conceptul de contract
class ICheltuiala {
public:
	virtual float getCostLunar() = 0;
	virtual void getInfo() = 0;

};
//clasa concreta(ce nu este abstracta)
class Angajat : public ICheltuiala {
	string nume;
	float salariu;

public:

	Angajat(string _nume, float _salariu) {
		this->nume = _nume;
		this->salariu = _salariu;
	}
	float getCostLunar() {
		return this->salariu;
	}
	void getInfo() {
		cout << "\nAngajat " << this->nume << " salariul: " << this->salariu;
	}

};
//clasa abstracta
//are cel putin o metoda virtuala pura
class ACheltuiala :public ICheltuiala {
protected:
	string denumire;
	string dataInregistrare;
public:
	ACheltuiala(string _denumire, string _dataInregistrare) {
		this->denumire = _denumire;
		this->dataInregistrare = _dataInregistrare;
	}

};
//clasa concreta
class ChUtilitati :public ACheltuiala {
	float costlunar;
public:
	ChUtilitati(string _denumire, string _dataInregistrare, float _costlunar) :ACheltuiala(_denumire, _dataInregistrare) {
		this->costlunar = _costlunar;
	}
	float getCostLunar() {
		return this->costlunar;
	}
	void getInfo() {
		cout << "\nDenumirea Utilitatii: " << this->denumire << " Costul lunar: " << this->costlunar;

	}

};

class ChEchipament :public ACheltuiala {
	float costAchizitie;
	int nrLuniAmortizare;
public:
	ChEchipament(string _denumire, string _dataInregistrare, float _costAchizitie,int _nrLuniAmortizare) :ACheltuiala(_denumire, _dataInregistrare) {
		this->costAchizitie = _costAchizitie;
		this->nrLuniAmortizare = _nrLuniAmortizare;	
	}
	float getCostLunar() {
		return this->costAchizitie/this->nrLuniAmortizare;
	}
	void getInfo() {
		cout << "\nDenumirea Echipamentului: " << this->denumire << " Costul lunar: " << this->costAchizitie;

	}

};

class Companie {
//colectie de toate cheltuielile
//metoda care intoarce totalul cheltuielilor pe luna
	ICheltuiala** listacheltuieli=nullptr;
	int nrCheltuieli=0;
public:
	Companie(ICheltuiala** _listacheltuieli, int _nrCheltuieli) {
		this->nrCheltuieli = _nrCheltuieli;
		this->listacheltuieli = new ICheltuiala * [this->nrCheltuieli];//deep pentru vector de adrese
		for (int i = 0; i < this->nrCheltuieli; i++) {
			this->listacheltuieli[i] = _listacheltuieli[i];//shallow pentru cheltuieli
		}
	}
	float getTotalCheltuieliLunare() {
		float total = 0;
		for (int i = 0; i < this->nrCheltuieli; i++) {
			if(this->listacheltuieli[i]!=nullptr)
			total += this->listacheltuieli[i]->getCostLunar();
		}
		return total;
	}


};

int main() {
	//Interfata
	//ICheltuiala ch;
	ICheltuiala* pCh= nullptr;
	//cout << pCh->getCostLunar();
	//Obiecte de tip clasa concreta
	Angajat a("Gigel",1200);
	a.getInfo();
	//clasa abstracta
	//ACheltuiala* cheltuiala=new ACheltuiala("a", "b");
	

	//obiect de tip clasa concreta din clasa abstracta
	ChUtilitati chApa("contract apa", "05.04.2022", 300);
	chApa.getInfo();
	ACheltuiala* ch = new ChUtilitati("contract energie electrica", "21.08.2024", 600);
	ch->getInfo();
	ACheltuiala* ch2 = new ChEchipament("laptop", "18.06.2024", 6900, 36);

	Companie c1(new ICheltuiala * [3]{&a, &chApa, ch2}, 3);
	Companie c2(new ICheltuiala * [3] {&a, ch, ch2}, 3);
	cout<<"\nTotal cheltuieli lunare: "<< c2.getTotalCheltuieliLunare();

	return 0;
}