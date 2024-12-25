#include <iostream>
#include <cstring>
//TEST PE 27 SAU 28 NOIEMBRIE
using namespace std;
enum Facultate {
	CSIE,MK,MN=100,FABIZ
};
union ID {
	long cnp;
	int cui;
	char test;
};
class Produs {

	int codUnic;
	string denumire;
	int cantitate;
	char um[10];
	bool estefragil;
	int istoricpreturi[20];
	int nrpreturi;

public:
	void adaugacantitatenoua(int val) {
		cantitate += val;
	}
	void reducerePretCurent(float procent) {
		istoricpreturi[nrpreturi - 1] *= 1 - procent;
	}

	//metode de tip constructori
	//supraincarc operatori
	//destructor
};


int main()
{
	//sir de caractere
	// met1 alocare statica
	/*char sir[50];//dezavantaj:spatiu de stocare fix
	cin >> sir;
	cout << sir<<endl;*/

	// met 2 alocare dinamica
	/*char* sir2 = nullptr;
	char buffer[50];
	cin >> buffer;
	sir2 = new char[strlen(buffer) + 1];
	strcpy_s(sir2, strlen(buffer) + 1, buffer);
	cout << endl << sir2<<endl;
	delete[] sir2;*/
	// met 3 clasa string (alocare dinamica "ascunsa")
	/*string sir3;
	cin >> sir3;
	cout << sir3;
	sir3 = "Popescu";
	cout << endl << sir3;
	sir3 + -= " ceva rau";
	sir3 = buffer;*/


	//enum
	//Facultate f;
	//f = Facultate::CSIE;
	//cout << endl << f;
	//int codfacultate;
	//cin >> codfacultate;
	//f = (Facultate)codfacultate;
	//cout << f;

	/*ID id;
	id.cnp = 1672345;
	cout << endl << id.cnp << " " << id.test << " " << id.cui;
	id.cui = 123456;
	cout << endl << id.cnp << " " << id.test << " " << id.cui;*/

	//clase
	Produs p1;//implicit constructor;
	p1.adaugacantitatenoua(5);

	return 0;
}