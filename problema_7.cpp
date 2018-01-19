#include <iostream>
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
	fstream g("gemene.txt", ios::out);

	unsigned int n;
	unsigned int x = 3;
	unsigned int nr_perechi = 0;

	cin >> n;
	while (nr_perechi < n)
	{
		if (prim(x) && prim(x + 2)) 
		{
			g << x << ' ' << x + 2 << '\n';
			nr_perechi++;
		}

		x += 2;
	}

	g.close();
	return 0;
}