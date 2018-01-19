#include <fstream>
#include <string.h>

using namespace std;


fstream f("note.in", ios::in);
ofstream g("note.out", ios::out);


void schimba(double & a, double & b) 
{
    double temp;
    temp = a;
    a = b;
    b = temp;
}


void schimba(char* a, char* b) 
{
    char temp[21];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}


double medie_matee(double medie_oral, double nota_teza) 
{
    return (medie_oral + 3 * nota_teza) / 4;
}


void ordonare_dupa_medii(char m_nume[201][51], int n, double* medie_mate) 
{
    bool ordonat = false;
    int t = n - 1;

    while (!ordonat) 
    {
        ordonat = true;

        for (int i = 0; i < t; i++)
            if (medie_mate[i] < medie_mate[i + 1]) 
            {
                schimba(medie_mate[i], medie_mate[i + 1]);
                schimba(m_nume[i], m_nume[i + 1]);
                ordonat = false;
            }
    }
}


void prelucrare_informatii(int n) 
{
    char m_nume[201][51];
    char nume[201];
    char prenume[201];

    double medie_mate[200];
    double m_oral;
    double n_teza;
    double media_clasei = 0;

    for (int i = 0; i < n; i++) 
    {
        f >> nume >> prenume >> m_oral >> n_teza;

        strcat(nume, " ");
        strcat(nume, prenume);
        strcpy(m_nume[i], nume);

        medie_mate[i] = medie_matee(m_oral, n_teza);
    }

    ordonare_dupa_medii(m_nume, n, medie_mate);
    for (int i = 0; i < n; i++)
        if (medie_mate[i] >= 8) g << m_nume[i] << ' ' << medie_mate[i] << '\n';

    for (int i = 0; i < n; i++) media_clasei += medie_mate[i];
    
    g << media_clasei / n;
}


int main() {
    int n;

    f >> n; f.get();
    prelucrare_informatii(n);

    f.close();
    g.close();
    return 0;
}