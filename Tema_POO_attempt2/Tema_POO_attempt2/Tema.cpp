//TEMA: o alta clasa in care sa pui ce s-a intamplat azi si un char*, un float* 
// si o enumeratie sau un vector de enumeratii;
#include<iostream>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
enum Regiune_a_bucurestiului {
	Sector1,Sector2,Sector3,Sector4,Sector5,Sector6,Ilfov
};
class Blocuri {
	int id;
	char* Adresa;
	float* Consum_curent;
	int locatari;
	int luni;
	Regiune_a_bucurestiului regiune;
public:
	Blocuri()
	{
		cout << "\n Constructor fara param.";
		id = -1;
		Adresa = new char[1];
		strcpy(Adresa, "");
		Consum_curent = new float[1];
			Consum_curent[0] = 0.0;
		locatari = 0;
		luni = 0;
		regiune = Ilfov;
	}

	Blocuri(int _id, const char* _Adresa) {
		cout << "\n Constructor cu cativa param.";
		id = _id;
		Adresa = new char[strlen(_Adresa) + 1];
		strcpy(Adresa, _Adresa);
		Consum_curent = new float[1];
			Consum_curent[0] = 0.0;
		locatari = 0;
		luni = 0;
		regiune = Ilfov;
	}

	Blocuri(int _id, const char* _Adresa, int _locatari, Regiune_a_bucurestiului _regiune, int _luni) {
		cout << "\n Constructor cu toti parametrii.";
		id = _id;
		Adresa = new char[strlen(_Adresa) + 1];
		strcpy(Adresa, _Adresa);
		luni = _luni;
		Consum_curent = new float[luni];
		for (int i = 0; i < luni; i++)
		{
			Consum_curent[i] = 0.0;
		}
		locatari = _locatari;
		regiune = _regiune;

	}
	void setConsumCurent(int luna, float consum) {
		Consum_curent[luna] = consum;
	}



	Blocuri(const Blocuri& f) {
		cout << "\n Constructor Copiere";
		id = f.id;
		Adresa = new char[strlen(f.Adresa) + 1];
		strcpy(Adresa, f.Adresa);
		luni = f.luni;
		Consum_curent = new float[luni];
		for (int i = 0; i < luni; i++)
		{
			Consum_curent[i] = f.Consum_curent[i];
		}
		locatari = f.locatari;
		regiune = f.regiune;

	}
	void Afisare() {
		cout << endl << "----------------------" << endl;
		cout << "Id Bloc: " << id << endl;
		cout << "Adresa Blocului: " << Adresa<<endl;
		cout << "Cu cate luni in urma se genereaza raportul: " << luni << endl;
		cout << "Raport consum curent (exprimat in kwh): ";
		for (int i = 0; i < luni; i++)
			cout << Consum_curent[i] << " ";
		cout << endl << "Numarul de locatari: " << locatari<<endl;
		cout << "Regiunea: ";
		switch (regiune) {
		case Sector1:cout << "Sector 1";
		case Sector2:cout << "Sector 2";
		case Sector3:cout << "Sector 3";
		case Sector4:cout << "Sector 4";
		case Sector5:cout << "Sector 5";
		case Sector6:cout << "Sector 6";
		
		default: cout << "Ilfov";
		}
		cout << endl << "----------------------" << endl;
	}
	~Blocuri() {
		cout << "\n Apel destructor.";
		delete[] Adresa;
		delete[] Consum_curent;
		Adresa = nullptr;
		Consum_curent = nullptr;
	}
};
int main() {
	Blocuri Belsugului;
	
	Blocuri Uan(1, "Intrarea campului 22");
	Blocuri Nordis(2, "Strada Tzepei 01", 0, Sector1, 12);
	Nordis.Afisare();
	return 0;

}