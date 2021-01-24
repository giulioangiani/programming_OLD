#include <iostream>
#include <assert.h>

using namespace std;

/*
Esercizio 1 (8 punti)
Scrivere una funzione che riceve in ingresso tre valori float: value, threshold
e epsilon. La funzione deve restituire valore true se la differenza in valore
assoluto tra value e threshold `e inferiore a epsilon, e valore false viceversa.
*/

bool calculate(float value, float threshold, float epsilon) {
  assert(epsilon > 0); // assumo epsilon positivo sempre
  return abs(value-threshold) < epsilon;
}

int main()
{
  float v, t, e;
  cout << "Inserisci il value :";
  cin >> v;
  cout << "Inserisci il threshold :";
  cin >> t;
  cout << "Inserisci epsilon :";
  cin >> e;
  cout << "risultato soglia: " << calculate(v,t,e);
  return 0;
}
