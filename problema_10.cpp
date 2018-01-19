#include <fstream>

using namespace std;


unsigned int cifra(unsigned int n)
{
	if (!n) return 0;
	return n % 9 ? n % 9 : 9;
}


int main()
{
	fstream f("date.in", ios::in);
	fstream g("date.out", ios::out);

	unsigned int n;
	unsigned int x;
	unsigned int tmp;
	unsigned int contor = 0;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
	{
		f >> x;
		tmp = cifra(x);
		contor += (tmp == 2 || tmp == 3 || tmp == 5 || tmp == 7);
	}

	g << contor;

	f.close();
	g.close();
	return 0;
}