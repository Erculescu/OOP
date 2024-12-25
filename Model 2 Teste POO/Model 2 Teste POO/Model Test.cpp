#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Plantatie
{
	const int id;
	string adresa;
	int nrPomi;
	int* varsta;
	static int varstaMinimaRod;
	string portAltoi;
	bool DestinatieIntensiva;
public:
	Plantatie(int _id) :id(_id) {
		this->adresa = "-";
		this->nrPomi = 0;
		this->varsta = nullptr;
		this->portAltoi = "-";
		this->DestinatieIntensiva = false;
	}
	void setvarsta(int _nrpomi,int* _varsta) {
		if (_nrpomi > 0&&_varsta!=nullptr) {
			this->varsta = nullptr;
			this->varsta = new int[_nrpomi];
			this->nrPomi = _nrpomi;
			for(int i=0;i<this->nrPomi;i++)
			{
				this->varsta[i] = _varsta[i];
			}
		}
	}
	int* getvarsta() const {
		return this->varsta;
	}
	void setadresa(string _adresa) {
		this->adresa = _adresa;
	}
	string const getadresa() {
		return this->adresa;
	}
//Constructor cu toti param + destructor

	Plantatie(int _id, string _adresa, int _nrPomi, int* _varsta, string _portAltoi, bool _DestnatieIntensiva):id(_id) {
		this->adresa = _adresa;
		if (_nrPomi > 0 && _varsta != nullptr)
		{
			this->nrPomi = _nrPomi;
			this->varsta = nullptr;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++)
				this->varsta[i] = _varsta[i];
		}
		this->portAltoi = _portAltoi;
		this->DestinatieIntensiva = _DestnatieIntensiva;


	}
	~Plantatie() {
		cout << "\nApel Destructor";
		if(this->varsta!=nullptr)
		{
			delete[]this->varsta;
			this->varsta = nullptr;
		}
	}
	//Metoda getNrPomiVarstaMinima(int varsta) 
	int getNrPomiVarstaMinima(int* varsta) {
		int k = 0;
		for (int i = 0; i < this->nrPomi; i++)
		{
			if (this->varsta[i] == this->varstaMinimaRod)
				k++;
		}
		return k;
	}
	//Constructor copiere
	Plantatie(const Plantatie& p):id(p.id) {
		this->adresa = p.adresa;
		if (p.nrPomi > 0 && p.varsta != nullptr)
		{
			this->nrPomi = p.nrPomi;
			this->varsta = nullptr;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++)
				this->varsta[i] = p.varsta[i];
		}
		this->portAltoi = p.portAltoi;
		this->DestinatieIntensiva = p.DestinatieIntensiva;

	}

	//Operator =
	Plantatie& operator=(const Plantatie& p) {
		if (this != &p) {
			if (this->varsta != nullptr)
			{
				delete[]this->varsta;
				this->varsta = nullptr;
			}
			this->adresa = p.adresa;
			if (p.nrPomi > 0 && p.varsta != nullptr)
			{
				this->nrPomi = p.nrPomi;
				this->varsta = nullptr;
				this->varsta = new int[this->nrPomi];
				for (int i = 0; i < this->nrPomi; i++)
					this->varsta[i] = p.varsta[i];
			}
			this->portAltoi = p.portAltoi;
			this->DestinatieIntensiva = p.DestinatieIntensiva;

		}
		return *this;
	}

	//Operatorul int+Clasa
	friend Plantatie operator+(int x, const Plantatie& p)
	{//Op + nu modifica operanzii
		Plantatie rez = p;
		if (rez.varsta != nullptr) {
			delete[] rez.varsta;
			rez.varsta = nullptr;
		}
		rez.varsta = new int[rez.nrPomi + 1];
		for (int i = 0; i < rez.nrPomi; i++)
			rez.varsta[i] = p.varsta[i];
		rez.varsta[rez.nrPomi] = x;
		rez.nrPomi++;
		return rez;

	}
	friend ostream& operator<<(ostream& out, const Plantatie& p) {
		out << "\n--------------------";
		out << "\nAdresa Pepinierei: " << p.adresa;
		out << "\nNr pomi disponibili: " << p.nrPomi;
		out << "\nVarsta pomilor: ";
		for (int i = 0; i < p.nrPomi; i++)
			out << p.varsta[i] << " ";
		out << "\nPort-Altoiul pomilor: " << p.portAltoi;
		out << "\nSunt potriviti plantarii in regim intensiv: ";
		if (p.DestinatieIntensiva == 0)
			out << "Nu";
		else out << "Da";
		out << "\n--------------------";
		return out;
	}
	friend istream& operator>>(istream& in, Plantatie& p) {
		
		cout << "\nAdresa Pepinierei: ";
		string buffer;
		in >> buffer;
		p.adresa = buffer;
		cout << "\nNr pomi disponibili: ";
		in >> p.nrPomi;
		cout << "\nVarsta pomilor: ";
		for (int i = 0; i < p.nrPomi; i++)
			in >> p.varsta[i];
		cout << "\nPort-Altoiul pomilor: ";
		in >> buffer;
		p.portAltoi = buffer;
		cout << "\nSunt potriviti plantarii in regim intensiv: ";
		in >> p.DestinatieIntensiva;
		return in;
	}

	//Supraincarcare operator ==
	bool operator ==(const Plantatie& p)const {
		int k = 0;
		if (this->adresa == p.adresa)
			k++;
		if (this->nrPomi == p.nrPomi)
			k++;
		for (int i = 0; i < this->nrPomi; i++)
		{
			if (this->varsta[i] == p.varsta[i])
				k++;
		}
		if (this->portAltoi == p.portAltoi)
			k++;
		if (this->DestinatieIntensiva == p.DestinatieIntensiva)
			k++;
		return k == (4 + p.nrPomi);
	}

};

int Plantatie::varstaMinimaRod = 3;
int main() {
	//Testare constructor cu un param +getter si setter
	Plantatie Csaba(1);
	Csaba.setadresa("Strada Motilor 52");
	cout << Csaba.getadresa();
	int varste[] = { 4,2,5 };
	cout << endl << Csaba.getvarsta();
	Csaba.setvarsta(3, varste);
	cout << endl << Csaba.getvarsta();
	//Testare constructor cu toti param + destructor
	int age[] = { 3,6,2,1 };
	Plantatie Sarusi(2, "Arad", 4, age, "Corcodus", false);
	cout << endl << Sarusi.getadresa();
	//Testare functie getNrPomiVarstaMinima(int varsta) 
	cout << endl << Sarusi.getNrPomiVarstaMinima(age);
	//Testare constructor copiere
	Plantatie Samoila(Sarusi);
	cout << endl << Samoila.getadresa();
	//Testare Operator =
	Samoila=Csaba;
	cout << endl << Samoila.getadresa();
	//Testare operator +
	Samoila = 3+Samoila;
	cout << endl << Samoila.getNrPomiVarstaMinima(Samoila.getvarsta());
	//Testare operator << >>
	cin >> Samoila;
	cout << Samoila;
	//Testare operator ==
	Plantatie Maracineni(5);
	Maracineni = Samoila;
	if (Csaba == Maracineni)
		cout << "\nDa";
	else
		cout << "\nNu";
	return 0;
}