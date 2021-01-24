#include "persona.cpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<Persona> vp;

    int n;
    cout << "Inserisci il numero di persone: ";
    cin >> n;
    
    string nome, cognome;
    int anno;
    

    for (int i = 0; i < n; i++){
        cout << "Inserisci il nome della persona " << i + 1 << " : ";
        cin >> nome;
        cout << "Inserisci il cognome della persona " << i + 1 << " : ";
        cin >> cognome;
        cout << "Inserisci l'anno di nascità della persona " << i + 1 << " : ";
        cin >> anno;
        Persona p = Persona(nome, cognome, anno);
        vp.push_back(p);
    }
    
    //grazie ad algorithm (ordina in senso decrescente dall'inizio alla fine)
    // posso farlo perchè ho ridefinito operator< per la classe Persona
    sort(vp.begin(), vp.end());	
    
    // il più giovane è il primo della lista vp.at(0)
    // posso farlo perchè ho ridefinito operator<< per oggetti di tipo Persona
    cout << "Piu' giovane " << vp.at(0) << endl;	

	
	// soluzione naif con ciclo
	string cognomepiugiovane = "";
	int annominore = 9999;
    for (Persona p : vp){
        if (p.getAnno() < annominore) {
			annominore = p.getAnno();
			cognomepiugiovane = p.getCognome();
		}
    }
    cout << "Piu' giovane " << cognomepiugiovane << " anno " << annominore <<  endl;	

}
