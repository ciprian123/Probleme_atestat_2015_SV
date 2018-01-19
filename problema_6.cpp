#include <iostream>
#include <fstream>

using namespace std;


bool puternic(unsigned int n)
{
	unsigned int exp = 0;
	if (n <= 3) return false;
	while (n % 2 == 0) n /= 2, exp++;
	if (exp && exp < 2) return false;

	for (unsigned int i = 3; i * i <= n; i += 2)
	{
		exp = 0;
		while (n % i == 0) n /= i, exp++;
		if (exp && exp < 2) return false;
	}

	return n > 2 ? false : true;
}


int main()
{
	fstream g("numere.out", ios::out);
	unsigned int n;

	cin >> n;
	for (unsigned int i = 1; i <= n; ++i)
		if (puternic(i)) g << i << ' ';

	g.close();
	return 0;
}