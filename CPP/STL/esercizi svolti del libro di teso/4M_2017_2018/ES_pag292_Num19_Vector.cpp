/*ES.19 pag.292 libro di testo
Dopo aver inserito da tastiera un elenco di numeri float, 
memorizzandoli in un vettore, visualizzare quelli che sono superiori
ad una cifra fornita dall' utente
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <float> v;
	char fineElenco='N';
	float numero;
	bool trovato;
	while(fineElenco !='S')
	{
		//ottimizzazione: controllo inserimento numero e non carattere
		cout<<"inserisci il numero "<<endl;
		cin>>numero;
		v.push_back(numero);
		cout<<"elenco finito? S/N"<<endl;
		cin>>fineElenco;
		fineElenco=toupper(fineElenco);
		while(fineElenco!='S' && fineElenco!='N')
			{
				cout<<"\n Errore...elenco finito? (S/N)?";
				cin>>fineElenco;
				fineElenco=toupper(fineElenco);
					}	
	}	
	//ottimizzazione: controllo inserimento numero e non carattere
	cout<<"inserisci il numero per il confronto "<<endl;
	cin>>numero;
	cout<<"gli elementi maggiori di "<<numero<<" sono: "<<endl;
	for (int i = 0; i < v.size(); i++)
		if(v.at(i)>numero)
		{
			cout<<v.at(i) << endl;   //cout << v[i] << endl;
			trovato=true;
		}
		else trovato=false;
	if(trovato==false)
		cout<<"nessun numero "<<endl;			
	system("pause");
	return 0;
}
