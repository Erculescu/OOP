#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Persoana {
	char* nume;
	int varsta;
public:
	Persoana() {
		this->nume = new char[strlen("anonim") + 1];
		strcpy(this->nume, "anonim");
		this->varsta = 0;
	}
	Persoana(const char* _nume, int _varsta) {
		if (strlen(_nume) != 0 && _nume != nullptr) {
			this->nume = nullptr;
			this->nume = new char[strlen(_nume) + 1];
			strcpy(this->nume, _nume);
		}
		if (_varsta > 0)
			this->varsta = _varsta;
	}
	Persoana(const Persoana& p)
	{
		if (strlen(p.nume) != 0 && p.nume != nullptr) {
			this->nume = nullptr;
			this->nume = new char[strlen(p.nume) + 1];
			strcpy(this->nume, p.nume);
		}
		if (p.varsta > 0)
			this->varsta = p.varsta;
	}
	Persoana& operator =(const Persoana& p) {
		if (this != &p)
		{
			if (this->nume != nullptr)
			{
				delete[] this->nume;
				this->nume = nullptr;
			}
			if (strlen(p.nume) != 0 && p.nume != nullptr) {
				this->nume = nullptr;
				this->nume = new char[strlen(p.nume) + 1];
				strcpy(this->nume, p.nume);
			}
			if (p.varsta > 0)
				this->varsta = p.varsta;


		}
		return *this;

	}

	~Persoana() {
		if (this->nume != nullptr)
		{
			delete[] this->nume;
			this -> nume = nullptr;
		}
	}

	void setnume(const char* _nume) {
		if (strlen(_nume) != 0 && _nume != nullptr) {
			this->nume = nullptr;
			this->nume = new char[strlen(_nume) + 1];
			strcpy(this->nume, _nume);
		}
	}
	char* getnume() {
		return this->nume;
	}
	int getvarsta() {
		return this->varsta;
	}
	void setvarsta(int _varsta) {
		if (_varsta > 0)
			this->varsta = _varsta;
	}

};


class Departament {
	char* denumire;
	int nrangajati;
	static int totalangajati;
public:
	Departament() {
		this->denumire = new char[strlen("anonim") + 1];
		strcpy(this->denumire, "anonim");
		this->nrangajati = 0;
		this->totalangajati += this->nrangajati;
	}
	Departament(const char* _denumire, int _nrangajati) {
		if (_denumire != nullptr && strlen(_denumire) > 0) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy(this->denumire, _denumire);
		}
		if (_nrangajati > 0)
		{
			this->nrangajati = _nrangajati;
			this->totalangajati += _nrangajati;
		}
	}
	~Departament() {
		if (this->denumire != nullptr)
		{
			delete[]this->denumire;
			this->denumire = nullptr;
		}
	}
		Departament(const Departament& d) {
			if (d.denumire != nullptr && strlen(d.denumire) > 0) {
				this->denumire = new char[strlen(d.denumire) + 1];
				strcpy(this->denumire, d.denumire);
			}
			if (d.nrangajati > 0)
			{
				this->nrangajati = d.nrangajati;
				this->totalangajati += d.nrangajati;
			}
		}
		Departament& operator=(const Departament& d) {
			if (this != &d) {
				if (this->denumire != nullptr)
				{
					delete[]this->denumire;
					this->denumire = nullptr;
				}
				if (d.denumire != nullptr && strlen(d.denumire) > 0) {
					this->denumire = new char[strlen(d.denumire) + 1];
					strcpy(this->denumire, d.denumire);
				}
				if (d.nrangajati > 0)
				{
					this->nrangajati = d.nrangajati;
					this->totalangajati += d.nrangajati;
				}

			}
			return *this;
		}
		Departament(const char* _denumire) {
			if (_denumire != nullptr && strlen(_denumire) > 0) {
				this->denumire = new char[strlen(_denumire) + 1];
				strcpy(this->denumire, _denumire);
			}
			this->nrangajati = 0;
			this->totalangajati += this->nrangajati;
		}

		friend ostream& operator<<(ostream& out, const Departament& d) {
			out << "\n---------------------\n";
			out << "Denumirea Departamentului: " << d.denumire;
			out << "\nNumarul de angajati din departament: " << d.nrangajati;
			out << "\nNumarul de angajati din intreaga companie: " << d.totalangajati;
			out << "\n---------------------\n";
			return out;
		}
		friend istream& operator>>(istream& in, Departament& d) {
			cout << "Introduceti denumirea departamentului:";
			string buffer;
			in >> buffer;
			if(d.denumire!=nullptr)
			{
				delete[]d.denumire;
				d.denumire = nullptr;
			}
			d.denumire = new char[buffer.length()+1];
			strcpy(d.denumire, buffer.data());
			in >> d.nrangajati;
			d.totalangajati += d.nrangajati;
			return in;
		}


};
int Departament::totalangajati = 0;


int main()
{
	Persoana Rares;
	Persoana Carmen("Carmen Braticevici", 18);
	cout << Carmen.getnume() << "  " << Carmen.getvarsta();
	Rares.setnume("Erculescu"); Rares.setvarsta(20);
	cout << endl << Rares.getnume() << "   " << Rares.getvarsta();
	Rares = Carmen;
	cout << endl << Rares.getnume() << "   " << Rares.getvarsta();
	Departament Hr("Human Resources", 5000);
	cout << Hr;
	return 0;
}