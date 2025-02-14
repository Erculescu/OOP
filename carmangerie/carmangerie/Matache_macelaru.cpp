#include <iostream>
#include <cstring>
using namespace std;
enum tipuri {carne_proaspata,congelata,produse_din_carne};
class magazin {
	const int id;
	tipuri tip;
	int nr_prod;
	string* produse;
	string* data_exp;
	float* pret;
	static int contor;
public:
	magazin():id(contor++) {
		this->tip = carne_proaspata;
		this->nr_prod = 0;
		this->produse = nullptr;
		this->data_exp = nullptr;
		this->pret = nullptr;
	}
	magazin(tipuri _tip, int _nr_prod, string* _produse, string* _data_exp, float* _pret) :id(contor++) {
		this->tip = _tip;
		this->nr_prod = _nr_prod;
		this->produse = new string[this->nr_prod];
		this->data_exp = new string[this->nr_prod];
		this->pret = new float[this->nr_prod];
		for (int i = 0; i < this->nr_prod; i++) {
			this->produse[i] = _produse[i];
			this->data_exp[i] = _data_exp[i];
			this->pret[i] = _pret[i];
		}
	}
	~magazin() {
		delete[] this->produse;
		this->produse = nullptr;
		delete[] this->data_exp;
		this->data_exp = nullptr;
		delete[] this->pret;
		this->pret = nullptr;
	}
	magazin(const magazin& m):id(contor++) {
		this->tip = m.tip;
		this->nr_prod = m.nr_prod;
		this->produse = new string[this->nr_prod];
		this->data_exp = new string[this->nr_prod];
		this->pret = new float[this->nr_prod];
		for (int i = 0; i < this->nr_prod; i++) {
			this->produse[i] = m.produse[i];
			this->data_exp[i] = m.data_exp[i];
			this->pret[i] = m.pret[i];
		}

	}
		magazin& operator=(const magazin & m){
			if (this != &m) {
				delete[] this->produse;
				this->produse = nullptr;
				delete[] this->data_exp;
				this->data_exp = nullptr;
				delete[] this->pret;
				this->pret = nullptr;
				this->tip = m.tip;
				this->nr_prod = m.nr_prod;
				this->produse = new string[this->nr_prod];
				this->data_exp = new string[this->nr_prod];
				this->pret = new float[this->nr_prod];
				for (int i = 0; i < this->nr_prod; i++) {
					this->produse[i] = m.produse[i];
					this->data_exp[i] = m.data_exp[i];
					this->pret[i] = m.pret[i];
				}
		}
			return *this;
		}
		friend ostream& operator<<(ostream& out, const magazin& m) {
			out << "\n__________________________\n";
			out << "\ntipul prodselor: " << m.tip;
			out << "\nnr produse: " << m.nr_prod;
			out << "\nDenumire, pret si data expirarii a produselor: \n";
			for (int i = 0; i < m.nr_prod; i++)
				out << m.produse[i] << "  " << m.pret[i] << " " << m.data_exp[i] << endl;
			out << "\n__________________________\n";
			return out;
		}

		tipuri get_tip() {
			return this->tip;
		}
		void set_tip(tipuri _tip) {
			this->tip = _tip;
		}
		int get_nr_prod() {
			return this->nr_prod;
		}
		void set_nr_prod(int _nr_prod) {
			this->nr_prod = _nr_prod;
		}
		string* get_produse() {
			return this->produse;
		}
		void set_produse(string* _produse,int _nr_prod) {
			this->nr_prod = _nr_prod;
			if (this->produse != nullptr)
			{
				delete[] this->produse;
				this->produse = new string[this->nr_prod];
				for (int i=0;i<this->nr_prod;i++)
					this->produse[i] = _produse[i];
			}
		}
		string* get_data_exp() {
			return this->data_exp;
		}
		void set_data_exp(string* _data_exp, int _nr_prod) {
			this->nr_prod = _nr_prod;
			if (this->data_exp != nullptr)
			{
				delete[] this->data_exp;
				this->data_exp = new string[this->nr_prod];
				for (int i = 0; i < this->nr_prod; i++)
					this->data_exp[i] = _data_exp[i];
			}
		}

		float* get_pret() {
			return this->pret;
		}
		void set_pret(float* _pret, int _nr_prod) {
			this->nr_prod = _nr_prod;
			if (this->pret != nullptr)
			{
				delete[] this->pret;
				this->pret = new float[this->nr_prod];
				for (int i = 0; i < this->nr_prod; i++)
					this->pret[i] = _pret[i];
			}
		}
		magazin operator*=(string s) {
			for (int i = 0; i < this->nr_prod; i++)
			{
				if (s == this->data_exp[i])
				{
					this->pret[i] = (this->pret[i] * 0.75);
				}
			}
			return *this;
		}
		bool operator==(const magazin& m) const {
			int k = 0;
			for (int i = 0; i < this->nr_prod; i++) {
				if (this->produse[i] == m.produse[i] && this->pret[i] == m.pret[i])
					k++;
			}
			return k == this->nr_prod;
		}
		friend class retea_magazine;
};


class retea_magazine {
	int nr_magazine;
	magazin* magazine;
public:
	retea_magazine() {
		this->nr_magazine = 0;
		this->magazine = nullptr;
	}
	retea_magazine(int _nr_magazine, magazin* _magazine) {
		this -> nr_magazine = _nr_magazine;
		this->magazine = new magazin[this->nr_magazine];
		for (int i = 0; i < this->nr_magazine; i++)
			this->magazine[i] = _magazine[i];
	}
	retea_magazine(const retea_magazine& r) {
		this->nr_magazine = r.nr_magazine;
		this->magazine = new magazin[this->nr_magazine];
		for (int i = 0; i < this->nr_magazine; i++)
			this->magazine[i] = r.magazine[i];
	}
	~retea_magazine() {
		delete[] this->magazine;
		this->magazine = nullptr;
	}

	retea_magazine operator=(const retea_magazine& r) {
		if(this!=&r){
			delete[] this->magazine;
			this->magazine = nullptr;
			this->nr_magazine = r.nr_magazine;
			this->magazine = new magazin[this->nr_magazine];
			for (int i = 0; i < this->nr_magazine; i++)
				this->magazine[i] = r.magazine[i];
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const retea_magazine& r) {
		out << "\n__________________________\n";
		out << "\nNr magazine: " << r.nr_magazine;
		out << "\nMagazinele sunt: \n";
		for (int i = 0; i < r.nr_magazine; i++)
			out << r.magazine[i];
		out << "\n__________________________\n";
		return out;
	}
	retea_magazine operator +=(const magazin& m){
		retea_magazine aux(*this);
		delete[] this->magazine;
		this->magazine = nullptr;
		bool ok = false; int k = NULL;
		for (int i = 0; i < aux.nr_magazine; i++)
		{
			if (aux.magazine[i] == m)
			{
				ok = true; k = i;
			}
		}
		if (ok == true) {
			this->magazine = new magazin[aux.nr_magazine];
			for (int i = 0; i < aux.nr_magazine; i++) {
				if (i == k)
					this->magazine[i] = m;
				else this->magazine[i] = aux.magazine[i];
			}
		}
		else {
			this->nr_magazine = aux.nr_magazine + 1;
			this->magazine = new magazin[this->nr_magazine];
			for (int i = 0; i < aux.nr_magazine; i++)
			{
				this->magazine[i] = aux.magazine[i];
			}
			this->magazine[this->nr_magazine - 1] = m;
		}
		return *this;

	}
};




int magazin::contor = 0;

int main() {
	magazin m1;
	string prod[] = { "ceafa porc","piept pui","muschi vita" };
	string data[] = { "12.12.2024","05.04.2025","21.08.2025" };
	float pret[] = { 30.1,21.9,100,12 };
	magazin m2(carne_proaspata, 3, prod, data, pret);
	cout << m2;
	magazin m3 = m2;
	m3 *= "12.12.2024";
	cout << m3;
	if (m2 == m2)
		cout << "magazinele au aceleasi produse cu aceleasi proprietati\n";
	else cout << "\nmagazinele nu au aceleasi produse cu aceleasi proprietati\n";
	cout << "\n__________________testare has a______________________\n";
	string prod2[] = { "carnati","toba","salam","babic" };
	string data2[] = { "12.12.2024","05.04.2025","21.08.2025","12.12.2024" };
	float pret2[] = { 69.3,28.2,66.3,54.3 };
	magazin m4(produse_din_carne, 4, prod2, data2, pret2);
	magazin mc[] = { m2,m3,m4 };
	retea_magazine r(3, mc);
	cout << r;
	string data3[] = { "10.10.2025","05.05.2025","21.05.2025" };
	magazin m5(carne_proaspata, 3, prod, data3, pret);
	r += m5;
	cout << r;
	string prod3[] = { "filet cod","carne tocata","pui intreg","iepure" };
	magazin m6(congelata, 4, prod3, data2, pret2);
	r += m6;
	cout << r;



	return 0;
}
