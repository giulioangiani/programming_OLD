#include <iostream>
#include <exception>
using namespace std;

struct punto {
    double x;
    double y;
};

punto operator+(const punto a, const punto b) {
    return {(a.x+b.x),(a.y+b.y)};
}


ostream& operator<<(ostream& o, const punto a) {
    o << "{" << a.x << "," << a.y << "}";
}

bool operator<(const punto& a, const punto& b) {
    if (a.x < b.x) return true;
    if (a.x > b.x) return false;
    if (a.y < b.y) return true;
    return false;
}
bool operator>(const punto& a, const punto& b) {
    if (a.x > b.x) return true;
    if (a.x < b.x) return false;
    if (a.y > b.y) return true;
    return false;
}
bool operator==(const punto& a, const punto& b) {
    return ((a.x==b.x) && (a.y==b.y));
}



template<typename T>
T somma(T a, T b) {
    return a+b;
}

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


template<typename T>
void stampaArray(T v[], int dim) {
    for (int i=0; i<dim; i++) {
        cout << v[i] << endl;
    }

}

int main()
{
    cout << somma(1, 2) << endl;
    cout << somma((string)"Ciao",  (string)"raga!") << endl;

    punto p1 {2, 3};
    punto p2 {7, 4};
    //punto p3 = somma(p1, p2);

    cout << (p1>p2) << endl;
    cout << "uguali (1) = " << (p1==p2) << endl;
    cout << "uguali (2) = " << operator==(p1, p2) << endl;
    cout << operator<(p1, p2) << endl;
    cout << operator+(p1, p2) << endl;




    /*

    cout << p3.x << ":" << p3.y << endl;
    cout << p3 << endl;

    // ordinamento
    int vint[] {2,4,5,1,12,6,98};
    int arrSize = sizeof(vint)/sizeof(vint[0]);
    cout << "arrSize " << arrSize << endl;
    ordina(vint, arrSize, 'A');
    stampaArray(vint, arrSize);
    ordina(vint, arrSize, 'D');
    stampaArray(vint, arrSize);

    string vstr[] {"oggi", "è", "una", "bella", "giornata"};
    arrSize = sizeof(vstr)/sizeof(vstr[0]);
    cout << "arrSize " << arrSize << endl;
    ordina(vstr, arrSize, 'A');
    stampaArray(vstr, arrSize);
    ordina(vstr, arrSize, 'D');
    stampaArray(vstr, arrSize);

    cout << "=================================\n";
    cout << vint << endl;
    cout << vint+1 << endl;
    cout << *(vint+4) << endl;
    cout << 2[vint] << endl;
    cout << "=================================\n";
    cout << vstr << endl;
    cout << vstr+1 << endl;
    cout << *(vstr+4) << endl;
    cout << 2[vstr] << endl;

    cout << "=================================\n";


//  cout.operator<<(2);
//	operator<<(cout, vstr[0] + "\n");
//    cout << operator+((string)"ciao", (string)"mondo");

    punto vpunti[] {p1, p2};
    //ordina(vpunti, 2, 'A');   //   ==> e questo??
    //stampaArray(vpunti, 2);
    */




    return 0;

}
