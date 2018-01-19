#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


fstream f("cuvinte.txt", ios::in);


void citire_cuvant(char* cuv) 
{
    f >> cuv;
    f.get();
}


bool palindrom(char* cuv) 
{
    char temp_cuv[21];
    strcpy(temp_cuv, cuv);

    unsigned int t = strlen(temp_cuv);

    for (int i = 0; i < t; i++) temp_cuv[i] = (char) toupper(temp_cuv[i]);

    for (int i = 0; i < t / 2; i++)
        if (temp_cuv[i] != temp_cuv[t - i - 1]) return false;

    return true;
}


int main() 
{
    unsigned int n;
    char cuv[21];
    bool exista = false;

    f >> n; f.get();
    for (unsigned int i = 0; i < n; i++) 
    {
        citire_cuvant(cuv);
        if (palindrom(cuv)) 
        {
            cout << cuv << ' ';
            exista = true;
        }
    }

    if (!exista) cout << "Nu exista";
    f.close();
    return 0;
}