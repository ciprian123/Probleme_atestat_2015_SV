#include <fstream>
#include <string.h>

using namespace std;

fstream f("tablou.in", ios::in);
fstream g("tablou.out", ios::out);


void citire_text(char* text) 
{
    char cuv[31];

    while (f >> cuv) 
    {
        strcat(cuv, " ");
        strcat(text, cuv);
        f.get();
    }
}


unsigned int nr_cuvinte(char* text) 
{
    unsigned int nr_cuv = 0;
    unsigned int l = strlen(text);

    for (int i = 0; i < l; i++)
        nr_cuv += (isalpha(text[i]) && text[i + 1] == ' ' || isalpha(text[i]) && text[i + 1] == '.');

    return nr_cuv;
}


void afisare_propozitii(char* text) 
{
    int start = 0;
    int end;
    unsigned int l = strlen(text);

    for (int i = 0; i < l; i++)
        if (text[i] == '.') 
        {
            end = i;
            for (int j = start; j <= end; j++)
                g << text[j];
            g << endl;
            start = i + 1 + (text[i + 1] == ' ');
        }
}


int main() 
{
    char text[1001] = "";

    citire_text(text);
    g << nr_cuvinte(text) << '\n';
    afisare_propozitii(text);


    f.close();
    g.close();
    return 0;
}