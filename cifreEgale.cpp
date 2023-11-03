#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
ofstream fout("bac.out");
int main()
{
	int a, b, nra, na, i;
	cin >> a >> b;
	nra = log10(a) + 1; // nr. cifre a lui a
	na = 0;
	// calculez cel mai mic numar de lungime nra
	// care are toate cifrele egale cu 1 (111...111 (de nra ori 1))
	for (i = 1; i <= nra; i++)
		na = na*10 + 1;
	// calculez cel mai mic numar >= a 
	// care are toate cifrele egale
	for (i = 1; i <= 9; i++)
		if (na*i >= a) break;
	while (na*i <= b)
	{
		// afisez numarul curent care indeplineste conditia
		fout << na*i << ' ';
		// calculez urmatorul numarul
		if (i == 9) na = na*10 + 1, i = 1;
		else i++;
	}
	return 0;
}	
