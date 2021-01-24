#include <iostream>


using namespace std;

struct nodo {
    int content;
    nodo* next;
    nodo* prec;
};

typedef nodo* node_ptr;
node_ptr start = nullptr;
node_ptr last = nullptr;

void stampalista(node_ptr p) {
    std::cout << "LIST: ";
    while (p) {
        std::cout << p->content << " ";
        p = p->next;
        }
    std::cout << std::endl;
}

void stampainversa(node_ptr p) {
    std::cout << "LIST: ";
    while (p) {
        std::cout << p->content << " ";
        p = p->prec;
        }
    std::cout << std::endl;
}

void in_coda(int elem) {
    // inserisce in testa
    if (!start) {
        // first element
        start = new nodo();
        start->content = elem;
        start->next = NULL;
        start->prec = NULL;
        last = start;
    }
    else {
        // agisco sull'ultimo elemento tramite il puntore last
        last->next = new nodo();
        last->next->content = elem;
        last->next->next = NULL;
        last->next->prec = last;
        last = last->next;
    }
}


int main()
{
    stampalista(start);
    in_coda(10);
    stampalista(start);
    in_coda(20);
    in_coda(30);
    in_coda(40);
    stampalista(start);
    stampainversa(last);
    return 0;
}
