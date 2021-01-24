#include <iostream>
#include <fstream>

using namespace std;

struct nodo {
  string info;
  nodo* next;
};

nodo* pstart;

void insCoda(nodo* &p, string w) {
  nodo* tmp = new nodo;
  tmp->info = w;
  tmp->next = nullptr;
  if (!p) {
    p = tmp;
  } 
  else if (p->next == nullptr) {
    p->next = tmp;
  }
  else {
    nodo* finder = p;
    while (finder->next != nullptr) finder = finder->next;
    finder->next = tmp;
  }
}

void showList(nodo* p) {
  while(p) {
    cout << ">> " << p->info << endl;
    p = p->next;
  }
}

int contaParole(nodo* p, string w) {
  if (!p) return 0;
  if (p->info == w) return 1 + contaParole(p->next, w);
  return contaParole(p->next, w);
}

void stampaInverso(nodo* p) {
  if (!p) return;
  stampaInverso(p->next);
  cout << ">> " << p->info << endl;
}


bool presente(nodo* p, string w) {
  if (!p) return false;
  if (p->info == w) return true;
  return presente(p->next, w);
}


int main() {
  ifstream fin;
  fin.open("input.txt");
  string s;
  while (!fin.eof()) {
    fin >> s;
    cout << s << endl;
    insCoda(pstart, s);
  }
  showList(pstart);
  cout << "=======================\n";
  cout << "ciao : " << contaParole(pstart, "ciao") << endl;
  cout << "nessuna : " << contaParole(pstart, "nessuna") << endl;
  cout << "bene : " << contaParole(pstart, "bene") << endl;
  cout << "=======================\n";
  stampaInverso(pstart);
  cout << "=======================\n";
  cout << "ciao : " << presente(pstart, "ciao") << endl;
  cout << "nessuna : " << presente(pstart, "nessuna") << endl;
  cout << "bene : " << presente(pstart, "bene") << endl;

  return 0;
}
