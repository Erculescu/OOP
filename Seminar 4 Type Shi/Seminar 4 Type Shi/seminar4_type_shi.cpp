#include <iostream>
using namespace std;

enum Facultate {
	CSIE, MK, MN, FABIZ,OTHER
};


class Student {
	char* nume;
	Facultate facultate;
	string specializare;
	float noteBac[7];
	int nrNote;
	bool esteBursier;
public:
	//metode accesor
	bool getesteBursier() {
		return esteBursier;
	}
	//metoda set pentru esteBursier
	void setesteBursier(bool _esteBursier) {
		
		esteBursier = _esteBursier;
	}
	void initializare() {
		nume=nullptr;
		facultate=Facultate::OTHER;
		specializare="-";
		noteBac[7];
		nrNote=0;
		esteBursier = false;
	}
	void afisare() {
		cout << endl << "---------------------------------------------------------"<<endl;
		if (nume != nullptr)
			cout << "Numele studentului: " << nume << endl;
		else cout << "Nume absent!"<<endl;
		cout << "Facultatea:" << facultate << endl;
		cout << "Specializare: " << specializare << endl;
		cout << "Nr note: " << nrNote << endl;
		cout << "Note bac: " << noteBac << endl;
		for(int i=0;i<nrNote;i++)
		{
			cout << noteBac[i] << " ";
		}
		cout << endl << "Este bursier?: " << esteBursier<<endl;
		cout << endl << "---------------------------------------------------------"<<endl;

	}
	void setnume(const char* _nume) {
		if (_nume != nullptr && strlen(_nume) >= 5) {
			//obiectul deja exista, poate deja are un nume
			if (nume != nullptr) {
				delete[] nume;
				nume = nullptr;
			}
			nume = new char[strlen(_nume) + 1];
			strcpy(nume, _nume);
		}
	}
	const char* getnume() {//ca sa fie incapsulat, trebuie folosit in getter return const nume!!!!!!
		return nume;
	}

};
int main() {
	Student s;
	s.initializare();
	s.afisare();
	s.setnume("Andrei Ionescu");
	s.afisare();
	//s.getnume()[0] = 'M';
	if (s.getnume() != nullptr)
	{
		cout << endl << s.getnume() << endl;
	}else
	{
		cout << "Nu exista"<<endl;
	}
	cout << "Este bursier?: " << s.getesteBursier();
	s.setesteBursier(true);
	cout << "\nEste bursier?: " << s.getesteBursier();


	return 0;
}