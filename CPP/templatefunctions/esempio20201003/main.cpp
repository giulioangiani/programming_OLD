#include <iostream>
#include <fstream>

using namespace std;


bool crea(string nomefile) {
    fstream f;
    bool result = false;    // file esistente
    f.open(nomefile.c_str(), ios::in|ios::binary);
    if (!f) {
        f.open(nomefile.c_str(), ios::out|ios::binary);
        result = true;      // file creato
    }
    f.close();
    return result;
}

int main()
{
    string nomefile = "";
    cout << "che file vuoi creare? "; cin >> nomefile;
    bool creato = crea(nomefile);
    if (!creato) {
        cout << "il file already exists\n";
    }
    else {
        cout << "il file non esistente ed è stato creato\n";
    }
    cout << "Hello world!" << endl;
    return 0;
}
