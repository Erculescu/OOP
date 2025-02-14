#include<iostream>
using namespace std;




class Entitate {
public:
	virtual void procent() = 0;

};




class PersonaJJOc {
	string nume;
	int nrLovituri;
	int* puncteDamage;
	int HPtotal;
public:
	PersonaJJOc() {
		this->nume = "anonim";
		this->nrLovituri = 0;
		this->puncteDamage = nullptr;
		this->HPtotal = 100;
	}
	PersonaJJOc(const string _nume, int _nrlovituri, int* _puncteDamage, int _HPtotal) {
		this->nume = _nume;
		this->nrLovituri = _nrlovituri;
		this->puncteDamage = new int[_nrlovituri];
		for (int i = 0; i < this->nrLovituri; i++)
			this->puncteDamage[i] = _puncteDamage[i];
		this->HPtotal = _HPtotal;
	}
	~PersonaJJOc() {
		if(this->puncteDamage!=nullptr)
		{
			delete[] this->puncteDamage;
			this->puncteDamage = nullptr;
		}
	}
	PersonaJJOc(const PersonaJJOc& p) {
		this->nume = p.nume;
		this->nrLovituri = p.nrLovituri;
		this->puncteDamage = new int[p.nrLovituri];
		for (int i = 0; i < this->nrLovituri; i++)
			this->puncteDamage[i] = p.puncteDamage[i];
		this->HPtotal = p.HPtotal;
	}
	PersonaJJOc& operator=(const PersonaJJOc& p) {
		if (this != &p) {
			if (this->puncteDamage != nullptr)
			{
				delete[] this->puncteDamage;
				this->puncteDamage = nullptr;
			}
			this->nume = p.nume;
			this->nrLovituri = p.nrLovituri;
			this->puncteDamage = new int[p.nrLovituri];
			for (int i = 0; i < this->nrLovituri; i++)
				this->puncteDamage[i] = p.puncteDamage[i];
			this->HPtotal = p.HPtotal;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const PersonaJJOc& p) {
		out << "\nNume: " << p.nume;
		out << "\nNumarul de combinatii de lovituri: " << p.nrLovituri;
		out << "\nPunctele de damage pt fiecare lovitura: ";
		for (int i = 0; i < p.nrLovituri; i++)
			out << p.puncteDamage[i] << "  ";
		out << "\nHP total: " << p.HPtotal << endl;
		return out;
	}
	string getnume() { return this->nume; }
	void setnume(const string _nume) { this->nume = _nume; }
	int getnrLovituri() { return this->nrLovituri; }
	void setnrLovituri(int _nrLovituri) { this->nrLovituri = _nrLovituri; }
	int* getpuncteDamage() { return this->puncteDamage; }
	void setpuncteDamage(int _nrLovituri, int* _puncteDamage) {
		if (this->puncteDamage != nullptr)
			delete[] this->puncteDamage;
		this->nrLovituri = _nrLovituri;
		this->puncteDamage = new int[this->nrLovituri];
		for (int i = 0; i < this->nrLovituri; i++)
			this->puncteDamage[i] = _puncteDamage[i];
	}
	int getHPtotal() { return this->HPtotal; }

	PersonaJJOc operator+=(int x) {
		this->HPtotal = this->HPtotal + x;
		return *this;
	}
	bool operator>=(const PersonaJJOc& p) {
		int k = 0;
		for (int i = 0; i < this->nrLovituri; i++)
		{
			if (this->puncteDamage[i] > p.puncteDamage[i])
				k++;
		}
		if (this->HPtotal >= p.HPtotal)
			k++;
		return k == this->nrLovituri + 1;
	}
	template <typename T>
	void adauga(T x) {
		this->nrLovituri++;
		int* aux = new int[this->nrLovituri];
		for (int i = 0; i < this->nrLovituri - 1; i++)
			aux[i] = this->puncteDamage[i];
		x = abs(x);
		x = floor(x);
		aux[this->nrLovituri - 1] = x;
		if (this->puncteDamage != nullptr)
			delete[] this->puncteDamage;
		this->puncteDamage = new int[this->nrLovituri];
		for (int i = 0; i < this->nrLovituri; i++)
			this->puncteDamage[i] = aux[i];
		delete[] aux;
	}
};

class Protagonist :public PersonaJJOc ,public Entitate {
	int nrObiective;
	int* procentajObiective;
public:
	Protagonist() :PersonaJJOc() {
		this->nrObiective = 0;
		this->procentajObiective = nullptr;
	}
	Protagonist(int _nrObiective, int* _procentajObiective, const string _nume, int _nrLovituri, int* _puncteDamage, int _HPtotal)
		:PersonaJJOc(_nume, _nrLovituri, _puncteDamage, _HPtotal) {
		this->nrObiective = _nrObiective;
		this->procentajObiective = new int[this->nrObiective];
		for (int i = 0; i < this->nrObiective; i++)
			this->procentajObiective[i] = _procentajObiective[i];
	}
	~Protagonist() {
		if (this->procentajObiective != nullptr) {
			delete[] this->procentajObiective;
			this->procentajObiective = nullptr;
		}
	}
	Protagonist(const Protagonist& p) :PersonaJJOc(p) {
		this->nrObiective = p.nrObiective;
		this->procentajObiective = new int[this->nrObiective];
		for (int i = 0; i < this->nrObiective; i++)
			this->procentajObiective[i] = p.procentajObiective[i];
	}
	Protagonist& operator=(const Protagonist& p) {
		if (this != &p) {
			PersonaJJOc::operator=(p);
			if (this->procentajObiective != nullptr) {
				delete[] this->procentajObiective;
				this->procentajObiective = nullptr;
			}
			this->nrObiective = p.nrObiective;
			this->procentajObiective = new int[this->nrObiective];
			for (int i = 0; i < this->nrObiective; i++)
				this->procentajObiective[i] = p.procentajObiective[i];
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, Protagonist& p) {
		out << "\nDetalii despre protagonist: ";
		out << (PersonaJJOc&)p;
		out << "\nNumarul de obiective: " << p.nrObiective;
		out << "\nProcentajele de indeplinire a obiectivelor: ";
		for (int i = 0; i < p.nrObiective; i++)
			out << p.procentajObiective[i] << " ";
		return out;
	}
	void procent() {
		float s = 0;
		for (int i = 0; i < this->nrObiective; i++)
			if (this->procentajObiective[i] == 100)
				s++;
		cout << "\nPorcentajul de completare al obiectivelor este: " <<
			(s / this->nrObiective) * 100 << "%\n";
	}
};





int main() {
	PersonaJJOc p1;
	int d1[] = { 15,20,44 };
	PersonaJJOc p2("Dexter", 3, d1,100);
	p1 = p2;
	cout << p1;
	p2 += 25;
	cout << p2;
	int d2[] = { 8,13,27 };
	PersonaJJOc p3("Miguel Prado", 3, d2, 75);
	if (p2 >= p3)
		cout << "\nDexter este mai puternic decat Miguel Prado (logic)\n";
	else cout << "\nMiguel Prado este mai puternic decat Dexter (never)\n";
	int d3[] = { 100,100,100,25,33,100,17 };
	Protagonist pr1(7, d3, "Dexter", 3, d1, 100);
	cout << pr1;
	pr1.procent();
	p2.adauga(-33.3);
	cout << p2;

	return 0;
}