/*
Read the whole program code and fill the spaces with the required functions
DO NOT TOUCH the main program!
You can only comment and uncomment some lines of code
for testing your functions step-by-step

You have 45 minutes from this moment!

Enjoy!
*/

#include <iostream>
#include <math.h>
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
Ex1: Write a boolean template function called isempty
which receives a nodo<T>* pointer returns true if
list is empty, false otherwise

[points 5]
*/

// HERE YOUR CODE



// End of isempty function

/*
Ex2: Write a template function called findElement
which receives a nodo<T>* pointer and a T element
and returns the T* pointer to that element if present,
nullptr otherwise

[points 10]
*/

// HERE YOUR CODE



// End of findElement function

struct rectangle {
    double base;
    double height;
};

/*
Ex3: Write a function called calculateDiagonal
which receives a rectangle element and returns
the length value of its diagonal

[points 5]
*/

// HERE YOUR CODE


/*
Ex4: Write all the required overriding functions
to get a string representation of all provided structs
(they should be five...)
[points 10]
*/

// HERE YOUR CODE
ostream& operator<<(ostream& os, rectangle r) {
    os << "[" << r.base << "," << r.height << "]";
}
bool operator==(rectangle r1, rectangle r2) {
    return ((r1.base == r2.base) && (r1.height == r2.height));
}

double calculateDiagonal(rectangle r) {
    return sqrt(r.base*r.base + r.height*r.height);
}

template <typename T>
nodo<T>* findElement(nodo<T>* p, T x) {
    while(p) {
        if (p->info == x) return p;
        p = p->next;
    };
    return nullptr;
}

template <typename T>
bool isempty(nodo<T>* p) {
    return p==nullptr;
}

// End of overriding functions

int main()
{
    nodo<rectangle>* rptr = nullptr;

    cout << "Lista vuota: " << isempty(rptr) << endl;

    intesta(rptr, {3, 4});
    intesta(rptr, {1, 2});
    intesta(rptr, {8, 5});
    cout << "Lista vuota: " << isempty(rptr) << endl;

    /*expected output
        Lista vuota: 1
        Lista vuota: 0
    */


    rectangle r1 {3,8};
    cout << r1 << " : diagonal " << calculateDiagonal(r1) << "\n";
    /*expected output
    [3,8] : diagonal 8.544
    */
    rectangle r2 {1,2};
    nodo<rectangle>* tmp = findElement(rptr, r2);
    cout << " tmp = " << tmp->info << "\n";
    rectangle rmancante {0,2};
    nodo<rectangle>* tmp2 = findElement(rptr, rmancante);
    if (!tmp2) cout << " Mancante = " << rmancante << "\n";

    /*expected output
     tmp = [1,2]
     Mancante = [0,2]
    */

    /*expected output

    p1 is farther than p2
    p3 is farther than p2

    */

    return 0;
}

