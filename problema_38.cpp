#include <iostream>
#include <cstring>

using namespace std;


void citire_cuvant(char* cuv) 
{
    cin >> cuv;
    cin.get();
}


bool vocala(char c) 
{
    return (bool) strchr("AEIOUaeiou", c);
}


unsigned int poz_ultima_vocala (char* cuv) 
{
    int poz;
    for (int i = strlen(cuv) - 1; i >= 0; i--)
        if (vocala(cuv[i])) return i;

    return -1;
}


bool cuvintele_rimeaza(char* cuv1, char* cuv2) 
{
    char suf_1[21];
    char suf_2[21];

    strcpy(suf_1, cuv1 + poz_ultima_vocala(cuv1));
    strcpy(suf_2, cuv2 + poz_ultima_vocala(cuv2));

    return strcmp(suf_1, suf_2) == 0;
}


int main() {
    char cuv1[21];
    char cuv2[21];

    cout << "Introduceti primul cuvant... "; citire_cuvant(cuv1);
    cout << "Introduceti al doilea cuvant... "; citire_cuvant(cuv2);

    if (cuvintele_rimeaza(cuv1, cuv2)) cout << "Cuvintele " << cuv1 << " si " << cuv2 << " rimeaza!";
    else cout << "Cuvintele " << cuv1 << " si " << cuv2 << " nu rimeaza!";
    return 0;
}