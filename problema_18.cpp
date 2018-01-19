#include <fstream>

using namespace std;


bool prim(unsigned int x)
{
	if (x <= 1) return false;
	if (x <= 3) return true;
	if (x % 2 == 0 || x % 3 == 0) return false;

	for (unsigned int i = 5; i * i <= x; i += 6)
		if (x % i == 0 || x % (i + 2) == 0) return false;

	return true;
}


int main()
{
	fstream f("linie.in", ios::in);
	fstream g("linie.out", ios::out);

	unsigned int a[51][51];
	unsigned int n;
	unsigned int nr_max = 0;
	unsigned int linie_max = 0;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) f >> a[i][j];

	for (unsigned int i = 1; i <= n; ++i)
	{
		unsigned int nr_prime = 0;
		for (unsigned int j = 1; j <= n; ++j) nr_prime += prim(a[i][j]);

		if (nr_prime > nr_max)
		{
			nr_max = nr_prime;
			linie_max = i;
		}
	} 

	g << linie_max << '\n';
	for (unsigned int i = 1; i <= n; ++i) g << a[i][i] << ' ';


	f.close();
	g.close();
	return 0;
}