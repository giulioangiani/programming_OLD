/*

*/

#include <iostream>

using namespace std;

template <class T>
struct nodo {
    T info;
    nodo<T>* next;
};

template <typename T>
void intesta(nodo<T>* &p, T x) {
    nodo<T>* tmp = new nodo<T>;
    tmp->info = x;
    tmp->next = p;
    p = tmp;
}

/*
Ex1: Write a template function called printlist
which receives a nodo<T>* pointer
and prints out the list nodes content
*/

// HERE YOUR CODE

template <typename T>
void printlist(nodo<T>* p) {
    while (p) {
        cout << p->info << "\n";
        p=p->next;
    }
}

struct circle {
    double radius;
};



struct square {
    double side;
};

struct rectangle {
    double base;
    double height;
};

/*
Ex2: Write all the required overriding functions
to get a string representation of all provided structs
*/

// HERE YOUR CODE
ostream& operator<<(ostream& os, circle c) {
    os << "Radius: " << c.radius;
}
ostream& operator<<(ostream& os, square s) {
    os << "[" << s.side << "]";
}
ostream& operator<<(ostream& os, rectangle r) {
    os << "[" << r.base << "," << r.height << "]";
}
double getArea(rectangle r);
bool operator>(rectangle r1, rectangle r2) {
    return getArea(r1) > getArea(r2);
}

/*
Ex3: Write a function called getArea which gets a rectangle element in and throws out a double value out.
this value is the area of that rectangle
*/

// HERE YOUR CODE
double getArea(rectangle r) {
    return r.base*r.height;
}


int main()
{
    nodo<circle>* pcircle = nullptr;
    intesta(pcircle, {5.0});
    intesta(pcircle, {1.0});
    intesta(pcircle, {3.0});
    intesta(pcircle, {4.5});

    printlist(pcircle);
    /*expected output

    Radius: 4.5
    Radius: 3
    Radius: 1
    Radius: 5

    */
    nodo<square>* psquare = nullptr;
    intesta(psquare, {5.0});
    intesta(psquare, {1.0});
    intesta(psquare, {3.0});
    intesta(psquare, {4.0});
    printlist(psquare);
    /*expected output

    [4]
    [3]
    [1]
    [5]
    */

    nodo<rectangle>* prectangle = nullptr;
    rectangle r1 {4,5};
    rectangle r2 {3,7};
    intesta(prectangle, r1);
    intesta(prectangle, r2);
    printlist(prectangle);
    /*expected output
    [3,7]
    [4,5]
    */

    cout << "Area of r1 is " << getArea(r1) << endl;
    cout << "Area of r2 is " << getArea(r2) << endl;
    /*expected output
    Area of r1 is 20
    Area of r2 is 21
    */


    // REMARK! A rectangle is bigger than another if its area is bigger!
    if (r1 > r2) {
        cout << "r1 is bigger than r2";
    }
    else {
        cout << "r2 is bigger than r1 or they are equals";
    }

    /*expected output
    r2 is bigger than r1 or they are equals
    */


    return 0;
}
