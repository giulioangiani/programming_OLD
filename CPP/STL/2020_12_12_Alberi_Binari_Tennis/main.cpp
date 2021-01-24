/*
 * Tabellone tennis
 *
 * */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct partita {
    string giocatoreA;
    string giocatoreB;
    int set1_A, set1_B, set2_A, set2_B, set3_A, set3_B;
};

ostream& operator<<(ostream& os, partita p) {
    os << p.giocatoreA << ":" << p.giocatoreB;
    os << " [" << p.set1_A << "-" << p.set1_B << "] ";
    os << " [" << p.set2_A << "-" << p.set2_B << "] ";
    os << " [" << p.set3_A << "-" << p.set3_B << "] ";
    return os;
}

struct nodo {
    partita content;
    nodo* dx;
    nodo* sx;
};
typedef nodo* node_ptr;
node_ptr root = nullptr;

void insElement(node_ptr &p, partita val) {
    p = new nodo();
    p->content = val;
    p->dx = nullptr;
    p->sx = nullptr;
}

void risultati (node_ptr p) {
    if (!p) return;
    cout << p->content << endl;
    risultati(p->sx);
    risultati(p->dx);
}

string vincitoreGara(partita p) {
    int setA = 0;
    int setB = 0;
    if (p.set1_A > p.set1_B) setA++;
    else setB++;
    if (p.set2_A > p.set2_B) setA++;
    else setB++;
    if (p.set3_A > p.set3_B) setA++;
    else setB++;
    //cout << setA << ":" << setB << endl;
    if (setA > setB) return p.giocatoreA;
    else return p.giocatoreB;
}

string sconfittoGara(partita p) {
    int setA = 0;
    int setB = 0;
    if (p.set1_A > p.set1_B) setA++;
    else setB++;
    if (p.set2_A > p.set2_B) setA++;
    else setB++;
    if (p.set3_A > p.set3_B) setA++;
    else setB++;
    //cout << setA << ":" << setB << endl;
    if (setA < setB) return p.giocatoreA;
    else return p.giocatoreB;
}

string vincitore(node_ptr p) {
    /*
    Scrivere il codice per stampare il nome del vincitore del torneo
    */
    return vincitoreGara(p->content);
}

int gareVinte(node_ptr p, string giocatore) {
    /*
    Scrivere il codice per restituire
    il numero di gare vinte dal giocatore specificato
    */

    // visito l'albero e conto quante volte il vincitoreGara è uguale a giocatore
    if (!p) return 0;
    if (vincitoreGara(p->content) == giocatore) {
        return 1+gareVinte(p->sx, giocatore)+gareVinte(p->dx, giocatore);
    }
    else {
        return gareVinte(p->sx, giocatore)+gareVinte(p->dx, giocatore);
    }
}

vector<int> vintiEPersi(node_ptr p, string giocatore) {
    /*
    Scrivere il codice per restituire
    un array di due interi contenenti nella posizione 0
    il numero dei set vinti da un certo giocatore,
    nella posizione 1 il numero di quelli persi
    */
    vector<int> tmp {0, 0};
    if (!p) return tmp;
    if (p->content.giocatoreA == giocatore) {
        if (p->content.set1_A > p->content.set1_B) tmp[0]++;
        if (p->content.set1_A < p->content.set1_B) tmp[1]++;

        if (p->content.set2_A > p->content.set2_B) tmp[0]++;
        if (p->content.set2_A < p->content.set2_B) tmp[1]++;

        if (p->content.set3_A > p->content.set3_B) tmp[0]++;
        if (p->content.set3_A < p->content.set3_B) tmp[1]++;

    }
    if (p->content.giocatoreB == giocatore) {
        if (p->content.set1_A < p->content.set1_B) tmp[0]++;
        if (p->content.set1_A > p->content.set1_B) tmp[1]++;

        if (p->content.set2_A < p->content.set2_B) tmp[0]++;
        if (p->content.set2_A > p->content.set2_B) tmp[1]++;

        if (p->content.set3_A < p->content.set3_B) tmp[0]++;
        if (p->content.set3_A > p->content.set3_B) tmp[1]++;
    }

    vector<int> turnoprecedente_sx = vintiEPersi(p->sx, giocatore);
    vector<int> turnoprecedente_dx = vintiEPersi(p->dx, giocatore);

    tmp[0] = tmp[0] + turnoprecedente_sx[0] + turnoprecedente_dx[0];
    tmp[1] = tmp[1] + turnoprecedente_sx[1] + turnoprecedente_dx[1];

    return tmp;
}


void stampaGareGiocatore(node_ptr p, string giocatore) {
    if (!p) return;
    if ((p->content.giocatoreA == giocatore) || (p->content.giocatoreB == giocatore)) {
        cout << p->content << endl;
    }
    stampaGareGiocatore(p->sx, giocatore);
    stampaGareGiocatore(p->dx, giocatore);
}

void cavalcataVincente (node_ptr p) {
    /*
    Scrivere il codice per stampare i risultati
    ottenuti dal vincitore del torneo
    */

    string vincitoreTorneo = vincitore(p);
    stampaGareGiocatore(p, vincitoreTorneo);

}

void elimiatiAlPrimoTurno (node_ptr p) {
    /*
    Scrivere il codice per stampare i nomi degli eliminati al primo turno
    */
    if (!p) return;
    if (!p->sx && !p->dx) {
        // foglia
        cout << sconfittoGara(p->content) << endl;
    }
    elimiatiAlPrimoTurno(p->sx);
    elimiatiAlPrimoTurno(p->dx);
}


void aLivelli(node_ptr p) {
    queue<node_ptr> Q = {};
    Q.push(p);
    while (!Q.empty()) {
        node_ptr tmp = Q.front();
        Q.pop();
        cout << tmp->content << endl;
        if (tmp->sx)
            Q.push(tmp->sx);
        if (tmp->dx)
            Q.push(tmp->dx);
    }
}

void aLivelliTurno(node_ptr p, int turno) {
    queue<pair<node_ptr, int>> Q = {};
    Q.push({p, turno});
    while (!Q.empty()) {
        auto tmp = Q.front();
        Q.pop();
        cout << tmp.first->content << " [ Turno " << tmp.second << " ]" << endl;

        if (tmp.first->sx)
            Q.push({tmp.first->sx, tmp.second - 1});
        if (tmp.first->dx)
            Q.push({tmp.first->dx, tmp.second - 1});
    }
}

int main()
{
    insElement(root, {"Djokovic", "Nadal", 6, 2, 3, 6, 6, 4});

    insElement(root->sx, {"Djokovic", "Thiem", 6, 0, 6, 4, 0, 0});
    insElement(root->dx, {"Medvedev", "Nadal", 2, 6, 7, 6, 3, 6});

    insElement(root->sx->sx, {"Djokovic", "Federer", 2, 6, 6, 0, 6, 3});
    insElement(root->sx->dx, {"Thiem", "Tsitsipas", 4, 6, 6, 1, 6, 4});
    insElement(root->dx->sx, {"Medvedev", "Rublev", 6, 0, 6, 2, 0, 0});
    insElement(root->dx->dx, {"Zverev", "Nadal", 0, 6, 7, 6, 2, 6});

    risultati(root);


    // vincitore
    cout << "*********************************************\n";
    cout << "Vincitore torneo: " << vincitore(root) << endl;

    // garavinte
    cout << "*********************************************\n";
    cout << "Gare vinte da Zverev " << gareVinte(root, "Zverev") << endl;
    cout << "Gare vinte da Thiem " << gareVinte(root, "Thiem") << endl;
    cout << "Gare vinte da Nadal " << gareVinte(root, "Nadal") << endl;
    cout << "Gare vinte da Djokovic " << gareVinte(root, "Djokovic") << endl;

    // cavalcata vincente
    cout << "*********************************************\n";
    cavalcataVincente(root);


    // vinti e persi
    cout << "*********************************************\n";
    vector<int> vp = vintiEPersi(root, "Nadal");
    cout << "Vinti e persi da Nadal " << vp[0] << ":" << vp[1] << endl;
    vector<int> vp2 = vintiEPersi(root, "Djokovic");
    cout << "Vinti e persi da Djokovic " << vp2[0] << ":" << vp2[1] << endl;


    // elimiatiAlPrimoTurno
    cout << "*********************************************\n";
    cout << "Eliminati al primo turno : \n";
    elimiatiAlPrimoTurno(root);


    // aLivelli
    cout << "*********************************************\n";
    aLivelli(root);

    // aLivelli con turno
    cout << "*********************************************\n";
    aLivelliTurno(root, 3);

    return 0;


}
