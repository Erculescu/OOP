#include<iostream>
using namespace std;

enum Categorie{Telefon,Laptop,Televizoare,Electrocasnice};
class MagazinElectronice {
	const int id;
	string denumire;
	float pret;
	int nrFeature;
	string* Features;
	Categorie categorie;
	static float costTransport;
	bool Conectivitatewifi;
public:
	MagazinElectronice(int _id) :id(_id) {
		this->denumire = "-";
		this->pret = 0;
		this->nrFeature = 0;
		this->Features = nullptr;
		this->categorie = Telefon;
		this->Conectivitatewifi = false;
	}
	MagazinElectronice(int _id, string _denumire, float _pret, int _nrFeature, string* _Features, Categorie _categorie, bool _Conectivitatewifi) :id(_id) {
		this->denumire = _denumire;
		if (_pret > 0)
			this->pret = _pret;
		if (_nrFeature > 0 && _Features != nullptr)
		{
			int k = 0;
			string* copie = new string[_nrFeature];
			for (int i = 0; i < _nrFeature; i++)
			{
				bool OK = true;
				for (int j = 0; j < _nrFeature; j++) {
					if(_Features[i]==copie[j])
					{
						OK = false;
						break;
					}
				}
				if(OK)
				{
					copie[k++] = _Features[i];
				}
			}



			this->nrFeature = k;
			this->Features = new string[k];
			for (int i = 0; i < this->nrFeature; i++)
			{
				this->Features[i] = copie[i];
			}
			delete[] copie;
		}
		this->categorie = _categorie;
		this->Conectivitatewifi = _Conectivitatewifi;
	}
	~MagazinElectronice() {
		if (Features != nullptr)
		{
			delete[] this->Features;
			this->Features = nullptr;
		}
	}
	void setdenumire(string _denumire) {
		this->denumire = _denumire;
	}
	string getdenumire() {
		return this->denumire;
	}
	void setpret(float _pret) {
		if(_pret>0)
		this->pret = _pret;

	}
	float getpret() {
		return this->pret;
	}
	void setFeatures(int _nrFeature, string* _Features) {
		if (_nrFeature > 0 && _Features != nullptr)
		{
			this->nrFeature = _nrFeature;
			this->Features = new string[this->nrFeature];
			for (int i = 0; i < this->nrFeature; i++)
				this->Features[i] = _Features[i];
		}

	}

	string* getFeatures() {
		return this->Features;
	}
	static void setcostTransport(float _costTransport) {
		if(_costTransport>0)
		MagazinElectronice::costTransport = _costTransport;
	}
	static float getcostTransport() {
		return MagazinElectronice::costTransport;
	}
	void setcategorie(Categorie _categorie) {
		this->categorie = _categorie;
	}
	Categorie getcategorie() {
		return this->categorie;
	}

	bool getPosibilitatecumparare(float buget) {
		float costtotal = this->pret + MagazinElectronice::costTransport;
		return buget > costtotal;
	}

	MagazinElectronice(const MagazinElectronice& m) :id(m.id) {
		this->denumire = m.denumire;
		if (m.pret > 0)
			this->pret = m.pret;
		if (m.nrFeature > 0 && m.Features != nullptr)
		{
			this->nrFeature = m.nrFeature;
			this->Features = new string[this->nrFeature];
			for (int i = 0; i < this->nrFeature; i++)
				this->Features[i] = m.Features[i];
		}
		this->categorie = m.categorie;
		this->Conectivitatewifi = m.Conectivitatewifi;


	}

	MagazinElectronice& operator=(const MagazinElectronice& m) {
		if (this != &m) {
			if (Features != nullptr)
			{
				delete[] this->Features;
				this->Features = nullptr;
			}
			this->denumire = m.denumire;
			if (m.pret > 0)
				this->pret = m.pret;
			if (m.nrFeature > 0 && m.Features != nullptr)
			{
				this->nrFeature = m.nrFeature;
				this->Features = new string[this->nrFeature];
				for (int i = 0; i < this->nrFeature; i++)
					this->Features[i] = m.Features[i];
			}
			this->categorie = m.categorie;
			this->Conectivitatewifi = m.Conectivitatewifi;

		}
		return *this;
	}

	bool operator==(const MagazinElectronice& m)const {
		int k = 0;
		if (this->categorie == m.categorie)
			k++;
		for (int i = 0; i < this->nrFeature; i++)
			if (this->Features[i] == m.Features[i])
				k++;
		return k == 1 + m.nrFeature;
	}

	friend MagazinElectronice operator+(string x, const MagazinElectronice& m) {
		MagazinElectronice rez = m;
		bool OK = true;
		for (int i = 0; i < rez.nrFeature; i++)
		{		if (rez.Features[i] == x)
				OK = false;
	}
		if (OK) {
			delete[]rez.Features;
			rez.Features = new string[rez.nrFeature + 1];
			for (int i = 0; i < rez.nrFeature; i++)
				rez.Features[i] = m.Features[i];
			rez.Features[rez.nrFeature] = x;
			rez.nrFeature++;
		}
		return rez;
	}


	friend ostream& operator<<(ostream& out, const MagazinElectronice& m) {
		out << "\n----------------------";
		out << "\nDenumire: " << m.denumire;
		out << "\nPret: " << m.pret;
		out << "\nNr feature-uri: " << m.nrFeature;
		out << "\nFeature: ";
		for (int i = 0; i < m.nrFeature; i++)
			out << m.Features[i]<<endl;
		out <<"\nCategoria: "<< m.categorie;
		out << "\nSe poate conecta la wifi?  " << m.Conectivitatewifi;
		out << "\n----------------------";
		return out;
	}
	friend istream& operator>>(istream& in, MagazinElectronice& m) {
		cout << "\nIntrodu denumirea: ";
		in >> m.denumire;
		cout << "\nIntrodu pretul: ";
		in >> m.pret;
		cout << "\nIntrodu numarul de feature-uri: ";
		in >> m.nrFeature;
		//delete[]m.Features;
		cout << "\nIntrodu feature-urile: ";
		m.Features = new string[m.nrFeature];
		for (int i = 0; i < m.nrFeature; i++)
			in >> m.Features[i];
		string buffer;
		cout << "\nIntrodu categoria: ";
		in >> buffer;
		if (buffer == "Telefon")
			m.categorie = Telefon;
		else
			if (buffer == "Laptop")
				m.categorie = Laptop;
			else
				if (buffer == "Televizoare")
					m.categorie = Televizoare;
				else
					m.categorie = Electrocasnice;
		cout << "\nExista conectivitate wifi? ";
		in >> buffer;
		if (buffer == "true")
			m.Conectivitatewifi = true;
		else
			m.Conectivitatewifi = false;
		return in;
	}

};
float MagazinElectronice::costTransport = 30;

int main() {
	MagazinElectronice m1(1);
	string feat[] = { "ecran_4k", "camera_11_mp","Face_id", "ecran_4k"};
	MagazinElectronice m2(2, "Iphone 14", 4200, 4, feat, Telefon, true);
	cout << m2;
	cin >> m1;
	cout << MagazinElectronice::getcostTransport();
	MagazinElectronice m3(m1);
	cout << m3;
	m3 = m2;
	cout << m3;
	if (m1 == m2)
		cout << "\nDa";
	else cout << "\nNu";
	m1 = "face_id"+m1;
	cout << m1;
	return 0;
}