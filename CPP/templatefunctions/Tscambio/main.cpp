#include <iostream>

using namespace std;

template<typename T>
void scambia(T& x, T& y) {

    T tmp = x;
    x = y;
    y = tmp;

}

void scambia_int(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void scambia_float(float &a, float &b) {
    float tmp = a;
    a = b;
    b = tmp;
}
void scambia_string(string &a, string &b) {
    string tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    /*
    int a = 2; int b = 3;
    scambia(a, b);
    cout << " A = " << a << "  B = " << b << endl;
    float c = 2.5; float d = 3.6;
    scambia(c, d);
    cout << " C = " << c << "  D = " << d << endl;
    */

    int a = 2;
    int b = 3;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << a << ":" << b << endl;

    scambia_int(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    scambia(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;




    float f1 = 2.5;
    float f2 = 3.5;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    scambia(f1, f2);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    scambia_float(f1,f2);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    string s = "ciao";
    string t = "belli";
    scambia_string(s,t);
    cout << "s = " << s << endl;
    cout << "t = " << t << endl;


    return 0;
}
