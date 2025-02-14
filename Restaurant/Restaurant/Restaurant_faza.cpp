#include<iostream>
using namespace std;
enum culoare {rosu,galben, verde, albastru,mov, bej};
enum tip{normal, vegetarian, vegan, raw_vegan};


class FelMancare {
	string denumire;
	culoare Culoare;
	float greutate;
	int calorii;
	int nrAlergeni;
	string* alergeni;
	tip Tip;
public:
	FelMancare() {
		this->denumire = "Necunoscut";
		this->Culoare = rosu;
		this->greutate = 0;
		this->calorii = 0;
		this->nrAlergeni = 0;
		this->alergeni = nullptr;
		this->Tip = normal;
	}
	FelMancare(const string _denumire, culoare _Culoare, float _greutate, int _calorii, int _nrAlergeni,const string* _alergeni, tip _Tip) {
		this->denumire = _denumire;
		this->Culoare = _Culoare;
		this->greutate = _greutate;
		this->calorii = _calorii;
		this->nrAlergeni = _nrAlergeni;
		this->alergeni = new string[this->nrAlergeni];
		for (int i = 0; i < this->nrAlergeni; i++) {
			this->alergeni[i] = _alergeni[i];
		}
		this->Tip = _Tip;
	}
	FelMancare(const FelMancare& f) {
		this->denumire = f.denumire;
		this->Culoare = f.Culoare;
		this->greutate = f.greutate;
		this->calorii = f.calorii;
		this->nrAlergeni = f.nrAlergeni;
		this->alergeni = new string[this->nrAlergeni];
		for (int i = 0; i < this->nrAlergeni; i++) {
			this->alergeni[i] = f.alergeni[i];

		}
		this -> Tip = f.Tip;
	}
	~FelMancare() {
		if (this->alergeni != nullptr) {
			delete[] this->alergeni;
			this->alergeni = nullptr;
		}
		}
	FelMancare& operator=(const FelMancare& f) {
		if(this!=&f){
			if (this->alergeni != nullptr) {
				delete[] this->alergeni;
				this->alergeni = nullptr;

			}
			this->denumire = f.denumire;
			this->Culoare = f.Culoare;
			this->greutate = f.greutate;
			this->calorii = f.calorii;
			this->nrAlergeni = f.nrAlergeni;
			this->alergeni = new string[this->nrAlergeni];
			for (int i = 0; i < this->nrAlergeni; i++) {
				this->alergeni[i] = f.alergeni[i];

			}
			this->Tip = f.Tip;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const FelMancare& f) {
		out << "\nDenumire: " << f.denumire;
		out << "\nCuloare: " << f.Culoare;
		out << "\nGreutate: " << f.greutate;
		out << "\nCalorii: " << f.calorii;
		out << "\nNumar alergeni: " << f.nrAlergeni;
		out << "\nAlergenii: ";
		for(int i=0;i<f.nrAlergeni;i++)
		{
			out << f.alergeni[i] << " ";
		}
		out << "\nTipul: " << f.Tip;
		out << endl;
		return out;
	}
	FelMancare operator++() {
		this->greutate = this->greutate + 50;
		return *this;
	}
	FelMancare operator++(int) {
		this->greutate = this->greutate + 25;
		return *this;
	}
	friend class Meniu;
};

class Meniu {
	string denumireRest;
	int nrFeluri;
	FelMancare* feluri;
	float* preturi;
public:
	Meniu() {
		this->denumireRest = "Necunoscut";
		this->nrFeluri = 0;
		this->feluri = nullptr;
		this->preturi = nullptr;
	}
	Meniu(const string _denumireRest, int _nrFeluri, FelMancare* _feluri, float* _preturi) {
		this->denumireRest = _denumireRest;
		this->nrFeluri = _nrFeluri;
		this->feluri = new FelMancare[this->nrFeluri];
		this->preturi = new float[this->nrFeluri];
		for (int i = 0; i < this->nrFeluri; i++)
		{
			this->feluri[i] = _feluri[i];
			this->preturi[i] = _preturi[i];
		}
	}
	~Meniu() {
		if (this->feluri != nullptr) {
			delete[] this->feluri;
			this->feluri = nullptr;
		}
		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}
	}
	Meniu(const Meniu& m) {
		this->denumireRest = m.denumireRest;
		this->nrFeluri = m.nrFeluri;
		this->feluri = new FelMancare[this->nrFeluri];
		this->preturi = new float[this->nrFeluri];
		for (int i = 0; i < this->nrFeluri; i++)
		{
			this->feluri[i] = m.feluri[i];
			this->preturi[i] = m.preturi[i];
		}
	}
	Meniu& operator=(const Meniu& m) {
		if (this != &m) {
			if (this->feluri != nullptr) {
				delete[] this->feluri;
				this->feluri = nullptr;
			}
			if (this->preturi != nullptr) {
				delete[] this->preturi;
				this->preturi = nullptr;
			}
			this->denumireRest = m.denumireRest;
			this->nrFeluri = m.nrFeluri;
			this->feluri = new FelMancare[this->nrFeluri];
			this->preturi = new float[this->nrFeluri];
			for (int i = 0; i < this->nrFeluri; i++)
			{
				this->feluri[i] = m.feluri[i];
				this->preturi[i] = m.preturi[i];
			}
		}
		return *this;

	}
	friend ostream& operator<<(ostream& out, const Meniu& m) {
		out << "\nDenumire restaurant: " << m.denumireRest;
		out << "\nNumar feluri de mancare: " << m.nrFeluri;
		out << "\nFelurile de mancare sunt: ";
		for (int i = 0; i < m.nrFeluri; i++)
		{
			out << m.feluri[i];
			out << "Pretul: " << m.preturi[i] << endl;
		}
		return out;
	}

	Meniu& operator+=(const FelMancare& f) {
		Meniu aux = *this;
		if (this->feluri != nullptr) {
			delete[] this->feluri;
			this->feluri = nullptr;
		}
		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}
		this->nrFeluri = aux.nrFeluri + 1;
		this->feluri = new FelMancare[this->nrFeluri];
		this->preturi = new float[this->nrFeluri];
		for (int i = 0; i < this->nrFeluri - 1; i++) {
			this->feluri[i] = aux.feluri[i];
			this->preturi[i] = aux.preturi[i];
		}
		this->feluri[this->nrFeluri - 1] = f;
		this->preturi[this->nrFeluri - 1] = 0;
		return *this;
		
	}
	operator float()const {
		float s = 0;
		for (int i = 0; i < this->nrFeluri; i++) {
			s = s + this->feluri[i].calorii;
		}
		s = s / this->nrFeluri;
		return s;
	}
	float& operator[](int i) {
		if (i >= 0 && i < this->nrFeluri) {
			return this->feluri[i].greutate;
		}
		else {
			throw "index invalid";
			exit(-1);
		}
	}
};


int main() {
	FelMancare f1;
	string al1[] = { "oua","alune","gluten" };
	FelMancare f2("Omleta", galben, 350, 700, 3, al1,normal);
	FelMancare f3 = f2;
	f3++;
	cout << f3;
	++f2;
	cout << f2;
	FelMancare f4("Friptura", rosu, 400, 900, 2, new string[2]{ "oua","gluten" }, normal);
	cout << f4;
	FelMancare vf[] = { f1,f2,f3,f4 };
	float vp[] = { 20,25,30,55 };
	Meniu m1("Hanul lui manuc", 4, vf, vp);
	cout << m1;
	cout << "\n|||||||||||||||||||||||||||||||\n";
	FelMancare f5("Salata", verde, 180, 200, 1, new string[1]{ "gluten" }, raw_vegan);
	m1 += f5;
	cout << m1;
	cout << "\n|||||||||||||||||||||||||||||||\n";
	float medie = m1;
	cout << "\nMedia de calorii per fel de mancare este: " << medie;
	cout << "\n|||||||||||||||||||||||||||||||\n";
	cout << m1[4];

	return 0;
}