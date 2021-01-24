/*
 * Albero binario di ricerca
 *
 * */
#include <iostream>
#include <fstream>


using namespace std;

struct nodo {
    int content;
    nodo* dx;
    nodo* sx;
};
typedef nodo* node_ptr;
node_ptr root = nullptr;

void insABR(node_ptr &p, int val) {
	if (p==nullptr) {
		p = new nodo();
		p->content = val;
		p->dx = nullptr;
		p->sx = nullptr;
	}
	else {
		if (p->content > val) {
			insABR(p->sx, val);
		}
		else if (p->content < val) {
			insABR(p->dx, val);
		}
	}
}

int profondita(node_ptr p) {
    // restituisce la profondità dell'albero puntato da p
    if (!p) return -1;
    int ps = 1+profondita(p->sx);
    int pd = 1+profondita(p->dx);
    return max(ps, pd);
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

bool isBilanciato(node_ptr p) {
    if (p==nullptr) return true;
    int profsx = profondita(p->sx);
    int profdx = profondita(p->dx);
    return ((profsx-profdx < 2) && (profsx-profdx >
     -2) && isBilanciato(p->sx) && isBilanciato(p->dx));
}

int main()
{
	
	ifstream fin;
	fin.open("input.txt");
	int N;
	int val;
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> val;
		insABR(root, val);
	}
	
	cout << "Visita in order: "; inorder(root);
	cout << "\nProfondità: " << profondita(root);
	cout << "\nBilanciato: " << isBilanciato(root);
	cout << "\nPresente 10: " << ricercaABR(root, 10);
	cout << "\nPresente 40: " << ricercaABR(root, 40);
	
	
    return 0;
}


