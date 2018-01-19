#include <fstream>

using namespace std;


unsigned int cifra(unsigned long long x)
{
	return x < 10 ? x : cifra(x / 10);
}


bool verifica(unsigned long long x)
{
	unsigned long long ogl = 0;
	unsigned long long tmp = x;

	while (x)
	{
		ogl = ogl * 10 + x % 10;
		x /= 10;
	}

	return tmp == ogl;
}


int main()
{
	fstream f("numar.in", ios::in);
	fstream g("numar.out", ios::out);

	unsigned int n;
	unsigned long long x;
	unsigned long long nr = 0;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
	{
		f >> x;
		nr = nr * 10 + cifra(x);
	}

	g << nr << '\n' << "numarul " << nr;
	if (verifica(nr)) g << " este palindrom";
	else g << " nu este palindrom"; 

	f.close();
	g.close();
	return 0;
}