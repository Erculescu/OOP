#include<iostream>
using namespace std;
class Student {
	string nume;
	static int nrStudenti;
public:
	static float taxaresanta;
	Student(string _nume) {
		this->nume = _nume;
		Student::nrStudenti++;
	}
	static int getNrStudenti() {
		return Student::nrStudenti;
	}
	//verifica daca param sunt eligibili pentru un potential obiect
	static bool verificare(string _nume, int _varsta) {
		//to do de adaugat conditii
		return true;
	}//Metodele statice nu au nevoie de obiecte!!!!



};
//Subiect despre proiecte software la test
//pt fiecare proiect exista limbajul de progr
//static nr proiecte multilimbaj

class Masina {
public:
	string model;
};
//has a
class Persoana{
public:
	string nume;
	Masina masina;
	Persoana() {
		this->nume = "anonim";
		this->masina.model = "Dacia";
		this->adresa = "bucuresti";
		this->contBancar = "1234567890";
	}

protected:
	string adresa;//Este private pt exteriorul clasei sau "public" pt derivatele din ea
private:
	string contBancar;

};
//Student is a persoana
class Stud :private Persoana {
public:
	string facultate;
	Persoana::nume;//publicizare
	Stud():Persoana() {
		this->facultate = "ASE";
	}
};

int Student::nrStudenti = 0;
float Student::taxaresanta = 100;
int main() {
	Student s1("Gigel");
	cout << endl << s1.taxaresanta;
	cout << endl << Student::taxaresanta;
	cout << endl << Student::getNrStudenti();

	cout << endl << "\n----------------------Derivare----------------";
	Stud s2;
	Persoana p1;
	
	return 0;
}