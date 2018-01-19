#include <fstream>
#include <climits>

using namespace std;


int suma_col(int a[101][101], unsigned int n, unsigned int col)
{
	int suma = 0;
	for (unsigned int i = 1; i <= n; ++i) suma += a[i][col];

	return suma;
}


int main()
{
	fstream f("matrice.in", ios::in);
	fstream g("matrice.out", ios::out);

	int a[101][101];
	int maxim = INT_MIN;
	unsigned int n;
	unsigned int m;

	f >> n >> m;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= m; ++j) 
		{
			f >> a[i][j];
			maxim = max(maxim, a[i][j]);
		}

	g << maxim << '\n';
	++n;
	for (unsigned int i = 1; i <= m; ++i) a[n][i] = suma_col(a, n, i);

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= m; ++j) g << a[i][j] << ' ';
		g << '\n';
	}

	f.close();
	g.close();
	return 0;
}