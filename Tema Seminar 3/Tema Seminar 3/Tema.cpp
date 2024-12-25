#include<iostream>
#include<string.h>
#define CRT_SECURE_NO_WARNINGS
using namespace std;
//De facut o clasa cu denumirea numelui nostru cu vector dinamic,
// static, sir de caractere, vector de bool,
// cu metode de afisare si inițializare si setter+getter

class R {
	int id;
	int lungime;
	int* vectordinamic = new int[lungime];
	float vectorstatic[10];
	string sir;
	int lungime_bool;
	bool* este_adevarat=new bool[lungime_bool];

public:
	void initializare() {
		id = -1;
		lungime = -1;
		vectordinamic = nullptr;
		sir = '-';
		lungime_bool = 0;
		este_adevarat = nullptr;
	}
	void getbool() {
		if (lungime_bool == 0)
		{
			cout << "\nNu exista informatii in plus legate de lista.";
		}
		else
		{
			for (int i = 0; i < lungime_bool; i++)
			{
				cout << este_adevarat[i] << "  ";
			}cout << endl;
		}
	}
	void afisare() {
		cout << endl<<"-----------------------------------------------------"<<endl;
		cout << "Id: " << id << endl;
		cout << "Lungimea vectorilor: " << lungime << endl;
		cout << "Elementele vectorului dinamic: ";
		for(int i=0;i<lungime;i++)
		{
			cout << vectordinamic[i] << " ";
		}
		cout << endl << "Elementele vectorului static: ";
		for (int i = 0; i < lungime; i++)
		{
			cout << vectorstatic[i]<<" ";
		}
		cout << endl << "Sirul: " << sir << endl;
		cout << "Lungimea vectorului bool: " << lungime_bool<<endl;
		cout << "Elementele bool-ului: ";
		for(int i=0;i<lungime_bool;i++)
		{
			cout << este_adevarat[i] << " ";
		}
		
		cout << endl<<"-----------------------------------------------------";
	}

	void setvectordin() {
		int n;
		cout << "Introduceti lungimea vectorului: ";
		cin >> n;
		if(n<0)
		{
			cout << "Dimensiune Invalida!";
		}
		else {
			delete[] vectordinamic;
			lungime = n;
			vectordinamic = new int[lungime];
			cout << "Introduceti valorile vectorului:";
			for(int i=0;i<lungime;i++)
			{
				cin >> vectordinamic[i];
			}
		}
	}
	void setbool() {
		int n;
		cout << "Introduceti lungimea vectorului boolean: ";
		cin >> n;
		if (n < 0)
		{
			cout << "Dimensiune Invalida!";
		}
		else {
			delete[] este_adevarat;
			lungime_bool = n;
			este_adevarat = new bool[lungime_bool];
			cout << "Introduceti elementele vectorului boolean: ";
				for (int i = 0; i < lungime_bool; i++) {
					cin >> este_adevarat[i];
				}

		}
	}
	string getsir() {
		return sir;
	}
	void setsir(string sirnou) {
	if (!sirnou.empty() && sirnou.length() > 3)
			sir = sirnou;
	}
};





int main()
{	
	R rares;
	rares.initializare();
	rares.setbool();
	rares.getbool();
	rares.setvectordin();
	rares.setsir("Rares");
	rares.afisare();
	rares.setsir("Carmen");
	cout<<endl<<rares.getsir();




	return 0;
}