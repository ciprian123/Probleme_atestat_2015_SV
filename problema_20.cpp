#include <fstream>

using namespace std;


bool triunghi(unsigned int a, unsigned int b, unsigned int c)
{
	return a && b && c && a + b > c && a + c > b && b + c > a;
}


int main()
{
	fstream f("vector.in", ios::in);
	fstream g("matrice.out", ios::out);

	unsigned int n;
	unsigned int index = 0;
	unsigned int a[31];
	unsigned int m[31 * 31 * 31][3];

	f >> n;
	for (unsigned int i = 1; i <= n; ++i) f >> a[i];

	for (unsigned int i = 1; i <= n - 2; ++i)
		for (unsigned int j = i + 1; j <= n - 1; ++j)
			for (unsigned int k = j + 1; k <= n; ++k)
				if (triunghi(a[i], a[j], a[k])) 
				{
					m[index][0] = a[i];
					m[index][1] = a[j];
					m[index++][2] = a[k];
				}

	for (unsigned int i = 0; i < index; ++i)
	{
		for (unsigned int j = 0; j < 3; ++j) g << m[i][j] << ' ';
		g << '\n';
	}

	f.close();
	g.close();
	return 0;
}