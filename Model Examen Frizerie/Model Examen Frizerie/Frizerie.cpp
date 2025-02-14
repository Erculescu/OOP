#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include<cstring>
using namespace std;

enum friz{barbershop, coafor,spa};

class frizerie {
	char* denumire;
	int nrfrizeri;
	friz tipfrizerie;

	const int idfrizerie;
	static int contor;
public:
	frizerie():idfrizerie(contor+1) {
		this->denumire = new char[strlen("Anonim") + 1];
		this->denumire = strcpy(this->denumire, "Anonim");
		this->nrfrizeri = 0;
		this->tipfrizerie = barbershop;
		this->contor++;
	}
	frizerie(const char* _denumire, int _nrfrizeri, friz _tipfrizerie) :idfrizerie(contor + 1) {
		this->denumire = new char[strlen(_denumire) + 1];
		this->denumire = strcpy(this->denumire, _denumire);
		if (_nrfrizeri > 0)
			this->nrfrizeri = _nrfrizeri;
		else this->nrfrizeri = 0;
		this->tipfrizerie = _tipfrizerie;
		this->contor++;
	}
	frizerie(const frizerie& f) :idfrizerie(contor + 1) {
		this->denumire = new char[strlen(f.denumire) + 1];
		this->denumire = strcpy(this->denumire, f.denumire);
		if (f.nrfrizeri > 0)
			this->nrfrizeri = f.nrfrizeri;
		else this->nrfrizeri = 0;
		this->tipfrizerie = f.tipfrizerie;
		this->contor++;
	
	}
	~frizerie() {
		if (this->denumire != NULL)
		{
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		
	}
	frizerie operator=(const frizerie& f) {
		if (this != &f) {
			if (this->denumire != NULL)
			{
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			this->denumire = new char[strlen(f.denumire) + 1];
			this->denumire = strcpy(this->denumire, f.denumire);
			if (f.nrfrizeri > 0)
				this->nrfrizeri = f.nrfrizeri;
			else this->nrfrizeri = 0;
			this->tipfrizerie = f.tipfrizerie;
			this->contor++;
		}
		return *this;

	}
	const char* getDenumire() {
		return this->denumire;
	}
	void setDenumire(const char* _denumire) {
		if (this->denumire != NULL)
		{
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		this->denumire = new char[strlen(_denumire) + 1];
		this->denumire = strcpy(this->denumire, _denumire);
	}
	


};
int frizerie::contor = 0;

int main() {
	frizerie f1;
	frizerie f2("Frezarie", 2, spa);
	frizerie f3(f2);
	return 0;
}