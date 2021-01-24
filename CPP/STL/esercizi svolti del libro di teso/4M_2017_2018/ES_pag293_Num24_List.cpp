/* ES. num.24 pag.293
Da tastiera si inserisce un elenco di numeri, memorizzandoli in una
lista bidirezionale: se il numero è pari viene inserito all inizio,
altrimenti alla fine. Visualizzare poi i numeri inseriti prima in
ordine di inserimento e poi in ordine crescente.
*/
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list <int> l;
	int d;
// inserimento componenti
	cout<< "Numero (0=fine): ";
	cin >> d;
//aggiunge i componenti della lista
	while (d != 0) {
		if(d%2==0) l.push_back(d);
		else l.push_front(d);
		cout << "Altro numero (0=fine): ";
		cin >> d;
	}
//	visualizzazione mediante iteratore in ordine di inserimento
	list<int>::iterator iter ;
	cout<<"la lista inserita \x8a: "<<endl;
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter <<endl;
//	visualizzazione in ordine crescente
	l.sort();
	cout<<"la lista ordinata in ordine crescente \x8a: "<<endl;
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter <<endl;
	system("pause");
	return 0;
}
