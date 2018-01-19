#include <iostream>
#include <fstream>

using namespace std;


void inversare(unsigned int a[], unsigned int n)
{
	unsigned int tmp;
	unsigned int m = n / 2;

	for (unsigned int i = 1; i <= m; ++i)
	{
		tmp = a[i];
		a[i] = a[n - i + 1];
		a[n - i + 1] = tmp;
	}
}


int main()
{
	fstream f("mat.in", ios::in);

	unsigned int a[50][50];
	unsigned int n;
	unsigned int m;

	f >> n >> m;
	for (unsigned int i = 1; i <= n; ++i)
		for (unsigned int j = 1; j <= m; ++j) f >> a[i][j];

	for (unsigned int i = 1; i <= n; ++i)
	{
		for (unsigned int j = 1; j <= m; ++j) cout << a[i][j] << ' ';
		cout << '\n';
	}

	cout << '\n';
	for (unsigned int i = 1; i <= n; ++i)
	{
		if (i % 2 == 1) inversare(a[i], m);
		for (unsigned int j = 1; j <= m; ++j) cout << a[i][j] << ' ';
		cout << '\n';
	}

	f.close();
	return 0;
}