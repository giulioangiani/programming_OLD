#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    int content;
    nodo* dx;
    nodo* sx;
};

typedef nodo* node_ptr;

// definisco il puntatore all'albero
node_ptr root = NULL;

// funzione per inserimento calcolo della profondità di un albero binario
int deep(node_ptr p) {
    if (p==NULL) return 0;
    else return max(1+deep(p->sx), 1+deep(p->dx));
}

// funzione per inserimento bilanciato in albero binario
node_ptr insBilanciato(node_ptr p, int val) {

    if (p == NULL) {
        p = new nodo();
        p->content = val;
        p->dx = p->sx = NULL;
    }
    else {
        if (deep(p->dx) >= deep(p->sx)) {
            // inserisco a sinistra
            p->sx = insBilanciato(p->sx, val);
        }
        else {
            // inserisco a destra
            p->dx = insBilanciato(p->dx, val);
        }
    }
    return p;
}


// funzione per visita a livelli(ampiezza) di un albero binario.
// restituisce un vector con tutti i valori presenti nell'albero
// per livello
vector<int> ampiezza(node_ptr p) {
	queue<node_ptr> q ;
    vector<int> result;
	q.push(p);
	while (!q.empty()) {
		node_ptr tmp = q.front();
		q.pop();
        result.push_back(tmp->content);
		if (tmp->sx) q.push(tmp->sx);
		if (tmp->dx) q.push(tmp->dx);
	}
    return result;
}

int main()
{

    // inserimento dei valori dell'albero binario
    root = insBilanciato(root, 10);
    root = insBilanciato(root, 5);
    root = insBilanciato(root, 15);
    root = insBilanciato(root, 3);
    root = insBilanciato(root, 12);
    root = insBilanciato(root, 7);
    root = insBilanciato(root, 1);
    root = insBilanciato(root, 20);
    root = insBilanciato(root, 11);

    // visita in ampiezza dell'albero
    vector<int> v = ampiezza(root);

    // stampa dei valori presenti nell'albero
    for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

