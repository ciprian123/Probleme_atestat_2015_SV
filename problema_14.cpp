#include <iostream>

using namespace std;


unsigned int cifra(unsigned int a)
{
	unsigned int cmax = 0;

	do 
	{
		cmax = (a % 10) > cmax ? (a % 10) : cmax;
		a /= 10;
	} while (a);

	return cmax;
}


unsigned int cmmdc(unsigned int a, unsigned int b)
{
	unsigned int r;

	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}


int main()
{
	unsigned int n;
	unsigned int a[50];
	unsigned int dc = 0;

	cin >> n;
	for (unsigned int i = 1; i <= n; ++i) cin >> a[i];

	for (unsigned int i = 1; i <= n; ++i) cout << cifra(a[i]) << ' ';

	if (n > 1)
	{
		dc = cmmdc(a[1], a[2]);
		for (unsigned int i = 2; i <= n; ++i) dc = cmmdc(dc, a[i]);
	}
	else dc = a[1];

	cout << '\n' << dc;
	return 0;
}