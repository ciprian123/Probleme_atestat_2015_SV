#include <iostream>
#include <fstream>

using namespace std;


unsigned int suma_divizori(unsigned int x)
{
	unsigned int s = 0;
	unsigned int tmp = x / 2;
	for (unsigned int i = 1; i <= tmp; ++i)
		s += (tmp % i == 0 ? i : 0);

	return s;
}


int main()
{
	fstream f("numere.txt", ios::in);

	unsigned int a;
	unsigned int b;

	while (f >> a >> b)
		if (suma_divizori(a) == b + 1 && suma_divizori(b) == a + 1) cout << a << ' ' << b << '\n';

	f.close();
	return 0;
}