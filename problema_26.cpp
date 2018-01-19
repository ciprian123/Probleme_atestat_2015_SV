#include <fstream>

using namespace std;


bool prim(unsigned int n)
{
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (unsigned int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0) return false;

	return true;
}


int main()
{
	fstream f("mat.in", ios::in);
	fstream g("mat.out", ios::out);

	unsigned int a[50][50];
	unsigned int n;
	unsigned int m;

	f >> n >> m;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= m; ++j) f >> a[i][j];

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= m; ++j) g << a[i][j] << ' ';
		g << '\n';
	}

	g << '\n';
	for (unsigned int i = 1; i <= n; ++i)
	{
		unsigned int suma = 0;
		unsigned int contor = 0;

		g << "Linia " << i << " - ";
		for (unsigned int j = 1; j <= m; ++j)
			if (prim(a[i][j]))
			{
				suma += a[i][j];
				contor++;
			}

		if (contor) g << (double)suma / contor << '\n';
		else g << "fara elemente prime\n";
	}

	f.close();
	return 0;
}