#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
    int content;
    nodo* next;
};

typedef nodo* node_ptr;


void print_list(node_ptr p) {
    cout << "LIST: ";
    while (p) {
        cout << p->content << " ";
        p = p->next;
    }
    cout << endl;
}

void in_testa(int v, node_ptr& p) {
    cout << "in testa \n";
    // inserisce in testa
    if (!p) {
    //    printf("primo\n");
        p = new nodo();
        p->content = v;
        p->next = NULL;
    }
    else {
    //    printf("altro elemento\n");
        node_ptr tmp = new nodo();
        tmp->content = v;
        tmp->next = p;
        p = tmp;

    }
}

void in_coda(int v, node_ptr& p) {
    cout << "in coda  \n";
    if (!p) in_testa(v, p);
    else {
        node_ptr tmp = p;
        // cerco l'ultimo
        while (tmp->next) {
            tmp = tmp->next;
        }
        node_ptr nuovo = new nodo();
        nuovo->next = NULL;
        nuovo->content = v;
        tmp->next = nuovo;
    }
}


void in_ordine(int v, node_ptr& p) {
    if ((!p) || (p->content > v)) {
        in_testa(v, p);
    }
    else {
        node_ptr tmp = p;
        // cerco il primo maggiore di v
        while (tmp && tmp->content < v) {
            tmp = tmp->next;
        }
     //   cout << "trovato" << tmp << endl;
        if (!tmp) {
            in_coda(v, p);
        }

        else {
        //    cout << "trovato elem : " << tmp->content << endl;
        //    cout << "trovato elem->next : " << tmp->next << endl;
            node_ptr nuovo = new nodo();
            nuovo->next = tmp;
            nuovo->content = v;

            // riparto dall'inizio per modificare il puntatore dell'elemento precedente al nuovo nodo
            node_ptr start_tmp = p;
            while (start_tmp->next != tmp) start_tmp = start_tmp->next;
            start_tmp->next = nuovo;

        }
    }
}
