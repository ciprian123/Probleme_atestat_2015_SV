#include <fstream>

using namespace std;


int main()
{
	fstream f("tablou.in", ios::in);
	fstream g("tablou.out", ios::out);

	unsigned int n;
	unsigned int v[101];
	unsigned int minucp = 1;
	unsigned int maxucp = 1;

	f >> n;
	for (unsigned int i = 1; i <= n; ++i) f >> v[i];

	for (unsigned int i = 1; i < n; ++i)
		for (unsigned int j = i + 1; j <= n; j++)
			if (v[i] > v[j])
			{
				unsigned int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}

	for (unsigned int i = 1; i <= n; ++i) g << v[i] << ' ';
	g << '\n';

	for (unsigned int i = 1; i <= n; ++i)
		if (v[i] % 2 == 0)
		{
			minucp = v[i];
			break;
		}

	for (unsigned int i = n; i >= 1; --i)
		if (v[i] % 2 == 0)
			{
				maxucp = v[i];
				break;
			}

	if (minucp != 1) g << maxucp << ' ' << minucp;
	else g << "Nu exista!";	

	f.close();
	g.close();
	return 0;
}