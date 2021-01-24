#include <iostream>

using namespace std;

int funz(int N, int A[], int v){
    int j = 0;
    for (int i = 0; i < N; i++){
        if (A[i] % v == 0)
            j++;
    }
    return j++;
}

int main()
{
    int N, v;

    cout << "Inserisci la dimensione dell'array: ";
    cin >> N;

    cout << "Inserisci il numero V: ";
    cin >> v;

    int A[N];

    for (int i = 0; i < N; i++){
        cout << "Inserisci il valore nell'array: ";
        cin >> A[i];
    }

    cout << "Il numero di elementi in A che sono multipli di V è: " << funz(N, A, v) << endl;
}
