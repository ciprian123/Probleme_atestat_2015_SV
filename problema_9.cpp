#include <fstream>

using namespace std;


void rotund(unsigned int n, unsigned int &x, unsigned int &y)
{
	x = y = 0;
	
	while (n > 0)
	{
		n % 2 ? ++y : ++x;
		n /= 2;
	}
}


int main()
{
	fstream f("atestat.in", ios::in);
	fstream g("atestat.out", ios::out);

	bool exista = false;
	unsigned int n;
	unsigned int x;
	unsigned int y;

	while (f >> n)
	{
		rotund(n, x, y);
		if (x == y)
		{
			g << n << ' ';
			exista = true;
		}
	}

	if (!exista) g << "Nu exista!";

	f.close();
	g.close();
	return 0;
}