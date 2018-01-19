#include <fstream>

using namespace std;


int main()
{	
	fstream f("matrice.in", ios::in);
	fstream g("matrice.out", ios::out);

	unsigned int a[100][100];
	unsigned int n;

	bool simetrica = true;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) f >> a[i][j];

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= n; ++j) g << a[i][j] << ' ';
		g << '\n';
	}

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= n - i + 1; ++j)
			if (a[i][j] != a[n - j + 1][n - i + 1])
			{
				simetrica = false;
				i = j = n + 1;
			}
	}

	g << (simetrica ? "DA" : "NU");

	f.close();
	g.close();
	return 0;
}