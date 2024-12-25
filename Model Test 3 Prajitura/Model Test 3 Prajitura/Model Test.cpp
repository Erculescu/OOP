#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Prajitura {
	string denumire;
	int nrCalorii;
	int nrIngrediente;
	float* gramajIngrediente;
	bool esteVegana;
	float rating;//1-5
	static float pretAmbalaj;//in caz de servicii transport
	//static float gramajMinim;
public:
	Prajitura() {
		this->denumire = "-";
		this->nrCalorii = 0;
		this->nrIngrediente = 0;
		this->gramajIngrediente = nullptr;
		this->esteVegana = false;
		this->rating = 1;

	}
	float getrating() {
		return this->rating;
	}
	void setrating(float _rating) {
		if (_rating >= 1 && _rating <= 5)
			this->rating = _rating;
	}
	static float getPretAmbalaj() {
		return Prajitura::pretAmbalaj;
	}
	static void setPretAmbalaj(float _pretAmbalaj) {
		if (_pretAmbalaj > 0)
			Prajitura::pretAmbalaj = _pretAmbalaj;
	}
	//nu am primit si rating ca am zis sa exersam constr fara toti param
	Prajitura(string _denumire, int _nrCalorii, int _nrIngrediente, float* _gramajIngrediente,bool _esteVegana ) {
	this->denumire = _denumire;
	this->nrCalorii = _nrCalorii;
	if(_nrIngrediente>0&&_gramajIngrediente!=nullptr)
	{
		this->nrIngrediente = _nrIngrediente;
		this->gramajIngrediente = new float[nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++)
			this->gramajIngrediente[i] = _gramajIngrediente[i];
	}
	this->esteVegana = _esteVegana;
	this->rating = 1;
}

	float getGramajTotal() {
		float rez = 0;
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			rez += this->gramajIngrediente[i];
		}
		return rez;
	}
	~Prajitura() {
		if (this->gramajIngrediente != nullptr) {
			delete[]this->gramajIngrediente;
			this->gramajIngrediente = nullptr;
		}
	}
	Prajitura(const Prajitura& p) {
		this->denumire = p.denumire;
		this->nrCalorii = p.nrCalorii;
		if (p.nrIngrediente > 0 && p.gramajIngrediente != nullptr)
		{
			this->nrIngrediente = p.nrIngrediente;
			this->gramajIngrediente = new float[nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->gramajIngrediente[i] = p.gramajIngrediente[i];
		}
		this->esteVegana = p.esteVegana;
		this->rating = p.rating;


	}

	Prajitura& operator=(const Prajitura& p)
	{
		if (this != &p) {
			if (this->gramajIngrediente != nullptr) {
				delete[]this->gramajIngrediente;
				this->gramajIngrediente = nullptr;
			}
			this->denumire = p.denumire;
			this->nrCalorii = p.nrCalorii;
			if (p.nrIngrediente > 0 && p.gramajIngrediente != nullptr)
			{
				this->nrIngrediente = p.nrIngrediente;
				this->gramajIngrediente = new float[nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++)
					this->gramajIngrediente[i] = p.gramajIngrediente[i];
			}
			this->esteVegana = p.esteVegana;
			this->rating = p.rating;

		}
		return *this;
	}
	Prajitura& operator*=(int multiplicator) {
		if (multiplicator > 0)
		{
			for (int i = 0; i < this->nrIngrediente; i++)
				this->gramajIngrediente[i] *= multiplicator;
		}

		return *this;
	}



	friend ostream& operator<<(ostream& out, const Prajitura& p)
	{
		out << "\n Denumire: " << p.denumire << "\n Nr calorii: " << p.nrCalorii << "\n Nr Ingrediente: " << p.nrIngrediente;
		out << "\n Gramaj Ingrediente: ";
		for (int i = 0; i < p.nrIngrediente; i++)
			out << p.gramajIngrediente[i]<<" ";
		out << "\n Este vegana?: " << p.esteVegana;
		out << "\n Rating: " << p.rating;
		return out;
	}

	friend Prajitura operator+(float x, const Prajitura& p) {
		//op+NU modifica operanzii
		Prajitura rez=p;
		if (rez.gramajIngrediente != nullptr)
		{
			delete[] rez.gramajIngrediente;
			rez.gramajIngrediente = nullptr;

		}
		rez.gramajIngrediente = new float[rez.nrIngrediente + 1];
		for (int i = 0; i < p.nrIngrediente; i++)
		{
			rez.gramajIngrediente[i] = p.gramajIngrediente[i];
		}
		rez.gramajIngrediente[rez.nrIngrediente] = x;
		rez.nrIngrediente++;

		return rez;
	}


};


float Prajitura::pretAmbalaj = 10;


int main()
{
	cout << "\n Zona constructor fara param, get si set";
	Prajitura p1;
	p1.setrating(4);
	cout << endl << p1.getrating();
	Prajitura::setPretAmbalaj(22);
	cout << endl << Prajitura::getPretAmbalaj();
	cout << "\n Constructor cu toti si destructor";
	float gramaje[] = { 500.4,20,10,55 };
	Prajitura p2("Amandina", 1000, 4, gramaje, true);
	cout << p2;
	cout << endl << p2.getGramajTotal();
	cout << "\n Zona constructor copiere.";
	Prajitura p3(p2);
	cout << p3;
	cout << "\n Zona testare operator egal";
	Prajitura p4;
	p4 = p3;
	cout << endl;
	cout << p4;
	cout << "\n Zona Testare operator *=";
	p4 *= 3;
	cout << endl;
	cout << p4;
	cout << "\n Zona Testare operator + ";
	p4=0.5+p4;
	cout << endl;
	cout << p4;
	/*Sau*/Prajitura p5 = 123 + p4;//copy elision


	return 0;
}