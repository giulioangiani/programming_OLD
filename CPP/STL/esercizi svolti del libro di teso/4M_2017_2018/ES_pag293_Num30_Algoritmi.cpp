/* ES. num.30 pag.293
Dato un vettore di numeri, memorizzare per ciascun numero in un
altro vettore il doppio del numero se è minore di 100, 
il triplo se è maggiore o uguale.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v1, v2;
void caricaVettore()
{
	int d;
// inserimento componenti
	cout<< "Numero (0=fine): ";
	cin >> d;
//aggiunge i componenti del vettore
	while (d != 0) {
		v1.push_back(d);
		cout << "Altro numero (0=fine): ";
		cin >> d;
	}
}
	
void creaVettore( int num)
{
			if(num<100) v2.push_back(2*num);
			else v2.push_back(3*num);	
}	
void visualizza()
{
	vector<int>::iterator i ;
	cout<<"il vettore creato \x8a: "<<endl;
	for (i= v2.begin(); i!= v2.end(); i++)
		cout << *i <<endl;
}
int main()
{
	caricaVettore();
	for_each(v1.begin(),v1.end(),creaVettore);
	visualizza();
	system("pause");
	return 0;
}	

