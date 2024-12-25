#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Magazin {
	const int nrRap;
	char* dataAn;
	int nrVanzari;
	float* valoareVanzare;
public:
	Magazin():nrRap(0+Magazin::nrVanzari++) {
		//Constructor fara param
		this->dataAn = new char[strlen("necunoscut") + 1];
		strcpy(this->dataAn, "necunoscut");
		this->nrVanzari = 0;
		this->valoareVanzare = nullptr;
	}
	Magazin(const char* _dataAn, int _nrVanzari, const float* _valoareVanzare) :nrRap(0 + Magazin::nrVanzari++) {
		//Constructor cu toti param
		if (_dataAn != nullptr)
		{
			this->dataAn = new char[strlen(_dataAn) + 1];
			strcpy(this->dataAn, _dataAn);
		}
		if (_nrVanzari > 0)
			this->nrVanzari = _nrVanzari;
		this->valoareVanzare = new float[_nrVanzari];
		for (int i = 0; i < _nrVanzari; i++)
		{
			this->valoareVanzare[i] = _valoareVanzare[i];
		}
	}
		Magazin(const Magazin& f) :nrRap(0 + Magazin::nrVanzari++) {
			//Constructor copiere
			if (f.dataAn != nullptr)
			{
				this->dataAn = new char[strlen(f.dataAn) + 1];
				strcpy(this->dataAn, f.dataAn);
			}
			if (f.nrVanzari > 0)
				this->nrVanzari = f.nrVanzari;
			this->valoareVanzare = new float[f.nrVanzari];
			for (int i = 0; i < f.nrVanzari; i++)
			{
				this->valoareVanzare[i] = f.valoareVanzare[i];
			}
		}
	
		void Afisare() {
			cout << "\n ----------------------------\n";
			cout << "Data raport Z: " << this->dataAn<<endl;
			cout << "Numar Vanzari: " <<this-> nrVanzari<<endl;
			cout << "Valoare Vanzari: " << endl;
			for (int i = 0; i < this->nrVanzari; i++)
				cout << this->valoareVanzare[i]<<" ";
			cout << "\n ----------------------------\n";

		}
		Magazin& operator =(const Magazin& f) {
			if (this != &f)
			{
				if (this->dataAn != nullptr)
				{
					delete[] this->dataAn;
					this->dataAn = nullptr;
				}
				if (this->valoareVanzare != nullptr)
				{
					delete[] this->valoareVanzare;
					this->valoareVanzare = nullptr;
				}
				if (f.dataAn != nullptr)
				{
					this->dataAn = new char[strlen(f.dataAn) + 1];
					strcpy(this->dataAn, f.dataAn);
				}
				if (f.nrVanzari > 0)
					this->nrVanzari = f.nrVanzari;
				this->valoareVanzare = new float[f.nrVanzari];
				for (int i = 0; i < f.nrVanzari; i++)
				{
					this->valoareVanzare[i] = f.valoareVanzare[i];
				}
			}
			return *this;
		}

		Magazin& operator +=(float x) {
			if(x>0)
			{
				float* copie;
				copie = new float[this->nrVanzari];
				for (int i = 0; i < this->nrVanzari; i++)
					copie[i] = this->valoareVanzare[i];
				this->nrVanzari++;
				this->valoareVanzare = new float[this->nrVanzari];
				for (int i = 0; i < this->nrVanzari; i++)
					this->valoareVanzare[i] = copie[i];
				this->valoareVanzare[this->nrVanzari - 1] = x;
				delete[] copie; copie = nullptr;
			}
			return *this;
		}

		Magazin& operator-=(float x) {
			int k=0;
			float* copie;
			copie = new float[this->nrVanzari - 1];
			for (int i = 0; i < this->nrVanzari; i++)
			{
				if (x != this->valoareVanzare[i])
				{
					copie[k] =this->valoareVanzare[i];
					k++;
				}

			}
			this->nrVanzari = k;
			this->valoareVanzare = new float[k];
			for (int i = 0; i < this->nrVanzari; i++)
			{
				this->valoareVanzare[i] = copie[i];
			}
			delete[] copie; copie = nullptr;
			return *this;
		}

		~Magazin() {
			cout << "\n Apel Destructor";
			if(this->dataAn!=nullptr)
			{
				delete[] this->dataAn;
				this->dataAn = nullptr;
			}
			if(this->valoareVanzare!=nullptr)
			{
				delete[] this->valoareVanzare;
				this->valoareVanzare = nullptr;
			}
		}
		friend ostream& operator<<(ostream& out, const Magazin& m);
		friend istream& operator>>(istream& in, Magazin& m);
};


ostream& operator<<(ostream& out, const Magazin& m) {
	out << "\n ----------------------------\n";
	out << "Data raport Z: " << m.dataAn << endl;
	out << "Numar Vanzari: " << m.nrVanzari << endl;
	out << "Valoare Vanzari: " << endl;
	for (int i = 0; i < m.nrVanzari; i++)
		out << m.valoareVanzare[i] << " ";
	out << "\n ----------------------------\n";
	return out;
}

istream& operator>>(istream& in, Magazin& m) {
	/*const int nrRap;
	char* dataAn;
	int nrVanzari;
	float* valoareVanzare;*/
	//if (m.dataAn != nullptr) {
	//	delete[] m.dataAn;
	//	m.dataAn = nullptr;
	//}
	//char dat[100];
	//cout << "Introduceti data din an: "<<endl;
	//in >> dat;
	//
	//	m.dataAn = new char[strlen(dat) + 1];
	//	strcpy(m.dataAn, dat);
	if (m.dataAn != nullptr) {
		delete[] m.dataAn;
		m.dataAn = nullptr;
	}

	// Allocate a temporary buffer for the date input
	char dat[100];
	cout << "Introduceti data din an: " << endl;
	in >> dat;  // Read into a temporary buffer

	// Allocate and copy the input to m.dataAn
	m.dataAn = new char[strlen(dat) + 1];
	strcpy(m.dataAn, dat);
	
	cout << "Introduceti nr de vanzari din acea zi: " << endl;
	int x;
	in >> x;
	if(x>0)
	{
		if (m.valoareVanzare != nullptr)
			delete[] m.valoareVanzare;
		m.nrVanzari = x;
		m.valoareVanzare = new float[x];
		cout << "Introduceti valorile fiecarei vanzari: ";
		for(int i=0; i<x;i++)
		{
			in >> m.valoareVanzare[i];
		}
	}
	else {
		m.nrVanzari = 0;
		m.valoareVanzare = nullptr;
	}
	return in;
}

int main()
{

	Magazin Vest;
	Vest.Afisare();
	float pret[] = { 280.9,500,620 };
	Magazin Pompe("5 Februarie 2024",3,pret);
	Pompe.Afisare();
	Vest=(Pompe);
	Vest.Afisare();
	Pompe += (969.3);
	Pompe.Afisare();
	Vest -= (280.9);
	Vest.Afisare();
	cout << Pompe;
	Magazin Best;
	cin >> Best;
	cout << Best;

	return 0;

}