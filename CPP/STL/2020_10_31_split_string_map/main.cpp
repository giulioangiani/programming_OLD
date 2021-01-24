#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>


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

    string s = "un esempio di split di stringa";
    vector<string> v = split(s, ' ');
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }

    cout << "\n\n=================\n";

    map<string, scheda> rubrica;

    ifstream fin;
    string tmp;
    fin.open("input.txt");
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
