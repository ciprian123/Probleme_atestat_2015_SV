#include <fstream>

using namespace std;


int main()
{
	fstream f("matrice.in", ios::in);
	fstream g("matrice.out", ios::out);

	unsigned int a[101][101];
	unsigned int n;
	unsigned int val = 1;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = i; j <= n; ++j) a[i][j] = a[j][i] = val++;

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= n; ++j) g << a[i][j] << ' ';
		g << '\n';
	}

	f.close();
	g.close();
	return 0;
}