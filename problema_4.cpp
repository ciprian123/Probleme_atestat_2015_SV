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
	fstream f("atestat.in", ios::in);
	fstream g("atestat.out", ios::out);

	unsigned int a;
	unsigned int b;
	unsigned int k;
	unsigned int nr_prime = 0;

	f >> a >> b >> k;
	for (unsigned int i = a + !(a % 2); i <= b && nr_prime <= k; i += 2)
		if (prim(i))
		{
			g << i << ' ';
			nr_prime++;
		}

	if (k >= nr_prime) 
		g << "\nS-au gasit mai putine numere prime: " << nr_prime;

	f.close();
	g.close();
	return 0;
}
