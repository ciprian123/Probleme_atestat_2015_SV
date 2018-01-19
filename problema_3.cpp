#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	int a;
	int b;
	unsigned int nr_pp = 0;

	cin >> a >> b;
	while (a != b)
	{
		nr_pp += (sqrt(a) == floor(sqrt(a)));
		a = b;
		cin >> b;
	}

	nr_pp += (sqrt(a) == floor(sqrt(a)));
	cout << nr_pp;
	return 0;
}