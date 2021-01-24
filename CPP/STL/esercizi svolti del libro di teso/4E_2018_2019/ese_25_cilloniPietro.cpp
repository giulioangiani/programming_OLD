//esercizio25.cpp

#include<iostream>
#include<map>
#include<string>

using namespace std;
void inserimentoMap(map<string, string>&);
void visuaMap(map<string, string>,string);
int main()
{
	map<string, string>rubrica;
	string nome;
	string numero;
	string cercaNome;
	inserimentoMap(rubrica);
	cout<<"inserisci il nome del contatto da cercare (premi * per terminare) : "<<endl;
	cin>>cercaNome;
	visuaMap(rubrica,cercaNome);
	return 0;
}
void inserimentoMap(map<string, string>&rubrica)
{
	string nome;
	string numero;
	cout<<"inserisci il nome del contatto : "<<endl;
	cin>>nome;
	while(nome!="*")
	{
		cout<<"inserisci il numero del contatto : "<<endl;
		cin>>numero;
		rubrica[nome]=numero;
		cout<<"inserisci il nome del contatto : (premi * per terminare) "<<endl;
		cin>>nome;
	}
}
void visuaMap(map<string, string>rubrica,string pcercaNome)
{
	while(pcercaNome!="*")
	{
		map<string, string>::iterator i;
		i=rubrica.find(pcercaNome);
		if(i!=rubrica.end())
		{
			cout<<"il numero di "<< i->first <<" e'"<< i->second<<endl;
		}
		cout<<"inserisci il nome del contatto da cercare (premi * per terminare) : "<<endl;
		cin>>pcercaNome;
	}
}







