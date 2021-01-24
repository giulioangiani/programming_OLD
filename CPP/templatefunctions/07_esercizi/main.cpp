#include <iostream>

using namespace std;

/*
 Definire la struct Studente per gestire le informazioni degli studenti del Pascal
 La struttura deve avere campi per memorizzare:
 - nome
 - cognome
 - matricola
 - data di nascita (definita con una struct apposita)

 Creare un array di Studente e caricare dati di alcuni studenti

 - Visualizzare la lista degli studenti in ordine crescente per cognome
    (a parità di cognome per nome)
    (a parità di nome per data di nascita)

 - Ridefinire l'operazione di confronto (operator==) per controllare se due studenti sono la stessa persona
    (devono avere stesso nome, cognome e data di nascita)

*/

template<typename T>
void ordina(T v[], int dim, char tipoordinamento) {
    for (int i=0; i<dim-1; i++) {
        for (int j=i; j<dim; j++) {
            if (
                    ((tipoordinamento == 'A') && (v[j] < v[i]))
                    or
                    ((tipoordinamento == 'D') && (v[j] > v[i]))
                )
            {
                T tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }

        }
    }
}


struct data {
    int anno;
    int mese;
    int giorno;
};

struct studente {
    string nome;
    string cognome;
    int matricola;
    data datanascita;
};


ostream& operator<<(ostream& os, const data& s) {
    os << s.anno << "/" << s.mese << "/" << s.giorno;
}


bool operator==(const data& a, const data& b) {
    return ((a.anno==b.anno) && (a.mese==b.mese) && (a.giorno==b.giorno));
}

bool operator<(const data& a, const data& b) {
    if (a.anno < b.anno) return true;
    if (b.anno < a.anno) return false;
    if (a.mese < b.mese) return true;
    if (b.mese < a.mese) return false;
    if (a.giorno < b.giorno) return true;
    return false;
}

bool operator>(const data& a, const data& b) {
    return !(a<b);
}

bool operator<(const studente& a, const studente& b) {
    if (a.cognome < b.cognome) return true;
    if (a.cognome > b.cognome) return false;
    if (a.nome < b.nome) return true;
    if (a.nome > b.nome) return false;
    if (a.datanascita < b.datanascita) return true;
    return false;
}

bool operator>(const studente& a, const studente& b) {
    return !(a<b);
}

bool operator==(const studente& a, const studente& b) {
    return ((a.cognome==b.cognome) && (a.nome==b.nome) && (a.datanascita==b.datanascita));
}

ostream& operator<<(ostream& os, const studente& s) {
    os << "[" << s.matricola << " : " << s.cognome << " " << s.nome << " (" << s.datanascita << ")]";
}


int main()
{
    const int SIZE = 5;
    studente vet[] {
                        { "mario", "rossi", 12345, {2000, 6, 10}},
                        { "mario", "rossi", 62541, {2001, 10, 15}},
                        { "lucia", "green", 65653, {2000, 1, 1}},
                        { "mary", "jane", 12336, {2002, 11, 7}},
                        { "mario", "rossi", 77781, {2001, 10, 15}},
                    };


    ordina(vet, SIZE, 'A');

    for (int i=0; i<SIZE; i++) {
        cout << vet[i] << endl;
    }

    cout << "======================\n";

    cout << vet[2] << endl;
    cout << 2[vet] << endl;

    cout << "======================\n";

    operator<<(cout, vet[1]);
    cout << "======================\n";

    cout << "Uguali vet[2] e vet[3] ? " << operator==(vet[2], 3[vet]) << endl;
    cout << "======================\n";

    cout << "Elementi uguali:\n";
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE && i!=j; j++) {
            if (vet[i] == vet[j]){
                cout << "pos " << i << " e " << j << " : " << vet[i] << " ==> " << vet[j] << endl;
            }
        }
    }

    return 0;
}
