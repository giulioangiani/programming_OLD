#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

/*

Comuni reggiani
“La latitudine misura la distanza di un punto dall'equatore sia che si tratti
 del punto in direzione nord che in direzione sud. La longitudine invece misura la distanza di un punto a est o a ovest del meridiano di Greenwich in Gran Bretagna.”
Dato il file “coordinate_geografiche_comuni_reggiani.txt”
Visualizzare i nomi dei comuni in ordine crescente rispetto alla distanza dalla città di Reggio Emilia.
Il formato di output deve essere: nome comune1, nome comune2, nome comune3, ecc…
Visualizzare la distanza in metri dalla città di Reggio Emilia di un comune scelto dall’utente da tastiera.
Il formato di output deve essere: nome comune, distanza mt
Dato il file “altri_dati_comuni.txt”
Visualizzare il comune con la maggior altitudine.
Il formato di output deve essere: nome comune
Visualizzare i 3 comuni con la minor altitudine.
Il formato di output deve essere: nome comune1: altitudine mt, nome comune2: altitudine mt, nome comune3: altitudine mt.
Si vogliono visualizzare i nomi dei comuni con lo stesso CAP (non visualizzare i comuni che hanno un CAP diverso dagli altri).
Il formato di output deve essere: numero CAP: nome comune1, nome comune2, nome comune3, ecc..
Al fine di individuare i più importanti centri urbani decentrati, si vogliono visualizzare i vari comuni in ordine decrescente, rispetto al risultato dato dalla distanza (da Reggio) * il numero di abitanti.
Il formato di output deve essere: nome comune: distanza, numero di abitanti


*/


using namespace std;


struct scheda{
    int matricola;
    string nome;
    string cognome;
    string cellulare;
};

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

    map<string, scheda> rubrica;

    ifstream fin;
    string tmp;
    fin.open("coordinate_geografiche_comuni_reggiani.txt");
    while (!fin.eof()) {
        fin >> tmp;
        vector<string> vtmp = split(tmp, ',');
        int matricola = stoi(vtmp[0]);
        string nome = vtmp[1];
        string cognome = vtmp[2];
        string cell = vtmp[3];

        scheda s {matricola, nome, cognome, cell};
        rubrica[nome] = s;
    }

    for (map<string, scheda>::iterator it = rubrica.begin(); it != rubrica.end(); it++) {
        cout << it->first << ":" << (it->second).cellulare << endl;
    }

    return 0;
}
