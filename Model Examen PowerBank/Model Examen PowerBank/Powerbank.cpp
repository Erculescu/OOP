#include<iostream> 
using namespace std;
enum colour{red,green, yellow,blue};

class PowerBank {
	int capacitate;
	int greutate;
	colour culoare;
	int nrPorturi;
	float* vitezaincarcare;
	static int nrPowerBank;
public:
	PowerBank() {
		this->capacitate = 0;
		this->greutate = 0;
		this->culoare = blue;
		this->nrPorturi = 0;
		this->vitezaincarcare = nullptr;
		this->nrPowerBank++;
	}
	PowerBank(int _capacitate, int _greutate, colour _culoare, int _nrPorturi, float* _vitezaincarcare) {
		this->capacitate = _capacitate;
		this->greutate = _greutate;
		this->culoare = _culoare;
		if (_nrPorturi > 0)
			this->nrPorturi = _nrPorturi;
		else this->nrPorturi = 0;
		if (_vitezaincarcare != nullptr)
		{
			this->vitezaincarcare = new float[this->nrPorturi];
			for (int i = 0; i < this->nrPorturi; i++)
				this->vitezaincarcare[i] = _vitezaincarcare[i];
		}
		else this->vitezaincarcare = nullptr;
		this->nrPowerBank++;
	}
	
	PowerBank(const PowerBank &p) {
		this->capacitate = p.capacitate;
		this->greutate = p.greutate;
		this->culoare = p.culoare;
		if (p.nrPorturi > 0)
			this->nrPorturi = p.nrPorturi;
		else this->nrPorturi = 0;
		if (p.vitezaincarcare != nullptr)
		{
			this->vitezaincarcare = new float[this->nrPorturi];
			for (int i = 0; i < this->nrPorturi; i++)
				this->vitezaincarcare[i] = p.vitezaincarcare[i];
		}
		else this->vitezaincarcare = nullptr;
		this->nrPowerBank++;

	}

	~PowerBank() {
		delete[]this->vitezaincarcare;
		this->vitezaincarcare = nullptr;
	}

	PowerBank operator=(const PowerBank& p) {
		if(this!=&p){
			delete[]this->vitezaincarcare;
			this->vitezaincarcare = nullptr;
			this->capacitate = p.capacitate;
			this->greutate = p.greutate;
			this->culoare = p.culoare;
			if (p.nrPorturi > 0)
				this->nrPorturi = p.nrPorturi;
			else this->nrPorturi = 0;
			if (p.vitezaincarcare != nullptr)
			{
				this->vitezaincarcare = new float[this->nrPorturi];
				for (int i = 0; i < this->nrPorturi; i++)
					this->vitezaincarcare[i] = p.vitezaincarcare[i];
			}
			else this->vitezaincarcare = nullptr;
		}
		return *this;
	}

	int getCapacitate() {
		return this->capacitate;
	}
	void setCapacitate(int _capacitate) {
		if(_capacitate>0)
			this->capacitate = _capacitate;
	}
	int getGreutate() {
		return this->greutate;
	}
	void setGreutate(int _greutate) {
		if (_greutate > 0)
			this->greutate = _greutate;
	}
	colour getCuloare() {
		return this->culoare;
	}
	void setCuloare(colour _culoare) {
		this->culoare = _culoare;
	}
	int getNrPorturi() {
		return this->nrPorturi;
	}
	void setNrPorturi(int _nrPorturi) {
		if (_nrPorturi > 0)
			this->nrPorturi = _nrPorturi;
	}
	float* getVitezaIncarcare() {
		return this->vitezaincarcare;
	}
	void setVitezaincarcare(float* _vitezaincarcare, int _nrPorturi){
		if (_nrPorturi > 0)
			this->nrPorturi = _nrPorturi;
		else this->nrPorturi = 0;
		if (_vitezaincarcare != nullptr)
		{
			this->vitezaincarcare = new float[this->nrPorturi];
			for (int i = 0; i < this->nrPorturi; i++)
				this->vitezaincarcare[i] = _vitezaincarcare[i];
		}
		else this->vitezaincarcare = nullptr;
	}

	static int getNrPowerBank() {
		return nrPowerBank;
	}
	
	PowerBank operator +=(int procentaj) {
		this->capacitate = this->capacitate + this-> capacitate * procentaj / 100;
		return *this;

	}
	PowerBank operator -=(int procentaj) {
		this->capacitate = this->capacitate - this->capacitate * procentaj / 100;
		return *this;

	}

	bool operator==(PowerBank p) const{
		int k = 0;
		if (this-> capacitate ==p.capacitate)
			k++;
		if (this->greutate == p.greutate)
			k++;
		if (this->culoare == p.culoare)
			k++;
		if (this->nrPorturi == p.nrPorturi)
			k++;
		for (int i = 0; i < this->nrPorturi; i++)
			if (this->vitezaincarcare[i] == p.vitezaincarcare[i])
				k++;
		return k == (4 + this->nrPorturi);
	}


	friend ostream& operator<<(ostream& out, PowerBank p) {
		out << "\n___________despartitor______________\n";
		out << "\nCapacitate: " << p.capacitate ;
		out << "\nGreutate: " << p.greutate;
		out << "\nCuloare: " << p.culoare;
		out << "\nNumar porturi: " << p.nrPorturi;
		out << "\nViteza de incarcare pentru: ";
		for (int i = 0; i < p.nrPorturi; i++)
		{
			out << "Portul: " << i + 1 << " " << p.vitezaincarcare[i] << endl;
		}
		out << "\n___________despartitor______________\n";
		return out;
	}
	void early() {
		cout << "\nNumarul de powerbank-uri este: " << this->nrPowerBank;
	}
	virtual void late() {
		cout << "\nExista " << this->nrPowerBank << " powerbank-uri ";
	}

	template <typename t>
	void afis(t value);

};

template <typename t>
void PowerBank::afis(t value) {
	cout << value;
}


class BaterieSolara :public PowerBank {
	int nrCelule;
public:
	BaterieSolara() :PowerBank() {
		this->nrCelule = 0;
	}
	BaterieSolara(int _capacitate, int _greutate, colour _culoare, int _nrPorturi, float* _vitezaincarcare,
		int _nrCelule) :PowerBank(_capacitate, _greutate, _culoare, _nrPorturi, _vitezaincarcare) {
		if (_nrCelule > 0)
			this->nrCelule = _nrCelule;
	}
	BaterieSolara(const BaterieSolara& b) :PowerBank(b) {
		this->nrCelule = b.nrCelule;
	}
	BaterieSolara operator=(const BaterieSolara& b) {
		if (this != &b) {
			PowerBank::operator=(b);
			this->nrCelule = b.nrCelule;
		}
		return *this;
	}

friend ostream& operator<<(ostream& out, BaterieSolara b){
	out << "\n_____________________________\n";
	out << "\nNr celule: " << b.nrCelule;
	out << "\nCapacitate: " << b.getCapacitate();
	out << "\nGreutate: " << b.getGreutate();
	out << "\nCuloare: " << b.getCuloare();
	out << "\nNumar Porturi: " << b.getNrPorturi();
	out << "\nViteza de incarcare pentru: ";
	for (int i = 0; i < b.getNrPorturi(); i++)
	{
		out << "Portul: " << i + 1 << " " << b.getVitezaIncarcare()[i] << endl;
	}

	out << "\n_____________________________\n";
	return out;
}

void early() {
	cout << "\nNumarul de baterii solare este: " << this->getNrPowerBank();
}
void late() override {
	cout << "\nExista " << this->getNrPowerBank() << " baterii solare";
}
};




int PowerBank::nrPowerBank = 0;
int main()
{
	PowerBank p1;
	float v1[] = {12.3,22.12,130.01,220.5};
	PowerBank p2(5000, 350, blue, 4, v1);
	p2 += 25;
	cout <<endl<< p2.getCapacitate();
	p2 -= 40;
	if (p1 == p2) cout << "\nSunt egale";
	else cout << "\nNu sunt egale";
	cout << p2;
	PowerBank p3(p2);
	if (p3 == p2) cout << "\nSunt egale";
	else cout << "\nNu sunt egale";

	BaterieSolara b1;
	float v2[] = { 1000,750,900,1500 };
	BaterieSolara b2(29000, 25000, green, 4, v2, 16);
	cout << b2;
	BaterieSolara b3(b2);
	cout << b3;
	cout << "\n____________-Prezentare Early Binding______________\n";
	p2.early();//Diferenta dintre early si late binding este ca early binding se face la compilare si late binding la runtime
	b2.early();
	cout << "\n____________-Prezentare Late Binding_______________\n";
	p2.late();
	BaterieSolara* pb = new BaterieSolara();
	pb->late();
	delete pb;
	cout << "\n__________________Afisare template___________________\n";
	p2.afis("Caz de utilizare al template-ului");
	return 0;
}