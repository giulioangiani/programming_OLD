/*
 * Albero binario
 *
 * */
#include <iostream>
#include <vector>

using namespace std;

struct nodo {
    int content;
    nodo* dx;
    nodo* sx;
};
typedef nodo* node_ptr;
node_ptr root = nullptr;

void visita_preorder(node_ptr p) {   // preorder =>
    if (p) {    // se p non è null
        cout << p->content << " ";  // stampa il valore contenuto nella radice puntata da p
        visita_preorder(p->sx);  // applica la visita in preordine al sottoalbero di sx
        visita_preorder(p->dx);  // applica la visita in preordine al sottoalbero di dx
    }
}


// SCRIVI QUI LA FUNZIONE PER LA VISITA IN ORDER
void visita_inorder(node_ptr p) {   // inorder
}

// SCRIVI QUI LA FUNZIONE PER LA VISITA IN POSTORDER
void visita_postorder(node_ptr p) {   // postorder
}


// SCRIVI QUI LA FUNZIONE getContentPreOrder(node_ptr) 
// CHE RICEVE UN puntatore a nodo E RESTITUISCE UN vector<int>
// coi valori presenti nell'albero

vector<int> getContentPreOrder(node_ptr p) {   // preorder =>
	vector<int> result;
	// HERE YOUR CODE
    return result;
}


void insElement(node_ptr &p, int val) {
    p = new nodo();
    p->content = val;
    p->dx = nullptr;
    p->sx = nullptr;
}


int main()
{

    insElement(root, 8);
    insElement(root->sx, 5);
    insElement(root->dx, 15);
    insElement(root->sx->sx, 1);
    insElement(root->sx->dx, 6);
    insElement(root->dx->sx, 10);
    insElement(root->dx->dx, 18);

    cout << "Visita in Preorder  ";
    visita_preorder(root);
    cout << endl;
    cout << "Visita in Order  ";
    visita_inorder(root);
    cout << endl;
    cout << "Visita in Postorder  ";
    visita_postorder(root);


	cout << endl;
	vector<int> r = getContentPreOrder(root);
	for (vector<int>::iterator it=r.begin(); it != r.end(); it++) {
		cout << *it << " ";
		
	}
    return 0;
}

