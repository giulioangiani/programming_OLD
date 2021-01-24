#ifndef SCONTRINO_H
#define SCONTRINO_H

#include <string>
#include <vector>
#include <utility>      // std::pair, std::make_pair

using namespace std;

class Scontrino {


public:
  Scontrino(string n, string d, string o);
  string stampa();

private:
  string nome;
  string dataspesa;
  string orario;
  vector<pair<string, float>> voci;

};

#endif // SCONTRINO_H
