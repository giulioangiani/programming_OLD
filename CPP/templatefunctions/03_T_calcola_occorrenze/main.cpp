#include <iostream>

using namespace std;

template<typename T>
int occorrenze(T x[], T elem, int size) {    // il passaggio è per riferimento per gli array
    int cont = 0;
    for (int i = 0; i<size; i++) {
        if (x[i] == elem) cont++;
    }
    return cont;
}

int main()
{
    int x[] {1,2,3,4,5,4,3};
    int size = 7;
    int elem = 4;

    cout << elem << " presente " << occorrenze(x, elem, size) << " volte\n";

    string s[ ] {"ciao", "come", "state", "come", "oggi", "come", "ieri"};
    int sizes = 6;
    string s1 = "come";
    cout << s1 << " presente " << occorrenze(s, s1, sizes) << " volte\n";


    int vettint[ ] {1,2,3,3,2,3,4,3};
	int oc1 = occorrenze(vettint, 3, 8);
    cout << "3 presente " << oc1 << " volte\n";

	int oc2 = occorrenze(s, s1, 7);
    cout << "come presente " << oc2 << " volte\n";
    return 0;
}
