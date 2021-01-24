#include <iostream>

struct nodo {
    int content;
    nodo* next;
    nodo* prec;
};

typedef nodo* node_ptr;

void stampalista(node_ptr p) {
    std::cout << "LIST: ";
    while (p) {
        std::cout << p->content << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
