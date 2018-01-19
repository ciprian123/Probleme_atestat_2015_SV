#include <iostream>
#include <cstring>

using namespace std;


void citire_text(char* text)
{
    cin.get(text, 101);
    cin.get();
}


void eliminare_spatii_inutile(char* text) 
{
    char temp[101];
    int t = strlen(text);

    for (int i = 0; i < t; i++)
        while (text[i] == ' ' && text[i + 1] == ' ') 
        {
            strcpy(temp, text + i + 1);
            strcpy(text + i, temp);
        }
}


void afisare_text(char * text) 
{
    cout << text;
}


int main() {
    char text[101];

    cout << "Introduceti textul... "; citire_text(text);
    eliminare_spatii_inutile(text);
    cout << "Dupa eliminarea spatiilor inutile, textul este: "; afisare_text(text);
    return 0;
}