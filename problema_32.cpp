#include <fstream>
#include <string.h>

using namespace std;


ifstream f("tablou.in");
ofstream g("tablou.out");


void citire_text(char* text) 
{
    f.get(text, 201);
    f.get();
}


bool vocala(char c) 
{
    return (bool) strchr("AEIOUaeiou", c);
}


unsigned int nr_vocale(char* text) 
{
    unsigned int nr_voc = 0;
    
    for (int i = 0; i < strlen(text); i++) nr_voc += (vocala(text[i]));
    
    return nr_voc;
}


void strupr(char* text) 
{
    for (int i = 0; i < strlen(text); i++) text[i] = (char) toupper(text[i]);    
}


void eliminare_caractere_identice_alaturate(char* text) 
{
    char temp[201];

    for (int i = 0; i < strlen(text); i++) 
        while (text[i] == text[i + 1]) 
        {
            strcpy(temp, text + i + 1);
            strcpy(text + i, temp);
        }
}


void afisare_text(char* text) 
{
    g << text << '\n';
}


int main() {
    char text[201];

    citire_text(text);
    g << nr_vocale(text) << '\n';
    strupr(text);
    afisare_text(text);
    eliminare_caractere_identice_alaturate(text);
    afisare_text(text);

    f.close();
    g.close();
    return 0;
}