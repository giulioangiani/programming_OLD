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

struct Studente {
    // your fields
};


int main() {
    // here your code

    return 0;
}

