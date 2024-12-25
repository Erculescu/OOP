#include<iostream>
using namespace std;

enum TipMotor {Diesel,Benzina,Hybrid,Electric};

class Autovehicul {
	const int VIN;
	string model;
	float pretBaza;
	int NrOptionale;
	string* Optionale;
	float* pretOptionale;
	int caiputere;
	TipMotor combustibil;
public:
	Autovehicul(int _VIN) :VIN(_VIN) {
		this->model = "-";
		this->pretBaza = 0;
		this->NrOptionale = 0;
		this->Optionale = nullptr;
		this->pretOptionale = nullptr;
		this->caiputere = 0;
		this->combustibil = Diesel;
	}
	Autovehicul(int _VIN, string _model, float _pretBaza, int _NrOptionale, string* _Optionale, float* _pretOptionale, int _caiputere, TipMotor _combustibil) :VIN(_VIN) {
		this->model = _model;
		if (_pretBaza > 0)
			this->pretBaza = _pretBaza;
		if (_NrOptionale > 0 && _Optionale != nullptr && _pretOptionale != nullptr)
		{
			this->NrOptionale = _NrOptionale;
			this->Optionale = new string[this->NrOptionale];
			this->pretOptionale = new float[this->NrOptionale];
			for (int i = 0; i < this->NrOptionale; i++) {
				this->Optionale[i] = _Optionale[i];
				this->pretOptionale[i] = _pretOptionale[i];
			}
		}
		this->caiputere = _caiputere;
		this->combustibil = _combustibil;
		
		}

	Autovehicul (const Autovehicul& a):VIN(a.VIN) {
		this->model = a.model;
		if (a.pretBaza > 0)
			this->pretBaza = a.pretBaza;
		if (a.NrOptionale > 0 && a.Optionale != nullptr && a.pretOptionale != nullptr)
		{
			this->NrOptionale = a.NrOptionale;
			this->Optionale = new string[this->NrOptionale];
			this->pretOptionale = new float[this->NrOptionale];
			for (int i = 0; i < this->NrOptionale; i++) {
				this->Optionale[i] = a.Optionale[i];
				this->pretOptionale[i] = a.pretOptionale[i];
			}
		}
		this->caiputere = a.caiputere;
		this->combustibil = a.combustibil;
	}
	Autovehicul& operator=(const Autovehicul& a) {
		if (this != &a) {
			if (this->Optionale != nullptr)
			{
				delete[]this->Optionale;
				this->Optionale = nullptr;
			}
			if (this->pretOptionale != nullptr)
			{
				delete[]this->pretOptionale;
				this->pretOptionale = nullptr;
			}

			this->model = a.model;
			if (a.pretBaza > 0)
				this->pretBaza = a.pretBaza;
			if (a.NrOptionale > 0 && a.Optionale != nullptr && a.pretOptionale != nullptr)
			{
				this->NrOptionale = a.NrOptionale;
				this->Optionale = new string[this->NrOptionale];
				this->pretOptionale = new float[this->NrOptionale];
				for (int i = 0; i < this->NrOptionale; i++) {
					this->Optionale[i] = a.Optionale[i];
					this->pretOptionale[i] = a.pretOptionale[i];
				}
			}
			this->caiputere = a.caiputere;
			this->combustibil = a.combustibil;


		}
		return *this;
	}

	void Buildsheet(float buget){
		float* copiepr=new float[this->NrOptionale];
		string* copietx=new string[this->NrOptionale];
		float total = this->pretBaza;
		for (int i = 0; i < this->NrOptionale; i++)
		{
		
		copiepr[i] = this->pretOptionale[i];
		copietx[i] = this->Optionale[i];
		}
		float auxpr;
		string auxtx;
		for (int i = 0; i < this->NrOptionale; i++)
		{
			for(int j=i+1;j<this->NrOptionale;j++)
			{if(copiepr[i]>copiepr[j])
			{
				auxpr = copiepr[i];
				copiepr[i] = copiepr[j];
				copiepr[j] = auxpr;
				auxtx = copietx[i];
				copietx[i] = copietx[j];
				copietx[j] = auxtx;
			}
			}
		}
		int k = 0;
		while ((total + copiepr[k]) < buget&&k<this->NrOptionale) {
			cout <<endl<< copietx[k] << "Costa: " << copiepr[k];
			k++;
		}
		delete[]copiepr;
		delete[]copietx;
		copiepr = nullptr;
		copietx = nullptr;
	
	}


	string getmodel() {
		return this->model;
	}
	void setmodel(string _model) {
		this->model = _model;
	}
	float getPretBaza() {
		return this->pretBaza;
	}
	void setPretBaza(float _pretBaza) {
		if(_pretBaza>0)
		this->pretBaza = _pretBaza;
	}

	~Autovehicul() {
		if(this->Optionale!=nullptr)
		{
			delete[]this->Optionale;
			this->Optionale = nullptr;
		}
		if(this->pretOptionale!=nullptr)
		{
			delete[]this->pretOptionale;
			this->pretOptionale = nullptr;
		}
	}

	bool operator!=(string x)const {
		bool OK = true;
		for (int i = 0; i < this->NrOptionale; i++)
			if (this->Optionale[i] == x)
				OK = false;
		return OK;
	}

	friend ostream& operator<<(ostream& out, const Autovehicul& a) {
		out << "\n---------------------";
		out << "\nModel auto: " << a.model;
		out << "\nPret de baza: " << a.pretBaza;
		out << "\nNr de optionale disponibilie: " << a.NrOptionale;
		out << "\nOptionalele: ";
		for(int i=0;i<a.NrOptionale;i++)
		{
			out <<endl<< a.Optionale[i] << " Costa: " << a.pretOptionale[i];
		}
		out << "\nPuterea vehiculului: " << a.caiputere;
		out << "\nCombustibilul: " << a.combustibil;
		out << "\n---------------------";
		return out;
	}
	friend istream& operator>>(istream& in, Autovehicul& a) {
		cout << "\nmodel?";
		in >> a.model;
		cout << "\npret baza?";
		in >> a.pretBaza;
		cout << "\nnr optionale?";
		in >> a.NrOptionale;
		cout << "\ndenumirea optionalelor?";
		a.Optionale = new string[a.NrOptionale];
		for (int i = 0; i < a.NrOptionale; i++)
			in >> a.Optionale[i];
		cout << "\npretul optionalelor?";
		a.pretOptionale = new float[a.NrOptionale];
		for (int i = 0; i < a.NrOptionale; i++)
			in >> a.pretOptionale[i];
		cout << "\nputerea?";
		in >> a.caiputere;
		cout << "\ncombustibil?";
		string buffer;
		in >> buffer;
		if (buffer == "Diesel")
			a.combustibil = Diesel;
		else
			if (buffer == "Benzina")
				a.combustibil = Benzina;
			else
				if (buffer == "Hybrid")
					a.combustibil = Hybrid;
				else
					a.combustibil = Electric;
		return in;
	}
	friend Autovehicul operator+(string x,const Autovehicul& a) {
		Autovehicul rez = a;
		delete[] rez.Optionale;
		rez.Optionale = new string[rez.NrOptionale + 1];
		delete[] rez.pretOptionale;
		rez.pretOptionale = new float[rez.NrOptionale + 1];
		for (int i = 0; i < rez.NrOptionale; i++)
		{
			rez.Optionale[i] = a.Optionale[i];
			rez.pretOptionale[i] = a.pretOptionale[i];
		}
		rez.Optionale[rez.NrOptionale] = x;
		rez.pretOptionale[rez.NrOptionale] = 0;
		rez.NrOptionale++;
		return rez;
	}
	
};


int main() {
	float opt[] = { 120.5,632,1200 };
	string option[] = { "scaune incalzite","jante 20'","plafon panoramic" };
	Autovehicul a1(0212,"Rs3", 37200, 3, option, opt, 380, Benzina);
	cout << a1;
	Autovehicul a2(892);
	cin >> a2;
	cout << a2;
	Autovehicul a3(a2);
	Autovehicul a4(0722);
	a4 = a1;
	cout << a4;
	a3 = "shadowline" + a3;
	cout << a3;
	a2.Buildsheet(38000);
	if (a1 != "scaune incalzite")
		cout << "\nda";
	else cout << "\nNu";
	return 0;
}