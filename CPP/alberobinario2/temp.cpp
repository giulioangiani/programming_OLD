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


vector<int> preorderVector(node_ptr p, vector<int> v) {
    if (!p) return v;
    v.push_back(p->content);
//    cout << p->content << " ";
    v = preorderVector(p->sx,v);
    v = preorderVector(p->dx,v);
    return v;
}

void preorder(node_ptr p) {
    if (!p) return;
    cout << p->content << " ";
    preorder(p->sx);
    preorder(p->dx);
}


void inorder(node_ptr p) {
    if (!p) return;
    inorder(p->sx);
    cout << p->content << " ";
    inorder(p->dx);
}

int deep(node_ptr p) {
    if (p==NULL) return 0;
    else return max(1+deep(p->sx), 1+deep(p->dx));
}


bool fully_balanced(node_ptr p) {
    // insert here you code!
    return true;
}

void stampasolofoglie(node_ptr p) {	
    // insert here you code!

}

void stampalivello(node_ptr p, int liv, int cont) {	
    // insert here you code!
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

    
//    preorder(root); cout << endl;
//    inorder(root); cout << endl;

    vector<int> result {};
    result = preorderVector(root, result);
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }
    

    return 0;
}

