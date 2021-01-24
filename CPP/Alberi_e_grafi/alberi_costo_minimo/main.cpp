/*
 * Une albero binario rappresenta le possibili strade
 * che Ciccio può percorrere per raggiungere le case dei suoi amici
 * La casa di Ciccio si trova nella radice e le case degli amici nelle foglie
 * I nodi intermedi rappresentano la lunghezza delle strade che Ciccio deve
 * attraversare per andare a casa dei suoi amici.
 * Ciccio è molto pigro ma è stanco di stare solo e quindi andrà a trovare il più vicino.
 * Stampa il nome dell'amico che raggiungerà e la distanza percorsa
 */

#include <iostream>
#include <queue>

using namespace std;

struct nodo {
    string amico;
    int distanza;
    nodo* dx;
    nodo* sx;
};
typedef nodo* node_ptr;
node_ptr root = nullptr;

int distanzaPercorsa(node_ptr p) {
    if (!p) return 0;
    return p->distanza + min(distanzaPercorsa(p->sx), distanzaPercorsa(p->dx));
}

string amicoRaggiunto(node_ptr p) {

    queue<pair<node_ptr, int>> Q {}; // inizializzo la coda vuota
    Q.push({p, 0});       // inserisco il primo valore (p ricevuto da input)

    int minimo = 100000000;
    string amico = "xxx";

    while (!Q.empty()) {    // finché ci sono elementi in coda
        pair<node_ptr, int> tmp = Q.front();   // leggi il primo elemento
        Q.pop();                    // stacca ed elimina il primo elemento
        node_ptr p_tmp = tmp.first;
        int distanza = tmp.second;
        int totalepercorso = p_tmp->distanza+distanza;
//        cout << p_tmp->amico << " " << p_tmp->distanza << " " << distanza << " " << totalepercorso << "\n";// stampo il valore contenuto nel nodo puntato da tmp
        if (p_tmp->sx)                // se ho figlio sinistro metto in coda tmp->sx
            Q.push({p_tmp->sx, distanza+p_tmp->distanza});
        if (p_tmp->dx)                 // se ho figlio destro metto in coda tmp->dx
            Q.push({p_tmp->dx, distanza+p_tmp->distanza});

        // se è una foglia (casa di amico) => controllo se è il percorso più corto
        if (!p_tmp->sx && !p_tmp->dx) {
            if (totalepercorso < minimo) {
                minimo = totalepercorso;
                amico = p_tmp->amico;
            }
        }
    }

    return amico;

}

void insElement(node_ptr &p, int d, string a) {
    p = new nodo();
    p->distanza = d;
    p->amico = a;
    p->dx = nullptr;
    p->sx = nullptr;
}

int main()
{
    insElement(root, 0, "Ciccio");

    insElement(root->sx, 5, "--");
    insElement(root->dx, 15, "--");

    insElement(root->sx->sx, 1, "--");
    insElement(root->sx->dx, 7, "--");
    insElement(root->dx->sx, 10, "--");
    insElement(root->dx->dx, 18, "--");

    insElement(root->sx->sx->sx, 9, "Luca");
    insElement(root->sx->sx->dx, 11, "Andrea");
    insElement(root->sx->dx->sx, 7, "Jack");
    insElement(root->sx->dx->dx, 14, "Brando");

    insElement(root->dx->sx->sx, 10, "Frank");
    insElement(root->dx->sx->dx, 8, "Mohamed");
    insElement(root->dx->dx->sx, 3, "Juri");
    insElement(root->dx->dx->dx, 12, "Marko");

    //aLivelli(root);

    cout << "=================================\n";
    cout << "Amico raggiunto " << amicoRaggiunto(root) << endl;
    cout << "Distanza percorsa " << distanzaPercorsa(root) << endl;

    return 0;
}

