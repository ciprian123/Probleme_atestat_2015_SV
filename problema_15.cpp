#include <fstream>

using namespace std;


int main()
{
	fstream f("atestat.in", ios::in);
	fstream g("atestat.out", ios::out);

	unsigned int n;
	unsigned int v[101];

	bool frecv[10000] = { false };

	f >> n;
	for (unsigned int i = 1; i <= n; ++i)
	{
		f >> v[i];
		g << v[i] << ' ';
	}

	g << '\n';
	for (unsigned int i = 1; i <= n; ++i)
		if (!frecv[v[i]])
		{
			g << v[i] << ' ';
			frecv[v[i]] = true; 
		}

	f.close();
	g.close();
	return 0;
}