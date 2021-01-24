#include <iostream>
using namespace std;

// grafo con matrice di adiacenza
// matrice di interi con valore positivo sugli archi (peso)
// valore 0 se non c'è arco



const int N = 6;
const int MAXINT = 1000000;

typedef int grafo[N][N];
char archi[N] { 'A', 'B', 'C', 'D', 'E', 'F' };

grafo g {
                {0, 2, 3, 4, 0, 0},
                {0, 0, 0, 0, 5, 0},
                {0, 0, 0, 0, 0, 8},
                {0, 0, 0, 0, 1, 1},
                {0, 0, 0, 0, 0, 7},
                {0, 0, 0, 0, 0, 0},
            };


// esisteCammino - versione ricorsiva
bool esisteCamminoRic(grafo p, char start, char end) {
    if (start == end) return true;

    // get item position
    int start_idx = -1;
    for (int i=0; i<N; i++) {
        if (archi[i] == start) start_idx = i;
    }

    bool result = false;
    for (int i=0; i<N; i++) {
         if (p[start_idx][i] > 0) {
            if (esisteCamminoRic(p, archi[i], end)) result = true;
         }
     }

//    cout << start_idx << ":" << end_idx << endl;
    return result;
}


// costoCammino - versione ricorsiva
int costoCamminoRic(grafo p, char start, char end) {
    if (start == end) return 0;

    // get item position
    int start_idx = -1;
    for (int i=0; i<N; i++) {
        if (archi[i] == start) start_idx = i;
    }

    int min_cost = MAXINT;
    for (int i=0; i<N; i++) {
         if (p[start_idx][i] > 0) {
            int c = p[start_idx][i] + costoCamminoRic(p, archi[i], end);
            if (c && c < min_cost) min_cost = c;
         }
     }

    return min_cost;
}



using namespace std;

int main()
{
    cout << "GRAFO" << endl;
    printf(" ");
    for (int i=0; i<N; i++) {
        printf(" %c", archi[i]);
    }
    cout << endl;
    for (int i=0; i<N; i++) {
        printf("%c ", archi[i]);
        for (int j=0; j<N; j++) {
            printf("%d ", g[i][j]);
        }
        cout << endl;
    }



    cout << "Cammino AF : " << esisteCamminoRic(g, 'A', 'F') << endl;
    cout << "Costo AF : " << costoCamminoRic(g, 'A', 'F') << endl;

    cout << "Costo AA : " << costoCamminoRic(g, 'A', 'A') << endl;
    cout << "Costo AB : " << costoCamminoRic(g, 'A', 'B') << endl;

    cout << "Cammino BD : " << esisteCamminoRic(g, 'B', 'D') << endl;
    cout << "Cammino AE : " << esisteCamminoRic(g, 'A', 'E') << endl;
    return 0;
}

