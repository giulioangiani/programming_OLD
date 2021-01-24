#include <iostream>
#include <stdlib.h>
#include <time.h>       /* time */
#include <chrono>
#include <algorithm>


using namespace std;

bool standardsearch(int V[], int n, int inizio, int fine) {
    for (int i=inizio; i<fine; i++) {
        if (n == V[i]) return true;
    }
    return false;
}

bool binarysearch(int V[], int n, int inizio, int fine) {
    if (inizio > fine) return false; // l'intervallo specificato non è più valido
    // cerco elemento medio nell'intervallo specificato da inizio e fine
    int medio = (fine+inizio)/2;
    if (V[medio] == n) return true; // elemento trovato in posizione "medio"
    if (V[medio] > n) return binarysearch(V, n, inizio, medio-1); // lo cerco da inizio a medio-1
    if (V[medio] < n) return binarysearch(V, n, medio+1, fine); // lo cerco da medio+1 a fine
    return false;	// risultato di default
}

int main()
{
    /* initialize random seed: */
    srand (time(NULL));

    cout << time(NULL) << endl;

    // generazione automatica elementi di un array
    int dim = 1000*1000*10;
    int pos = dim-1;    // ultimo elemento
    int* v = new int[dim];  // devo usare un puntatore per evitare l'allocazione statica che dà errore

    for (int i=0; i<dim; i++) {
        v[i] = rand() % 10 + 1;
    }
    v[pos] = 5000;

    cout << "Standard search\n";
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    cout << "5000 in V : " << standardsearch(v, 5000, 0, dim) << endl;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;
    cout << "Standard search finita in " << time_span.count() << " millisecondi\n";

    sort(v, v+dim);
    cout << "Binary search\n";
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    cout << "5000 in V : " << binarysearch(v, 5000, 0, dim) << endl;
    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    duration<double, std::milli> time_span_2 = t4 - t3;
    cout << "Binary search finita in " << time_span_2.count() << " millisecondi\n";

    return 0;
}
