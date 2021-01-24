// CVettore.cpp: contenitore vector
#include <iostream>
#include <vector>
using namespace std;
// funzione principale
int main()
{
vector<int> v;
int d;
// inserimento componenti
cout << "Numero (0=fine): ";
cin >> d;
//aggiunge in CODA alle componenti del vettore già presenti
while (d != 0) {
v.push_back(d);
cout << "Altro numero (0=fine): ";
cin >> d;
}
// visualizza componenti
for (int i=0; i<v.size(); i++)
cout << v[i] << endl;
return 0;
}
