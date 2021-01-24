#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout;
    fout.open("output.txt");

    // leggo i dati di tre persone e li scrivo su file
    for (int i=0; i<3; i++) {
        string nome,cognome;
        int eta;
        cout << "Nome: "; cin >> nome;
        cout << "Cognome: "; cin >> cognome;
        cout << "Età: "; cin >> eta;
        fout << nome << "," << cognome << "," << eta << endl;   // stampo su file di output
    }

    fout.close();
    return 0;
}
