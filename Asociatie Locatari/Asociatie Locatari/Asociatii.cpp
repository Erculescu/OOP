#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Bloc {
	string denumire;
	string adresa;
	int nrApartamente;
	int nrLocatari;
public:
	Bloc() {
		this->denumire = "Anonim";
		this->adresa = "Anonim";
		this->nrApartamente = 0;
		this->nrLocatari = 0;
	}
	Bloc(const string _denumire, const string _adresa, int _nrApartamente, int _nrLocatari) {
		this->denumire = _denumire;
		this->adresa = _adresa;
		this->nrApartamente = _nrApartamente;
		this->nrLocatari = _nrLocatari;
	}
	Bloc(const Bloc& b) {
		this->denumire = b.denumire;
		this->adresa = b.adresa;
		this->nrApartamente = b.nrApartamente;
		this->nrLocatari = b.nrLocatari;
	}
	Bloc& operator=(const Bloc& b) {
		if(this!=&b){
			this->denumire = b.denumire;
			this->adresa = b.adresa;
			this->nrApartamente = b.nrApartamente;
			this->nrLocatari = b.nrLocatari;
		}
		return *this;
	}
	~Bloc() = default;
	friend ostream& operator<<(ostream& out, const Bloc& b) {
		out << "\nDenumire: " << b.denumire; 
		out << "\nAdresa: " << b.adresa;
		out << "\nNumar de apartamente: " << b.nrApartamente;
		out << "\nNumar de locatari: " << b.nrLocatari;
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Bloc& b) {
		cout << "Denumire: ";
		in >> b.denumire;
		cout << "Adresa: ";
		in >> b.adresa;
		cout << "Numar de apartamente: ";
		in >> b.nrApartamente;
		cout << "Numar de locatari: ";
		in >> b.nrLocatari;
		return in;
	}
	int getnrLocatari() { return this->nrLocatari; }
	int getnrApartamente() { return this->nrApartamente; }

	void serializare(const Bloc& b, const string numeFisier) {
		ofstream fout(numeFisier, ios::out | ios::binary);
			if (fout.is_open()) {
				int lungime = b.denumire.length();
				fout.write((char*)&lungime, sizeof(int));
				fout.write(b.denumire.c_str(), lungime);
				lungime = b.adresa.length();
				fout.write((char*)&lungime, sizeof(int));
				fout.write(b.adresa.c_str(), lungime);
				fout.write((char*)&b.nrApartamente, sizeof(int));
				fout.write((char*)&b.nrLocatari, sizeof(int));
				fout.close();
			}
			else { cout << "\nFisierul nu a putut fi deschis."; }
	}

	void deserializare(Bloc& b, const string numeFisier) {
		ifstream fin(numeFisier, ios::in | ios::binary);
		if (fin.is_open()) {
			int lungime = 0;
			fin.read((char*)&lungime, sizeof(int));
			char* buffer = new char[lungime + 1];
			fin.read(buffer, lungime);
			buffer[lungime] = '\0';
			b.denumire = buffer;
			delete[] buffer;
			lungime = 0;
			fin.read((char*)&lungime, sizeof(int));
			buffer = new char[lungime + 1];
			fin.read(buffer, lungime);
			buffer[lungime] = '\0';
			b.adresa = buffer;
			delete[] buffer;
			fin.read((char*)&b.nrApartamente, sizeof(int));
			fin.read((char*)&b.nrLocatari, sizeof(int));
			fin.close();
		}
		else { cout << "\nFisierul nu a putut fi deschis."; }

	}


};

class Asociatie {
	string denumireAsc;
	string adresaAsc;
	int nrBlocuri;
	Bloc* blocuri;
	static float fondRezerva;
	static float cotaLocatar;
public:
	Asociatie() {
		this->denumireAsc = "anonim";
		this->adresaAsc = "anonim";
		this->nrBlocuri = 0;
		this->blocuri = nullptr;
	}
	Asociatie(const string _denumireAsc, const string _adresaAsc, int _nrBlocuri, Bloc* _blocuri) {
		this->denumireAsc = _denumireAsc;
		this->adresaAsc = _adresaAsc;
		this->nrBlocuri = _nrBlocuri;
		this->blocuri = new Bloc[this->nrBlocuri];
		for (int i = 0; i < this->nrBlocuri; i++) {
			this->blocuri[i] = _blocuri[i];
		}
	}
	Asociatie(const Asociatie& a) {
		this->denumireAsc = a.denumireAsc;
		this->adresaAsc = a.adresaAsc;
		this->nrBlocuri = a.nrBlocuri;
		this->blocuri = new Bloc[this->nrBlocuri];
		for (int i = 0; i < this->nrBlocuri; i++) {
			this->blocuri[i] = a.blocuri[i];
		}
	}
	~Asociatie() {
		if (this->blocuri != nullptr) {
			delete[] this->blocuri;
			this->blocuri = nullptr;
		}
	}
	Asociatie& operator=(const Asociatie& a) {
		if (this != &a) {
			if (this->blocuri != nullptr) {
				delete[] this->blocuri;
				this->blocuri = nullptr;
			}
			this->denumireAsc = a.denumireAsc;
			this->adresaAsc = a.adresaAsc;
			this->nrBlocuri = a.nrBlocuri;
			this->blocuri = new Bloc[this->nrBlocuri];
			for (int i = 0; i < this->nrBlocuri; i++) {
				this->blocuri[i] = a.blocuri[i];
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Asociatie& a) {
		out << "\nDenumire asociatie: " << a.denumireAsc;
		out << "\nAdresa asociatiei: " << a.adresaAsc;
		out << "\nNumar de blocuri: " << a.nrBlocuri;
		out << "\nBlocuri: ";
		out << "\n_______________________\n";
		for (int i = 0; i < a.nrBlocuri; i++) {
			out << a.blocuri[i];
			out << "\n_______________________\n";
		}
		return out;
	}
	Bloc& operator[](int i) {
		if (i >= 0 && i < this->nrBlocuri) {
			return this->blocuri[i];
		}
		else { throw exception("Index invalid(ca si tine)"); }
	}
	Asociatie& operator+=(const Bloc& b) {
		Asociatie rez = *this;
		if (this->blocuri != nullptr) {
			delete[] this->blocuri;
			this->blocuri = nullptr;
		}
		this->nrBlocuri=rez.nrBlocuri + 1;
		this->blocuri = new Bloc[this->nrBlocuri];
		for (int i = 0; i < this->nrBlocuri - 1; i++) {
			this->blocuri[i] = rez.blocuri[i];
		}
		this->blocuri[this->nrBlocuri - 1] = b;
		return *this;
	}
	int blocProfitabil() {//folosim float blocProfitabil() pt a returna valoarea maxima
		float* pf = nullptr;	
		pf = new float[this->nrBlocuri];
		for (int i = 0; i < this->nrBlocuri; i++) {
			pf[i] = pf[i] + this->blocuri[i].getnrApartamente() * fondRezerva + this->blocuri[i].getnrLocatari() * cotaLocatar;
		}
		float max = pf[0];
		int index = 0;
		for (int i = 1; i < this->nrBlocuri; i++) {
			if (pf[i] > max) { max = pf[i]; index = i; }

		}
		delete[] pf;
		//return max;
		return index;
	}

	int blocGherla() {//folosim float blocProfitabil() pt a returna valoarea minima
		float* pf = nullptr;
		pf = new float[this->nrBlocuri];
		for (int i = 0; i < this->nrBlocuri; i++) {
			pf[i] = pf[i] + this->blocuri[i].getnrApartamente() * fondRezerva + this->blocuri[i].getnrLocatari() * cotaLocatar;
		}
		float min = pf[0];
		int index = 0;
		for (int i = 1; i < this->nrBlocuri; i++) {
			if (pf[i] < min) { min = pf[i]; index = i; }

		}
		delete[] pf;
		//return max;
		return index;
	}

	float valoareIncasataLunar() {
		float max = 0;
		for (int i = 0; i < this->nrBlocuri; i++) {
			max = max + this->blocuri[i].getnrApartamente() * fondRezerva + this->blocuri[i].getnrLocatari() * cotaLocatar;
		}
		return max;
		}

	void serializare(const Asociatie& a, const string numeFisier) {
		ofstream fout(numeFisier, ios::out | ios::binary);
		if (fout.is_open()) {
			int lungime = a.denumireAsc.length();
			fout.write((char*)&lungime, sizeof(int));
			fout.write(a.denumireAsc.c_str(), lungime);
			lungime - a.adresaAsc.length();
			fout.write((char*)&lungime, sizeof(int));
			fout.write(a.adresaAsc.c_str(), lungime);
			fout.write((char*)&a.nrBlocuri, sizeof(int));
			for (int i = 0; i < a.nrBlocuri; i++) {
				a.blocuri[i].serializare(a.blocuri[i], "bloc" + to_string(i) + ".bin");
				fout.close();
			}
		}
		else { cout << "\nFisierul nu a putut fi deschis."; }
	}
	void deserializare(Asociatie& a, const string numeFisier) {
		ifstream fin(numeFisier, ios::in | ios::binary);
		if (fin.is_open()) {
			int lungime = 0;
			fin.read((char*)&lungime, sizeof(int));
			char* buffer = new char[lungime + 1];
			fin.read(buffer, lungime);
			buffer[lungime] = '\0';
			a.denumireAsc = buffer;
			delete[] buffer;
			lungime = 0;
			fin.read((char*)&lungime, sizeof(int));
			buffer = new char[lungime + 1];
			fin.read(buffer, lungime);
			buffer[lungime] = '\0';
			a.adresaAsc = buffer;
			fin.read((char*)&a.nrBlocuri, sizeof(int));
			delete[] a.blocuri;
			a.blocuri = new Bloc[a.nrBlocuri];
			for (int i = 0; i < a.nrBlocuri; i++) {
				a.blocuri[i].deserializare(a.blocuri[i], "bloc" + to_string(i) + ".bin");

			}
			fin.close();
		}
		else { cout << "\nFisierul nu a putut fi deschis."; }

	}




};
float Asociatie::fondRezerva = 30;
float Asociatie::cotaLocatar = 20;


int main() {
	Bloc b1;
	Bloc b2("Bloc A1", "Dr. Belsugului 20", 60, 80);
	//cin >> b1;
	//cout << b1;
	cout << b2;
	Bloc b3("Bloc A2", "Calea vitan 25", 30, 43);
	Bloc b4("Bloc p2", "splaiu unirii 15", 90, 110);
	Bloc vb[] = { b2,b3,b4 };
	Asociatie a1("Asociatia 1", "calea bucuresti 12", 3, vb);
	cout << a1;
	//cout << a1[2];
	//a1[0] = b1;
	//cout << a1;
	Bloc b5("One Verdi 1", "Prima cale 01", 40, 68);
	a1 += b5;
	cout << a1;
	int index = a1.blocProfitabil();
	cout << "Blocul cel mai profitabil este: " << a1[index]<<endl;
	index = a1.blocGherla();
	cout << "Blocul cel mai putin profitabil este: " << a1[index]<<endl;
	cout << "\nAsociatia de locatari incaseaza lunar: " << a1.valoareIncasataLunar() << " lei" << endl;
	/*b1.serializare(b1, "bloc1.bin");
	Bloc b6;
	b6.deserializare(b6, "bloc1.bin");
	cout << b6;*/
	a1.serializare(a1, "asociatie1.bin");
	Asociatie a2;
	a2.deserializare(a2, "asociatie1.bin");
	cout << a2;
	return 0;
}