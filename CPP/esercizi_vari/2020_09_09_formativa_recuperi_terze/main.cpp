/*
Creare un file di testo chiamato "input.txt"
che contiene 5 numeri interi

3
4
12
4
5

Creo un programma che legge il file di testo
e costruisce una lista dinamiche con i valori presenti nel file

Chiede all'utente un numero da cercare in lista

Con un procedura ricorsiva "cercaric(nodo*, int) => boolean"
stampare a video se il numero è presente o no

*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo {
    int info;
    nodo* next;
};

void intesta(nodo* &p, int x) {
    nodo* tmp = new nodo;
    tmp->info = x;
    tmp->next = p;
    p = tmp;
}

bool cercaric(nodo* p, int n) {
    if (!p) return false;
    if (p->info == n) return true;
    return cercaric(p->next, n);
}

int main()
{
    nodo* piniz = nullptr;
    ifstream fin;
    fin.open("input.txt");
    int n;
    while (!fin.eof()) {
        fin >> n;
        cout << n << endl;
        intesta(piniz, n);
    }
    fin.close();

    cout << "Che numero vuoi cercare ? ";
    cin >> n;
    if (cercaric(piniz, n)) cout << " Trovato ";
    else cout << "Non trovato";

    return 0;
}
