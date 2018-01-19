#include <iostream>
#include <cstring>

using namespace std;


void citire_sir(char* sir) 
{
    cin.get(sir, 256);
    cin.get();
}


void sufix_maxim(char* sir1, char* sir2) 
{
    int l1 = strlen(sir1) - 1;
    int l2 = strlen(sir2) - 1;

    while (sir1[l1] == sir2[l2] && l1 >= 0) --l1, --l2;

    if (strlen(sir1) == l1 + 1) cout << "Nu exista!";
    else for (int i = l1 + 1; i < strlen(sir1); ++i) cout << sir1[i];
}


int main() 
{
    char s1[256];
    char s2[256];

    cout << "Introduceti primul sir "; citire_sir(s1);
    cout << "Introduceti al douilea sir "; citire_sir(s2);
    sufix_maxim(s1, s2);

    return 0;
}