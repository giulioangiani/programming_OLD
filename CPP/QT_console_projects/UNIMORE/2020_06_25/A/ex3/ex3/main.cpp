/*
Esercizio 3 (12 punti)

Creare una classe Scontrino che contiene il nome del negozio in cui `e stata re-
alizzata la spesa (una stringa), la data della spesa (una stringa), l’orario della

spesa (una stringa) ed un vector di float con le varie voci di spesa. Scrivere

due metodi per calcolare il totale della spesa e la voce di spesa massima, rispet-
tivamente. Scrivere un’applicazione console che consenta all’utente di inserire

i dati di uno scontrino, e che stampi a video il totale della spesa e la voce di
spesa massima usando i due metodi creati.
*/

#include <iostream>
#include "scontrino.cpp"
using namespace std;


int main()
{
	string nome, data, ora;
	/*
	cout << "Inserisci il nome del negozio :";
	cin >> nome;
	cout << "Inserisci la data dell'acquisto :";
	cin >> data;
	cout << "Inserisci l'ora dell'acquisto :";
	cin >> ora;	
	*/
	nome = "Supermercato UNIMORE";
	data = "2020/06/01";
	ora = "10:10";
	Scontrino* s;
	s = new Scontrino(nome, data, ora);
	s->addVoce("Acqua", 1);
	s->addVoce("Vino", 2.3);
	cout << s->stampa(); 
	cout << "====================\ntotale :" << s->getTotale();
	return 0;
}
