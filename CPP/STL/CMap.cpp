// CMap.cpp: contenitore map
#include <iostream>
#include <map>
#include <string>
using namespace std;
// funzione principale
int main()
{
	map<int, string> note;
	int freq;
	string nomenota;
	// inserimento note
	cout << "Frequenza della nota (0=fine): ";
	cin >> freq;
	while (freq != 0) {
		cout << "Nome della nota: ";
		cin >> nomenota;
		note[freq] = nomenota;
		cout << "Frequenza della nota (0=fine): ";
		cin >> freq;
	}
	// visualizza le note: prima il nome, poi la frequenza
	map<int, string>::iterator i;
	for (i = note.begin(); i != note.end(); i++)
		cout << i->second << ": " << i->first << " Hz" << endl;
	return 0;
}