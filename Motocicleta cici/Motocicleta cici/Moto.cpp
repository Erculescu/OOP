#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
enum tipPermis {A,A1,A2,B,C,E,Tr};
class Motocicleta {
	string marca;
	int nrCalatorii;
	int* kmCalatorii;
public:
	string serie;
	static tipPermis permis;

	Motocicleta() {
		this->marca = "anonim";
		this->nrCalatorii = 0;
		this->kmCalatorii = nullptr;
		this->serie = "anonim";
	}
	Motocicleta(const string _marca, int _nrCalatorii, int* _kmCalatorii) {
		this->marca = _marca;
		if (_nrCalatorii >= 0)
			this->nrCalatorii = _nrCalatorii;
		else this->nrCalatorii = 0;
		if (_kmCalatorii != nullptr) {
			{
				this->kmCalatorii = new int[this->nrCalatorii];
				for (int i = 0; i < this->nrCalatorii; i++)
					this->kmCalatorii[i] = _kmCalatorii[i];
			}
		}
		else
			this->kmCalatorii = nullptr;
	}




	Motocicleta(const string _marca, int _nrCalatorii, int* _kmCalatorii,const string _serie) {
		this->marca = _marca;
		if (_nrCalatorii >= 0)
			this->nrCalatorii = _nrCalatorii;
		else this->nrCalatorii = 0;
		if (_kmCalatorii != nullptr) {
			{
				this->kmCalatorii = new int[this->nrCalatorii];
				for (int i = 0; i < this->nrCalatorii; i++)
					this->kmCalatorii[i] = _kmCalatorii[i];
			}
		}
		else
			this->kmCalatorii = nullptr;
		this->serie = _serie;
		
	}
	Motocicleta(const Motocicleta& m) {
		this->marca = m.marca;
		if (m.nrCalatorii >= 0)
			this->nrCalatorii = m.nrCalatorii;
		else this->nrCalatorii = 0;
		if (m.kmCalatorii != nullptr) {
			{
				this->kmCalatorii = new int[this->nrCalatorii];
				for (int i = 0; i < this->nrCalatorii; i++)
					this->kmCalatorii[i] = m.kmCalatorii[i];
			}
		}
		else
			this->kmCalatorii = nullptr;
		this->serie = m.serie;
	}
	~Motocicleta() {
		if (this->kmCalatorii != nullptr)
		{
			delete[] this->kmCalatorii;
			this->kmCalatorii = nullptr;
		}
	}

	Motocicleta operator=(const Motocicleta& m) {
		if (this != &m) {
			if (this->kmCalatorii != nullptr)
			{
				delete[] this->kmCalatorii;
				this->kmCalatorii = nullptr;
			}
			this->marca = m.marca;
			if (m.nrCalatorii >= 0)
				this->nrCalatorii = m.nrCalatorii;
			else this->nrCalatorii = 0;
			if (m.kmCalatorii != nullptr) {
				{
					this->kmCalatorii = new int[this->nrCalatorii];
					for (int i = 0; i < this->nrCalatorii; i++)
						this->kmCalatorii[i] = m.kmCalatorii[i];
				}
			}
			else
				this->kmCalatorii = nullptr;
			this->serie = m.serie;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Motocicleta& m) {
		out << "\n___________________________\n";
		out << "\nMarca: " << m.marca;
		out << "\nNr calatorii: " << m.nrCalatorii;
		out << "\nKm parcursi in fiecare calatorie: ";
		for (int i = 0; i < m.nrCalatorii; i++)
			out << m.kmCalatorii[i] << " ";
		out << "\nSerie: " << m.serie;
		out << "\n___________________________\n";
		return out;
	}
	string getserie() {
		return this->serie;
	}

	void serializare(const Motocicleta& m, const string fisier) {
		ofstream fout(fisier, ios::out | ios::binary);
		if (fout.is_open()) {
			int lungime = m.marca.length();
			fout.write((char*)&lungime, sizeof(int));
			fout.write(m.marca.c_str(), lungime);
			fout.write((char*)&m.nrCalatorii, sizeof(int));
			for (int i = 0; i < m.nrCalatorii; i++)
				fout.write((char*)&m.kmCalatorii[i], sizeof(int));
			lungime = m.serie.length();
			fout.write((char*)&lungime, sizeof(int));
			fout.write(m.serie.c_str(), lungime);
			fout.close();
		}
		else cout << "fisierul nu a putut fi deschis." << endl;
	}
	void deserializare(const Motocicleta& m, const string fisier) {
		ifstream fin(fisier, ios::in | ios::binary);
		if (fin.is_open()) {
			int lungime;
			fin.read((char*)&lungime, sizeof(int));
			char* aux = new char[lungime + 1];
			fin.read(aux, lungime);
			aux[lungime] = '\0';
			this->marca = aux;
			delete[] aux;
			fin.read((char*)&this->nrCalatorii, sizeof(int));
			if (this->kmCalatorii != nullptr) {
				delete[] this->kmCalatorii;
				this->kmCalatorii = nullptr;
			}
			this->kmCalatorii = new int[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++)
				fin.read((char*)&this->kmCalatorii[i], sizeof(int));
			fin.read((char*)&lungime, sizeof(int));
			aux = new char[lungime + 1];
			fin.read(aux, lungime);
			aux[lungime] = '\0';
			this->serie = aux;
			delete[] aux;
		}
		else cout << "fisierul nu a putut fi deschis." << endl;
	}

};
tipPermis Motocicleta::permis = A;

class Vehicul :public Motocicleta {
public:
	Vehicul() :Motocicleta() {
		this->permis = A;
	}
	Vehicul(const string _marca, int _nrcalatorii, int* _kmCalatorii, string _serie) :Motocicleta(_marca, _nrcalatorii, _kmCalatorii) {
		this->serie = _serie;
	}
	~Vehicul() = default;
	string getserie() {
		return this->serie;
	}

};
class MotocicletaElectrica :public Motocicleta {
	int capacitateBaterie;
	int range;
	int nrIncarcari;
	int* kmIncarcati;
public:
	MotocicletaElectrica() :Motocicleta() {
		this->capacitateBaterie = 0;
		this->range = 0;
		this->nrIncarcari = 0;
		this->kmIncarcati = nullptr;
	}

	MotocicletaElectrica(int _capacitateBaterie, int _range,int _nrIncarcari, int* _kmIncarcati, const string _marca, int _nrcalatorii, int* _kmCalatorii, const string _serie) :Motocicleta(_marca, _nrcalatorii, _kmCalatorii, _serie) {
		this->capacitateBaterie = _capacitateBaterie;
		this->range = _range;
		if (_nrIncarcari > 0) {
			this->nrIncarcari = _nrIncarcari;;
			if(this->kmIncarcati!=nullptr)
			{
				delete[] this->kmIncarcati;
				this->kmIncarcati = new int[this->nrIncarcari];
				for (int i = 0; i < this->nrIncarcari; i++)
					this->kmIncarcati[i] = _kmIncarcati[i];
			}
			else{
				this->kmIncarcati = new int[this->nrIncarcari];
				for (int i = 0; i < this->nrIncarcari; i++)
					this->kmIncarcati[i] = _kmIncarcati[i];
			}
		}
		 else{ this->nrIncarcari = 0; this->kmIncarcati = nullptr; }
	}
	~MotocicletaElectrica() {
		if (this->kmIncarcati != nullptr)
		{
			delete[] this->kmIncarcati;
			this->kmIncarcati = nullptr;
		}
	}
	MotocicletaElectrica(const MotocicletaElectrica& me) :Motocicleta(me) {
		this->capacitateBaterie = me.capacitateBaterie;
		this->range = me.range;
		if (me.nrIncarcari >= 0) {
			this->nrIncarcari = me.nrIncarcari;;
			if (this->kmIncarcati != nullptr)
			{
				delete[] this->kmIncarcati;
				this->kmIncarcati = new int[this->nrIncarcari];
				for (int i = 0; i < this->nrIncarcari; i++)
					this->kmIncarcati[i] = me.kmIncarcati[i];
			}
			else {
				this->kmIncarcati = new int[this->nrIncarcari];
				for (int i = 0; i < this->nrIncarcari; i++)
					this->kmIncarcati[i] = me.kmIncarcati[i];
			}
		}
		else { this->nrIncarcari = 0; this->kmIncarcati = nullptr; }
	}
	MotocicletaElectrica operator=(const MotocicletaElectrica& me) {
		if (this != &me) {
			Motocicleta::operator=(me);
			if (this->kmIncarcati != nullptr)
			{
				delete[] this->kmIncarcati;
				this->kmIncarcati = nullptr;
			}
			this->capacitateBaterie = me.capacitateBaterie;
			this->range = me.range;
			if (me.nrIncarcari >= 0) {
				this->nrIncarcari = me.nrIncarcari;;
				if (this->kmIncarcati != nullptr)
				{
					delete[] this->kmIncarcati;
					this->kmIncarcati = new int[this->nrIncarcari];
					for (int i = 0; i < this->nrIncarcari; i++)
						this->kmIncarcati[i] = me.kmIncarcati[i];
				}
				else {
					this->kmIncarcati = new int[this->nrIncarcari];
					for (int i = 0; i < this->nrIncarcari; i++)
						this->kmIncarcati[i] = me.kmIncarcati[i];
				}
			}
			else { this->nrIncarcari = 0; this->kmIncarcati = nullptr; }
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const MotocicletaElectrica& me) {
		out << (Motocicleta&)me;
		out << "\n_________Caracteristici motocicleta electrica__________\n";
		out << "\nCapacitate baterie: " << me.capacitateBaterie;
		out << "\nRange: " << me.range;
		out << "\nNr incarcari: " << me.nrIncarcari;
		out << "\nKm incarcati la fiecare incarcare: ";
		for (int i = 0; i < me.nrIncarcari; i++)
			out << me.kmIncarcati[i]<<" ";
		out << "\n___________________________\n";
		return out;
	}

};



int main() {
	int km1[] = { 2322,89,100,300 };
	int km2[] = { 50,21,33,110,19 };
	Motocicleta m1;
	Motocicleta m2("Bmw", 4, km1,"WAUZZZ555");
	Motocicleta m3(m2);
	cout << m2;
	Vehicul v1("Audi", 5, km2, "WPZZZ2020");
	Motocicleta* p;
	p = &m1;
	cout << p->getserie()<<endl;
	p = &v1;
	cout << p->getserie();
	m1.serializare(m2, "fisier.bin");
	m1.deserializare(m1, "fisier.bin");
	cout << m1;
	int kmi[] = { 22,37,14,34 };
	MotocicletaElectrica me1(45, 90,4,kmi, "Harley Davidson", 5, km2, "USADDD01");
	cout << me1;

	return 0;
}