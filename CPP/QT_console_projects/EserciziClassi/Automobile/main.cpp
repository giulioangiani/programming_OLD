/*
Creare una classe Automobile che contiene descrizione, marca (due stringhe),
un intero che indica i kilometri percorsi e un float che è il valore dell'auto.
Una automobile, quando viene istanziata, ha la marcia in folle (0)

Scrivere un’applicazione console che chieda all'utente di inserire descrizione, marca,
valore e kilometri percorsi da una automobile e poi stampi
il prezzo diminuendo di 1000€ ogni 10000 kilometri percorsi


Scrivere un’applicazione console che chieda all'utente di inserire descrizione, marca,
valore e kilometri percorsi da una automobile e poi chieda all'utente di inserire
UP per aumentare la marcia di uno
DOWN per scalare (sempre di uno)
QUIT per uscire
Dopo ogni inserimento stampare la marcia attuale con un metodo apposito
(NOTA): le marce non possono andare sotto -1 (retromarcia) e sopra a 6.
*/

#include <iostream>
#include "automobile.h"
using namespace std;

int main() {
	
	Automobile* a = new Automobile("Ritmo", "FIAT", 15000, 30000);
	cout << "Prezzo : " << a->getPrezzo() << endl;
	
	string m;
	while (1) {
		cout << "Marcia : " << a->getMarcia() << "\n >> ";
		cin >> m;
		if (m == "QUIT") break;
		a->cambia(m);
	}
	
	
	
	return 0;
}
