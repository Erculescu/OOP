#include<iostream>
#include<cmath>
#include <string>
using namespace std;
enum source {solara,eoliana,hidro};

class Furnizor {
	string nume;
	source sursa_energie;
	float* consum_lunar_efectiv, consum_lunar_estimat;
	const int nrcontract;
	int durata_contract;
	static int contor;
	static float pret_kw;
public:
	Furnizor() :nrcontract(contor++) {
		this->nume = "anonim";
		this->sursa_energie = eoliana;
		this->consum_lunar_efectiv = nullptr;
		this->consum_lunar_estimat = 0;
		this->durata_contract = 0;
}

	Furnizor(string _nume, source _sursa_energie, float* _consum_lunar_efectiv, float _consum_lunar_estimat, int _durata_contract) :nrcontract(contor++)
	{
		this->nume = _nume;
		this->sursa_energie = _sursa_energie;
		if (_durata_contract > 0)
			this->durata_contract = _durata_contract;
		else
			this->durata_contract = 0;
		if (this->durata_contract > 0)
		{
			this->consum_lunar_efectiv = new float[this->durata_contract];
			for (int i = 0; i < this->durata_contract; i++)
				this->consum_lunar_efectiv[i] = _consum_lunar_efectiv[i];
		}
		else this->consum_lunar_efectiv = nullptr;
		if (_consum_lunar_estimat >= 0)
			this->consum_lunar_estimat = _consum_lunar_estimat;
		else this->consum_lunar_estimat = 0;

	}

	Furnizor(const Furnizor& f):nrcontract(f.nrcontract) {

		this->nume = f.nume;
		this->sursa_energie = f.sursa_energie;
		if (f.durata_contract > 0)
			this->durata_contract = f.durata_contract;
		else
			this->durata_contract = 0;
		if (this->durata_contract > 0)
		{
			this->consum_lunar_efectiv = new float[this->durata_contract];
			for (int i = 0; i < this->durata_contract; i++)
				this->consum_lunar_efectiv[i] = f.consum_lunar_efectiv[i];
		}
		else this->consum_lunar_efectiv = nullptr;
		if (f.consum_lunar_estimat >= 0)
			this->consum_lunar_estimat = f.consum_lunar_estimat;
		else this->consum_lunar_estimat = 0;


	}

	~Furnizor() {
		if (this->consum_lunar_efectiv != nullptr)
		{
			delete[] this->consum_lunar_efectiv;
			this->consum_lunar_efectiv = nullptr;
		}
	}

	Furnizor operator=(Furnizor& f) {
		if (this != &f) {
			if (this->consum_lunar_efectiv != nullptr)
			{
				delete[] this->consum_lunar_efectiv;
				this->consum_lunar_efectiv = nullptr;
			}
			this->nume = f.nume;
			this->sursa_energie = f.sursa_energie;
			if (f.durata_contract > 0)
				this->durata_contract = f.durata_contract;
			else
				this->durata_contract = 0;
			if (this->durata_contract > 0)
			{
				this->consum_lunar_efectiv = new float[this->durata_contract];
				for (int i = 0; i < this->durata_contract; i++)
					this->consum_lunar_efectiv[i] = f.consum_lunar_efectiv[i];
			}
			else this->consum_lunar_efectiv = nullptr;
			if (f.consum_lunar_estimat >= 0)
				this->consum_lunar_estimat = f.consum_lunar_estimat;
			else this->consum_lunar_estimat = 0;
		}
		return *this;
	}
	string getnume() {
		return this->nume;
	}
	void setnume(string _nume) {
		this->nume = _nume;
	}
	source getsursa() {
		return this->sursa_energie;
	}
	void setsursa(source _sursa_energie) {
		this->sursa_energie = _sursa_energie;
	}
	float* getconsumlunarefectiv() {
		return this->consum_lunar_efectiv;
	}
	void setconsumlunarefectiv(float* _consum_lunar_efectiv,int _durata_contract){
		if (this->consum_lunar_efectiv != nullptr)
		{
			delete[] this->consum_lunar_efectiv;
			this->consum_lunar_efectiv = nullptr;
		}
		if (_durata_contract > 0)
			this->durata_contract = _durata_contract;
		else
			this->durata_contract = 0;
		if (this->durata_contract > 0)
		{
			this->consum_lunar_efectiv = new float[this->durata_contract];
			for (int i = 0; i < this->durata_contract; i++)
				this->consum_lunar_efectiv[i] = _consum_lunar_efectiv[i];
		}
		else this->consum_lunar_efectiv = nullptr;
	}
	float getconsumlunarestimat() {
		return this->consum_lunar_estimat;
	}
	void setconsumlunarestimat(float _consum_lunar_estimat) {
		if (_consum_lunar_estimat >= 0)
			this->consum_lunar_estimat = _consum_lunar_estimat;
		else this->consum_lunar_estimat = 0;
	}

	int getduratacontract() {
		return this->durata_contract;
	}
	void setduratacontract(int _durata_contract) {
		if (_durata_contract >= 0)
			this->durata_contract = _durata_contract;
	}

	void operator()(int x, float y) {
		if (x < this->durata_contract&&y>=0)
			this->consum_lunar_efectiv[x] = y;

	}
	operator double() const {
		float k = 0;
		for (int i = 0; i < this->durata_contract; i++)
		{
			k = k + abs(this->consum_lunar_efectiv[i] - this->consum_lunar_estimat);
		}
		return k;

	}


	int lunaconsummin() {
		float luna_min = this->consum_lunar_efectiv[0];
		int luna = 0;
		for (int i = 0; i < this->durata_contract; i++)
		{
			if (this->consum_lunar_efectiv[i] < luna_min) {
				luna_min = this->consum_lunar_efectiv[i];
				luna = i;
			}
		}
		return luna+1;
	}
	
	float consumtotal() {
		float total = 0;
		for (int i = 0; i < this->durata_contract; i++)
			total = total + this->consum_lunar_efectiv[i];
		total = total * pret_kw;
		return total;
	}


	friend ostream& operator<<(ostream& out, const Furnizor& f)
	{
		out << "\n_____________________________\n";
		out << "\nNume: " << f.nume;
		out << "\nSursa de energie: " << f.sursa_energie;
		out << "\nDurata contract: " << f.durata_contract;
		out << "\nConsum lunar efectiv pentru lunile de contract: ";
		for (int i = 0; i < f.durata_contract; i++)
			out << f.consum_lunar_efectiv[i] << " ";
		out << "\nConsum lunar estimat: " << f.consum_lunar_estimat;
		out << "\n_____________________________\n";

		return out;
	}

};

float Furnizor::pret_kw = 0.7;
int Furnizor::contor = 0;

class Factura {
public:
	virtual float total() = 0;
	virtual void afisare() = 0;
	virtual ~Factura() = default;//virtual se realizeaza late binding
};//!! de nu uitat tabela de fct virtuale
//retine amprenta comportamentullui

class FacturaFurnizor : public Factura {
	Furnizor f;
public:
	FacturaFurnizor(Furnizor _f) :f(_f) {}
	float total() {
		return f.consumtotal();
	}
	void afisare() {
		cout << f;
	}
};
/*pt a demonstra virtualizarea, avem nev de 2 clase sau clasa de baza+derivata*/



int main() {
	Furnizor f1;
	float consum[] = { 333,211,79.9 };
	Furnizor f2("SolarClean", solara, consum, 188.3, 3);
	cout << f1;
	f2(1, 188.6);
	cout << f2;
	double k = f2;
	cout << "\n_____________Testare diferenta absoluta dintre consumuri____________\n";
	cout << k;
	cout << "\n___________________Testare metoda luna consum minim_________________\n";
	cout << f2.lunaconsummin();
	cout << "\n___________________Testare metoda valoare totala consum_________________\n";
	cout << f2.consumtotal();
	cout << "\n__________________Testare concept virtualizare prin abstractizare____________________\n";	
	FacturaFurnizor ff1(f2);
	cout << ff1.total();
	return 0;
}