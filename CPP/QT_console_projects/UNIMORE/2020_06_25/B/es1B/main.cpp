#include <iostream>
#include <vector>

using namespace std;

int occ(vector <int> v, int n){
    int j = 0;
    for (int i = 0; i < (int)v.size(); i++){
        if (n == v[i])
            j++;
    }

    return j;
}

int main()
{
    int n;
    vector <int> v;

    cout << "Inserisci n: ";
    cin >> n;

    string valore = " ";

    while (valore != "STOP"){
        cout << "Inserisci il valore del vector o scrivi 'STOP' se hai finito\n";
        cin >> valore;
        if (valore != "STOP")
            v.push_back(stoi(valore));
    }
    cout << "Il numero delle occorrenze è: " << occ(v, n) << endl;
}
