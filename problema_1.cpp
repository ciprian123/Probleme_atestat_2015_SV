#include <iostream>

using namespace std;


unsigned int prima(unsigned long long n)
{
	return n < 10 ? n : prima(n / 10);
}


int main()
{
	unsigned long long a;
	unsigned long long b;
	unsigned int nr_perechi = 0;

	cin >> a;
	while (prima(a) != a % 10)
	{
		cin >> b;
		nr_perechi += (a % 10 == prima(b));
		a = b;
	}

	cout << nr_perechi;
	return 0;
}