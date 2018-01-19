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


void eliminare(unsigned int a[], unsigned int &n, unsigned int poz)
{
	for (unsigned int i = poz; i < n; ++i) a[i] = a[i + 1];
	--n;
}


int main()
{
	fstream f("date.in", ios::in);
	fstream g("date.out", ios::out);

	unsigned int a[101][101];
	unsigned int prime[101 * 101];
	unsigned int index = 1;
	unsigned int n;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) 
		{
			f >> a[i][j];
			if (prim(a[i][j])) prime[index++] = a[i][j];
		}

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= n; ++j) g << a[i][j] << ' ';
		g << '\n';
	}

	for (unsigned int i = 1; i < index; ++i) g << prime[i] << ' ';
	g << '\n';

	for (unsigned int i = 1; i < index; ++i)
		if (prime[i] > 9 && ((prime[i] % 100) / 10) % 2 == 1)
		{
			eliminare(prime, index, i);
			--i;
		}

	for (unsigned int i = 1; i < index; ++i) g << prime[i] << ' ';

	f.close();
	return 0;
}