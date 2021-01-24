// OrdinaVettore.cpp: uso di sort con contenitore
// vector per termini
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// funzione principale
int main()
{
	vector<string> termini;
	string t;
// inserimento termini
	cout << "Termine (*=fine): ";
	cin >> t;
	while (t != "*") {
		termini.push_back(t);
		cout << "Altro termine (*=fine): ";
		cin >> t;
	}
// ordinamento alfabetico
	sort(termini.begin(), termini.end());
// elenco ordinato
	vector<string>::iterator i;
	for (i=termini.begin(); i!=termini.end(); i++)
		cout << *i << endl;
	return 0;
}
