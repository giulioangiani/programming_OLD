// CVettoreConta.cpp: contenitore vector e algoritmo count
/*
	Es.pag.293 num.29
	Dato un vettore contenente l elenco dei comuni di provenienza 
	degli studenti di una classe, contare quante volte compare il
	nome di un comune richiesto dall utente.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// funzione principale
int main()
{
	vector<string> elenco;
	string comune;
	// inserimento componenti
	cout << "Quale comune (*=fine): ";
	cin >> comune;
	while (comune != "*") {
		elenco.push_back(comune);
		cout << "Altro comune (*=fine): ";
		cin >> comune;
	}
	// conteggio del comune richiesto
	string cercato;
	cout << "comune da contare: ";
	cin >> cercato;
	cout << "Risultato conteggio = "
		<< count(elenco.begin(), elenco.end(), cercato)
		<< endl;
	return 0;
}
