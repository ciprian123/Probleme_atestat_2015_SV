#include <fstream>

using namespace std;


unsigned int prima(unsigned int n)
{
	return n < 10 ? n : prima(n / 10);
}


int main()
{
	fstream f("tablou.in", ios::in);
	fstream g("tablou.out", ios::out);

	unsigned int n;
	unsigned int v[101];
	unsigned int suma = 0;
	unsigned int contor = 0;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
	{
		f >> v[i];
		if (prima(v[i]) == v[i] % 10)
		{
			suma += v[i];
			contor++;
		}
	}

	for (unsigned int i = n; i >= 1; --i) g << v[i] << ' ';
	g << '\n';

	if (contor) g << (double) suma / contor;
	else g << 0;

	f.close();
	g.close();
	return 0;
}