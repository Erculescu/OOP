#include<iostream>
#include<string>
#include<fstream>
using namespace std;
enum material{Lemn, ABS,TPU,Carbon};

class comanda {
	const int id;
	static int contor;
	material tip;
	int nrBuc;
	string* dimensiuni;
	string categorie;
	float cost;
public:
	comanda():id(contor++) {
		this->tip = Lemn;
		this->nrBuc = 0;
		this->dimensiuni = nullptr;
		this->categorie = "anonim";
		this->cost = 0;
	}
	comanda(material _tip, int _nrBuc, const string* _dimensiuni, const string _categorie, float _cost) :id(contor++) {
		this->tip = _tip;
		this->nrBuc = _nrBuc;
		this->dimensiuni = new string[this->nrBuc];
		for (int i = 0; i < this->nrBuc; i++) {
			this->dimensiuni[i] = _dimensiuni[i];
		}
		this->categorie = _categorie;
		this->cost = _cost;
	}
	~comanda() {
		if (this->dimensiuni != nullptr)
		{
			delete[] this->dimensiuni;
			this->dimensiuni = nullptr;
		}
	}
	comanda(const comanda& c):id(contor++) {
		this->tip = c.tip;
		this->nrBuc = c.nrBuc;
		this->dimensiuni = new string[this->nrBuc];
		for (int i = 0; i < this->nrBuc; i++) {
			this->dimensiuni[i] = c.dimensiuni[i];
		}
		this->categorie = c.categorie;
		this->cost = c.cost;

	}
	comanda& operator=(const comanda& c){
		if (this != &c) {
			if (this->dimensiuni != nullptr)
			{
				delete[] this->dimensiuni;
				this->dimensiuni = nullptr;
			}
			this->tip = c.tip;
			this->nrBuc = c.nrBuc;
			this->dimensiuni = new string[this->nrBuc];
			for (int i = 0; i < this->nrBuc; i++) {
				this->dimensiuni[i] = c.dimensiuni[i];
			}
			this->categorie = c.categorie;
			this->cost = c.cost;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const comanda& c) {
		out << "\nTipul materialului: " << c.tip;
		out << "\nNumarul de bucati: " << c.nrBuc;
		out << "\nDimensiunile pentru fiecare bucata: ";
		for (int i = 0; i < c.nrBuc; i++)
			out << c.dimensiuni[i] << "; ";
		out << "\nCategoria: " << c.categorie;
		out << "\nCostul: " << c.cost << " Lei";
		out << endl;
		return out;
	}
	bool operator<(const comanda& c) {
		int k = 0, l = 0;
		if (this->nrBuc < c.nrBuc)
			l++; else k++;
		if (this->cost < c.cost)
			l++; else k++;
		return k < l;
	}

	comanda& operator+=(const comanda& c) {
		if (this->tip == c.tip) {
			if (this->categorie != c.categorie) {
				this->categorie + " si " + c.categorie;
			}
			this->cost = this->cost + c.cost;
			string* temp = new string[this->nrBuc + c.nrBuc];
			for (int i = 0; i < this->nrBuc; i++) {
				temp[i] = this->dimensiuni[i];
			}
			for (int i = 0, j = this->nrBuc; i < c.nrBuc; i++, j++)
				temp[j] = c.dimensiuni[i];
			if (this->dimensiuni != nullptr)
				delete[] this->dimensiuni;
			this->dimensiuni = new string[this->nrBuc + c.nrBuc];
			this->nrBuc = this->nrBuc + c.nrBuc;
			for (int i = 0; i < this->nrBuc; i++)
				this->dimensiuni[i] = temp[i];
			delete[] temp;
		}
		return *this;
	}

	void serializare(const comanda& c, const string numeFisier) {
		ofstream fout(numeFisier, ios::out | ios::binary);
		if (fout.is_open()) {
			fout.write((char*)&c.tip, sizeof(material));
			fout.write((char*)&c.nrBuc, sizeof(int));
			for (int i = 0; i < c.nrBuc; i++) {
				int lungime = c.dimensiuni[i].length();
				fout.write((char*)&lungime, sizeof(int));
				fout.write(c.dimensiuni[i].c_str(), lungime);
			}
			int lungime = c.categorie.length();
			fout.write((char*)&lungime, sizeof(int));
			fout.write(c.categorie.c_str(), lungime);
			fout.write((char*)&c.cost, sizeof(float));
			fout.close();
		}
		else { cout << "\nFisierul nu a putut fi deschis."; }
	}


	void deserializare(comanda& c, const string numeFisier) {
		ifstream fin(numeFisier, ios::in | ios::binary);
		if (fin.is_open()) {
			fin.read((char*)&c.tip, sizeof(material));
			fin.read((char*)&c.nrBuc, sizeof(int));
			c.dimensiuni = new string[c.nrBuc];
			for (int i = 0; i < c.nrBuc; i++) {
				int lungime;
				fin.read((char*)&lungime, sizeof(int));
				char* aux = new char[lungime + 1];
				fin.read(aux, lungime);
				aux[lungime] = '\0';
				c.dimensiuni[i] = aux;
				delete[] aux;
			}
			int lungime;
			fin.read((char*)&lungime, sizeof(int));
			char* aux = new char[lungime + 1];
			fin.read(aux, lungime);
			aux[lungime] = '\0';
			c.categorie = aux;
			delete[] aux;
			fin.read((char*)&c.cost, sizeof(float));
			fin.close();
		}
		else { cout << "\nFisierul nu a putut fi deschis."; }
	}

	void scrief(const string numefisier) {
		ofstream fout(numefisier);
			if (fout.is_open()) {
				fout << "\nTipul materialului: " << this->tip;
				fout << "\nNumarul de bucati: " << this->nrBuc;
				fout << "\nDimensiunile pentru fiecare bucata: ";
				for (int i = 0; i < this->nrBuc; i++)
					fout << this->dimensiuni[i] << "; ";
				fout << "\nCategoria: " << this->categorie;
				fout << "\nCostul: " << this->cost << " Lei";
				fout << endl;
				fout.close();
			}
			else { cout << "\nFisierul nu a putut fi deschis."; }
	}


};

class task :public comanda {
	string descriere;
	int durata;
public:
	task() :comanda() {
		this->descriere = "anonim";
		this->durata = 0;
	}
	task(const string _descriere, int _durata, material _tip, int _nrBuc, const string* _dimensiuni, const string _categorie, float _cost) :comanda(_tip, _nrBuc, _dimensiuni, _categorie, _cost) {
		this->descriere = _descriere;
		this->durata = _durata;
	}
	task(const task& t) :comanda(t) {
		this->descriere = t.descriere;
		this->durata = t.durata;
	}
	~task() = default;
	task& operator=(const task& t) {
		if (this != &t) {
			comanda::operator=(t);
			this->descriere = t.descriere;
			this->durata = t.durata;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const task& t) {
		out << "\nDescrierea task-ului: " << t.descriere;
		out << "\nDurata task-ului: " << t.durata << " minute";
		out << comanda(t);
		return out;
	}
	
	int& operator[](int index) {}//supraincarcare []
	bool operator!() {}//supraincarcare !
	task& operator++() {}//uspraincarcare operator ++ prefixat
	task& operator++() const {}//supraincarcare operator ++ sufixat
	bool operator==(const task& t) {}//supraincarcare ==
	operator double() {} //supraincarcare cast
	task& operator+(int val)  {}//supraincarcare +
	task& operator*(int val) {}//supraincarcare *
	friend istream& operator>>(istream& in,/*const*/ task& t) {}//supraincarcare >>
	task& operator%(int val) {}//supraincarcare %
	task& operator&&(task& t) {}//supraincarcare &&
	task& operator&(task& t) {}//supraincarcare &
	task& operator^(task& t) {}//supraincarcare ^

};
int maxim(comanda* comenzi,int nrComenzi) {
	comanda max = comenzi[0];
	int index = 0;
	for (int i = 1; i < nrComenzi; i++)
	{
		if (max < comenzi[i])
		{
			max = comenzi[i];
			index = i;
		}
	}
	return index;
}


int comanda::contor = 0;

int main() {
	comanda c1;
	string dim[] = { "6x6x6","10x10x10","22x22x22" };
	comanda c2(ABS, 3, dim, "piese schimb", 100);
	comanda c3 = c2;
	cout << c3;
	if (c1 < c2)
		cout << "\nComanda 2 este mai profitabila decat comanda 1";
	else cout << "\nComanda 1 este mai profitabila decat comanda 2";
	c2 += c3;
	cout << c2;
	task t1;
	string dim1[] = { "4x4x4","12x15x21","22x23x10" };
	task t2("Imprimare piese", 120, Carbon, 3, dim1, "piese", 1200);
	task t3(t2);
	cout << t3;
	comanda vc[] = { c1,c2,c3 };
	cout << "\nComanda cu costul maxim este: " << vc[maxim(vc, 3)];
	c2.serializare(c2, "comanda2.bin");
	comanda c4;
	c4.deserializare(c4, "comanda2.bin");
	cout << c4;
	c4.scrief("comenzi.txt");
	return 0;
}