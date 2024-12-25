#include<iostream>
using namespace std;

int main()
{
	//c:scanf si printf
	//c++ cin cout +>> si <<
	int n;
	//scanf("%d", &n);
	cout << "n=";
	cin >> n;
	//("n=%d", n);
	cout << "n=" << n;
	int* px; //px=0xcccc
	//px=NULL; asa nu
	px = nullptr;//nullptr=null pointer
	int nr = NULL;
	px = &nr;
	px = nullptr;
	px++;
	cout << endl << px;
	px -= 1;

	//alocared dinamica +dezalocare pt a nu avea memory leaks (sa yeet-uim pointerii)
	//px = (int*)malloc(n * sizeof(int));
	px = new int[10]; //alocare n elemente;
	//free(px);
	for (int i = 0; i < 10; i++)
		px[i] = i;
	cout << endl << px;
	cout << endl << *px;
	delete[] px;

	int* px2 = nullptr;
	px2 = new int(10);//pointer la un int + initializare acel unic int
	cout << endl << &px2;//prima e pe stiva
	cout << endl << *(&px2);
	cout << endl << px2;
	cout << endl << *px2;
	delete px2;

	int* px3 = new int[1];
	px3[0] = 10;
	delete[] px3;
	//variabile+ pointeri constanti
	int a = 20;
	const int b=6;
	//b=10; NU MERGE BOS
	n = b;
	const int* pa1;//pointer spre continut constant
	pa1 = &a;
	//*pa1 = 30;
	int const* pa2;//pointer spre continut constant
	pa2 = &a;
	//*pa2 = 30;
	int* const pa3=&a;//pointer constant
	//pa3 = &a;
	*pa3 = 30;
	const int* const pa4=&a;

	return 0;
}