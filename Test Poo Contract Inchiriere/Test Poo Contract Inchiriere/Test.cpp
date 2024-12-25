#include<iostream>
using namespace std;
enum TipCombustibil { Benzina, Diesel, Hybrid, Electric };
class ContractInchiriere {
	const int id;
	string modelMasina;
	float pretZi;
	int nrOptionale;
	string* optionale;
	float pretOptional;
	static int Nrinchirieri;
	TipCombustibil tipcombustibil;
public:
	ContractInchiriere(int _id) :id(_id) {
		this->modelMasina = "-";
		this->pretZi = 0;
		this->nrOptionale = 0;
		this->optionale = nullptr;
		this->pretOptional = 0;
		this->Nrinchirieri++;
		this->tipcombustibil = Benzina;
		
	}
	static int getNrinchirieri(){
		return ContractInchiriere::Nrinchirieri;
	}
	static void setNrinchirieri(int _Nrinchirieri) {
		if (_Nrinchirieri > 0)
			ContractInchiriere::Nrinchirieri = _Nrinchirieri;
	}
	TipCombustibil gettipcombustibil() {
		return this->tipcombustibil;
	}
	void settipcombustibil(TipCombustibil _tipcombustibil) {
		this->tipcombustibil = _tipcombustibil;
	}

	ContractInchiriere(int _id, string _modelMasina, float _pretZi, int _nrOptionale, string* _optionale, float _pretoptional, TipCombustibil _tipcombustibil) :id(_id) {
		this->modelMasina = _modelMasina;
		if (_pretZi > 0)
			this->pretZi = _pretZi;
		int k = 0;
		if (_nrOptionale > 0)
		{
			string* copie = new string[_nrOptionale];
			for (int i = 0; i < _nrOptionale; i++)
			{
				bool ok = true;
				for (int j = 0; j < _nrOptionale; j++)
				{
					if (_optionale[i] == copie[i])
					{
						ok = false;
						break;
					}
				}
				if (ok)
					copie[k++] = _optionale[i];
			} this->nrOptionale = k;
			this->optionale = new string[this->nrOptionale];
			for (int i = 0; i < this->nrOptionale; i++)
			{
				this->optionale[i] = copie[i];

				
			}
			delete[]copie;
		}

		/*	this->nrOptionale = _nrOptionale;
		this->optionale = new string[this->nrOptionale];
		for (int i = 0; i < this->nrOptionale; i++)
			this->optionale[i] = _optionale[i];*/
		if (_pretoptional > 0)
			this->pretOptional = _pretoptional;
		this->Nrinchirieri++;
		this->tipcombustibil = _tipcombustibil;

	}
	~ContractInchiriere() {
		cout << "\napel destructor";
		if(this->optionale!=nullptr)
		{
			delete[] this->optionale;
			this->optionale = nullptr;
		}
	}
	ContractInchiriere(const ContractInchiriere& c) :id(c.id) {
		this->modelMasina = c.modelMasina;
		if (c.pretZi > 0)
			this->pretZi = c.pretZi;
		if (c.nrOptionale > 0)
			this->nrOptionale = c.nrOptionale;
		this->optionale = new string[this->nrOptionale];
		for (int i = 0; i < this->nrOptionale; i++)
			this->optionale[i] = c.optionale[i];
		if (c.pretOptional > 0)
			this->pretOptional = c.pretOptional;
		this->Nrinchirieri++;
		this->tipcombustibil = c.tipcombustibil;
	}

	ContractInchiriere& operator=(const ContractInchiriere& c) {
		if (this != &c)
		{
			if (this->optionale != nullptr)
			{
				delete[] this->optionale;
				this->optionale = nullptr;
			}
			this->modelMasina = c.modelMasina;
			if (c.pretZi > 0)
				this->pretZi = c.pretZi;
			if (c.nrOptionale > 0)
				this->nrOptionale = c.nrOptionale;
			this->optionale = new string[this->nrOptionale];
			for (int i = 0; i < this->nrOptionale; i++)
				this->optionale[i] = c.optionale[i];
			if (c.pretOptional > 0)
				this->pretOptional = c.pretOptional;
			this->Nrinchirieri++;
			this->tipcombustibil = c.tipcombustibil;

		}
		return *this;
	}

		int getNrOptionale(float buget, int nrZile) {
			float costfinal=0;
			int k = 0,copiezile=nrZile;
			while(copiezile!=0&&costfinal<buget)
			{
				costfinal += this->pretZi;
				copiezile--;
			}
			copiezile = nrZile;
			while(copiezile!=0&&costfinal<buget)
			{
				if (costfinal + this->pretOptional < buget)
					k++;
				costfinal += this->pretOptional;
				copiezile--;

			}
			return k;

		}
		bool operator==(const ContractInchiriere& c)const {
			int k = 0;
			for (int i = 0; i < this->nrOptionale; i++)
				if (this->optionale[i] == c.optionale[i])
					k++;
			return k == c.nrOptionale;
		}
		friend ContractInchiriere operator+(string x, const ContractInchiriere& c) {
			ContractInchiriere rez = c;
			bool OK = true;
			for (int i = 0; i < rez.nrOptionale; i++)
			{
				if (rez.optionale[i] == x)
					OK = false;
			}
			if (OK == true)
			{
				if (rez.optionale != nullptr)
				{
					delete[]rez.optionale;
					rez.optionale = nullptr;
				}
				rez.optionale = new string[rez.nrOptionale + 1];
				for (int i = 0; i < rez.nrOptionale; i++)
					rez.optionale[i] = c.optionale[i];
				rez.optionale[rez.nrOptionale] = x;
				rez.nrOptionale++;
			}
			return rez;
		}



	friend ostream& operator<<(ostream& out, const ContractInchiriere& c) {
		out << "\n-----------------------";
		out << "\nModel masina: " << c.modelMasina;
		out << "\nPret per zi: " << c.pretZi;
		out << "\nNr optionale disponibilie: " << c.nrOptionale;
		out << "\nOptionalele disponibilie: ";
		for (int i = 0; i < c.nrOptionale; i++)
			out << c.optionale[i] << "; ";
		out << "\nPretul optionalelor: " << c.pretOptional;
		out << "\nTipul combustibilului: " << c.tipcombustibil;
		return out;
	}
	friend istream& operator>>(istream& in, ContractInchiriere& c) {
		cout << "\nIntroduceti modelul autovehiculului: ";
		string buffer;
		in >> c.modelMasina;
		cout << "\nIntroduceti pretul per zi: ";
		in >> c.pretZi;
		cout << "\nIntroduceti nr de optionale: ";
		in >> c.nrOptionale;
		c.optionale = new string[c.nrOptionale];
		cout << "\nIntroduceti optionalele: ";
		for (int i = 0; i < c.nrOptionale; i++)
			in >> c.optionale[i];
		cout << "\nIntroduceti pretul optionalelor: ";
		in >> c.pretOptional;
		cout << "\nIntroduceti tipul combustibilului: ";
		in >>buffer;
		if (buffer == "Diesel")
			c.tipcombustibil = Diesel;
		else
			if (buffer == "Benzina")
				c.tipcombustibil = Benzina;
			else
				if (buffer == "Hybrid")
					c.tipcombustibil = Hybrid;
				else
					c.tipcombustibil = Electric;
		c.Nrinchirieri++;
		return in;
	}

};
int ContractInchiriere::Nrinchirieri = 0;

int main() {
	string opt[] = { "gps","scaun copil","gps"};
	ContractInchiriere c1(1, "Audi A3", 300, 2, opt, 100, Diesel);
	cout << c1;
	ContractInchiriere c2(2);
	cin >> c2;
	ContractInchiriere c3(3);
	c3 = c1;
	cout << c3;
	ContractInchiriere c4(c2);
	cout << endl<<ContractInchiriere::getNrinchirieri();
	ContractInchiriere::setNrinchirieri(10);
	cout <<endl<< c2.getNrOptionale(10000, 10);
	ContractInchiriere c5(c1);
	if (c2 == c5)
		cout << "\nDa";
	else cout << "\nNu";
	c2 = "gps" + c2;
	cout << c2;
	cout << c1;
	return 0;
}