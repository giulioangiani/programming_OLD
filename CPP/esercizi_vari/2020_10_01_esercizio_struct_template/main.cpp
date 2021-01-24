/*
Creare un file di testo chiamato "input.txt"
che contiene 4 righe
In ogni riga è presente un numero di matricola ed il cognome di uno studente

10021 Rossi
29929 Franchi
87123 Secchi
17711 Zoppi

Creare una struct studente per mantenere i dati presenti nel file

Creare un programma che legge il file di testo
e costruisce una lista dinamica con i valori presenti nel file

Chiede all'utente un numero di matricola da cercare in lista

Creare una procedura ricorsiva "cerca(nodo*, int) => studente*"
che riceve il puntatore alla lista ed il numero di matricola da trovare
e restituisca al chiamante il puntatore al nodo se trovato, NULL altrimenti

*/
#include <iostream>
#include <fstream>
using namespace std;

struct studente {
    int matricola;
    string cognome;
};

struct nodo {
    studente info;
    nodo* next;
};
ostream&

void intesta(nodo* &p, studente x) {
    nodo* tmp = new nodo;
    tmp->info = x;
    tmp->next = p;
    p = tmp;
}

nodo* cercaric(nodo* p, int matricola) {
    if (!p) return nullptr;
    if (p->info.matricola == matricola) return p;
    return cercaric(p->next, matricola);
}

int main()
{
    nodo* piniz = nullptr;
    ifstream fin;
    fin.open("input.txt");
    int matricola;
    string cognome;
    while (!fin.eof()) {
        fin >> matricola;
        fin >> cognome;
        if (cognome!="") {
            cout << matricola << ":" << cognome << endl;
            studente s {matricola, cognome};
            intesta(piniz, s);
        }
        cognome="";
    }
    fin.close();

    cout << "Che matricola vuoi cercare ? ";
    cin >> matricola;
    nodo* finder = cercaric(piniz, matricola);
    if (finder) cout << " Trovato " << finder->info;
    else cout << "Non trovato";

    return 0;
}
