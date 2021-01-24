/*
Per la gestione di un file di dati relativo agli articoli presenti in un magazzino e avente il seguente tracciato record:

COD,DESC,CATEGORIA,PREZZO,GIACENZA,SCORTAMINIMA

Si presenti il seguente menù:
a)	Crea il file mag.csv
b)	Aggiungi nuovi record in coda al file
c)	Visualizza il numero di record presenti nel file
d)	Visualizza tutti gli articoli presenti in magazzino, indicando per ciascuno codice, descrizione, prezzo
e)	Visualizza del valore totale di magazzino
f)	Visualizza del valore di magazzino relativamente ad una categoria precedentemente acquisita da utente
g)	Visualizza del numero di articoli sottoscorta
h)	Modifica il prezzo di un articolo di cui si sia indicato il codice
i)	Data una descrizione di articolo visualizza la giacenza in magazzino
j)	Visualizza la descrizione dell'articolo più costoso
k)  Elimina dal file un articolo identificato tramite codice

*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct articolo {
    int codice;
    string descrizione;
    string categoria;
    float prezzo;
    int giacenza;
    int scortaminima;
};
ostream& operator<<(ostream& os, articolo a) {
    os << a.codice << "," << a.descrizione << "," << a.prezzo;
}

struct nodo {
    articolo info;
    nodo* next;
};


articolo letturaNuovoArticolo() {
    articolo tmp;
    cout << "Inserisci codice : "; cin >> tmp.codice;
    cout << "Inserisci descrizione : "; cin >> tmp.descrizione;
    cout << "Inserisci prezzo : "; cin >> tmp.prezzo;
    return tmp;
}

template <typename T>
void aggiungiElementoAlFile(T a, string nomefile) {
    fstream f;
    f.open(nomefile.c_str(), ios::app);
    f << a << endl;
    f.close();
}

bool crea(string nomefile) {
    fstream f;
    bool result = false;    // file esistente
    f.open(nomefile.c_str(), ios::in);
    if (!f) {
        f.open(nomefile.c_str(), ios::out);
        result = true;      // file creato
    }
    f.close();
    return result;
}

int readLineNumbers(string nomefile) {
    fstream f;
    f.open(nomefile.c_str(), ios::in);

    int result = 0;
    string line;
    while (!f.eof()) {
       getline(f,line);
       if (line != "") result++;    // skip empty lines
    }

    f.close();
    return result;
}


void makeListFromFile(string nomefile, nodo* &p) {
    fstream f;
    f.open(nomefile.c_str(), ios::in);
    string line;
    while (!f.eof()) {
       articolo a;
       getline(f,line);
       stringstream linestream(line);
       string item;
       int counter = 0;
       while (getline(linestream, item, ','))
        {
            if (counter == 0) a.codice = stoi(item);
            if (counter == 1) a.descrizione = item;
            if (counter == 3) a.prezzo = stof(item);
/*           nodo* tmp = new nodo;
           tmp->info = a;
           tmp->next = p;
           p = tmp;
*/
        }
/*
       // cerco la virgola
       int pos = line.find(',');
       if (pos > -1) {  // find restituisce -1 se il carattere cercato non è nella stringa
           a.codice = stoi(line.substr(0, pos));
           a.descrizione = line.substr(pos+1, line.length());
           nodo* tmp = new nodo;
           tmp->info = a;
           tmp->next = p;
           p = tmp;
       }
    */
    }
    f.close();
}

void stampaRecords(string nomefile) {
    fstream f;
    f.open(nomefile.c_str(), ios::in);

    int result = 0;
    string line;
    while (!f.eof()) {
       articolo a;
       getline(f,line);
       // cerco la virgola
       int pos = line.find(',');
       if (pos > -1) {  // find restituisce -1 se il carattere cercato non è nella stringa
           a.codice = stoi(line.substr(0, pos));
           a.descrizione = line.substr(pos+1, line.length());
           cout << a << endl;
       }
    }

    f.close();
}



int main()
{
    // esercizio a
    const string nomefile = "mag.csv";
    bool creato = crea(nomefile);
    if (!creato) {
        cout << "il file already exists\n";
    }
    else {
        cout << "il file non esistente ed è stato creato\n";
    }
    nodo* pstart = nullptr;
    makeListFromFile(nomefile, pstart);
    return 0;

    // esercizio b
    articolo nuovo = letturaNuovoArticolo();
    aggiungiElementoAlFile(nuovo, nomefile);

    // esercizio c
    cout << "record presenti " << readLineNumbers(nomefile) << endl;

    // esercizio d
    cout << "Visualizza articoli " << endl;
    stampaRecords(nomefile);


    makeListFromFile(nomefile, pstart);



    return 0;
}
