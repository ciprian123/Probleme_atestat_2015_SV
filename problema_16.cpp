#include <fstream>

using namespace std;


void citire(bool a[101][101], unsigned int &n)
{
	fstream f("tablou.in", ios::in);

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) f >> a[i][j];

	f.close();
}


unsigned int suma_linie(bool a[101][101], unsigned int n, unsigned int linie)
{
	unsigned int suma = 0;

	for (unsigned int i = 1; i <= n; ++i) suma += a[linie][i];

	return suma;
}


unsigned int suma_coloana(bool a[101][101], unsigned int n, unsigned int coloana)
{
	unsigned int suma = 0;
	
	for (unsigned int i = 1; i <= n; ++i) suma += a[i][coloana];

	return suma;
}



int main()
{
	fstream g("tablou.out", ios::out);

	bool a[101][101];

	unsigned int n;
	unsigned int smax_col = 0;

	citire(a, n);
	for (unsigned int i = 1; i <= n; ++i) g << a[i][i] << ' ';
	g << '\n';


	for (unsigned int i = 1; i <= n; ++i) smax_col = max(smax_col, suma_coloana(a, n, i));

	for (unsigned int i = 1; i <= n; ++i)
		if (suma_coloana(a, n, i) == smax_col) g << suma_linie(a, n, i) << ' ';

	g.close();
	return 0;
}