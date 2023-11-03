#include <fstream>
#include <iostream>
using namespace std;
ofstream fout("bac.out");
bool cifreEgale(int);
int main()
{
	int a, b, x;
	cin >> a >> b;
	for (x = a; x <= b; x++)
	{
		if (cifreEgale(x))
			fout << x << ' ';
	}
	fout.close();
	return 0;
}
bool cifreEgale(int x)
{
	int cif = x%10;
	while (x)
	{
		if (x%10 != cif) return 0;
		x /= 10;
	}
	return 1;
}
