// CVettoreStringhe.cpp: contenitore vector di stringhe
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T> void Stampa(vector<T> v)
{
	typename vector<T>::iterator p;
	cout << "Visualizzazione componenti del vettore:" << endl;
	for (p = v.begin(); p != v.end(); p++)
		cout << *p << endl;
	cout << endl;
}

// funzione principale
int main()
{
	vector<string> prov;
	string sigla;
// inserimento componenti
	cout << "Sigla provincia (*=fine): ";
	cin >> sigla;
	while (sigla != "*") {
		prov.push_back(sigla);
		cout << "Altra provincia (*=fine): ";
		cin >> sigla;
	}
	Stampa(prov);
	return 0;
}
