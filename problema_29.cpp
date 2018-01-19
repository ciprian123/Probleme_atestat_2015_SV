#include <iostream>
#include <cstring>

using namespace std;


unsigned int vocale(char sir[])
{
	unsigned int nr_vocale = 0;
	unsigned int l_sir = strlen(sir);

	for (unsigned int i = 0; i < l_sir; ++i) 
		nr_vocale += (bool)strchr("AEIOUaeoiu", sir[i]);

	return nr_vocale;
}


int main()
{
	char sir1[201];
	char sir2[201];
	char temp[201];

	unsigned int nr_vocale;
	unsigned int nr_max_vocale = 0;

	cin.get(sir1, 201);
	strcpy(sir2, sir1);

	char* p = strtok(sir1, " ");
	while (p)
	{
		strcpy(temp, p);

		nr_vocale = vocale(temp);
		nr_max_vocale = max(nr_max_vocale, nr_vocale);

		p = strtok(NULL, " ");
	}

	p = strtok(sir2, " ");
	while (p)
	{
		strcpy(temp, p);
		if (vocale(temp) == nr_max_vocale) cout << temp << ' ';

		p = strtok(NULL, " ");
	}

	return 0;
}