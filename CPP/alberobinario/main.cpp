#include <iostream>

using namespace std;

struct nodo {
    int content;
    nodo* dx;
    nodo* sx;
};

typedef nodo* node_ptr;

node_ptr root;


void preorder(node_ptr p) {
    if (p) {
        cout << p->content << " ";
        preorder(p->sx);
        preorder(p->dx);
    }
}


void inorder(node_ptr p) {
    if (p) {
        inorder(p->sx);
        cout << p->content << " ";
        inorder(p->dx);
    }
}

void postorder(node_ptr p) {
    if (p) {
        postorder(p->sx);
        postorder(p->dx);
        cout << p->content << " ";
    }
}


void addval(int v, node_ptr p) {
    if (!p) {
        p = new nodo();
        p->content = v;
        p->dx = p->sx = NULL;
    }
    else {
        if (p->content > v) {

            if (p->sx) addval(v, p->sx);
            else {
                p->sx = new nodo();
                p->sx->content = v;
                p->sx->dx = p->sx->sx = NULL;
            }
        }
        else {

            if (p->dx) addval(v, p->dx);
            else {
                p->dx = new nodo();
                p->dx->content = v;
                p->dx->dx = p->dx->sx = NULL;
            }

        }

    }
}

int deep(node_ptr p) {
    if (!p) return 0;
    return 1+max(deep(p->sx), deep(p->dx));
}

bool balanced(node_ptr p) {
    if (!p) return true;
    return deep(p->sx) == deep(p->dx);

}

bool fully_balanced(node_ptr p) {
    if (!p) return true;
    return (balanced(p) && fully_balanced(p->sx) && fully_balanced(p->dx));

}

void stampasolofoglie(node_ptr p) {	
	if (!p) return;
	
	if (!p->dx && !p->sx) {
		// e' una foglia
		cout << p->content << ",";
	}
	else {
		stampasolofoglie(p->dx);
		stampasolofoglie(p->sx);
	}
}

void stampalivello(node_ptr p, int liv, int cont) {	


}



int main()
{

    cout << "DEEP " << deep(root) << endl;

    // fill tree values
    root = new nodo();
    root->content = 10;
    root->dx = NULL;
    root->sx = NULL;


    root->sx = new nodo();
    root->dx = new nodo();

    root->sx->content = 5;
    root->dx->content = 15;

    root->sx->sx = new nodo();
    root->sx->dx = new nodo();
    root->dx->sx = new nodo();
    root->dx->dx = new nodo();

    root->sx->sx->content = 2;
    root->sx->sx->dx = NULL;
    root->sx->sx->sx = NULL;

    root->sx->dx->content = 8;
    root->sx->dx->dx = NULL;
    root->sx->dx->sx = NULL;

    root->dx->sx->content = 12;
    root->dx->sx->dx = NULL;
    root->dx->sx->sx = NULL;

    root->dx->dx->content = 19;
    root->dx->dx->dx = NULL;
    root->dx->dx->sx = NULL;

    // root value
    cout << "root value " << root->content << endl;

    preorder(root); printf("\n");
    inorder(root); printf("\n");
    postorder(root); printf("\n");

    cout << "DEEP " << deep(root) << endl;
    cout << "BALANCED root: " << balanced(root) << endl;
    cout << "FULLY BALANCED root: " << fully_balanced(root) << endl;

    addval(9, root);
    addval(13, root);
    addval(14, root);
    addval(21, root);
    inorder(root); printf("\n");

    cout << "DEEP: " << deep(root) << endl;
    cout << "BALANCED root: " << balanced(root) << endl;
    cout << "FULLY BALANCED root: " << fully_balanced(root) << endl;
	cout << "SOLO FOGLIE "; stampasolofoglie(root);
    return 0;
}

