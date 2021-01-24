#include <iostream>
#include <map>
#include <windows.h>
using namespace std;

void Inserimento(int &index,string nome_citta,map<int,string>&mappa)
{
	cout<<"Inserire il cap(0 per terminare): ";
	cin>>index;
			
	if(index!=0)
	{
		cout<<"Inserire la citta': ";
		cin>>nome_citta;
			
		cout<<endl;
				
		mappa[index]=nome_citta;
	}
}

void Primo_caso(string citta_incognito,bool trovato,map<int,string> mappa)
{
	map<int,string>::iterator i;
	
	cout<<"Inserire la citta' da cercare: ";
	cin>>citta_incognito;
			
	for(i=mappa.begin();i!=mappa.end();i++)
	{
		if(i->second==citta_incognito)
		{
			trovato=true;
			cout<<"il cap e' "<<i->first<<endl;
		}
	}
	cout<<endl;
	
	if(trovato==false)
	{
		cout<<"Cap non trovato"<<endl;
	}
}

void Secondo_caso(int cap_incognito,bool trovato,map<int,string> mappa)
{
	map<int,string>::iterator i;
	
	cout<<"Inserire il cap da cercare: ";
	cin>>cap_incognito;

	for(i=mappa.begin();i!=mappa.end();i++)
	{
		if(i->first==cap_incognito)
		{
			trovato=true;
			cout<<"la citta' e' "<<i->second<<endl;
		}
	}
	cout<<endl;
	
	if(trovato==false)
	{
		cout<<"citta' non trovata"<<endl;
	}
}

int main()
{
	map<int,string> mappa;
	//map<int,string>::iterator i;
	int index,x,cap_incognito,y;
	string nome_citta,citta_incognito;
	bool trovato;
	
	do
	{
		do
		{
			Inserimento(index,nome_citta,mappa);
		}
		while(index!=0);
		cout<<endl;
		
		cout<<"Inserire 1 per trovare la citta, 0 per il cap : ";
		cin>>y;
		
		cout<<endl;
		
		switch(y)
		{
			case(1):
			{
				Primo_caso(citta_incognito,trovato,mappa);
				
				break;
			}
			
			case(0):
			{
				Secondo_caso(cap_incognito,trovato,mappa);
				
				break;
			}
			
			default:
			{
				cout<<"Processo di individuazione non eseguito"<<endl;
			}
	    }

		cout<<"Inserire 1 per ripetere la procedura: ";
	    cin>>x;
	    cout<<endl;
		
		if(x==1)
	    {
			cout<<"Premere invio per continuare: ";
			cin.get();
			cin.ignore();
			system("cls");
			
			mappa.clear();
			trovato=false;
	    }
	}
	while(x==1); 

	return 0;
	
}

