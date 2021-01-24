// CMap_Dizionario.cpp: traduzione di parole 
// con contenitore map
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> dizionario; // contenitore per le parole

// prototipi delle funzioni
void CaricaDizionario();
void Trova();

// funzione principale
int main()
{
	CaricaDizionario();
	Trova();
	return 0;
}





// caricamento del dizionario
void CaricaDizionario()
{
	string parola, traduz;
	cout << "---------------------" << endl;
	cout << "Carica il dizionario" << endl;
	cout << "Parola italiana (* = fine): ";
	cin >> parola;
	while (parola != "*") {
		cout << "Traduzione: ";
		cin >> traduz;
		dizionario[parola] = traduz;
		cout << "Parola italiana (* = fine): ";
		cin >> parola;
	}
} // CaricaDizionario




// cerca la parola nel dizionario
void Trova ()
{
	string vocabolo; // termine da ricercare
	string tradotto;
	map<string, string>::iterator p; // iteratore
	cout << "---------------------" << endl;
	cout << "Ricerca nel dizionario" << endl;
	cout << "Parola da cercare (* = fine): ";
	cin >> vocabolo;
	while (vocabolo != "*") {
		p = dizionario.find(vocabolo);
		if (p != dizionario.end())
			cout << "Traduzione: " << p->second << endl;
		else
			cout << "Termine non trovato" << endl;
		cout << "Altra parola da cercare (* = fine): ";
		cin >> vocabolo;
	}
} // Trova
