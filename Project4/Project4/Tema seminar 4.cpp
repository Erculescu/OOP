//TEMA: o alta clasa in care sa pui ce s-a intamplat azi si un char*, un float* 
// si o enumeratie sau un vector de enumeratii;
#include <iostream>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
enum ZileleSaptamanii {
	Luni, Marti, Miercuri, Joi, Vineri, Sambata, Duminica, OTHER
};
class Cereale {//Un depozit de grane cumpara intr-o zi a saptamanii cereale si are nevoie sa contorizeze acest lucru.
	int id;
	char* DenumireProdus;
	float* Gramaj;//reprezentat in kg
	enum ZileleSaptamanii zilelesaptamanii;

public:
	Cereale() {
		cout << "\n APEL CONSTRUCTOR FARA PARAM";
		id = -1;
		DenumireProdus = nullptr;
		Gramaj = nullptr;
		zilelesaptamanii = ZileleSaptamanii::OTHER;

	}
	Cereale(int _id, ZileleSaptamanii _zilelesaptamanii) {
		cout << "\n APEL CONSTRUCTOR CU CATIVA PARAM";
		if (_id >= 0)
			id = _id;
		else
			cout << "Valoare invalida pentru id.";
		DenumireProdus = nullptr;
		Gramaj = nullptr;
		zilelesaptamanii = _zilelesaptamanii;
	}

	Cereale(int _id ,const char* _DenumireProdus, float _Gramaj, ZileleSaptamanii _zilelesaptamanii) {
		cout << "\nAPEL CONSTRUCTOR CU TOTI PARAM";
		if (_id >= 0)
			id = _id;
		else
			cout << "Valoare invalida pentru id.";
		if (strlen(_DenumireProdus) != 0 && _DenumireProdus != nullptr) {
			DenumireProdus = new char[strlen(_DenumireProdus) + 1];
			strcpy(DenumireProdus, _DenumireProdus);
		}
		else { DenumireProdus = nullptr; }
		Gramaj = new float(_Gramaj);
		zilelesaptamanii = _zilelesaptamanii;
	}

	Cereale(const Cereale& f) {
		cout << "\nAPEL CONSTRUCTOR COPIERE";
		id = f.id;
		if(strlen(f.DenumireProdus)!=0&& f.DenumireProdus!=nullptr)
		{
			DenumireProdus = new char[strlen(f.DenumireProdus) + 1];
			strcpy(DenumireProdus, f.DenumireProdus);
		}
		else
			DenumireProdus = nullptr;
		Gramaj = new float(*f.Gramaj);
		zilelesaptamanii = f.zilelesaptamanii;


	}

	void Afisare() {
		cout << endl << "-------------------------------" << endl;
		cout << "Id: " << id << endl;
		cout << "Denumirea Produsului: "; if (DenumireProdus != nullptr)
			cout << DenumireProdus << endl;
		else
			cout << "Inexistenta" << endl;
		cout << "Gramajul(exprimat in kg): "; if (Gramaj != nullptr)
			cout << *Gramaj << endl;
		else
			cout << "Inexistenta";
		cout << "Ziua in care cantitatea de cereale a fost achizitionata: ";
		switch (zilelesaptamanii) {
		case Luni: cout << "Luni"; break;
		case Marti: cout << "Marti"; break;
		case Miercuri: cout << "Miercuri"; break;
		case Joi: cout << "Joi"; break;
		case Vineri: cout << "Vineri"; break;
		case Sambata: cout << "Sambata"; break;
		case Duminica: cout << "Duminica"; break;
		default: cout << "Other"; break;
		}
			cout << endl << "-------------------------------" << endl;
		
	}
	~Cereale() {
		cout << "\n APEL DESTRUCTOR";
		if(DenumireProdus!=nullptr)
		{
			delete[] DenumireProdus;
			DenumireProdus = nullptr;
		}
		if(Gramaj!=nullptr)
		{
			delete Gramaj;
			Gramaj = nullptr;
		}
	}


};

int main() {
	Cereale grau;
	Cereale porumb(2,"porumb", 666.9f, Vineri);
	porumb.Afisare();
	return 0;
}