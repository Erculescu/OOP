#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;
//Nota 1 Să se creeze un proiect în Microsoft Visual Studio care să nu genereze erori de compilare si de linkeditare.
//Nota 2 Definiți în fișierul sursă generat clasa Sejur.Toate atributele se definesc în zona privată a clasei.

class Sejur {
	const int id;
	char* destinatie;
	float pretBaza;
	int nrExcursiiOptionale;
	float* pretExcursie;
	char* dataPlecare;
	int nrZile;
public:
	//•	Sa se implementeze constructorul cu un parametru (id) și metode de acces la membrii noi adaugati in clasa (get si set). 
	// Acolo unde este cazul, metodele de tip set definesc validări pentru parametri si arunca exceptii ExceptieInput;
	Sejur(int _id):id(_id) {
		this->destinatie = new char[strlen("necunoscut") + 1];
		strcpy(this->destinatie, "necunoscut");
		this->pretBaza = 0;
		this->nrExcursiiOptionale = 0;
		this->pretExcursie = nullptr;
		this->dataPlecare = new char[strlen("necunoscut") + 1];
		strcpy(this->dataPlecare, "necunoscut");
		this->nrZile = 0;
	}

	const char* getDestinatie() {
		return this->destinatie;
	}
	void setDestinatie(const char* _destinatie) {
		if (this->destinatie != nullptr)
		{
			delete[] this->destinatie;
			this->destinatie = nullptr;
		}
		this->destinatie = new char[strlen(_destinatie) + 1];
		strcpy(this->destinatie, _destinatie);
	}
	void setDataPlecare(const char* _dataPlecare) {
		if (this->dataPlecare != nullptr)
		{
			delete[] this->dataPlecare;
			this->dataPlecare = nullptr;
		}
		this->dataPlecare = new char[strlen(_dataPlecare) + 1];
		strcpy(this->dataPlecare, _dataPlecare);
	}

	//Nota 3 Să se implementeze constructorul cu toți parametri și destructorul clasei. 
	Sejur(int _id, const char* _destinatie, float _pretBaza, int _nrExcursiiOptionale, float* _pretExcursie, const char* _dataPlecare, int _nrZile):id(_id) {
		if (this->destinatie != nullptr)
		{
			delete[] this->destinatie;
			this->destinatie = nullptr;
		}
		this->destinatie = new char[strlen(_destinatie) + 1];
		strcpy(destinatie, _destinatie);
		if (_pretBaza > 0)
			this->pretBaza = _pretBaza;
		else
			this->pretBaza = 0;
		if (_nrExcursiiOptionale > 0)
		{
			this->nrExcursiiOptionale = _nrExcursiiOptionale;
			if(this->pretExcursie!=nullptr)
			{
				delete[] this->pretExcursie;
				this->pretExcursie = nullptr;
			}
			this->pretExcursie = new float[nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++)
				this->pretExcursie[i] = _pretExcursie[i];
		}
		if (this->dataPlecare != nullptr) {
			delete[] this->dataPlecare;
			this->dataPlecare = nullptr;
		}
		this->dataPlecare = new char[strlen(_dataPlecare) + 1];
		strcpy(this->dataPlecare, _dataPlecare);
		if (_nrZile > 0)
			this->nrZile = _nrZile;
		else
			_nrZile = 0;

	}
	~Sejur() {
		cout << "\nApel destructor";
		if (this->destinatie != nullptr)
		{
			delete[] this->destinatie;
			this->destinatie = nullptr;
		}
		if (this->pretExcursie != nullptr)
		{
			delete[] this->pretExcursie;
			this->pretExcursie = nullptr;
		}
		if (this->dataPlecare != nullptr) {
			delete[] this->dataPlecare;
			this->dataPlecare = nullptr;
		}
	}
	//1 punct Să se implementeze metoda getNrMaximExcursii(float bugetMaximSejur) 
	// ce returneaza numarul maxim de excursii optionale pe care le poate achizitiona
	// un client tinand cont si de pretul de baza al sejurului.
	int getNrMaximExcursii(float bugetMaximSejur) {
		float* copie;
		float aux,sum=0;
		int i,j;
		copie = new float[this->nrExcursiiOptionale];
		for (i = 0; i < this->nrExcursiiOptionale; i++) {
			copie[i] = this->pretExcursie[i];
		}
		for (i = 0; i <this-> nrExcursiiOptionale; i++)
		{
			for(j=i+1;j<this->nrExcursiiOptionale;j++)
				if(copie[i]>copie[j])
				{
					aux = copie[i];
					copie[i] = copie[j];
					copie[j] = aux;
				}
		
		}
		i = 0;
		while(sum<=bugetMaximSejur&&i<this->nrExcursiiOptionale)
		{
			sum = sum + copie[i];
			i++;
		}
		delete[] copie;
		return i;
	}

	//1 punct Implementați constructorul de copiere

	Sejur(const Sejur& s):id(s.id) {
		this->destinatie = new char[strlen(s.destinatie) + 1];
		strcpy(destinatie, s.destinatie);
		if (s.pretBaza > 0)
			this->pretBaza = s.pretBaza;
		else
			this->pretBaza = 0;
		if (s.nrExcursiiOptionale > 0)
		{
			this->nrExcursiiOptionale = s.nrExcursiiOptionale;

			this->pretExcursie = new float[nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++)
				this->pretExcursie[i] = s.pretExcursie[i];
		}
		this->dataPlecare = new char[strlen(s.dataPlecare) + 1];
		strcpy(this->dataPlecare, s.dataPlecare);
		if (s.nrZile > 0)
			this->nrZile = s.nrZile;
		else
			nrZile = 0;
	}


	//1 punct Să se supraîncarce operatorul de atribuire (=).

	Sejur& operator=(const Sejur& s) {
		if(this!=&s)
			if (this->destinatie != nullptr)
			{
				delete[] this->destinatie;
				this->destinatie = nullptr;
			}
		this->destinatie = new char[strlen(s.destinatie) + 1];
		strcpy(destinatie, s.destinatie);
		if (s.pretBaza > 0)
			this->pretBaza = s.pretBaza;
		else
			this->pretBaza = 0;
		if (s.nrExcursiiOptionale > 0)
		{
			this->nrExcursiiOptionale = s.nrExcursiiOptionale;
			if (this->pretExcursie != nullptr)
			{
				delete[] this->pretExcursie;
				this->pretExcursie = nullptr;
			}
			this->pretExcursie = new float[nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++)
				this->pretExcursie[i] = s.pretExcursie[i];
		}
		if (this->dataPlecare != nullptr) {
			delete[] this->dataPlecare;
			this->dataPlecare = nullptr;
		}
		this->dataPlecare = new char[strlen(s.dataPlecare) + 1];
		strcpy(this->dataPlecare, s.dataPlecare);
		if (s.nrZile > 0)
			this->nrZile = s.nrZile;
		else
			nrZile = 0;
		return *this;
	}
	//1 punct Sa se supraincarca operatorul float care sa returneze costul total in cazul in
	// care se achizitioneaza toate excursiile optionale disponibile pentru acel sejur.
	operator float()const  {
		float sum = 0;
		for (int i = 0; i < this->nrExcursiiOptionale; i++)
			sum = sum + this->pretExcursie[i];
		return sum;
	}



	//1 punct Să se supraîncarce operatorul - - in forma de postdecrementare care sa elimine din respectivul
	//sejur excursiile cu pretul minim. Daca exista mai multe astfel de excursii, se vor elimina toate aceste excursii.


	Sejur operator--(int) {
		Sejur copieRez = *this;
		float* copie;
		float aux,min=this->pretExcursie[0];
		int k=0;
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			if (min > this->pretExcursie[i])
				min = this->pretExcursie[i];
		}
		for (int i = 0; i < this->nrExcursiiOptionale; i++)
		{
			if (min != this->pretExcursie[i])
				k++;
		}
		
		copie = new float[k];
		for (int i = 0, j=0; i < this->nrExcursiiOptionale; i++)
		{
			if (min != this->pretExcursie[i])
			{
				copie[j++] = this->pretExcursie[i];
			}

		}
		
		delete[] this->pretExcursie;
		/*this->pretExcursie = new float[k];
		this->nrExcursiiOptionale = k;
		for (i = 0; i < this->nrExcursiiOptionale; i++){
			this->pretExcursie[i] = copie[i];
		}*/
		this->pretExcursie = copie;
		//delete[]copie;
		return copieRez;
	}

	friend istream& operator>>(istream& in, Sejur& s);
	friend ostream& operator<<(ostream& out, Sejur& s);

}; 

//1 punct Să se supraîncarce operatorii << și >> pentru afișarea și citirea obiectelor
// de tip Sejur (implementarea trebuie sa permita citirea sirurilor de caractere cu spatii). 
	ostream& operator<<(ostream& out, Sejur& s) {
		out << "\n----------------------------\n";
		out << "Destinatia: " << s.destinatie << endl;
		out << "Pret de baza: " << s.pretBaza << endl;
		out << "Nr excursii optionale" << s.nrExcursiiOptionale << endl;
		if (s.nrExcursiiOptionale > 0) {
			out << "Pretul Excursiilor: ";
			for (int i = 0; i < s.nrExcursiiOptionale; i++)
			{
				out << s.pretExcursie[i] << " ";
			}
		}
		out <<endl<< "Data plecarii: " << s.dataPlecare<<endl;
		out << "Nr zile: " << s.nrZile;
		out << "\n----------------------------\n";
		return out;
	}




	istream& operator>>(istream& in, Sejur& s) {
		char temp[100];
		cout << "Introduceti Destinatia: ";
		in >> temp;
		s.setDestinatie(temp);
		cout << "Introduceti Pretul de baza: ";
		in >> s.pretBaza;
		cout << "Introduceti numarul de excursii optionale: ";
		in >> s.nrExcursiiOptionale;
		if (s.nrExcursiiOptionale < 0)
			s.nrExcursiiOptionale = 0;
		if (s.nrExcursiiOptionale > 0) {
			cout << "Introduceti pretul excursiilor: ";
			s.pretExcursie = nullptr;
			s.pretExcursie = new float[s.nrExcursiiOptionale];
			for (int i = 0; i < s.nrExcursiiOptionale; i++)
				in >> s.pretExcursie[i];
		}
		cout << "Introduceti data de plecare:";
		in >> temp;
		s.setDataPlecare(temp);
		cout << "Introduceti numarul de zile ale sejurului: ";
		in >> s.nrZile;
		return in;
}


int main() {

	Sejur Amalfi(1);
	Sejur Berlin(Amalfi);
	Amalfi.setDestinatie("Sudul Italiei");
	cout << Amalfi.getDestinatie();
	cout << endl << Berlin.getNrMaximExcursii(7000);
	float excursii[] = { 692.2,221.6,66.2 };
	Sejur Bucuresti(2, "Otopeni", 500, 3, excursii, "21 august", 4);
	float total=Bucuresti;
	//cin >> Amalfi;
	Bucuresti--;
	cout << Bucuresti;
	cout <<endl<< total;
	return 0;
}