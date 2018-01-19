#include <fstream>

using namespace std;


unsigned int cmmdc(unsigned int x, unsigned int y)
{
	unsigned int r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}

	return x;
}


int main()
{
	fstream f("fractii.in", ios::in);
	fstream g("fractii.out", ios::out);

	unsigned int n;
	unsigned int x;
	unsigned int y;
	unsigned int tmp;
	unsigned int nr_ireductibile = 0;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
	{
		f >> x >> y;
		tmp = cmmdc(x, y);
		nr_ireductibile += (tmp == 1);
		g << x / tmp << ' ' << y / tmp << '\n';
	}

	g << nr_ireductibile;

	f.close();
	g.close();
	return 0;
}