// CVettoreConta.cpp: contenitore vector e algoritmo count
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// funzione principale
int main()
{
	vector<string> elenco;
	string specie;
	// inserimento componenti
	cout << "Quale specie (*=fine): ";
	cin >> specie;
	while (specie != "*") {
		elenco.push_back(specie);
		cout << "Altra specie (*=fine): ";
		cin >> specie;
	}
	// conteggio della specie richiesta
	string cercata;
	cout << "Specie da contare: ";
	cin >> cercata;
	cout << "Risultato conteggio = "
		<< count(elenco.begin(), elenco.end(), cercata)
		<< endl;
	return 0;
}