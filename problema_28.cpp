#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;


void schimba(unsigned int &a, unsigned int &b)
{
	unsigned int tmp;

	tmp = a;
	a = b;
	b = tmp;
}


bool perfect(unsigned int x)
{
	unsigned int sdiv = 0;
	unsigned int i;

	for (i = 1; i * i < x; ++i)
		if (x % i == 0) sdiv += (i + x / i);

	if (i * i == x) sdiv += i;
 	return sdiv - x == x;
}


int main()
{
	fstream f("atestat.in", ios::in);
	fstream g("atestat.out", ios::out);

	unsigned int n;
	unsigned int a[101][101];
	unsigned int nr_pp = 0;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= n; ++j) 
		{
			f >> a[i][j];
			nr_pp += perfect(a[i][j]);
		}

	g << nr_pp << '\n';
	unsigned int tmp = n / 2;
	for (unsigned int i = 1; i <= tmp; ++i) schimba(a[i][n - i + 1], a[n - i + 1][i]);

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= n; ++j) g << a[i][j] << ' ';
		g << '\n';
	}

	f.close();
	g.close();
	return 0;
}