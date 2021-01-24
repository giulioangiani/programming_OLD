#include "persona.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <string> nome, cognome;
    vector <int> anno;
    int n, a;
    string c;

    cout << "Inserisci il numero di persone: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << "Inserisci il nome della persona " << i + 1 << " : ";
        cin >> c;
        nome.push_back(c);
        cout << "Insrisci il cognome della persona " << i + 1 << " : ";
        cin >> c;
        cognome.push_back(c);
        cout << "Inserisci l'anno di nascità della persona " << i + 1 << " : ";
        cin >> a;
        anno.push_back(a);
    }

    Persona *p;
    p = new Persona();

    cout << "La persona più giovane è " << nome[p->giovane(anno)] << " "<< cognome[p->giovane(anno)] << " nata nell'anno " << anno[p->giovane(anno)] << endl;
}
