#include <fstream>

using namespace std;


bool palindrom(unsigned int x)
{
	unsigned int tmp = x;
	unsigned int ogl = 0;

	while (x)
	{
		ogl = ogl * 10 + x % 10;
		x /= 10;
	}

	return ogl == tmp;
}


int main()
{
	fstream f("matrice.in", ios::in);
	fstream g("matrice.out", ios::out);

	unsigned int a[51][51];
	unsigned int n;
	unsigned long long suma = 0;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) f >> a[i][j];

	for (unsigned int i = 1; i < n; ++i) 
		if (palindrom(a[1][i])) g << a[1][i] << ' ';
	
	for (unsigned int i = 1; i < n; ++i)
		if (palindrom(a[i][n])) g << a[i][n] << ' ';

	for (unsigned int i = n; i > 1; --i)
		if (palindrom(a[n][i])) g << a[n][i] << ' ';

	for (unsigned int i = n; i > 1; --i)
		if (palindrom(a[i][1])) g << a[i][1] << ' ';


	for (unsigned int i = 1; i < n; ++i)
		for (unsigned int j = i + 1; j <= n; ++j) suma += a[i][j];

	g << '\n' << suma;

	f.close();
	g.close();
	return 0;
}