#include<iostream>
using namespace std;

class Termen {
	float coeficient;
	int grad;
public:
	Termen() {
		this->coeficient = 0;
		this->grad = 0;
	}
	Termen(float _coeficient, int _grad) {
		this->coeficient = _coeficient;
		this->grad = _grad;
	}
	Termen(const Termen& T) {
		this->coeficient = T.coeficient;
		this->grad = T.grad;
	}
	~Termen() = default;
	Termen& operator=(const Termen& T) {
		if(this!=&T){
			this->coeficient = T.coeficient;
			this->grad = T.grad;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, Termen& T) {
		out << "\nCoeficientul: " << T.coeficient;
		out << " - Gradul: " << T.grad<<";";
		return out;
	}
	friend istream& operator>>(istream& in, Termen& T) {
		cout << "\nCoeficientul: ";
		in >> T.coeficient;
		cout << "Gradul: ";
		in >> T.grad;
		return in;
	}

	Termen& operator--(int)  {
		if (this->grad-1 != 0) {
			this->coeficient = this->coeficient * this->grad;
			this->grad--;
		}
		else { this->coeficient = 0; this->grad = 0; }
		return *this;
	}
	Termen& operator++(int) {
		if (this->grad + 1 != 0) {
			this->coeficient = this->coeficient / this->grad;
			this->grad++;
		}
		else {
			this->coeficient = 0; this->grad = 0;
		}
		return *this;
	}
	friend class Polinom;

};

class Polinom{
	int nrTermeni;
	Termen* termeni;
public:
	Polinom() {
		this->nrTermeni = 0;
		this->termeni = nullptr;
	}
	Polinom(int _nrTermeni, Termen* _termeni) {
		this->nrTermeni = _nrTermeni;
		this->termeni = new Termen[this->nrTermeni];
		for (int i = 0; i < this->nrTermeni; i++) {
			this->termeni[i] = _termeni[i];
		}
	}

	Polinom(const Polinom& p) {
		this->nrTermeni = p.nrTermeni;
		this->termeni = new Termen[this->nrTermeni];
		for (int i = 0; i < this->nrTermeni; i++) {
			this->termeni[i] = p.termeni[i];
		}
	}
	~Polinom() {
		if (this->termeni != nullptr) {
			delete[] this->termeni;
			this->termeni = nullptr;
		}
	}
	Polinom& operator=(const Polinom& p) {
		if (this != &p) {
			if (this->termeni != nullptr) {
				delete[] this->termeni;
				this->termeni = nullptr;
			}
			this->nrTermeni = p.nrTermeni;
			this->termeni = new Termen[this->nrTermeni];
			for (int i = 0; i < this->nrTermeni; i++) {
				this->termeni[i] = p.termeni[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Polinom& p) {
		out << "\nNumarul de termeni: " << p.nrTermeni;
		out << "\nTermenii: ";
		for (int i = p.nrTermeni - 1; i >= 0; i--) {
			out << p.termeni[i] << " ";
		}
		out << "\n___________________________\n";
		return out;
	}
	friend istream& operator>>(istream& in, Polinom& p) {
		cout << "\nNumarul de termeni: ";
		in >> p.nrTermeni;
		cout << "Termenii: ";
		delete[]p.termeni;
		p.termeni = new Termen[p.nrTermeni];
		for (int i = 0; i < p.nrTermeni; i++)
			in >> p.termeni[i];
		return in;
	}
	operator double() const {
		double suma = 0;
		for (int i = 0; i < this->nrTermeni; i++) {
			suma = suma + this->termeni[i].coeficient * pow(2, this->termeni[i].grad);
		}
		return suma;

	}
	Polinom operator--(int) {
		
		for (int i = 0; i < this->nrTermeni; i++) {
			this->termeni[i]--;
		}
	
		return *this;
	}
	Polinom operator++(int) {
		for (int i = 0; i < this->nrTermeni; i++)
			this->termeni[i]++;
		return *this;

	}
	Polinom operator+(const Termen& t) const {
		Polinom rez;
		rez.nrTermeni = this->nrTermeni + 1;
		rez.termeni = new Termen[rez.nrTermeni];
		int p=-1;
		for (int i = 0; i < rez.nrTermeni - 1; i++)
		{
			if (t.grad < this->termeni[i].grad) {
				p = i;
				break;
			}
		}
		if (p < this->nrTermeni)
		{
			for (int i = 0; i < p; i++)
				rez.termeni[i] = this->termeni[i];
			rez.termeni[p] = t;
			for (int i = p + 1; i < rez.nrTermeni; i++)
				rez.termeni[i] = this->termeni[i - 1];
		}
		else {
			for (int i = 0; i < this->nrTermeni; i++)
				rez.termeni[i] = this->termeni[i];
			rez.termeni[this->nrTermeni] = t;
		}
		return rez;
	}
};




int main() {
	Termen t1(1, 2);
	Termen t2(2.4, 3);
	Termen t3(4, 6);
	Termen t4(8.2, 9);
	Termen t5(0.5, 10);
	Termen vt[] = { t1,t2,t3,t4,t5 };
	Polinom p1(5, vt);
	cout << t3;
	cout << p1;
	double s = p1;
	cout << "\nrezultatul polinomului cand x=2 este: " << s;
	Polinom p2 = p1;
	p2--;
	cout << p2;
	p1++;
	Termen t6(0.7, 5);
	p1 = p1 + t6;
	cout << p1;
	Polinom p3;
	cin >> p3;
	p3++;
	cout << p3;
	return 0;
}