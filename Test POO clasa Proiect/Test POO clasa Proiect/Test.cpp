#include<iostream>
using namespace std;


class Proiect {
	string denumire;
	int nrMembri;
	int nrLimbaje;
	string* limbaje;
	float buget;
	static int nrProiecteMultiLimbaj;
	bool InternalUse;
public:
	//Zona constr fara param + get & set
	Proiect() {
		this->denumire = "-";
		this->nrMembri = 0;
		this->nrLimbaje = 0;
		this->limbaje = nullptr;
		this->buget = 0;
		this->InternalUse = false;
	}
	int getnrLimbaje() {
		return nrLimbaje;
	}
	void setnrLimbaje(int _nrLimbaje) {
		if(_nrLimbaje>0)
		this->nrLimbaje = _nrLimbaje;
	}
	string* getlimbaje() {
		return limbaje;
	}
	void setlimbaje(string* _limbaje,int _nrlimbaje) {
		if (_limbaje != nullptr&&_nrlimbaje>0) {
	
			this->nrLimbaje = _nrlimbaje;
			if(nrLimbaje>1)
			{
				this->nrProiecteMultiLimbaj++;
			}
			delete[] this->limbaje;
			this->limbaje = new string[this->nrLimbaje];
			for (int i = 0; i < this->nrLimbaje; i++)
			{
				this->limbaje[i] = _limbaje[i];
			}
		}
	}
	//Zona constr cu toti param & destr
	Proiect(const string _denumire, int _nrMembri, int _nrLimbaje, string* _limbaje, float _buget, bool _InternalUse) {
		this->denumire = _denumire;
		if (_nrMembri > 0)
			this->nrMembri = _nrMembri;
		string* copie = new string[_nrLimbaje];
		int k=0;
		for (int i = 0; i < _nrLimbaje; i++)
		{
			bool Ok = true;
			for (int j = 0; j < k; j++)
			{
				if (_limbaje[i] == copie[i])
				{
					Ok = false;
					break;
				}
			}
			if(Ok)
			{
				copie[k++] = _limbaje[i];
			}
		}
		this->nrLimbaje = k;
		this->limbaje = new string[this->nrLimbaje];
		for(int i=0;i<this->nrLimbaje;i++)
		{
			this->limbaje[i] = copie[i];
		}
		delete[] copie;

		/*if(_nrLimbaje>0)
		{
			this->nrLimbaje = _nrLimbaje;
			if (this->nrLimbaje > 1)
				this->nrProiecteMultiLimbaj++;
		}
		this->limbaje = new string[this->nrLimbaje];*/
		/*int cnrLimbaje = _nrLimbaje;
		for(int i=0;i<_nrLimbaje;i++)
		{
			int k = 0;
			for (int j = 0; j < _nrLimbaje; j++)
			{
				if (_limbaje[i] == _limbaje[j])
					k++;
			}
			if (k > 1)
				cnrLimbaje--;
		}
		if (cnrLimbaje > 0)
		{
			this->nrLimbaje = cnrLimbaje;
			if (this->nrLimbaje > 1)
				this->nrProiecteMultiLimbaj++;
		}
		this->limbaje = new string[this->nrLimbaje];
		int q = 0;
		for (int i = 0; i < _nrLimbaje; i++)
		{
			int k = 0;
			for (int j = 0; j < _nrLimbaje; j++)
			{
				if (_limbaje[i] == limbaje[j])
					k++;
			}
			if (k == 1)
				this->limbaje[q++] = _limbaje[i];
		}*/

		/*for (int i = 0; i < this->nrLimbaje; i++) {
			this->limbaje[i] = _limbaje[i];
		}*/
		if (_buget > 0)
			this->buget = _buget;
		this->InternalUse = _InternalUse;
	}
	~Proiect() {
		cout << "\nApel Destructor";
		if(this->limbaje!=nullptr)
		{
			delete[] this->limbaje;
			this->limbaje = nullptr;
		}
	}
	//Zona functie adauga limbaj
	void adaugaLimbaj(string limbaj, int pozitie) {
		string* rez;
		rez = nullptr;
		rez = new string[this->nrLimbaje + 1];
		if (pozitie < this->nrLimbaje) {
			for (int i = 0; i < pozitie; i++)
			{
				rez[i] = this->limbaje[i];
			}

			rez[pozitie] = limbaj;
			for (int i = pozitie + 1; i < this->nrLimbaje; i++)
			{
				rez[i] = this->limbaje[i];
			}
		}this->nrLimbaje++;
		if(this->nrLimbaje>1)
		this->nrProiecteMultiLimbaj++;
		delete[]this->limbaje;
		this->limbaje = new string[this->nrLimbaje];
		this->limbaje = rez;
	}

	//Zona constructor copiere
	Proiect (const Proiect& p) {

		this->denumire = p.denumire;
		if (p.nrMembri > 0)
			this->nrMembri = p.nrMembri;
		if(p.nrLimbaje>0)
		{
			this->nrLimbaje = p.nrLimbaje;
			if (this->nrLimbaje > 1)
				this->nrProiecteMultiLimbaj++;
		}
		this->limbaje = new string[this->nrLimbaje];
	/*	int cnrLimbaje = _nrLimbaje;
		for (int i = 0; i < _nrLimbaje; i++)
		{
			int k = 0;
			for (int j = 0; j < _nrLimbaje; j++)
			{
				if (_limbaje[i] == _limbaje[j])
					k++;
			}
			if (k > 1)
				cnrLimbaje--;
		}
		if (cnrLimbaje > 0)
		{
			this->nrLimbaje = cnrLimbaje;
			if (this->nrLimbaje > 1)
				this->nrProiecteMultiLimbaj++;
		}
		this->limbaje = new string[this->nrLimbaje];
		int q = 0;
		for (int i = 0; i < _nrLimbaje; i++)
		{
			int k = 0;
			for (int j = 0; j < _nrLimbaje; j++)
			{
				if (_limbaje[i] == limbaje[j])
					k++;
			}
			if (k == 1)
				this->limbaje[q++] = _limbaje[i];
		}*/

		for (int i = 0; i < this->nrLimbaje; i++) {
			this->limbaje[i] = p.limbaje[i];
		}
		if (p.buget > 0)
			this->buget =p.buget;
		this->InternalUse = p.InternalUse;
	}
	//Zona operator egal
	Proiect& operator=(const Proiect& p) {
		if (this != &p) {
			
			if (this->limbaje != nullptr)
			{
				delete[] this->limbaje;
				this->limbaje = nullptr;
			}
			this->denumire = p.denumire;
			if (p.nrMembri > 0)
				this->nrMembri = p.nrMembri;
			if (p.nrLimbaje > 0)
			{
				this->nrLimbaje = p.nrLimbaje;
				if (this->nrLimbaje > 1)
					this->nrProiecteMultiLimbaj++;
			}
			this->limbaje = new string[this->nrLimbaje];
			/*	int cnrLimbaje = _nrLimbaje;
				for (int i = 0; i < _nrLimbaje; i++)
				{
					int k = 0;
					for (int j = 0; j < _nrLimbaje; j++)
					{
						if (_limbaje[i] == _limbaje[j])
							k++;
					}
					if (k > 1)
						cnrLimbaje--;
				}
				if (cnrLimbaje > 0)
				{
					this->nrLimbaje = cnrLimbaje;
					if (this->nrLimbaje > 1)
						this->nrProiecteMultiLimbaj++;
				}
				this->limbaje = new string[this->nrLimbaje];
				int q = 0;
				for (int i = 0; i < _nrLimbaje; i++)
				{
					int k = 0;
					for (int j = 0; j < _nrLimbaje; j++)
					{
						if (_limbaje[i] == limbaje[j])
							k++;
					}
					if (k == 1)
						this->limbaje[q++] = _limbaje[i];
				}*/

			for (int i = 0; i < this->nrLimbaje; i++) {
				this->limbaje[i] = p.limbaje[i];
			}
			if (p.buget > 0)
				this->buget = p.buget;
			this->InternalUse = p.InternalUse;



		}
		return *this;
	}


	//Zona supraincarcare operator +
	Proiect operator +(const Proiect& p)const {
		Proiect rez;
		rez.denumire = this->denumire + "_" + p.denumire;
		rez.nrMembri = this->nrMembri + p.nrMembri;
		rez.nrLimbaje = this->nrLimbaje + p.nrLimbaje;
		rez.limbaje = new string[rez.nrLimbaje];
		for (int i = 0; i < this->nrLimbaje; i++)
			rez.limbaje[i] = this->limbaje[i];
		int poz = this->nrLimbaje;
		for (int i = 0; i < p.nrLimbaje; i++)
			rez.limbaje[poz+i] = p.limbaje[i];
		rez.buget = this->buget + p.buget;
		rez.nrProiecteMultiLimbaj = this->nrProiecteMultiLimbaj + p.nrProiecteMultiLimbaj;
		rez.InternalUse = this->InternalUse || p.InternalUse;

		
		return rez;
	}


	friend ostream& operator<<(ostream& out, const Proiect& p) {
		out << "\n-----------------------------";
		out << "\nDenumire: " << p.denumire;
		out << "\nNr membri: " << p.nrMembri;
		out << "\nNr limbaje programare: " << p.nrLimbaje;
		out << "\nLimbajele: ";
		for (int i = 0; i < p.nrLimbaje; i++)
			out << p.limbaje[i] << " ";
		out << "\nBuget: " << p.buget;
		out << "\nEste destinat pentru uz intern sau extern? " << p.InternalUse;
		out << "\n-----------------------------";
		return out;
	}

};

int Proiect::nrProiecteMultiLimbaj = 0;

int main() {
	//Testare constr fara param+ get si set
	Proiect p1;
	cout << p1.getlimbaje() << endl;
	string limbaj[] = { "cpp" };
	p1.setlimbaje(limbaj, 1);
	cout << p1.getnrLimbaje();
	//Testare constr cu toti param & destructor
	string lb[] = { "cpp", "java", "react", "python" };
	Proiect p2("aplicatie", 5, 4, lb, 5000, 1);
	//Testare proprietatea de unicitate
	string test[] = { "cpp","cpp","assembly" };
	Proiect p3("app", 5, 3, test, 7000, 1);
	cout << endl << p3.getnrLimbaje();
	//Testare functie adauga limbaj
	p1.adaugaLimbaj("java", 1);
	//Testare Constr copiere
	Proiect p4(p2);
	//Testare operator egal
	p1 = p3;
	//Testare supraincarcare operator +
	Proiect p5;
	p5 = p1 + p2;
	//Testare supraincarcare operator<<
	cout << p2;
	cout << p3;
	return 0;
}