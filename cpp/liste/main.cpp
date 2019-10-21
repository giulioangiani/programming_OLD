#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
    int content;
    nodo* next;
};

typedef nodo* node_ptr;

node_ptr root;
node_ptr q;
node_ptr ord, rnd;


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

int main()
{

    cout << "============== IN TESTA =======\n";
    print_list(root);
    in_testa(10, root);
    print_list(root);
    in_testa(15, root);
    print_list(root);
    in_testa(30, root);
    print_list(root);

    cout << "============== IN CODA =====\n";
    print_list(q);
    in_coda(5, q);
    print_list(q);
    in_coda(15, q);
    print_list(q);
    in_coda(25, q);
    print_list(q);

    cout << "============== IN ORDINE =======\n";
    in_ordine(5, ord);
    print_list(ord);
    in_ordine(3, ord);
    print_list(ord);
    in_ordine(1, ord);
    print_list(ord);
    in_ordine(4, ord);
    print_list(ord);
    in_ordine(16, ord);
    print_list(ord);
    in_ordine(8, ord);
    print_list(ord);
    in_ordine(-10, ord);
    print_list(ord);
    in_ordine(-7, ord);
    print_list(ord);
    in_ordine(23, ord);
    print_list(ord);
    in_ordine(10, ord);
    print_list(ord);


    cout << "============== RANDOM =======\n";
    /* initialize random seed: */
    srand (time(NULL));
    for (int i=0; i<30; i++) {
        int n = rand() % 100 + 1;
        cout << "\nEstratto " << n << "\n";
        in_ordine(n, rnd);
        print_list(rnd);

    }



    return 0;
}

