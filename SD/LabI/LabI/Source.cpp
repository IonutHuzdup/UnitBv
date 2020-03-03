#include<iostream>
using namespace std;

void read(float*& v, float& p)
{
	int i;
	cout << "Introduceti numarul de numere:"; cin >> p;
	v = new float[p];
	for (i = 0; i < p; i++) {
		cin >> v[i];
	}
}

void write(float* v, float n)
{
	int i;
	for (i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

//Problema 1:
void triplete(float* v, float n)
{
	int i;
	for (i = 0; i < n - 2; i++) {
		if (v[i] < v[i + 1] && v[i + 1] < v[i + 2])
		{
			cout << v[i] << " " << v[i + 1] << " " << v[i + 2];
			cout << endl;
		}
	}

}

//Problema 2:
void readNatural(unsigned*& w, unsigned& m)
{
	unsigned i;
	cout << "Introduceti numarul de numere:"; cin >> m;
	w = new unsigned[m];
	for (i = 0; i < m; i++) {
		cin >> w[i];
	}
}

void aparitii(unsigned* v, unsigned n)
{
	unsigned frecventa[100], i;
	for (i = 0; i < 100; i++) {
		frecventa[i] = 0;
	}

	for (i = 0; i < n; i++) {
		frecventa[v[i]]++;
	}

	for (i = 0; i < 100; i++) {
		if (frecventa[i] != 0)cout << "Elementul " << i << " apare de " << frecventa[i] << " ori." << endl;
	}

}

//Problema 3:
void verificare(float* v, float n)
{
	int i, crescator = 0, descrescator = 0;
	for (i = 0; i < n - 1; i++) {
		if (v[i] > v[i + 1]) descrescator = 1;
		else if (v[i] < v[i + 1]) crescator = 1;
	}
	if (crescator == 1 && descrescator == 1) cout << "Vectorul nu este sortat.";
	if (crescator == 1 && descrescator == 0) cout << "Vectorul este sortat crescator.";
	if (crescator == 0 && descrescator == 1) cout << "Vectorul este sortat descrescator.";
}

//Problema 4:
void citire(int**& a, int& m, int& n)
{
	int i, j;
	cout << "Introduceti numarul de linii:"; cin >> m;
	cout << "introduceti numarul de coloane:"; cin >> n;
	a = new int* [m];
	for (i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

int putere(int x, int y)
{
	int i, p = 1;
	for (i = 1; i <= y; i++)
		p = p * x;
	return p;
}

void numereBaza10(int** a, int m, int n)
{
	int i, j, nr;
	for (i = 0; i < m; i++) {
		nr = 0;
		for (j = n - 1; j >= 0; j--) {
			if (a[i][j] == 1)
				nr = nr + putere(2, n - 1 - j);
		}
		cout << "Numarul de pe linia " << i << " este:" << nr << endl;
	}
}

//Problema 5:
void citireElevi(int**& a, int& n)
{
	int i, j;

	cout << "Introduceti numarul de elevi:"; cin >> n;
	a = new int* [n];
	for (i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

void afisare(int** a, int n)
{
	int i, j, ok;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i][j] == a[j][i] && a[i][j] == 1) cout << "(" << i + 1 << "," << j + 1 << ") ";
		}
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		a[i][i] = 0; ok = 1;
		for (j = 0; j < n; j++) {
			if (a[i][j] == 1)ok = 0;
		}
		if (ok == 1)cout << "Elevul care nu agreeaza pe nimeni este : " << i + 1;
		a[i][i] = 1;
	}
	cout << endl;
	for (j = 0; j < n; j++) {
		a[j][j] = 0; ok = 1;
		for (i = 0; i < n; i++) {
			if (a[i][j] == 1)ok = 0;
		}
		if (ok == 1)cout << "Elevul care nu este agreat de nimeni este: " << j + 1;
		a[j][j] = 1;
	}
}

//Problema 6:
void cifre(unsigned x, unsigned p)
{
	unsigned* v, copie, i = 0;
	int j;
	copie = x;
	v = new unsigned[x];
	while (copie != 0) {
		v[i] = copie % 10;
		copie /= 10;
		i++;
	}

	for (int k = 0; k < 10; k++) {
		for (j = i - 1; j >= 0 && p > 0; j--) {
			if (v[j] == k) { v[j] = 99; p--; }
		}
	}


	for (j = i - 1; j >= 0; j--) {
		if (v[j] < 10)
			copie = copie * 10 + v[j];
	}
	cout << endl << copie;
	delete[] v;
}

//Problema 7:
void matriceSpirala(int** a, int n)
{

	int startRow = 0, startCol = 0, number = 1, endRow = n - 1, endCol = n - 1, i, j;
	while (startCol < endCol && startRow < endRow) {
		for (i = startCol; i <= endCol; i++) {
			a[startRow][i] = number;
			number++;
		}
		startRow++;
		for (i = startRow; i <= endRow; i++) {
			a[i][endCol] = number;
			number++;
		}
		endCol--;
		for (i = endCol; i >= startCol; i--) {
			a[endRow][i] = number;
			number++;
		}
		endRow--;
		for (i = endRow; i >= startRow; i--) {
			a[i][startCol] = number;
			number++;
		}
		startCol++;
	}

	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}
}

//Problema 8:
void matriceConcentrica(int**& a, int n)
{
	int i, suma = 0;

	a = new int* [n];
	for (i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int startRow = 0, endRow = n - 1, startCol = 0, endCol = n - 1;
	while (startRow <= endRow && startCol <= endCol) {
		cout << "Suma de pe patratul " << startCol + 1 << " este:";
		for (i = startCol; i <= endCol; i++) {
			suma = suma + a[startRow][i];
		}
		startRow++;
		for (i = startRow; i <= endRow; i++) {
			suma = suma + a[i][endCol];
		}
		endCol--;
		for (i = endCol; i >= startCol; i--) {
			suma = suma + a[endRow][i];
		}
		endRow--;
		for (i = endRow; i >= startRow; i--) {
			suma = suma + a[i][startCol];
		}
		startCol++;
		cout << suma << endl;
		suma = 0;
	}
	for (i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}

//Problema 9:
void matriceCirculara(int*& v, int& n)
{
	int** a, i;
	cout << "Introduceti numarul de elemente din vector:"; cin >> n;
	v = new int[n];
	a = new int* [n];
	for (i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	cout << "Introduceti elementele vectorului:";
	for (i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (i = 0; i < n; i++) {
		a[0][i] = v[i];
	}
	for (i = 1; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			a[i][j] = a[i - 1][j + 1];
		}
		a[i][n - 1] = a[i - 1][0];
	}

	for (i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}
	for (i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	delete[] v;
}

//Problema 10 a):
void matriceSubdiagonala(int**& a, int n)
{
	int i;
	a = new int* [n];
	for (i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) a[i][j] = 0;
			else cin >> a[i][j];
		}
	}
	int* v, x = 0;
	v = new int[n];
	for (i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			v[x] = a[i][j];
			x++;
		}
	}

	for (i = 0; i < x; i++) {
		cout << v[i] << " ";
	}

	for (i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	delete[] v;
}

//Problema 12:
void betasah(int**& a, int& n)
{
	int i, j, K, D, k;
	cout << "Introduceti dimensiunea suprafetei de joc:"; cin >> n;
	cout << "Introduceti numarul de dame:"; cin >> D;
	cout << "Introduceti numarul de patrate gri:"; cin >> K;
	a = new int* [n];
	for (i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (j > i) a[i][j] = -1;
			else a[i][j] = 0;
		}
	}
	if (D > 0) {
		i = 1;
		cout << "Introduceti pozitia damelor:"; cin >> j >> k;
		a[j][k] = 1;
		while (i < D) {
			cout << "Introduceti pozitia damelor:"; cin >> j >> k;
			while (a[j][k] != 0) { cout << "Pozitie invalida, reintroduceti."; cin >> j >> k; }
			i++; a[j][k] = 1;
		}
	}
	else cout << "\n0 dame";
	if (K > 0) {
		i = 0;
		while (i < K) {
			cout << "Introduceti pozitia patratelor gri:"; cin >> j >> k;
			while (a[j][k] != 0) { cout << "Pozitie invalida, reintroduceti."; cin >> j >> k; }
			i++; a[j][k] = 9;
		}
	}
	else cout << "\n0 patrate gri";
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (a[i][j] == 1) {
				for (k = i - 1; k >= 0 && a[k][j] == 0; k--)  a[k][j] = 7;
				for (k = j + 1; k < n && a[i][k] == 0; k++)  a[i][k] = 7;
				for (k = i + 1; k < n && a[k][j] == 0; k++)  a[k][j] = 7;
				for (k = j - 1; k >= 0 && a[i][k] == 0; k--)  a[i][k] = 7;
				for (k = 1; k < n - i && a[i + k][j + k] == 0; k++) a[i + k][j + k] = 7;
				for (k = 1; k < n - i + j && a[i - k][j - k] == 0; k++) a[i - k][j - k] = 7;
				for (k = 1; k < i + j && a[i - k][j + k] == 0; k++) a[i - k][j + k] = 7;
				for (k = 1; k < n / 2 && a[i + k][j - k] == 0; k++)a[i + k][j - k] = 7;
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << endl;
		for (j = 0; j <= i; j++) {
			cout << a[i][j] << " ";
		}
	}

	for (i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}

void main()
{
	//Problema 1:
	/*
	float* v, n;
	read(v, n);
	triplete(v, n);
	delete[] v;
	*/

	//Problema 2:
	/*
	unsigned* w, m;
	readNatural(w, m);
	aparitii(w, m);
	delete[] w;
	*/

	//Problema 3:
	/*
	float* v, n;
	read(v, n);
	verificare(v, n);
	delete[] v;
	*/

	//Problema 4:
	/*
	int** a, m, n, i;
	citire(a, m, n);
	numereBaza10(a, m, n);
	for (i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	*/

	//Problema 5:
	/*
	int** a, m, i;
	citireElevi(a, m);
	afisare(a, m);
	for (i = 0; i < m; i++) {
		delete[] a[i];
	}
	delete[] a;
	*/

	// Problema 6:
	/*
	unsigned n, p, copie, nr = 0;
	cout << "Introduceti un numar:"; cin >> n;
	copie = n;
	while (copie != 0) {
		nr++; copie /= 10;
	}
	cout << "Introduceti numarul de cifre de eliminat:"; cin >> p;
	while (p >= nr) {
		cout << "Numarul de cifre de eliminat este prea mare, reintroduceti."; cin >> p;
	}
	cifre(n, p);
	*/

	//Problema 7:
	/*
	int** a, n, i;
	cout << "Introduceti n:"; cin >> n;
	a = new int* [n];
		for (i = 0; i < n; i++) {
			a[i] = new int[n];
		}

	if (n % 2 == 0)
	matriceSpirala(a, n);
	else cout << "Nu se poate";

	for (i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	*/

	//Problema 8:
	/*
	int** a, n;
	cout << "Introduceti n:"; cin >> n;
	matriceConcentrica(a, n);
	*/

	//Problema 9:
	/*
	int*v, n;
	matriceCirculara(v, n);
	delete[] v;
	*/

	//Problema 10 a):
	/*
	int** a, n;
	cout << "Introduceti n:"; cin >> n;
	matriceSubdiagonala(a, n);
	*/

	//Problema 12:

	int** a, n;
	betasah(a, n);

}