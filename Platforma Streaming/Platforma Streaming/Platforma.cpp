#include<iostream>
using namespace std;
enum tip { filme, seriale, documentare };
template<tip t>
class Platforma {
	const string domeniu;
	float pret_abonament;
	int durata_luni;
	int nr_filme;
	string* filme;
	int nr_seriale;
	int* vizualizari_filme;
	string* seriale;
	int* vizualizari_seriale;

public:
	Platforma():domeniu("inexistent") {
		this->pret_abonament = 0;
		this->durata_luni = 0;
		this->nr_filme = 0;
		this->filme = nullptr;
		this->vizualizari_filme = nullptr;
		this->nr_seriale = 0;
		this->seriale = nullptr;
		this->vizualizari_seriale = nullptr;
	}

	Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_filme, const string* _filme, int* _vizualizari_filme,
		int _nr_seriale, const string* _seriale, int* _vizualizari_seriale) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_filme = _nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = _filme[i];
			this->vizualizari_filme[i] = _vizualizari_filme[i];
		}
		this->nr_seriale = _nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = _seriale[i];
			this->vizualizari_seriale[i] = _vizualizari_seriale[i];
		}

	}

	Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_filme, const string* _filme, int* _vizualizari_filme) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_filme = _nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = _filme[i];
			this->vizualizari_filme[i] = _vizualizari_filme[i];
		}
	}

	/*Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_seriale, const string* _seriale, int* _vizualizari_seriale) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_seriale = _nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = _seriale[i];
			this->vizualizari_seriale[i] = _vizualizari_seriale[i];
		}
	}*/

	Platforma(const Platforma& p) {
			this->pret_abonament = p.pret_abonament;
			this->durata_luni = p.durata_luni;
			this->nr_filme = p.nr_filme;
			this->filme = new string[this->nr_filme];
			this->vizualizari_filme = new int[this->nr_filme];
			for (int i = 0; i < this->nr_filme; i++) {
				this->filme[i] = p.filme[i];
				this->vizualizari_filme[i] = p.vizualizari_filme[i];
			}
			this->nr_seriale = p.nr_seriale;
			this->seriale = new string[this->nr_seriale];
			this->vizualizari_seriale = new int[this->nr_seriale];
			for (int i = 0; i < this->nr_seriale; i++) {
				this->seriale[i] = p.seriale[i];
				this->vizualizari_seriale[i] = p.vizualizari_seriale[i];
			}
	}
	~Platforma() {
		if (this->filme != nullptr) {
			delete[] this->filme;
			this->filme = nullptr;
		}
		if (this->vizualizari_filme != nullptr)
		{
			delete[] this->vizualizari_filme;
			this->vizualizari_filme = nullptr;
		}
		if (this->seriale != nullptr) {
			delete[] this->seriale;
			this->seriale = nullptr;
		}
		if (this->vizualizari_seriale != nullptr) {
			delete[] this->vizualizari_seriale;
			this->vizualizari_seriale = nullptr;
		}
	}
	Platforma& operator=(const Platforma& p) {
		if (this != &p) {
			if (this->filme != nullptr) {
				delete[] this->filme;
				this->filme = nullptr;
			}
			if (this->vizualizari_filme != nullptr)
			{
				delete[] this->vizualizari_filme;
				this->vizualizari_filme = nullptr;
			}
			if (this->seriale != nullptr) {
				delete[] this->seriale;
				this->seriale = nullptr;
			}
			if (this->vizualizari_seriale != nullptr) {
				delete[] this->vizualizari_seriale;
				this->vizualizari_seriale = nullptr;
			}
			this->pret_abonament = p.pret_abonament;
			this->durata_luni = p.durata_luni;
			this->nr_filme = p.nr_filme;
			this->filme = new string[this->nr_filme];
			this->vizualizari_filme = new int[this->nr_filme];
			for (int i = 0; i < this->nr_filme; i++) {
				this->filme[i] = p.filme[i];
				this->vizualizari_filme[i] = p.vizualizari_filme[i];
			}
			this->nr_seriale = p.nr_seriale;
			this->seriale = new string[this->nr_seriale];
			this->vizualizari_seriale = new int[this->nr_seriale];
			for (int i = 0; i < this->nr_seriale; i++) {
				this->seriale[i] = p.seriale[i];
				this->vizualizari_seriale[i] = p.vizualizari_seriale[i];
			}

		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Platforma& p) {
		out << "\nDomeniul platformei: " << p.domeniu;
		out << "\nPretul abonamentului: " << p.pret_abonament;
		out << "\nDurata abonamentului in luni: " << p.durata_luni;
		if (p.nr_filme > 0)
		{
			out << "\nNumarul de filme disponibile: " << p.nr_filme;
			out << "\nLista filmelor disponibilie si cat de mult au fost vizionate: ";
			for (int i = 0; i < p.nr_filme; i++)
				out << p.filme[i] << " " << p.vizualizari_filme[i] << endl;
		}
		if (p.nr_seriale > 0) {
			out << "\nNumarul de seriale disponibile: " << p.nr_seriale;
			out << "\nLista serialelor disponibile si cat de mult au fost vizionate: ";
			for (int i = 0; i < p.nr_seriale; i++)
				out << p.seriale[i] << " " << p.vizualizari_seriale[i] << endl;
		}
		return out;
	}
	Platforma& operator+=(const string& s) {
		string* aux = new string[this->nr_filme + 1];
		int* aux2 = new int[this->nr_filme + 1];
		for (int i = 0; i < this->nr_filme; i++) {
			aux[i] = this->filme[i];
			aux2[i] = this->vizualizari_filme[i];
		}
		delete[] this->filme;
		delete[] this->vizualizari_filme;
		this->filme = new string[this->nr_filme + 1];
		this->vizualizari_filme = new int[this->nr_filme + 1];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = aux[i];
			this->vizualizari_filme[i] = aux2[i];
		}
		this->filme[this->nr_filme] = s;
		this->vizualizari_filme[this->nr_filme] = 0;
		this->nr_filme++;
		delete[] aux;
		delete[] aux2;
		aux = nullptr;
		aux2 = nullptr;
		return *this;
	}
	Platforma& operator-=(const string& s) {
		bool ok = false;
		int poz = -1;
		for (int i = 0; i < this->nr_filme; i++)
		{
			if (this->filme[i] == s) {
				ok = true;
				poz = i;
				break;
			}
		}
		if (ok == true) {
			string* aux = new string[this->nr_filme - 1];
			int* aux2 = new int[this->nr_filme - 1];
			for (int i = 0; i < poz; i++) {
				aux[i] = this->filme[i];
				aux2[i] = this->vizualizari_filme[i];
			}
			for (int i = poz + 1; i < this->nr_filme; i++) {
				aux[i - 1] = this->filme[i];
				aux2[i - 1] = this->vizualizari_filme[i];
			}
			delete[] this->filme;
			delete[] this->vizualizari_filme;
			this->filme = new string[this->nr_filme - 1];
			this->vizualizari_filme = new int[this->nr_filme - 1];
			this->nr_filme--;
			for (int i = 0; i < this->nr_filme; i++) {
				this->filme[i] = aux[i];
				this->vizualizari_filme[i] = aux2[i];
			}
			delete[] aux;
			delete[] aux2;
			aux = nullptr;
			aux2 = nullptr;
		}

		return *this;
	}
	operator double()const {
		int index = 0;
		int max = 0;
		for (int i = 0; i < this->nr_filme; i++) {
			if (this->vizualizari_filme[i] > max) {
				max = this->vizualizari_filme[i];
				index = i;
			}
		}
		for (int i = 0; i < this->nr_seriale; i++) {
			if (this->vizualizari_seriale[i] > max) {
				max = this->vizualizari_seriale[i];
				index = i;
			}
		}
		return max;

	}

};
template<>
class Platforma<filme>{
	const string domeniu;
	float pret_abonament;
	int durata_luni;
	int nr_filme;
	string* filme;

	int* vizualizari_filme;

public:
	Platforma() :domeniu("inexistent") {
		this->pret_abonament = 0;
		this->durata_luni = 0;
		this->nr_filme = 0;
		this->filme = nullptr;
		this->vizualizari_filme = nullptr;
		
	}


	Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_filme, const string* _filme, int* _vizualizari_filme) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_filme = _nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = _filme[i];
			this->vizualizari_filme[i] = _vizualizari_filme[i];
		}
	}

	/*Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_seriale, const string* _seriale, int* _vizualizari_seriale) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_seriale = _nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = _seriale[i];
			this->vizualizari_seriale[i] = _vizualizari_seriale[i];
		}
	}*/

	Platforma(const Platforma& p) {
		this->pret_abonament = p.pret_abonament;
		this->durata_luni = p.durata_luni;
		this->nr_filme = p.nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = p.filme[i];
			this->vizualizari_filme[i] = p.vizualizari_filme[i];
		}
		
	}
	~Platforma() {
		if (this->filme != nullptr) {
			delete[] this->filme;
			this->filme = nullptr;
		}
		if (this->vizualizari_filme != nullptr)
		{
			delete[] this->vizualizari_filme;
			this->vizualizari_filme = nullptr;
		}
		
	}
	Platforma& operator=(const Platforma& p) {
		if (this != &p) {
			if (this->filme != nullptr) {
				delete[] this->filme;
				this->filme = nullptr;
			}
			if (this->vizualizari_filme != nullptr)
			{
				delete[] this->vizualizari_filme;
				this->vizualizari_filme = nullptr;
			}
			
			}
			this->pret_abonament = p.pret_abonament;
			this->durata_luni = p.durata_luni;
			this->nr_filme = p.nr_filme;
			this->filme = new string[this->nr_filme];
			this->vizualizari_filme = new int[this->nr_filme];
			for (int i = 0; i < this->nr_filme; i++) {
				this->filme[i] = p.filme[i];
				this->vizualizari_filme[i] = p.vizualizari_filme[i];
			}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Platforma& p) {
		out << "\nDomeniul platformei: " << p.domeniu;
		out << "\nPretul abonamentului: " << p.pret_abonament;
		out << "\nDurata abonamentului in luni: " << p.durata_luni;
		if (p.nr_filme > 0)
		{
			out << "\nNumarul de filme disponibile: " << p.nr_filme;
			out << "\nLista filmelor disponibilie si cat de mult au fost vizionate: ";
			for (int i = 0; i < p.nr_filme; i++)
				out << p.filme[i] << " " << p.vizualizari_filme[i] << endl;
		}
		
		return out;
	}
	Platforma& operator+=(const string& s) {
		string* aux = new string[this->nr_filme + 1];
		int* aux2 = new int[this->nr_filme + 1];
		for (int i = 0; i < this->nr_filme; i++) {
			aux[i] = this->filme[i];
			aux2[i] = this->vizualizari_filme[i];
		}
		delete[] this->filme;
		delete[] this->vizualizari_filme;
		this->filme = new string[this->nr_filme + 1];
		this->vizualizari_filme = new int[this->nr_filme + 1];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = aux[i];
			this->vizualizari_filme[i] = aux2[i];
		}
		this->filme[this->nr_filme] = s;
		this->vizualizari_filme[this->nr_filme] = 0;
		this->nr_filme++;
		delete[] aux;
		delete[] aux2;
		aux = nullptr;
		aux2 = nullptr;
		return *this;
	}
	Platforma& operator-=(const string& s) {
		bool ok = false;
		int poz = -1;
		for (int i = 0; i < this->nr_filme; i++)
		{
			if (this->filme[i] == s) {
				ok = true;
				poz = i;
				break;
			}
		}
		if (ok == true) {
			string* aux = new string[this->nr_filme - 1];
			int* aux2 = new int[this->nr_filme - 1];
			for (int i = 0; i < poz; i++) {
				aux[i] = this->filme[i];
				aux2[i] = this->vizualizari_filme[i];
			}
			for (int i = poz + 1; i < this->nr_filme; i++) {
				aux[i - 1] = this->filme[i];
				aux2[i - 1] = this->vizualizari_filme[i];
			}
			delete[] this->filme;
			delete[] this->vizualizari_filme;
			this->filme = new string[this->nr_filme - 1];
			this->vizualizari_filme = new int[this->nr_filme - 1];
			this->nr_filme--;
			for (int i = 0; i < this->nr_filme; i++) {
				this->filme[i] = aux[i];
				this->vizualizari_filme[i] = aux2[i];
			}
			delete[] aux;
			delete[] aux2;
			aux = nullptr;
			aux2 = nullptr;
		}

		return *this;
	}
	operator double()const {
		int index = 0;
		int max = 0;
		for (int i = 0; i < this->nr_filme; i++) {
			if (this->vizualizari_filme[i] > max) {
				max = this->vizualizari_filme[i];
				index = i;
			}
		}
		
		
		return max;

	}

};
template<>
class Platforma<seriale> {
	const string domeniu;
	float pret_abonament;
	int durata_luni;
	/*int nr_filme;
	string* filme;*/
	int nr_seriale;
	/*int* vizualizari_filme;*/
	string* seriale;
	int* vizualizari_seriale;

public:
	Platforma() :domeniu("inexistent") {
		this->pret_abonament = 0;
		this->durata_luni = 0;
		/*this->nr_filme = 0;
		this->filme = nullptr;
		this->vizualizari_filme = nullptr;*/
		this->nr_seriale = 0;
		this->seriale = nullptr;
		this->vizualizari_seriale = nullptr;
	}

	/*Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_filme, const string* _filme, int* _vizualizari_filme,
		int _nr_seriale, const string* _seriale, int* _vizualizari_seriale) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_filme = _nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = _filme[i];
			this->vizualizari_filme[i] = _vizualizari_filme[i];
		}
		this->nr_seriale = _nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = _seriale[i];
			this->vizualizari_seriale[i] = _vizualizari_seriale[i];
		}

	}*/

	/*Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_filme, const string* _filme, int* _vizualizari_filme) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_filme = _nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = _filme[i];
			this->vizualizari_filme[i] = _vizualizari_filme[i];
		}
	}*/

	Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_seriale, const string* _seriale, int* _vizualizari_seriale) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_seriale = _nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = _seriale[i];
			this->vizualizari_seriale[i] = _vizualizari_seriale[i];
		}
	}

	Platforma(const Platforma& p) {
		this->pret_abonament = p.pret_abonament;
		this->durata_luni = p.durata_luni;
	/*	this->nr_filme = p.nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = p.filme[i];
			this->vizualizari_filme[i] = p.vizualizari_filme[i];
		}*/
		this->nr_seriale = p.nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = p.seriale[i];
			this->vizualizari_seriale[i] = p.vizualizari_seriale[i];
		}
	}
	~Platforma() {
		/*if (this->filme != nullptr) {
			delete[] this->filme;
			this->filme = nullptr;
		}
		if (this->vizualizari_filme != nullptr)
		{
			delete[] this->vizualizari_filme;
			this->vizualizari_filme = nullptr;
		}*/
		if (this->seriale != nullptr) {
			delete[] this->seriale;
			this->seriale = nullptr;
		}
		if (this->vizualizari_seriale != nullptr) {
			delete[] this->vizualizari_seriale;
			this->vizualizari_seriale = nullptr;
		}
	}
	Platforma& operator=(const Platforma& p) {
		if (this != &p) {
			/*if (this->filme != nullptr) {
				delete[] this->filme;
				this->filme = nullptr;
			}
			if (this->vizualizari_filme != nullptr)
			{
				delete[] this->vizualizari_filme;
				this->vizualizari_filme = nullptr;
			}*/
			if (this->seriale != nullptr) {
				delete[] this->seriale;
				this->seriale = nullptr;
			}
			if (this->vizualizari_seriale != nullptr) {
				delete[] this->vizualizari_seriale;
				this->vizualizari_seriale = nullptr;
			}
			this->pret_abonament = p.pret_abonament;
			this->durata_luni = p.durata_luni;
			/*this->nr_filme = p.nr_filme;
			this->filme = new string[this->nr_filme];
			this->vizualizari_filme = new int[this->nr_filme];
			for (int i = 0; i < this->nr_filme; i++) {
				this->filme[i] = p.filme[i];
				this->vizualizari_filme[i] = p.vizualizari_filme[i];
			}*/
			this->nr_seriale = p.nr_seriale;
			this->seriale = new string[this->nr_seriale];
			this->vizualizari_seriale = new int[this->nr_seriale];
			for (int i = 0; i < this->nr_seriale; i++) {
				this->seriale[i] = p.seriale[i];
				this->vizualizari_seriale[i] = p.vizualizari_seriale[i];
			}

		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Platforma& p) {
		out << "\nDomeniul platformei: " << p.domeniu;
		out << "\nPretul abonamentului: " << p.pret_abonament;
		out << "\nDurata abonamentului in luni: " << p.durata_luni;
		/*if (p.nr_filme > 0)
		{
			out << "\nNumarul de filme disponibile: " << p.nr_filme;
			out << "\nLista filmelor disponibilie si cat de mult au fost vizionate: ";
			for (int i = 0; i < p.nr_filme; i++)
				out << p.filme[i] << " " << p.vizualizari_filme[i] << endl;
		}*/
		if (p.nr_seriale > 0) {
			out << "\nNumarul de seriale disponibile: " << p.nr_seriale;
			out << "\nLista serialelor disponibile si cat de mult au fost vizionate: ";
			for (int i = 0; i < p.nr_seriale; i++)
				out << p.seriale[i] << " " << p.vizualizari_seriale[i] << endl;
		}
		return out;
	}
	Platforma& operator+=(const string& s) {
		string* aux = new string[this->nr_seriale + 1];
		int* aux2 = new int[this->nr_seriale + 1];
		for (int i = 0; i < this->nr_seriale; i++) {
			aux[i] = this->seriale[i];
			aux2[i] = this->vizualizari_seriale[i];
		}
		delete[] this->seriale;
		delete[] this->vizualizari_seriale;
		this->seriale = new string[this->nr_seriale + 1];
		this->vizualizari_seriale = new int[this->nr_seriale + 1];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = aux[i];
			this->vizualizari_seriale[i] = aux2[i];
		}
		this->seriale[this->nr_seriale] = s;
		this->vizualizari_seriale[this->nr_seriale] = 0;
		this->nr_seriale++;
		delete[] aux;
		delete[] aux2;
		aux = nullptr;
		aux2 = nullptr;
		return *this;
	}
	Platforma& operator-=(const string& s) {
		bool ok = false;
		int poz = -1;
		for (int i = 0; i < this->nr_seriale; i++)
		{
			if (this->seriale[i] == s) {
				ok = true;
				poz = i;
				break;
			}
		}
		if (ok == true) {
			string* aux = new string[this->nr_seriale - 1];
			int* aux2 = new int[this->nr_seriale - 1];
			for (int i = 0; i < poz; i++) {
				aux[i] = this->seriale[i];
				aux2[i] = this->vizualizari_seriale[i];
			}
			for (int i = poz + 1; i < this->nr_seriale; i++) {
				aux[i - 1] = this->seriale[i];
				aux2[i - 1] = this->vizualizari_seriale[i];
			}
			delete[] this->seriale;
			delete[] this->vizualizari_seriale;
			this->seriale = new string[this->nr_seriale - 1];
			this->vizualizari_seriale = new int[this->nr_seriale - 1];
			this->nr_seriale--;
			for (int i = 0; i < this->nr_seriale; i++) {
				this->seriale[i] = aux[i];
				this->vizualizari_seriale[i] = aux2[i];
			}
			delete[] aux;
			delete[] aux2;
			aux = nullptr;
			aux2 = nullptr;
		}

		return *this;
	}
	operator double()const {
		int index = 0;
		int max = 0;
		for (int i = 0; i < this->nr_seriale; i++) {
			if (this->vizualizari_seriale[i] > max) {
				max = this->vizualizari_seriale[i];
				index = i;
			}
		}
		for (int i = 0; i < this->nr_seriale; i++) {
			if (this->vizualizari_seriale[i] > max) {
				max = this->vizualizari_seriale[i];
				index = i;
			}
		}
		return max;

	}

};
template<>
class Platforma<documentare>{
	const string domeniu;
	float pret_abonament;
	int durata_luni;
	int nr_filme;
	string* filme;
	int nr_seriale;
	int* vizualizari_filme;
	string* seriale;
	int* vizualizari_seriale;

public:
	Platforma() :domeniu("inexistent") {
		this->pret_abonament = 0;
		this->durata_luni = 0;
		this->nr_filme = 0;
		this->filme = nullptr;
		this->vizualizari_filme = nullptr;
		this->nr_seriale = 0;
		this->seriale = nullptr;
		this->vizualizari_seriale = nullptr;
	}

	Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_filme, const string* _filme, int* _vizualizari_filme,
		int _nr_seriale, const string* _seriale, int* _vizualizari_seriale) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_filme = _nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = _filme[i];
			this->vizualizari_filme[i] = _vizualizari_filme[i];
		}
		this->nr_seriale = _nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = _seriale[i];
			this->vizualizari_seriale[i] = _vizualizari_seriale[i];
		}

	}

	Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_filme, const string* _filme, int* _vizualizari_filme) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_filme = _nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = _filme[i];
			this->vizualizari_filme[i] = _vizualizari_filme[i];
		}
	}

	/*Platforma(const string _domeniu, float _pret_abonament, int _durata_luni, int _nr_seriale, const string* _seriale, int* _vizualizari_seriale) :domeniu(_domeniu) {
		this->pret_abonament = _pret_abonament;
		this->durata_luni = _durata_luni;
		this->nr_seriale = _nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = _seriale[i];
			this->vizualizari_seriale[i] = _vizualizari_seriale[i];
		}
	}*/

	Platforma(const Platforma& p) {
		this->pret_abonament = p.pret_abonament;
		this->durata_luni = p.durata_luni;
		this->nr_filme = p.nr_filme;
		this->filme = new string[this->nr_filme];
		this->vizualizari_filme = new int[this->nr_filme];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = p.filme[i];
			this->vizualizari_filme[i] = p.vizualizari_filme[i];
		}
		this->nr_seriale = p.nr_seriale;
		this->seriale = new string[this->nr_seriale];
		this->vizualizari_seriale = new int[this->nr_seriale];
		for (int i = 0; i < this->nr_seriale; i++) {
			this->seriale[i] = p.seriale[i];
			this->vizualizari_seriale[i] = p.vizualizari_seriale[i];
		}
	}
	~Platforma() {
		if (this->filme != nullptr) {
			delete[] this->filme;
			this->filme = nullptr;
		}
		if (this->vizualizari_filme != nullptr)
		{
			delete[] this->vizualizari_filme;
			this->vizualizari_filme = nullptr;
		}
		if (this->seriale != nullptr) {
			delete[] this->seriale;
			this->seriale = nullptr;
		}
		if (this->vizualizari_seriale != nullptr) {
			delete[] this->vizualizari_seriale;
			this->vizualizari_seriale = nullptr;
		}
	}
	Platforma& operator=(const Platforma& p) {
		if (this != &p) {
			if (this->filme != nullptr) {
				delete[] this->filme;
				this->filme = nullptr;
			}
			if (this->vizualizari_filme != nullptr)
			{
				delete[] this->vizualizari_filme;
				this->vizualizari_filme = nullptr;
			}
			if (this->seriale != nullptr) {
				delete[] this->seriale;
				this->seriale = nullptr;
			}
			if (this->vizualizari_seriale != nullptr) {
				delete[] this->vizualizari_seriale;
				this->vizualizari_seriale = nullptr;
			}
			this->pret_abonament = p.pret_abonament;
			this->durata_luni = p.durata_luni;
			this->nr_filme = p.nr_filme;
			this->filme = new string[this->nr_filme];
			this->vizualizari_filme = new int[this->nr_filme];
			for (int i = 0; i < this->nr_filme; i++) {
				this->filme[i] = p.filme[i];
				this->vizualizari_filme[i] = p.vizualizari_filme[i];
			}
			this->nr_seriale = p.nr_seriale;
			this->seriale = new string[this->nr_seriale];
			this->vizualizari_seriale = new int[this->nr_seriale];
			for (int i = 0; i < this->nr_seriale; i++) {
				this->seriale[i] = p.seriale[i];
				this->vizualizari_seriale[i] = p.vizualizari_seriale[i];
			}

		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Platforma& p) {
		out << "\nDomeniul platformei: " << p.domeniu;
		out << "\nPretul abonamentului: " << p.pret_abonament;
		out << "\nDurata abonamentului in luni: " << p.durata_luni;
		if (p.nr_filme > 0)
		{
			out << "\nNumarul de filme disponibile: " << p.nr_filme;
			out << "\nLista filmelor disponibilie si cat de mult au fost vizionate: ";
			for (int i = 0; i < p.nr_filme; i++)
				out << p.filme[i] << " " << p.vizualizari_filme[i] << endl;
		}
		if (p.nr_seriale > 0) {
			out << "\nNumarul de seriale disponibile: " << p.nr_seriale;
			out << "\nLista serialelor disponibile si cat de mult au fost vizionate: ";
			for (int i = 0; i < p.nr_seriale; i++)
				out << p.seriale[i] << " " << p.vizualizari_seriale[i] << endl;
		}
		return out;
	}
	Platforma& operator+=(const string& s) {
		string* aux = new string[this->nr_filme + 1];
		int* aux2 = new int[this->nr_filme + 1];
		for (int i = 0; i < this->nr_filme; i++) {
			aux[i] = this->filme[i];
			aux2[i] = this->vizualizari_filme[i];
		}
		delete[] this->filme;
		delete[] this->vizualizari_filme;
		this->filme = new string[this->nr_filme + 1];
		this->vizualizari_filme = new int[this->nr_filme + 1];
		for (int i = 0; i < this->nr_filme; i++) {
			this->filme[i] = aux[i];
			this->vizualizari_filme[i] = aux2[i];
		}
		this->filme[this->nr_filme] = s;
		this->vizualizari_filme[this->nr_filme] = 0;
		this->nr_filme++;
		delete[] aux;
		delete[] aux2;
		aux = nullptr;
		aux2 = nullptr;
		return *this;
	}
	Platforma& operator-=(const string& s) {
		bool ok = false;
		int poz = -1;
		for (int i = 0; i < this->nr_filme; i++)
		{
			if (this->filme[i] == s) {
				ok = true;
				poz = i;
				break;
			}
		}
		if (ok == true) {
			string* aux = new string[this->nr_filme - 1];
			int* aux2 = new int[this->nr_filme - 1];
			for (int i = 0; i < poz; i++) {
				aux[i] = this->filme[i];
				aux2[i] = this->vizualizari_filme[i];
			}
			for (int i = poz + 1; i < this->nr_filme; i++) {
				aux[i - 1] = this->filme[i];
				aux2[i - 1] = this->vizualizari_filme[i];
			}
			delete[] this->filme;
			delete[] this->vizualizari_filme;
			this->filme = new string[this->nr_filme - 1];
			this->vizualizari_filme = new int[this->nr_filme - 1];
			this->nr_filme--;
			for (int i = 0; i < this->nr_filme; i++) {
				this->filme[i] = aux[i];
				this->vizualizari_filme[i] = aux2[i];
			}
			delete[] aux;
			delete[] aux2;
			aux = nullptr;
			aux2 = nullptr;
		}

		return *this;
	}
	operator double()const {
		int index = 0;
		int max = 0;
		for (int i = 0; i < this->nr_filme; i++) {
			if (this->vizualizari_filme[i] > max) {
				max = this->vizualizari_filme[i];
				index = i;
			}
		}
		for (int i = 0; i < this->nr_seriale; i++) {
			if (this->vizualizari_seriale[i] > max) {
				max = this->vizualizari_seriale[i];
				index = i;
			}
		}
		return max;

	}
};


int main() {
	
	string f1[] = { "goodfellas","casino","goodwill hunting" };
	string s1[] = {"breaking bad","better call saul"};
	string f2[] = { "300 days of summer","the dark knight","Tennet","The substance" };
	string s2[] = { "dexter","how I met your mother","the bookie","the sopranos" };
	int vf1[] = { 800,1000,1200 };
	int vs1[] = { 1000,870 };
	int vf2[] = { 645,1120,680,500 };
	int sf2[] = { 1400,1124,300,1700 };
	Platforma<documentare> p1;
	Platforma<documentare> p22("fsonline.com", 22, 1, 3, f1, vf1, 2, s1, vs1);
	Platforma<documentare> p33("hbo.max.com", 45, 2, 4, f2, vf2, 4, s2, sf2);
	p1 = p22;
	cout << p1;
	p33 += "Heat";
	cout << p33;
	p33 -= "Tennet";
	cout << p33;
	double x = p33;
	cout << endl << x;
	Platforma<filme> p2("fsonline.com", 22, 1, 3, f1, vf1);
	cout << p2;
	Platforma<seriale> p3("hbo.max.com", 45, 2, 4, s2, sf2);
	cout << p3;
	return 0;
}