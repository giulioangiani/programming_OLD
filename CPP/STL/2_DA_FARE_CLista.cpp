// CLista.cpp: contenitore list
#include <iostream>
#include <list>
#include <string>
using namespace std;
// funzione principale
int main()
{
	list<string> elenco;
	string nome;
// inserimento componenti
	cout << "Nome (*=fine): ";
	cin >> nome;
	while (nome != "*") {
		elenco.push_back(nome);
		cout << "Altro nome (*=fine): ";
		cin >> nome;
	}
//attivazione iteratore	
	list<string>::iterator i;
	elenco.sort();
	for (i=elenco.begin(); i!=elenco.end(); i++)
		cout << *i << endl;
	elenco.reverse();
	for (i=elenco.begin(); i!=elenco.end(); i++)
		cout << *i << endl;
	return 0;
}
