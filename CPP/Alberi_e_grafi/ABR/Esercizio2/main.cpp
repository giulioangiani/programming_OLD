/*
 * Albero binario di ricerca
 *
 * */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct nodo {
    string telefono;
    string cognome;
    string nome;
    nodo* dx;
    nodo* sx;
};
typedef nodo* node_ptr;
node_ptr rubrica_per_nome = nullptr;

void insABR(node_ptr &p, string nome, string cognome, string telefono) {
	if (p==nullptr) {
		p = new nodo();
		p->nome = nome;
		p->cognome = cognome;
		p->telefono = telefono;
		p->dx = nullptr;
		p->sx = nullptr;
	}
	else {
		if (p->nome > nome) {
			insABR(p->sx, nome, cognome, telefono);
		}
		else if (p->nome < nome) {
			insABR(p->dx, nome, cognome, telefono);
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
        cout << p->nome << " " << p->cognome << " " << p->telefono << "\n";  // stampa il valore contenuto nella radice puntata da p
        inorder(p->dx);  // applica la visita in preordine al sottoalbero di dx
    }
}

string ricercaABR(node_ptr p, string element) {
    if (!p) return "--";
    if (p->nome == element) return p->telefono;
    if (p->nome > element) return ricercaABR(p->sx, element);
    return ricercaABR(p->dx, element);
}

bool isBilanciato(node_ptr p) {
    if (p==nullptr) return true;
    int profsx = profondita(p->sx);
    int profdx = profondita(p->dx);
    return ((profsx-profdx < 2) && (profsx-profdx > -2) && isBilanciato(p->sx) && isBilanciato(p->dx));
}

vector<string> split(string str, char delim)
{
    stringstream ss(str);
    string token;
    vector<string> result;
    while (getline(ss, token, delim)) {
        result.push_back(token);
    }
    return result;
}

int main()
{
	
	ifstream fin;
	fin.open("input.txt");
	int N;
	fin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		vector<string> v;
		fin >> s;
		v = split(s, ',');
		insABR(rubrica_per_nome, v[0], v[1], v[2]);
	}
	
	cout << "Visita in order: "; inorder(rubrica_per_nome);
	cout << "\nProfondità: " << profondita(rubrica_per_nome);
	cout << "\nBilanciato: " << isBilanciato(rubrica_per_nome);
	cout << "\nNumero di Chiara : " << ricercaABR(rubrica_per_nome, "chiara");
	cout << "\nNumero di Roberto : " << ricercaABR(rubrica_per_nome, "roberto");
	
	
    return 0;
}


