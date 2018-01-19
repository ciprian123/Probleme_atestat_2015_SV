#include <iostream>

using namespace std;


void generare_matrice(char a[][50], unsigned int n) 
{
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++) 
        {
            if (i == j || i + j == n - 1) a[i][j] = 'D';
            if (i < j && i + j < n - 1) a[i][j] = 'N';
            if (i > j && i + j > n - 1) a[i][j] = 'S';
            if (i < j && i + j > n - 1) a[i][j] = 'E';
            if (i > j && i + j < n - 1) a[i][j] = 'V';
        }
}


void afisare_matrice(char a[][50], unsigned int n) 
{
    for (unsigned int i = 0; i < n; i++) 
    {
        for (unsigned int j = 0; j < n; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main() 
{
    unsigned int n;
    char a[50][50];

    cout << "n = "; cin >> n;
    generare_matrice(a, n);
    afisare_matrice(a, n);

    return 0;
}