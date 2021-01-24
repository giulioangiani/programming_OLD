#include "calciatore.h"

#include <iostream>

using namespace std;

int main()
{
    string nom, cog, naz;
    float anno, goal, part;

    cout <<"Inserisci il nome del calciatore: ";
    cin >> nom;

    cout <<"Inserisci il cognome del calciatore: ";
    cin >> cog;

    cout <<"Inserisci la nazionalità del calciatore: ";
    cin >> naz;

    cout <<"Inserisci l'anno di nascità del calciatore: ";
    cin >> anno;

    cout <<"Inserisci il numero di goal fatti dal calciatore: ";
    cin >> goal;

    cout <<"Inserisci il numero di parite giocate dal calciatore: ";
    cin >> part;

    Calciatore *c;
    c = new Calciatore();

    c->med(goal, part);

    cout << "\n=======================================\n\n";
    cout << "Nome:                      " << nom << endl;
    cout << "Cognome:                   " << cog << endl;
    cout << "Nazionalità:               " << naz << endl;
    cout << "Anno di nascità:           " << anno << endl;
    cout << "Numero goal fatti:         " << goal << endl;
    cout << "Numero partite giocate:    " << part << endl;
    cout << "\n=======================================\n\n";
    cout << "La media stagionale di " << nom << cog << " è " << c->getMed() << endl;
    cout << "\n=======================================\n\n";

}
