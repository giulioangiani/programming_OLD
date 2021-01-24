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
    if (p) {    // se p non è null
        visita_inorder(p->sx);  // applica la visita in ordine al sottoalbero di sx
        cout << p->content << " ";  // stampa il valore contenuto nella radice puntata da p
        visita_inorder(p->dx);  // applica la visita in ordine al sottoalbero di dx
    }
}

// SCRIVI QUI LA FUNZIONE PER LA VISITA IN ORDER
void visita_inorder_2(node_ptr p, vector<int>& risultato) {   // inorder
    if (p) {    // se p non è null
        visita_inorder_2(p->sx, risultato);  // applica la visita in ordine al sottoalbero di sx
        risultato.push_back(p->content);
        visita_inorder_2(p->dx, risultato);  // applica la visita in ordine al sottoalbero di dx
    }
}

// SCRIVI QUI LA FUNZIONE PER LA VISITA IN POSTORDER
void visita_postorder(node_ptr p) {   // postorder
    if (p) {    // se p non è null
        visita_postorder(p->sx);  // applica la visita in postordine al sottoalbero di sx
        visita_postorder(p->dx);  // applica la visita in postordine al sottoalbero di dx
        cout << p->content << " ";  // stampa il valore contenuto nella radice puntata da p
    }
}

// SCRIVI QUI LA FUNZIONE getContentPreOrder(node_ptr) 
// CHE RICEVE UN puntatore a nodo E RESTITUISCE UN vector<int>
// coi valori presenti nell'albero

vector<int> getContentPreOrder(node_ptr p) {   // preorder =>
	vector<int> result;
    if (p) {    // se p non è null
        result.push_back(p->content);
        // applica la funzione ricorsiva getContentPreOrder 
        // al sottoalbero di sx
        vector<int> result_sx = getContentPreOrder(p->sx);
        // applica la funzione ricorsiva getContentPreOrder
        // al sottoalbero di dx
        vector<int> result_dx = getContentPreOrder(p->dx);  
        
        for (vector<int>::iterator it=result_sx.begin(); it != result_sx.end(); it++) {
			result.push_back(*it);
		}
        for (vector<int>::iterator it=result_dx.begin(); it != result_dx.end(); it++) {
			result.push_back(*it);
		}
    }
    return result;
}

vector<int> getContentPostOrder(node_ptr p) {   // postorder =>
	vector<int> result;
    if (p) {    // se p non è null
        // applica la funzione ricorsiva getContentPostOrder 
        // al sottoalbero di sx
        vector<int> result_sx = getContentPostOrder(p->sx);
        for (vector<int>::iterator it=result_sx.begin(); it != result_sx.end(); it++) {
			result.push_back(*it);
		}

        // applica la funzione ricorsiva getContentPostOrder
        // al sottoalbero di dx
        vector<int> result_dx = getContentPostOrder(p->dx);  
        
        for (vector<int>::iterator it=result_dx.begin(); it != result_dx.end(); it++) {
			result.push_back(*it);
		}

        result.push_back(p->content);
    }
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
	cout << "Visita in preorder (vector come risultato): ";
	vector<int> r = getContentPreOrder(root);
	for (vector<int>::iterator it=r.begin(); it != r.end(); it++) {
		cout << *it << " ";
		
	}
	
	cout << endl;
	cout << "Visita in postorder (vector come risultato): ";
	vector<int> rpo = getContentPostOrder(root);
	for (vector<int>::iterator it=rpo.begin(); it != rpo.end(); it++) {
		cout << *it << " ";
		
	}
	
	cout << endl;
	cout << "Visita in order (vector via parametri): ";
	vector<int> vio;
	visita_inorder_2(root, vio);
	for (vector<int>::iterator it=vio.begin(); it != vio.end(); it++) {
		cout << *it << " ";
		
	}
	
	cout << endl;
	
    return 0;
}

