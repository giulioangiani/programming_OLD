/*
Scrivere una funzione template "esiste" che prende in ingresso un puntatore P ad una lista il cui campo informazione è di tipo T, ed un elemento E di tipo T
e restituisce VERO se l'elemento E è presente nella lista puntata da P, FALSO altrimenti
Scrivere anche un main di test, utilizzando le funzioni template già viste a lezione per creare la lista di elementi, e testare la funzione appena creata con  almeno 3 tipi di dato diversi e con il tipo dato
struct punto {
      float x,
      float y
}

che rappresenta un punto nel piano cartesiano
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


// PUNTO

struct punto {
    float x;
    float y;

    /*
    bool operator==(const punto& p2) {
        return ((this->x == p2.x) && (this->y == p2.y));
    }
    */

};

bool operator==(const punto& p1, const punto& p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y));
}


int main()
{
    nodo<int>* pint = nullptr;
    cout << "esiste 30 : " << esiste(pint, 30) << endl;
    cout << "esiste 25 : " << esiste(pint, 25) << endl;
    intesta(pint, 10);
    intesta(pint, 20);
    intesta(pint, 30);
    intesta(pint, 40);
    cout << "esiste 30 : " << esiste(pint, 30) << endl;
    cout << "esiste 25 : " << esiste(pint, 25) << endl;


    nodo<double>* pflo = nullptr;
    cout << "esiste 3.0 : " << esiste(pflo, 3.0) << endl;
    cout << "esiste 2.5 : " << esiste(pflo, 2.5) << endl;
    intesta(pflo, 1.0);
    intesta(pflo, 2.0);
    intesta(pflo, 3.0);
    intesta(pflo, 4.0);
    cout << "esiste 3.0 : " << esiste(pflo, 3.0) << endl;
    cout << "esiste 2.5 : " << esiste(pflo, 2.5) << endl;

    nodo<string>* pstr = nullptr;
    cout << "esiste uno : " << esiste(pstr, (string)"uno") << endl;
    cout << "esiste tre : " << esiste(pstr, (string)"tre") << endl;
    intesta(pstr, (string)"uno");
    intesta(pstr, (string)"due");
    intesta(pstr, (string)"tre");
    intesta(pstr, (string)"quattro");
    cout << "esiste uno : " << esiste(pstr, (string)"uno") << endl;
    cout << "esiste tre : " << esiste(pstr, (string)"tre") << endl;


    nodo<punto>* ppunto = nullptr;
    punto p1 {1.5, 2.5};
    punto p2 {0.0, 1.2};
    punto p3 {3.0, 2.0};
    punto p4 {1.0, 3.5};
    cout << "esiste p1 : " << esiste(ppunto, p1) << endl;
    cout << "esiste p4 : " << esiste(ppunto, p4) << endl;
    intesta(ppunto, p1);
    intesta(ppunto, p2);
    intesta(ppunto, p3);
    cout << "esiste p1 : " << esiste(ppunto, p1) << endl;
    cout << "esiste p4 : " << esiste(ppunto, p4) << endl;


    return 0;
}
