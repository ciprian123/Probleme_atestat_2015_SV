#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


fstream f("cuvinte.txt", ios::in);


void citire_sir(char* sir) 
{
    f.get(sir, 31);
    f.get();
}


bool vocala(char c) 
{
    return (bool) strchr("AEIOUaeiou", c);
}


bool cuvant_vocala(char* sir) 
{
    int t = strlen(sir);

    for (int i = 0; i < t; i++)
        if (!vocala(sir[i])) return false;

    return true;
}


int main() 
{
    unsigned int n;
    char cuv[31];
    bool exista = false;

    f >> n; f.get();
    for (int i = 0; i < n; i++) 
    {
        citire_sir(cuv);
        if (cuvant_vocala(cuv)) 
        {
            cout << cuv << ' ';
            exista = true;
        }
    }

    if (!exista) cout << "Nu exista";
    f.close();
    return 0;
}