#include <fstream>
#include <climits>

using namespace std;


void citire(unsigned int a[101][101], unsigned int &n)
{
	fstream f("tablou.in", ios::in);

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) f >> a[i][j];

	f.close();
}


unsigned int suma_cifre(unsigned int x)
{
	return x < 10 ? x : (x % 10) + suma_cifre(x / 10);
}


unsigned int minim(unsigned int a[101][101], unsigned int n)
{
	unsigned int min_el = UINT_MAX;

	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) min_el = min(min_el, a[i][j]);

	return min_el;
}


int main()
{
	fstream g("tablou.out", ios::out);

	unsigned int a[101][101];
	unsigned int n;
	unsigned int contor = 0;

	citire(a, n);
	g << minim(a, n) << '\n';

	for (unsigned int i = 2; i <= n; ++i)
		for (unsigned int j = n - i + 2; j <= n; ++j) contor += (suma_cifre(a[i][j]) % 2 == 0);

	if (contor) g << contor;
	else g << "Nu exista!";

	g.close();
	return 0;
}
