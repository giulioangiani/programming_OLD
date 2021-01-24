#include <iostream>

using namespace std;


bool cerca(int V[], int n, int inizio, int fine) {
    if (inizio > fine) return false; // l'array è vuoto
    if (V[inizio] == n) return true; // elemento trovato in posizione "inizio"
    return cerca(V, n, inizio+1, fine); // cercalo da qui in poi
}

int main()
{
    int arr[] {10,23,1,5,65,3,22};
    cout << " 65 in arr : " << cerca(arr, 65, 0, 7) << endl;
    cout << " 38 in arr : " << cerca(arr, 38, 0, 7) << endl;
    return 0;
}
