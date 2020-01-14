/*
 * Albero binario generico 
 * 
 * */
#include <iostream>

using namespace std;

struct nodo {
    int content;
    nodo* dx;
    nodo* sx;
};

typedef nodo* node_ptr;

node_ptr root;


void visita(node_ptr p) {
    if (p) {
        cout << p->content << " ";
        visita(p->sx);
        visita(p->dx);
    }
}


int main()
{

    // fill tree values
    root = new nodo();
    root->content = 8;
    root->dx = NULL;
    root->sx = NULL;

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
	 
    return 0;
}

