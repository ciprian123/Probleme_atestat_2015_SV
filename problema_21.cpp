#include <fstream>

using namespace std;


int main()
{	
	fstream f("matrice.in", ios::in);
	fstream g("matrice.out", ios::out);

	unsigned int a[100][100];
	unsigned int n;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) f >> a[i][j];

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= n; ++j) g << a[i][j] << ' ';
		g << '\n';
	}

	g << '\n';
	for (unsigned int i = 1; i < n; ++i)
	{
		for (unsigned int j = i + 1; j <= n; ++j)
		{
			unsigned int tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}
	}

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= n; ++j) g << a[i][j] << ' ';
		g << '\n';
	}

	f.close();
	g.close();
	return 0;
}