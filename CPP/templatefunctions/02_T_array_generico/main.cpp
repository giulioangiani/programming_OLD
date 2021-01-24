#include <iostream>

using namespace std;

template<typename T>
void ordina(T x[], int size) {    // il passaggio è per riferimento per gli array
    for (int i = 0; i<size-1; i++) {
        for (int j = i; j<size; j++) {
            if (x[i]>x[j]) {
                T tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
}

int main()
{
    int x[5] {9,8,7,6,5};
    for (int i = 0; i<5; i++) {
        cout << x[i] << endl;
    }
    cout << endl;
    ordina(x, 5);
    cout << endl;
    for (int i = 0; i<5; i++) {
        cout << x[i] << endl;
    }
    return 0;
}
