#include<iostream>
using namespace std;

class Persoana {
	const string cnp;
	string nume;
public:
	Persoana():cnp("0000000000000000") {
		this->nume = "anonim";
	}
	Persoana(const string _cnp, string _nume) :cnp(_cnp) {
		this->nume = _nume;
	}
	Persoana(const Persoana& p) :cnp(p.cnp) {
		this->nume = p.nume;
	}
	Persoana& operator=(Persoana& p) {
		if (this != &p) { this->nume = p.nume; }
		return *this;
	}
	~Persoana() = default;

	const string getCNP() {
		return this->cnp;
	}
	string getNume() {
		return this->nume;
	}
	void setNume(string _nume) {
		this->nume = _nume;
	}
	bool operator==(Persoana& p) const{
		int k = 0;
		if (this->cnp == p.cnp) { k++; }
		if (this->nume == p.nume) { k++; }
		return k == 2;
	}
	
};

class Asociatie {
	int nrMembri;
	Persoana* membri;//asociatie are un nr de persoane
	static float cotizatie;
public:
	Asociatie() {
		this->nrMembri = 0;
		this->membri = nullptr;
	}
	Asociatie(int _nrMembri, Persoana* _membri) {
		if (_nrMembri > 0) {
			this->nrMembri = _nrMembri;
			this->membri = new Persoana[this->nrMembri];
			for (int i = 0; i < this->nrMembri; i++) {
				this->membri[i] = _membri[i];
			}
		}
		else {
			this->nrMembri = 0;
			this->membri = nullptr;
		}
	}
	Asociatie(const Asociatie& a){
		if (a.nrMembri > 0) {
			this->nrMembri = a.nrMembri;
			this->membri = new Persoana[this->nrMembri];
			for (int i = 0; i < this->nrMembri; i++) {
				this->membri[i] = a.membri[i];
			}
		}
		else {
			this->nrMembri = 0;
			this->membri = nullptr;
		}
	}
	~Asociatie() {
		if (this->membri != nullptr) {
			delete[] this->membri;
			this->membri = nullptr;
		}
	}

	Asociatie& operator=(const Asociatie& a){
		if (this != &a) {
			if (this->membri != nullptr) {
				delete[] this->membri;
				this->membri = nullptr;
			}
			if (a.nrMembri > 0) {
				this->nrMembri = a.nrMembri;
				this->membri = new Persoana[this->nrMembri];
				for (int i = 0; i < this->nrMembri; i++) {
					this->membri[i] = a.membri[i];
				}
			}
			else {
				this->nrMembri = 0;
				this->membri = nullptr;
			}
		}
		return *this;
	}
	Persoana getMembri() {
		return *this->membri;
	}
	void setMembri(Persoana* _membri, int _nrMembri){
		if (this->membri != nullptr) {
			delete[] this->membri;
			this->membri = nullptr;
		}
		if (_nrMembri > 0) {
			this->nrMembri = _nrMembri;
			this->membri = new Persoana[this->nrMembri];
			for (int i = 0; i < this->nrMembri; i++) {
				this->membri[i] = _membri[i];
			}
		}
		else {
			this->nrMembri = 0;
			this->membri = nullptr;
		}
	}
	int getNrMembri() {
		return this->nrMembri;
	}
	void setNrMembri(int _nrMembri) {
		this->nrMembri = _nrMembri;
	}
	Asociatie& operator+=(Persoana& p) {
		Persoana* aux = new Persoana[this->nrMembri + 1];
		for (int i = 0; i < this->nrMembri; i++) {
			aux[i] = this->membri[i];
		}
		aux[this -> nrMembri] = p;
		if (this->membri != nullptr) {
			delete[] this->membri;
		}
		this->membri = new Persoana[this->nrMembri + 1];
		for (int i = 0; i < this->nrMembri; i++)
			this->membri[i] = aux[i];
		this->nrMembri++;
		this->membri[this->nrMembri - 1] = p;
		delete[] aux;
		return *this;
	}

	Asociatie& operator-=(Persoana& p) {
		int j = -1;
		for (int i = 0; i < this->nrMembri; i++) {
			if (this->membri[i] == p) {
				j = i;
				break;
			}
		}
		if (j != -1) {
			Persoana* aux = new Persoana[this->nrMembri - 1];
			for (int i = 0; i < j; i++)
				aux[i] = this->membri[i];
			for (int i = j + 1; i < this->nrMembri; i++)
				aux[i - 1] = this->membri[i];
			delete[] this->membri;
			this->membri = new Persoana[this->nrMembri - 1];
			this -> nrMembri--;
			for (int i = 0; i < this->nrMembri; i++)
				this->membri[i] = aux[i];
		}
		return *this;
	}



	friend ostream& operator<<(ostream& out, Asociatie& a) {
		out << "\nAsociatia are: " << a.nrMembri << " membri";
		out << "\nMembrii sunt: ";
		for (int i = 0; i < a.nrMembri; i++)
		{
			out << a.membri[i].getNume() <<", ";
		}
		out << "\nCotizatia este:" << Asociatie::cotizatie;
		return out;
	}

	virtual float getCotizatie() {//functie viruala pura +concept de late binding
		return 0;
	}
};

class Partid:public Asociatie {//partid is a asociatie
	const string denumire;
	int nrSimpatizanti;
	Persoana* simpatizanti;//partid has a nr de persoane
public:
	Partid() :denumire("anonim"), Asociatie() {
		this->nrSimpatizanti = 0;
		this->simpatizanti = nullptr;
	}
	Partid(const string _denumire,int _nrSimpatizanti, Persoana* _simpatizanti, int _nrMembri, Persoana* _membri) :denumire(_denumire), Asociatie(_nrMembri, _membri) {
		this->nrSimpatizanti = _nrSimpatizanti;
		this->simpatizanti = new Persoana[this->nrSimpatizanti];
		for (int i = 0; i < this->nrSimpatizanti; i++)
			this->simpatizanti[i] = _simpatizanti[i];
	}
	Partid(const Partid& p) :denumire(p.denumire), Asociatie(p) {
		this->nrSimpatizanti = p.nrSimpatizanti;
		this->simpatizanti = new Persoana[this->nrSimpatizanti];
		for (int i = 0; i < this->nrSimpatizanti; i++)
			this->simpatizanti[i] = p.simpatizanti[i];
	}
	~Partid() {
		if (this->simpatizanti != nullptr)
		{
			delete[]this->simpatizanti;
			this->simpatizanti = nullptr;
		}
	}
	Partid& operator=(Partid& p) {
		if (this != &p) {
			Asociatie::operator=(p);
			if (this->simpatizanti != nullptr)
			{
				delete[]this->simpatizanti;
				this->simpatizanti = nullptr;
			}
			this->nrSimpatizanti = p.nrSimpatizanti;
			this->simpatizanti = new Persoana[this->nrSimpatizanti];
			for (int i = 0; i < this->nrSimpatizanti; i++)
				this->simpatizanti[i] = p.simpatizanti[i];
		}
		return *this;
	}
	Partid& operator+=(Persoana& p) {
		Asociatie::operator+=(p);
		return *this;
	}
	Partid& operator-=(Persoana& p) {
		Asociatie::operator-=(p);
		return *this;
	}

	const string getDenumire() {
		return this->denumire;
	}

	friend ostream& operator<<(ostream& out, Partid& p) {
		out << "\nNumele partidului: " << p.denumire;
		out << (Asociatie&)p;
		out << "\nNumarul de simpatizanti: " << p.nrSimpatizanti;
		out << "\nSimpatizantii sunt: ";
		for (int i = 0; i < p.nrSimpatizanti; i++)
			out << p.simpatizanti[i].getNume() << ", ";
		out << "\n";
		return out;
	}
	
	float getCotizatie() {//functie suprascrisa 
		float k = 0;
		int n = this->getNrMembri();
		for (int i = 0; i < n; i++) {
			k = k + 100;
		}
		for (int i = 0; i < this->nrSimpatizanti; i++) {
			k = k + 50;
		}
		return k;
	}
};
float Partid::Asociatie::cotizatie = 100.0;


int main() {
	Persoana p1("1234567890", "Popescu Ion");
	Persoana p2("0987654321", "Vladescu Marian");
	Persoana p3("6548390210", "Georgescu Maria");
	Persoana p4("1012011319", "Maria Tiberiu");
	Persoana p5("0101010102", "Gigi Simigion");
	Persoana vp[] = { p1,p2,p3,p4 };
	Persoana p6("9897583642", "Aurel Popescu");
	Persoana p7("0404054212", "Nicolae Ceausescu");
	Persoana p8("2131456347", "Gigel Ionescu");
	Persoana vp2[] = { p6,p7,p8 };
	Partid partid1("partidul pardid",3,vp2, 4, vp);
	cout << partid1;
	partid1 += p5;
	cout << partid1;
	partid1 -= p5;
	/*if (p1 == p2)cout << "da";
	else cout << "nu";*/
	cout << partid1;
	Asociatie* a = new Partid("partidul partid", 3, vp2, 4, vp);
	cout << "\nCotizatia totala este: " << a->getCotizatie();//chiar daca a este de tip Asociatie, se apeleaza functia din clasa derivata
	//late binding
	delete a;
	Asociatie a1;
	cout <<endl<< a1.getCotizatie();//conceptul de polimorfism
	cout << "\nCotizatia totala este: " << partid1.getCotizatie();
	return 0;
}