#include <fstream>

using namespace std;


int main()
{
	fstream f("triunghi.in", ios::in);
	fstream g("triunghi.out", ios::out);

	unsigned int n;
	unsigned int val = 1;
	unsigned int l = 1;
	unsigned int sp;

	f >> n;
	sp = n;

	for (unsigned int i = 0; i <= n; ++i, --sp, l += 2)
	{
		for (unsigned int i = 1; i <= sp; ++i) g << ' ';
		for (unsigned int i = 1; i <= l; ++i) g << val++ << ' ';
		for (unsigned int i = 1; i <= sp; ++i) g << ' ';
		g << '\n';
	}

	f.close();
	g.close();
	return 0;
}