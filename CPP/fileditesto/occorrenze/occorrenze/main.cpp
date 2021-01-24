#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    char ch;
    cout << "Quale carattere vuoi cercare ? ";
    cin >> ch;
    char tmp;
    int cont = 0;
    while (!fin.eof()) {
        fin >> tmp;
        if (tmp == ch) cont++;
    }
    cout << "Trovato " << cont << " volte\n";   // stampo a video
    fout << "Trovato " << cont << " volte\n";   // stampo su file di output

    fin.close();
    fout.close();
    return 0;
}
