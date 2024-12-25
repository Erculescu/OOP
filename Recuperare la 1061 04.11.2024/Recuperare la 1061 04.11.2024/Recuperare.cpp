#include <iostream>
using namespace std;

enum Departament {
	IT,HR,SALES
};

class Angajat {
	const int cod;//codul este unic si generat automat 1001,1002 etc
	char* nume;
	Departament departament;
	float salariu;
	int nrBonusuri;
	float* listaBonusuri;
	static int nrAngajati;
	//static float salariuMediu;
	//static float fondSalarii;//doar pt angajatii curenti
public:
	//TO DO:
	//CONSTRUCTOR FARA PARAM
	Angajat():cod(1000+(++Angajat::nrAngajati)) {
		cout << "\n Apel constructor fara param";
		this->nume = new char[strlen("anonim") + 1];
		strcpy_s(this->nume, strlen("anonim") + 1, "anonim");
		this->departament = Departament::SALES;
		this->salariu = 0;
		this->nrBonusuri = 0;
		this->listaBonusuri = nullptr;
		

	}
	//CONSTRUCTOR CU TOTI PARAM
	Angajat(const char* _nume, Departament _departament, float _salariu, int _nrBonusuri, float* _listaBonusuri) :cod(1000 + (++Angajat::nrAngajati)) {
		cout << "\n Apel constructor cu toti param";
		if (_nume != nullptr) {
			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
		else
		{
			this->nume = new char[strlen("anonim") + 1];
			strcpy_s(this->nume, strlen("anonim") + 1, "anonim");
		}
		this->departament = _departament;
		this->salariu = _salariu;
		if (_nrBonusuri > 0 && _listaBonusuri != nullptr) {
			this->nrBonusuri = _nrBonusuri;
			this->listaBonusuri = new float[this->nrBonusuri];
			for(int i=0;i<this->nrBonusuri;i++)
			{
				this->listaBonusuri[i] = _listaBonusuri[i];
			}
		}
		else {
			this->nrBonusuri = 0;
			this->listaBonusuri = nullptr;

		}
	}
	//CONSTRUCTOR COPIERE
	Angajat(const Angajat& f):cod(1000 + (++Angajat::nrAngajati)) {//Folosesc referinta pentru ca vreau sa ocolesc copierea
		cout << "\n Apel constructor copiere.";
		if (f.nume != nullptr) {
			this->nume = new char[strlen(f.nume) + 1];
			strcpy_s(this->nume, strlen(f.nume) + 1, f.nume);
		}
		else
		{
			this->nume = new char[strlen("anonim") + 1];
			strcpy_s(this->nume, strlen("anonim") + 1, "anonim");
		}
		this->departament = f.departament;
		this->salariu = f.salariu;
		if (f.nrBonusuri > 0 && f.listaBonusuri != nullptr) {
			this->nrBonusuri = f.nrBonusuri;
			this->listaBonusuri = new float[this->nrBonusuri];
			for (int i = 0; i < this->nrBonusuri; i++)
			{
				this->listaBonusuri[i] = f.listaBonusuri[i];
			}
		}
		else {
			this->nrBonusuri = 0;
			this->listaBonusuri = nullptr;

		}
	}

	//METH AFISARE
	void Afisare() {
		cout << "\n______________________\n";
		cout << "cod: " << this->cod << endl;
		cout << "nume: " << this->nume << endl;
		cout << "departament: " << this->departament << endl;
		cout << "salariu: " << this->salariu << endl;
		cout << "nr bonusuri: " << nrBonusuri << endl;
		for (int i = 0; i < nrBonusuri; i++)
			cout << this->listaBonusuri[i] << " ";

		cout << "\n______________________\n";
	}
	//METH DE GESTIUNE A ATRIB STATICE
	static int getNrAngajati() {
		return Angajat::nrAngajati;
	}

	//GET SI SET PT NUME
	const char* getNume() {
		return this->nume;
	}
	char* getNume2() {
		char* copie = nullptr;
		if (this->nume != nullptr) {
			copie = new char[strlen(this->nume) + 1];
			strcpy_s(copie, strlen(this->nume) + 1, this->nume);
		}
		return copie;
	}
	//DESTRUCTOR
	~Angajat() {
		cout << "\n Apel destructor";
		if (this->nume != nullptr) {
			delete[] this->nume;
			nume = nullptr;
		}
		if (this->listaBonusuri != nullptr) {
			delete[] this->listaBonusuri;
			listaBonusuri = nullptr;
		}
	}
};
int Angajat::nrAngajati = 0;

int main() {
	Angajat a1;
	a1.Afisare();
	float bonusuri[] = { 120.5,1020,2000 };
	Angajat a2("Gigel", Departament::IT, 12000, 3, bonusuri);
	a2.Afisare();
	cout << a2.getNume();
	cout << endl << a2.getNume2();
	const char* nume = a2.getNume();
	char* nume2 = a2.getNume2();
	cout << endl << nume2;
	//NU UITAM DE DEZALOCAREA LUI GETNUME2
	if (nume2 != nullptr) {
		delete[] nume2;
		nume2 = nullptr;
	}
	cout << "\n Nr angajati: " << Angajat::getNrAngajati()<<endl;
	Angajat a3(a2);//apel constructor de copiere
	a3.Afisare();
	//sau
	Angajat a4 = a2;
	a4.Afisare();
	return 0;
}