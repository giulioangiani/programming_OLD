/*
Scrivere una funzione template "esiste" che prende in ingresso un puntatore P
ad una lista il cui campo informazione è di tipo T, ed un elemento E di tipo T
e restituisce VERO se l'elemento E è presente nella lista puntata da P, FALSO altrimenti


Scrivere una funzione template "minore" che prende in ingresso un puntatore P
ad una lista il cui campo informazione è di tipo T, e restituisce un puntatore al nodo
minore presente nella lista (restituisce nullptr se la lista è vuota)

Le funzioni devono poter essere invocate con il tipo dato studente definito nel codice

*/

#include <iostream>

using namespace std;

template <class T>
struct nodo {
    T info;
    nodo<T>* next;
};

template <typename T>
void intesta(nodo<T>* &p, T x) {
    nodo<T>* tmp = new nodo<T>;
    tmp->info = x;
    tmp->next = p;
    p = tmp;
}

template <typename T>
bool esiste(nodo<T>* p, T element) {
    if (!p) return false;
    if (p->info == element) return true;
    return esiste(p->next, element);
}


template <typename T>
nodo<T>* minore(nodo<T>* p) {
    if (!p) return nullptr;
    return p->next;
}
// DATA
struct data {
    int anno;
    int mese;
    int giorno;
};

// CLASSESCUOLA
struct classescuola {
    char sezione;
    int classe;
    string indirizzo;
};

// STUDENTE
struct studente {
    string nome;
    string cognome;
    data datanascita;
    classescuola classe;
};



int main()
{

    nodo<studente>* p = nullptr;

    studente s1 { "mara", "maldo", {2001, 4, 5}, {'C', 4, "INFO"} };
    studente s2 { "rosa", "spina", {2002, 1, 25}, {'D', 4, "INFO"} };
    studente s3 { "lino", "mando", {2002, 4, 7}, {'C', 4, "INFO"} };
    intesta(p, s1);
    intesta(p, s2);
    intesta(p, s3);

    nodo<studente>* giovane = nullptr;
    giovane = minore(p);
    cout << giovane->info << endl;

    // OUTPUT ATTESO
    /*
        lino mando , 2002/4/7 , 4C INFO

    */

    return 0;
}
