/* ES. num.20 pag.292
Acquisire da tastiera un elenco di parole, memorizzandole 
in un vettore, finchè l'utente segnala alla fine il numerodelle parole
memorizzate utilizzando il metodo opportuno del template vector.
Successivamente, dopo aver eliminato tutte le parole dal vettore, 
controllare che il vettore sia vuoto.
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string parola;
	vector<string> v;
	cout<<"inserisci una parola "<<endl;
	cin>>parola;
	while(parola!="*")
	{
		v.push_back(parola);
		cout<<"inserisci una parola "<<endl;
		cin>>parola;
	}
	cout<<"il numero di parole inserite \x8a: "<<v.size()<<endl;
	v.clear();
	cout<<"dimensione vettore dopo cancellazione "<<v.size()<<endl;
	system("pause");
	return 0;
}
