/*
 * Albero binario e rappresentazioni algenriche prefisse
 *
 * */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct nodo {
    char element;	// puo' essere un operatore o un digit [0-9]
    nodo* dx;
    nodo* sx;
};
typedef nodo* node_ptr;
node_ptr root = nullptr;

void ins(node_ptr &p, char e) {
	p = new nodo();
	p->element = e;
	p->dx = nullptr;
	p->sx = nullptr;
}

int calcola(node_ptr p) {
    // restituisce la profondità dell'albero puntato da p
    
    if (!p) return 0;
    if (p->element == '+') return calcola(p->sx) + calcola(p->dx);
    if (p->element == '*') return calcola(p->sx) * calcola(p->dx);
    
    
    return p->element - '0';
}

int main()
{
	
/*
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

*/

	/*
	ins(root, '+');
	ins(root->sx, '3');
	ins(root->dx, '5');
	cout << calcola(root) << endl;
	*/

	ins(root, '+');
	
	ins(root->sx, '*');
	ins(root->sx->sx, '2');
	ins(root->sx->dx, '4');


	ins(root->dx, '5');
	cout << calcola(root) << endl;
	
    return 0;
}


