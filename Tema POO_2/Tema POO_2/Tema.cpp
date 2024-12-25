//TEMA SIRURI DE CARACTERE: AVEM O AGENDA TELEFONICA IN CARE SE RETINE DOAR NUMELE PRIETENILOR. SE CERE
//SA SE AFISEZE CATI PRIETENI SUNT SARBATORITI DANDU-SE NUMELE SFANTULUI(ION,MIHAI,ANDREI,ELENA, ETC)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
void agenda(char grid[] [30], int n)
{
	int i, k=0;
	char prenume[30];
	const char* aniversare = "Ioan Ionut Ionel Ionica Ionas Nica Iona Ioana Oana Ianis Ionela Ion Mihail Mihai Misu Mihaita Mihaica Mihaela Andrei Andri Andreea Andra Andrada Maria Marian Marin Mariana Marina Maricica Mariuca Marilena Mimi Marghioala Ana Anuca Anuta Anica Anita Aneta Ani Anania Anisoara Ani Anisia Gavriil Gabriel Gavriel Gabriil Vasile Vasilica Vasilii Gheorghe George Gheorghita Georgia Georgian Georgiana Gica Georica Iorgu Grigorie Grigore Gregore Gruia Constantin Costin Costel Constanta Tanta Titi Elena Ileana Lena Leana Leanca Lenuta Helena Eleonora Paraschiva Paraschiv Chiva Pavel Paul Pavlu Lica Petru Petrica Petre Petrisor Petruta Petra Nicolae Nicolas Nicoleta Nicusor Nicolaus Nina Nae Stefan Stefania Fane Dimitrie Dumitru Mitru Mitica Demetru Ilie Simon Simion Simona Mona Monica Filofteia Fifi Floriile Florin Florian Florina Floriana Florica Florentina Florentin";
		cout << "Prietenii sunt:";
		for (i = 0; i < n; i++)
		{
			strcpy(prenume, grid[i]);
			strcpy(prenume, strtok(prenume, " "));
			if (strstr(aniversare, prenume))
			{		cout << grid[i] << endl;
			k++;
			}
	}
	cout << "Exista " << k << " prieteni ce au nume de sfant.";
}
int main()
{
	int n, i;
	cout << "introduceti numarul de contacte:";
	cin >> n;
	cin.ignore();
	char phonebook[10][30];
	cout << "introduceti contactele:";
	for (i = 0; i < n; i++)
	{
		cin.getline(phonebook[i],30);
	}
	agenda(phonebook, n);
	return 0;
}