/*
Es 27 pagina 293
*/
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
//Prototipi delle funzioni
void inputMappa(map<int, int>&);
void calcolaMedia(map<int, int>);
int main()
{
	map<int, int> elenco;
	inputMappa(elenco);
	calcolaMedia(elenco);
	system("pause");
	return(0);
}
void inputMappa(map<int, int>&elenco)
{
	int anno, numero;
	cout<<"Inserisci l'anno(0 per terminare): ";
	cin>>anno;
	if(elenco.find(anno)!=elenco.end())
	{
		cout<<"Anno gia' inserito, reinserisci: ";
		cin>>anno;
	}
	while(anno!=0)
	{
		cout<<"Inserisci il numero: ";
		cin>>numero;
		elenco[anno]=numero;
		cout<<"Inserisci l'anno(0 per terminare): ";
		cin>>anno;
		if(elenco.find(anno)!=elenco.end())
		{
			cout<<"Anno già inserito, reinserisci: ";
			cin>>anno;
		}
	}
}
void calcolaMedia(map<int, int> elenco)
{
	float m=0;
	map<int, int>::iterator i;
	for(i=elenco.begin(); i!=elenco.end(); i++)
	{
		m+=i->second;
	}	
	cout<<"La media dei valori e' "<<m/elenco.size()<<endl;
}





