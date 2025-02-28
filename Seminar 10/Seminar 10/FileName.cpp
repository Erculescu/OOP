#include<iostream>
using namespace std;

enum Ambalaj {
	CUTIE, HARTIE, GLOB, PLIC
};

ostream& operator<<(ostream& out, Ambalaj a) {
	switch (a)
	{
	case CUTIE:
		out << "Cutie";
		break;
	case HARTIE:
		out << "Hartie";
		break;
	case GLOB:
		out << "Glob";
		break;
	case PLIC:
		out << "Plic";
		break;
	default:
		out << "Lipsa";
		break;
	}
	return out;
}

istream& operator>>(istream& in, Ambalaj& a) {
	int x;
	cin >> x;
	switch (x)
	{
	case 0:
		a = Ambalaj::CUTIE;
		break;
	case 1:
		a = Ambalaj::HARTIE;
		break;
	case 2:
		a = Ambalaj::GLOB;
		break;
	case 3:
		a = Ambalaj::PLIC;
		break;
	default:
		a = Ambalaj::HARTIE;
		break;
	}
	return in;
}

//Cadou has a Ambalaj
class Cadou {
	string denumire = "-";
	float pret = 0;
	Ambalaj ambalaj = Ambalaj::HARTIE;

public:
	Cadou() {}

	Cadou(string _denumire, float _pret, Ambalaj _ambalaj) :denumire(_denumire), pret(_pret), ambalaj(_ambalaj) {}

	Cadou(const Cadou& c) :denumire(c.denumire), pret(c.pret), ambalaj(c.ambalaj) {}

	Cadou& operator=(const Cadou& c) {
		this->denumire = c.denumire;
		this->pret = c.pret;
		this->ambalaj = c.ambalaj;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Cadou& c) {
		out << "\nDenumire: " << c.denumire;
		out << ", pret: " << c.pret;
		out << ", ambalaj: " << c.ambalaj;
		return out;
	}

	friend istream& operator>>(istream& in, Cadou& c) {
		cout << "\nIntroduceti denumire: ";
		in >> c.denumire;
		cout << "Introduceti pret: ";
		in >> c.pret;
		cout << "Introduceti ambalaj: ";
		in >> c.ambalaj;
		return in;
	}
};
//Wishlist has a lista/vector cadou*
class Wishlist {
	string posesor="anonim";
	int nrCadouri=0;
	Cadou** listaCadouri=nullptr;
public:
	Wishlist(){ }
	Wishlist(string _posesor, int _nrCadouri, Cadou** _listaCadouri) {
		this->posesor = _posesor;
		if (_nrCadouri > 0 && _listaCadouri != nullptr) {
			this->nrCadouri = _nrCadouri;
			this->listaCadouri = new Cadou * [this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
			{
				//this->listaCadouri[i] = new Cadou();//const fara param
				//*this->listaCadouri[i] = *_listaCadouri[i];//Daca zic doar this e adresa, de asta punem *this pentru a obtine continutul

				this->listaCadouri[i] = new Cadou(*_listaCadouri[i]);//constructor de copiere

			}
		}

	}
	Wishlist(string _posesor, int _nrCadouri, Cadou* _listaCadouri) {
		this->posesor = _posesor;
		if (_nrCadouri > 0 && _listaCadouri != nullptr) {
			this->nrCadouri = _nrCadouri;
			this->listaCadouri = new Cadou * [this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
			{

				this->listaCadouri[i] = new Cadou(_listaCadouri[i]);//constructor de copiere

			}
		}

	}
	Wishlist(const Wishlist& w) {
		this->posesor = w.posesor;
		if (w.nrCadouri > 0 && w.listaCadouri != nullptr) {
			this->nrCadouri = w.nrCadouri;
			this->listaCadouri = new Cadou * [this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
			{
				//this->listaCadouri[i] = new Cadou();//const fara param
				//*this->listaCadouri[i] = *_listaCadouri[i];//Daca zic doar this e adresa, de asta punem *this pentru a obtine continutul

				this->listaCadouri[i] = new Cadou(*w.listaCadouri[i]);//constructor de copiere

			}
		}
	}

	Wishlist& operator=(const Wishlist& w) {
		if (this != &w) {
			if (this->listaCadouri != nullptr) {
				//parcurgem invers
				for (int i = 0; i < this->nrCadouri; i++)
					delete this->listaCadouri[i];

				delete[] this->listaCadouri;
				this->listaCadouri = nullptr;
			}
			this->posesor = w.posesor;
			if (w.nrCadouri > 0 && w.listaCadouri != nullptr) {
				this->nrCadouri = w.nrCadouri;
				this->listaCadouri = new Cadou * [this->nrCadouri];
				for (int i = 0; i < this->nrCadouri; i++)
				{
					//this->listaCadouri[i] = new Cadou();//const fara param
					//*this->listaCadouri[i] = *_listaCadouri[i];//Daca zic doar this e adresa, de asta punem *this pentru a obtine continutul

					this->listaCadouri[i] = new Cadou(*w.listaCadouri[i]);//constructor de copiere

				}
			}
		}
		else {
			this->listaCadouri = nullptr;
			this->nrCadouri = 0;
		}
		return *this;

	}
	~Wishlist() {
		if (this->listaCadouri != nullptr) {
			//parcurgem invers
			for (int i = 0; i < this->nrCadouri; i++)
				delete this->listaCadouri[i];
		
			delete[] this->listaCadouri;
			this->listaCadouri = nullptr;
		}
	}
	friend ostream& operator<<(ostream& out, const Wishlist& w) {
		out << "\nPosesor " << w.posesor;
		out << "\nNr cadouri " << w.nrCadouri;
		out << "\nLista cadouri: ";
		for (int i = 0; i < w.nrCadouri; i++)
		{
			out << *w.listaCadouri[i];
		}
		return out;
	}
};


int main() {
	Cadou c1("stilou", 450, CUTIE);
	Cadou c2("carte", 100, HARTIE);
	Cadou c3("glob", 60, GLOB);
	Cadou c4("geanta", 1000, CUTIE);
	Cadou* lista1[] = { &c1,&c2,&c3,&c4 };//nu se apeleaza niciun constructor din clasa Cadouri
	Wishlist w1("gigel", 4, lista1);
	cout << w1;
	Cadou lista2[] = { c1,c2,c3,c4 };//constructor copiere de 4 ori
	Wishlist w2("Costel", 4, lista2);
	cout << w2;
	Cadou lista3[4];//constructor fara param de 4 ori
	return 0;

	//!!La alocare statica ne roaga profa sa nu mai initializam tot vectorul pe 0, nullptr, etc

	//De lucrat si celelalte wishlist-uri din github!!!!!!
}