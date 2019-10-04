#include <iostream>
#include <vector>
using namespace std;

struct nodo {
    int content;
    nodo* dx;
    nodo* sx;
};

typedef nodo* node_ptr;

node_ptr root;

int deep(node_ptr p) {
    if (p==NULL) return 0;
    else return max(1+deep(p->sx), 1+deep(p->dx));
}

node_ptr insBilanciato(node_ptr p, int val) {

    if (p == NULL) {
    //    cout << " ---> inserisco " << val << endl;
        p = new nodo();
        p->content = val;
        p->dx = p->sx = NULL;
    }
    else {
    //    cout << val << " sx " << deep(p->sx) << " -- dx " << deep(p->dx) << endl;
        if (deep(p->dx) >= deep(p->sx)) {
            // inserisco a sinistra
    //        cout << " vado a SX\n";
            p->sx = insBilanciato(p->sx, val);
        }
        else {
            // inserisco a destra
    //        cout << " vado a DX\n";
            p->dx = insBilanciato(p->dx, val);
        }
    }
    return p;
}

int sommaValori(node_ptr p) {
    // insert here you code!
    // write a function which gets a pointer as input and
    // returns the sum of all values of tree nodes
    if (!p) return 0;
    else return p->content + sommaValori(p->sx) + sommaValori(p->dx);
    return 0;
}



void nienteFoglie(node_ptr p) {
    // insert here you code!
    // write a function which prints out only internal nodes pre-ordereded values
    if (!p) return;
    if (p->dx || p->sx) {
        cout << p->content << " ";
    }
    nienteFoglie(p->sx);
    nienteFoglie(p->dx);
}

void stampaLivello(node_ptr p, int start_level, int print_level) {
    if (start_level > print_level) return;
    if (start_level == print_level) {
        if (p) cout << p->content << " ";
    }
    else {
        stampaLivello(p->sx, start_level+1, print_level);
        stampaLivello(p->dx, start_level+1, print_level);
    }
}

int main()
{

    root = insBilanciato(root, 10);
    root = insBilanciato(root, 5);
    root = insBilanciato(root, 15);
    root = insBilanciato(root, 3);
    root = insBilanciato(root, 12);
    root = insBilanciato(root, 7);
    root = insBilanciato(root, 1);
    root = insBilanciato(root, 20);
    root = insBilanciato(root, 11);

    cout << sommaValori(root) << endl;
    nienteFoglie(root); cout  << endl;
    stampaLivello(root, 0, 2); // it should print "3 7 12 20 "
    return 0;
}

