/*
24) da tastiera si inserisce un elenco di numero memorizzandoli in in una lista bidirezionale : se è pari inserire all'inizio, altrimenti alla fine
visualizzare poi i numeri inseriti prima in ordine di inserimento poi in ordine crescente

*/
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void getInt(list<int>&, list<int>&, list<int>::iterator, bool);
void setInt(list<int>&, list<int>&, list<int>::iterator);

int main()
{
	
	list<int> lista; 
	list<int> listaR;
	list<int>::iterator i;
	bool order;
	
	setInt(lista, listaR, i);
	order = true;
	getInt(lista, listaR, i, order);
	order = false;
	getInt(lista, listaR, i, order);
	
	return 0;
}

void setInt(list<int>& lista, list<int>& listaR, list<int>::iterator i) {
	
	int n = 1;
	
	while(n!=0) {
		cout<<"Inserisci numero (0 per terminare): "<<endl;
		cin>>n;
		listaR.push_back(n);
		if(n%2!=0) {
			lista.push_front(n);
		} 
		else {
			lista.push_back(n);
		}
		
	}
	
}

void getInt(list<int>& lista, list<int>& listaR, list<int>::iterator i, bool order) {

	if (!order) {
		cout<<"------------------Visualizzazione in ordine di inserimento----------------------"<<endl;
		for (i=listaR.begin(); i!=listaR.end(); i++) {
			cout<<*i<<endl;
		}
	}
	else {
		cout<<"------------------Visualizzazione ordinata--------------------------------------"<<endl;
		lista.erase(remove(lista.begin(), lista.end(), 0), lista.end());
		lista.sort();
		for (i=lista.begin(); i!=lista.end(); i++) {
			cout<<*i<<endl;
		}
	}
	
	listaR.erase(remove(listaR.begin(), listaR.end(), 0), listaR.end());
	
}
