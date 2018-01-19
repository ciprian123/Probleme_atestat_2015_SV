#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


fstream f("atestat.in", ios::in);


void citire_text(char* text) 
{
    f.get(text, 301);
    f.get();
}


void schimba(char &a, char &b) 
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}


void schimba(unsigned int &a, unsigned int &b) 
{
    unsigned int temp;
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


char strrev(char* s) 
{
    unsigned int temp = strlen(s);
    for (int i = 0; i < temp / 2; i++) schimba(s[i], s[temp - i - 1]);
}


bool cuvant_palindrom(char* cuv) 
{
    char inv[21];

    strcpy(inv, cuv);
    strrev(inv);
    return (strcmp(cuv, inv) == 0);
}


void cel_mai_lung_palindrom(char* text) 
{
    unsigned int l;
    unsigned int l_max = 0;

    char* p;
    char sep[] = " ,.:;!?";
    char temp_text[301];
    char cuv_curent[21];
    char cuv_pal_max[21];

    strcpy(temp_text, text);
    p = strtok(temp_text, sep);

    while (p) 
    {
        strcpy(cuv_curent, p);
        l = strlen(cuv_curent);

        if (cuvant_palindrom(cuv_curent) && l > l_max) 
        {
            l_max = l;
            strcpy(cuv_pal_max, cuv_curent);
        }

        p = strtok(NULL, sep);
    }

    cout << "Cel mai lung cuvant palindrom este: " << cuv_pal_max << '\n' << '\n';
}



void ordonare_dupa_lungimi(char m[301][21], unsigned int n, unsigned int* lungimi) 
{
    bool ordonat = false;
    unsigned int t = n - 1;

    while (!ordonat) {
        ordonat = true;
        for (unsigned int i = 0; i < t; i++)
            if (lungimi[i] > lungimi[i + 1]) 
            {
                schimba(lungimi[i], lungimi[i + 1]);
                schimba(m[i], m[i + 1]);
                ordonat = false;
            }
    }
}


void afisare_ordonat(char* text) 
{
    char m[301][21];
    char* p;
    char temp_text[301];
    char cuv_curent[21];
    char sep[] = " .,:;?!";

    unsigned int nr_cuv = 0;
    unsigned int lungimi[301] = {0};

    strcpy(temp_text, text);
    p = strtok(temp_text, sep);

    while (p) 
    {
        strcpy(cuv_curent, p);
        lungimi[nr_cuv] = strlen(cuv_curent);
        strcpy(m[nr_cuv++], cuv_curent);

        p = strtok(NULL, sep);
    }

    cout << "Cuvintele in ordine crescatoare a lungimii:\n";
    ordonare_dupa_lungimi(m, nr_cuv, lungimi);
    for (unsigned int i = 0; i < nr_cuv; i++) cout << m[i] << '\n';
}


void afisare_text(char* text) 
{
    cout << "Sirul initial este:\n";
    cout << text << '\n' << '\n';
}


int main() {
    char text[301];

    citire_text(text);
    afisare_text(text);
    cel_mai_lung_palindrom(text);
    afisare_ordonat(text);

    f.close();
    return 0;
}