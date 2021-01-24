/* Es31pag293.cpp : dato l'elenco dei cognomi degli studenti di 1A e quelli degli studenti di 1B,
 memorizzare in un unico vettore l'elenco alfabetico degli studenti delle due classi. */

//problemi!

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int i=0;

void carica(vector<string>& p,char pcl)
{
	string com,risp;
	
	pcl=toupper(pcl);
	do {
		system("cls");
		cout<<"inserisci cognome classe 1"<<pcl<<": ";
		getline(cin,com);
		p.push_back(com);
		
		cout<<"vuoi inserirne un altro? (s-n) ";
		getline(cin,risp);
		while(toupper(risp[0])!='S' && toupper(risp[0])!='N')
		{
			cout<<"errore! vuoi inserirne un altro? (s-n) ";
			getline(cin,risp);
		}
	} while(toupper(risp[0])!='N');
}

void visualizza(vector<string>& p)
{
 	for(i=0;i<p.size();i++) cout<<p[i]<<"\n";	
}

int main ()
{
	vector <string> a;
	vector<string>::iterator ait;
	vector <string> b;
	vector<string>::iterator bit;
	vector <string> ab(4);
	char cl=0;
		
	cl='a';
	carica(a,cl);
	cl='b';
	carica(b,cl);
	
	//ab.reserve(a.size()+b.size());
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	visualizza(a);
	cout<<"\n\n";
	visualizza(b);
	cout<<"\n\n";		
	merge(ait=a.begin(),ait=a.end(),bit=b.begin(),bit=b.end(),ab.begin());
	cout<<ab[0]<<"\n";
	
	/cout<<"--- elenco cognomi ---\n";
	for(i=0;i<ab.size();i++) cout<<ab[i]<<"\n"; //vuoto
	cout<<"----------------------\n";
		
	_getch();
	return 0;
}
