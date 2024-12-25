#include<iostream>
#include<cstring>
using namespace std;


class Salariat {
	const int id;
	char* nume;
	static int nrSalariati;//static float salariumediu;
	static float salariuMinim;//din legislatie
	float salariu;
	int nrOreZi;
public:
	Salariat():id(0) {
		cout << "\n Constructor fara param.";
		this-> nume =new char[strlen("-")+1];
		strcpy_s(this->nume,2, "-");
		this->salariu = 0;
		this->nrOreZi = 0;
		Salariat::nrSalariati++;

	}

	Salariat(int _id,const char* _nume, float _salariu, int _nrOreZi) :id(_id) {
		cout << "\n Constructor cu toti param";
		this->nume = new char[strlen(_nume) + 1];
		strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		if (_salariu >= Salariat::salariuMinim)
			this->salariu = _salariu;
		else
		{
			cout << "\n Salariul este prea mic. Salariul minim a fost setat implicit";
				this->salariu = salariuMinim;
		}
		if (_nrOreZi > 8)
			this->nrOreZi = 8;
		else if (_nrOreZi < 1)
			this->nrOreZi = 1;
		else
		this->nrOreZi = _nrOreZi;
		Salariat::nrSalariati++;


	}


	Salariat(const Salariat& f) :id(f.id) {
		cout << "\n Constructor copiere.";
		this->nume = new char[strlen(f.nume) + 1];
		strcpy_s(this->nume, strlen(f.nume) + 1, f.nume);
		if (f.salariu >= Salariat::salariuMinim)
			this->salariu = f.salariu;
		else
		{
			cout << "\n Salariul este prea mic. Salariul minim a fost setat implicit";
			this->salariu = salariuMinim;
		}
		if (f.nrOreZi > 8)
			this->nrOreZi = 8;
		else if (f.nrOreZi < 1)
			this->nrOreZi = 1;
		else
			this->nrOreZi = f.nrOreZi;
		Salariat::nrSalariati++;


	}
	~Salariat() {
		cout << "\nApel Destructor.";
		if (this->nume != nullptr)
			delete[] this->nume;
		this->nume = nullptr;
	}

	void setNume(const char* _nume) {
		//Obiectul deja exista
		//Posibil Existenta nume deja
		if(this->nume!=nullptr)
		{
			delete[] this->nume;
			this->nume = nullptr;
		}
		this->nume = new char[strlen(_nume) + 1];
		strcpy_s(this->nume, strlen(_nume) + 1, _nume);
	}
	const char* getNume() {
		return this->nume;
	}

	void setSalariu(float _salariu) {
		if (_salariu >= Salariat::salariuMinim)
			this->salariu = _salariu;
		else
		{
			cout << "\n Salariul este prea mic. Salariul minim a fost setat implicit";
			this->salariu = salariuMinim;
		}
	}
	const float getSalariu() {
		return this->salariu;
	}

	Salariat& operator=(const Salariat& f) {
		cout << "\n Apel Operator =";
		if (this != &f) {
			if (this->nume != nullptr)
				delete[] this->nume;
			this->nume = nullptr;
		}this->nume = new char[strlen(f.nume) + 1];
		strcpy_s(this->nume, strlen(f.nume) + 1, f.nume);
		if (f.salariu >= Salariat::salariuMinim)
			this->salariu = f.salariu;
		else
		{
			cout << "\n Salariul este prea mic. Salariul minim a fost setat implicit";
			this->salariu = salariuMinim;
		}
		if (f.nrOreZi > 8)
			this->nrOreZi = 8;
		else if (f.nrOreZi < 1)
			this->nrOreZi = 1;
		else
			this->nrOreZi = f.nrOreZi;
		return *this;
	}
	void Afisare() {
		cout << "\n______________________________________\n";
		cout << "ID: " << this->id << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Salariu: " <<this->salariu << endl;
		cout << "Ore lucrate pe zi: " << this->nrOreZi << endl;
		cout << "\n______________________________________\n";
	}

};
int Salariat::nrSalariati = 0;
float Salariat::salariuMinim = 2500;
Salariat getSalariatMaxSalariu(Salariat v[], int nrSalariati) {
	//TO DO ACAS :*
	return Salariat();
}


//CONSTRUCTOR FARA PARAM
//CONSTRUCTOR CU TOTI PARAM
//CONSTRUCTOR COPIERE
//OPERATOR EGAL=
//METODA AFISARE
//DESTRUCTOR
//SET SALARIU
//GET SALARIU
//SET NUME
//GET NUME
int main() {
	Salariat s1;
	Salariat s2(1, "Erculescu Rares", 6000, 7);
	s1.Afisare();
	s2.Afisare();
	Salariat s3(s2);
	s3.Afisare();
	s1.setNume("Andreescu");
	s1.setSalariu(7800.50);
	s1.Afisare();
	s1 = s2;
	s1.Afisare();

	//Tema Problemele din github !!!!!!!!!
	return 0;
}