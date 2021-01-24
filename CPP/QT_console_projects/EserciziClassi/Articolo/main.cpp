/*
Creare una classe Articolo che contiene descrizione, marca (due stringhe), 
prezzo e sconto (float).

Scrivere un’applicazione console che consenta all’utente di inserire i dati di un articolo
e che stampi a video il prezzo scontato utilizzando un metodo apposito
es: mouse, trust, 15e, sconto 10 => stampa 13.50

Scrivere un’applicazione console che consenta all’utente di inserire i dati di tanti articoli
e che stampi a video la descrizione dell'articolo più costoso

*/

#include <iostream>
#include "articolo.h"
using namespace std;

int main() {
	
	Articolo* a = new Articolo("mouse", "Trust", 15, 10);
	cout << "Mouse : " << a->getPrezzo();
	
	return 0;
}
