#include <iostream>
#include <vector>
#include<list>
#include<set>
#include<map>
using namespace std;

namespace TEST {
	int variabilaTEST = 10;
}
namespace TEST2 {
	int variabilaTEST = 20;
}
using namespace TEST2;
/*using namespace TEST;*/
class Student {
public:
	string nume;
	float medie;
	Student() {

	}
	Student(string _nume, float _medie) {
		this->nume = _nume;
		this->medie = _medie;
	}
	friend ostream& operator <<(ostream& out, Student& s)
	{
		out << "Nume: " << s.nume << " Medie: " << s.medie;
		return out;
	}
	bool operator< (const Student& s) const{
		return this->nume < s.nume;
	}
};
int main() {
	std::cout << TEST::variabilaTEST << endl;
	cout << TEST2::variabilaTEST << endl;
	cout << variabilaTEST << endl;

	//STL~standard template library
	//faciliteaza lucrul cu structuri de date
	//vector
	vector<int> vInt;
	vInt.push_back(10);
	vInt.push_back(12);
	vInt.push_back(15);
	vInt[0] = 321;
	for (int i = 0; i < vInt.size(); i++) {
		cout << vInt[i] << " ";
	}
	//list
	cout << endl << "Afisare lista: ";
	list<float> listFloat;
	listFloat.push_back(10);
	listFloat.push_front(20);
	listFloat.push_front(35);
	
	//iterator
	list<float>::iterator it;
	for (it = listFloat.begin(); it != listFloat.end(); it++) {
		cout << *it << " ";
	}

	cout << endl << "Afisare vector: ";
	vector<int>::iterator itv;
	for (itv = vInt.begin(); itv != vInt.end(); itv++) {
		cout << *itv << " ";
	}
	//set
	cout << "\nSet: ";
	set<string> setString;
	setString.insert("Erculescu Rares");
	setString.insert("Mihai Rares");
	setString.insert("Erculescu Rares");
	setString.insert("Mihai Rares");
	setString.insert("Braticevici Carmen");
	set<string>::iterator its;
	for (its = setString.begin(); its != setString.end(); its++) {
		cout << *its << endl;
	}
	cout << "\nreversed iterator\n";
	//reversed iterator
	set<string>::reverse_iterator itrs;
	for (itrs = setString.rbegin(); itrs != setString.rend(); itrs++) {
		cout << *itrs << endl;
	}
	
	its = setString.find("Mihai Rares");
	if (its != setString.end()) {
		cout << "\nS-a gasit elementul cautat: " << *its;
	}
	else
	{cout << "\nNu s-a gasit elementul cautat.";
	}

	Student s1("Gigel", 9.75);
	Student s2("Dorel", 8.15);
	Student s3("Marian", 9.12);
	Student s4("Gigel", 9.30);
	set<Student> setStudenti;
	setStudenti.insert(s1);
	setStudenti.insert(s2);
	setStudenti.insert(s3);
	setStudenti.insert(s4);
	set<Student>::iterator itStud;
	/*for (itStud = setStudenti.begin(); itStud != setStudenti.end(); itStud++)
	{
		cout<<*itStud;
	}
	*/
	//map
	map<int, Student> mapStud;
	mapStud[0] = s1;
	mapStud[134] = s2;
	mapStud[134] = s1;
	mapStud.insert(pair<int, Student>(5, s3));
	map<int, Student>::iterator itmap;
	for (itmap = mapStud.begin(); itmap != mapStud.end(); itmap++)
	{
		cout << "\ncheie: " << itmap->first << " " << itmap->second;
	}

	//introduceti stl-ul set intr-o clasa tip container care permite unicitate
	//implementare de clasa care sa permita stocarea de persoane in contextul unicitatii care detin cate o masina
	map<Student, set<Student>> test;

	return 0;
}