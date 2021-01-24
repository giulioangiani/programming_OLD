#include <iostream>

using namespace std;

template<class T>
struct nodo
{
    T info;
    nodo<T>* next;
};


template<typename T>
void inTesta(nodo<T>* &p, T elem) {

    nodo<T>* tmp = new nodo<T>;
    tmp->info = elem;
    tmp->next = p;
    p = tmp;
}


template<typename T>
void leggi(nodo<T>* p) {
    while(p) {
        cout << p->info << " ";
        p = p->next;
    }
}


nodo<int>* intptr;
nodo<string>* strptr;

int main()
{
    // inizializzazione
    intptr = nullptr;
    inTesta(intptr, 10);
    inTesta(intptr, 20);
    leggi(intptr);

    strptr = nullptr;
    inTesta(strptr, (string)"molto");
    inTesta(strptr, (string)"figo");
    leggi(strptr);
}
