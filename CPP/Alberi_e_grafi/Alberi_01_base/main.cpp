/*
 * Albero binario generico
 *
 * */
#include <iostream>
#include <queue>

using namespace std;

struct nodo {
    int content;
    nodo* dx;
    nodo* sx;
};
typedef nodo* node_ptr;
node_ptr root = nullptr;

void visita(node_ptr p);
void insElement(node_ptr &p, int val) {
    p = new nodo();
    p->content = val;
    p->dx = nullptr;
    p->sx = nullptr;
}


int profondita(node_ptr p) {
    // restituisce la profondità dell'albero puntato da p
    if (!p) return -1;
    int ps = 1+profondita(p->sx);
    int pd = 1+profondita(p->dx);
    return max(ps, pd);
}


int minimo(node_ptr p) {
    // restituisce in valore minimo fra quelli contenuti nell'albero puntato da p
    if (!p) return 999999999;
    int ms = minimo(p->sx);
    int md = minimo(p->dx);
    return min(p->content, min(ms, md));
}

int massimo(node_ptr p) {
    // restituisce in valore massimo fra quelli contenuti nell'albero puntato da p
    if (!p) return -1;
    int ms = massimo(p->sx);
    int md = massimo(p->dx);
    return max(p->content, max(ms, md));
}

void insBilanciato(node_ptr& p, int n) {
    if (p==nullptr) {
        p = new nodo();
        p->content = n;
        p->dx = nullptr;
        p->sx = nullptr;
    }
    else {
        if (profondita(p->sx) > profondita(p->dx)) {
            insBilanciato(p->dx, n);
        }
        else {
            insBilanciato(p->sx, n);
        }
    }
}

void inorder(node_ptr p) {   // preorder =>
    if (p) {    // se p non è null
        inorder(p->sx);  // applica la visita in preordine al sottoalbero di sx
        cout << p->content << " ";  // stampa il valore contenuto nella radice puntata da p
        inorder(p->dx);  // applica la visita in preordine al sottoalbero di dx
    }
}

bool ricercaABR(node_ptr p, int element) {
    if (!p) return false;
    if (p->content == element) return true;
    if (p->content > element) return ricercaABR(p->sx, element);
    return ricercaABR(p->dx, element);
}

void aLivelli(node_ptr p) {
    queue<node_ptr> Q {}; // inizializzo la coda vuota
    Q.push(p);              // inserisco il primo valore (p ricevuto da input)
//    queue<node_ptr> Q = {p}; // inizializzo la coda vuota con p come unico valore

    while (!Q.empty()) {    // finché ci sono elementi in coda
        node_ptr tmp = Q.front();   // leggi il primo elemento
        Q.pop();                    // stacca ed elimina il primo elemento
        cout << tmp->content << " ";// stampo il valore contenuto nel nodo puntato da tmp
        if (tmp->sx)                // se ho figlio sinistro metto in coda tmp->sx
            Q.push(tmp->sx);
        if (tmp->dx)                 // se ho figlio destro metto in coda tmp->dx
            Q.push(tmp->dx);
    }
}

int main()
{
    insElement(root, 8);
    insElement(root->sx, 5);
    insElement(root->dx, 15);
    insElement(root->sx->sx, 1);
    insElement(root->sx->dx, 7);
    insElement(root->dx->sx, 10);
    insElement(root->dx->dx, 18);
    insElement(root->dx->sx->sx, 9);

    /*
    insBilanciato(root, 1);
    insBilanciato(root, 2);
    insBilanciato(root, 3);
    insBilanciato(root, 4);
    insBilanciato(root, 5);
    insBilanciato(root, 6);
    insBilanciato(root, 7);
    */

    inorder(root);
    cout << endl;
    cout << " ricercaABR 18 " << ricercaABR(root, 18) << endl;
    cout << " ricercaABR 28 " << ricercaABR(root, 28) << endl;

    cout << " \nPROF=" << profondita(root) << endl;

    cout << "===========\n";
    cout << minimo(root) << endl;

    cout << "===========\n";
    cout << massimo(root) << endl;

    cout << "====== A LIVELLI =====\n";
    aLivelli(root);


    /*

    // fill tree values
    root = new nodo();
    root->content = 8;
    root->dx = nullptr;
    root->sx = nullptr;



    root->sx = new nodo();
    root->dx = new nodo();

    root->sx->content = 19;
    root->dx->content = 6;

    root->sx->sx = new nodo();
    root->sx->dx = new nodo();
    root->dx->sx = new nodo();
    root->dx->dx = new nodo();

    root->sx->sx->content = 7;
    root->sx->sx->dx = NULL;
    root->sx->sx->sx = NULL;

    root->sx->dx->content = 65;
    root->sx->dx->dx = NULL;
    root->sx->dx->sx = NULL;

    root->dx->sx->content = 4;
    root->dx->sx->dx = NULL;
    root->dx->sx->sx = NULL;

    root->dx->dx->content = 33;
    root->dx->dx->dx = NULL;
    root->dx->dx->sx = NULL;


	// struttura
	cout << "##### ALBERO BINARIO GENERICO #####\n\n\n";

	cout << "           " << root->content << endl;
	cout << "    " << root->sx->content << "-----+-----" << root->dx->content << endl;

	cout << root->sx->sx->content << "---+---" << root->sx->dx->content;
	cout << "   " << root->dx->sx->content << "---+---" << root->dx->dx->content << endl;

	cout << "           \n\nVisita generica: ";
	// visita
	visita(root);
    */

    return 0;
}

void visita(node_ptr p) {   // preorder =>
    if (p) {    // se p non è null
        cout << p->content << " ";  // stampa il valore contenuto nella radice puntata da p
        visita(p->sx);  // applica la visita in preordine al sottoalbero di sx
        visita(p->dx);  // applica la visita in preordine al sottoalbero di dx
    }
}
