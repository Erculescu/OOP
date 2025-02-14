#include<iostream>
#include<vector>
//#include "Persoana.h"
using namespace std;

int sumaInt(int v1, int v2) {
	return v1 + v2;
}
template<class T>
T suma(T v1, T v2) {
	return v1 + v2;
}
template<class T1, class T2>
T1 sumaGenerala(T2 v1, T2 v2) {
	return(T1) (v1 + v2);
}

class Angajat{
public:
	string nume;
	float salariu;
	explicit operator float() {
		return this->salariu;
	}
	Angajat(float _salariu) {
		this->nume = "Anonim";
		this->salariu = _salariu;
	}
	Angajat() {
		this->nume = "-";
		this->salariu = 0;
	}
	Angajat& operator+(const Angajat a) {
		Angajat rez;
		rez.nume = this->nume;	
		rez.salariu = this->salariu + a.salariu;
		return rez;
	}
	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "Nume: " << a.nume << " Salariu: " << a.salariu;
		return out;
	}
};
template<class T>
class Container {
	T v[10];
	int nrelem;
public:
	Container() {
		this->nrelem = 0;
	}
	Container(T _v[10], int _nrelem) {
		this->nrelem = _nrelem;
		for (int i = 0; i < this->nrelem; i++) {
			this->v[i] = _v[i];
		}
	}
	friend ostream& operator<<(ostream& out, const Container<T>& c) {
		out << "nr elem:" << c.nrelem << endl;
		for (int i = 0; i < c.nrelem; i++) {
			out << c.v[i] << " ";
		}
		return out;
	}
	
};


int main() {
	/*Persoana p;
	p.nume = "Gigel";
	p.prezentare();*/

	int rez = sumaInt(2, 3);
	Angajat a1;
	a1.salariu = 5000;
	Angajat a2;
	a2.salariu = 1000;
	//int rez2 = sumaInt(a1, a2);
	rez = suma<int>(2, 5);
	cout << "Suma int: " << rez << endl;
	float rezfloat = suma<float>(2.5, 5.5);
	cout << "Suma float: " << rezfloat << endl;
	string rezstring = suma<string>("Ana", " are mere");
	cout << "Suma string: " << rezstring << endl;
	Angajat rezAngajat = suma<Angajat>(a1, a2);
	cout << "Suma Angajat: " << rezAngajat.salariu << endl;
	int rezint = sumaGenerala<int, int>(2, 5);
	cout << "Suma int: " << rezint << endl;
	bool rezbool = sumaGenerala<bool, int>(2, 5);
	cout << "Suma bool: " << rezbool << endl;
	rezfloat = sumaGenerala<float, Angajat>(a1, a2);
	cout << "Suma float: " << rezfloat << endl;


	int v[] = { 1,2,3,4,5 };
	Container<int> containerInt(v, 5);
	cout << containerInt << endl;
	Angajat vAngajat[] = { a1,a2 };
	Container<Angajat> containerAngajat(vAngajat, 2);
	cout << containerAngajat << endl;

	vector<int> vInt;
	vInt.push_back(1);
	return 0;
}