#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    // leggo N numero di parole
    int N;
    fin >> N;
    int s[N];
    int pari = 0;
    int massimo = -1;
    for (int i=0; i<N; i++) {
        fin >> s[i];
        if (s[i] % 2 == 0) pari++;

        if ((i==0) || (s[i] > massimo)) massimo = s[i];
    }

    fout << pari << endl;
    fout << massimo << endl;

    fin.close();
    fout.close();
    return 0;
}
