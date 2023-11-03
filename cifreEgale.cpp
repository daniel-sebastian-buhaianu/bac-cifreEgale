#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
ofstream fout("bac.out");
int nrCifre(int);
int main()
{
	int a, b, i, nrca, nrcb, pca, pcb, xa, xb, cif, nrc;
	cin >> a >> b;
	nrca = nrCifre(a); // nr. cifre a lui a
	pca = a/pow(10, nrca-1); // prima cifra a lui a
	// calculez cel mai mic numar >= a 
	// care are toate cifrele egale
	for (xa = i = 0; i < nrca; i++)
		xa = xa*10 + pca;
	if (xa < a)
	{
		if (pca != 9)
			for (xa = i = 0; i < nrca; i++)
				xa = xa*10 + pca+1;
		else
			for (xa = i = 0; i <= nrca; i++)
				xa = xa*10 + 1;
	}
	nrcb = nrCifre(b); // retin nr. cifre a lui b
	pcb = b/pow(10, nrcb-1); // retin prima cifra a lui b
	// calculez cel mai mare numar <= b
	// care are toate cifrele egale
	for (xb = i = 0; i < nrcb; i++)
		xb = xb*10 + pcb;
	if (xb > b)
	{
		if (pcb != 1)
			for (xb = i = 0; i < nrcb; i++)
				xb = xb*10 + pcb-1;
		else
			for (xb = i = 0; i < nrcb-1; i++)
				xb = xb*10 + 9;
	}
	cif = xa%10, nrc = nrca;
	while (1)
	{
		for (i = 0; i < nrc; i++) // afisez numarul curent
			fout << cif;
		fout << ' ';
		// verific daca mai sunt numere din [a, b]
		// care sa indeplineasca conditia
		if (cif == xb%10 && nrc == nrcb) break;
		// mai sunt numere, deci construiesc urmatorul numar
		cif = (cif+1)%10;
		if (!cif) cif = 1, nrc++;
	}
	fout.close();
	return 0;
}
int nrCifre(int x)
{
	int nrc = 0;
	while (x)
	{
		nrc++;
		x /= 10;
	}
	return nrc;
}
