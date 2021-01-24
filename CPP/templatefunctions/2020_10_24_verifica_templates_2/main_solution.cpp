/*
Read the whole program code and fill the spaces with the required functions
DO NOT TOUCH the main program!
You can only comment and uncomment some lines of code
for testing your functions step-by-step

You have 45 minutes from this moment!

Enjoy!
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
Ex1: Write a template function called occurrences
which receives a nodo<T>* pointer and a T element
and return the number occurrences of element in list

[points 10]
*/

// HERE YOUR CODE

template <typename T>
int occurrences(nodo<T>* p, T element) {
    int n = 0;
    while (p) {
        if (p->info == element) n++;
        p=p->next;
    }
    return n;
}

struct point2D {
    double x;
    double y;
};

struct point3D {
    double x;
    double y;
    double z;
};

/*
Ex2: Write all the required overriding functions
to get a string representation of all provided structs
(they should be five...)
[points 10]
*/

// HERE YOUR CODE
ostream& operator<<(ostream& os, point2D p) {
    os << "[" << p.x << "," << p.y << "]";
}
bool operator==(point2D p1, point2D p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y));
}
bool operator>(point2D p1, point2D p2) {
    return ((p1.x*p1.x + p1.y*p1.y) > (p2.x*p2.x + p2.y*p2.y));
}
ostream& operator<<(ostream& os, point3D p) {
    os << "[" << p.x << "," << p.y << "," << p.z << "]";
}
bool operator==(point3D p1, point3D p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z));
}



int main()
{
    nodo<point2D>* ppoint2d = nullptr;
    intesta(ppoint2d, {5, 0});
    intesta(ppoint2d, {1, 0});
    intesta(ppoint2d, {5, 0});
    intesta(ppoint2d, {3, 0});
    intesta(ppoint2d, {4, 5});
    intesta(ppoint2d, {5, 0});

    point2D p1 {5,0};
    cout << p1 << " present " << occurrences(ppoint2d, p1) << " times\n";
    point2D p2 {1,0};
    cout << p2 << " present " << occurrences(ppoint2d, p2) << " times\n";
    point2D p3 {0,1};
    cout << p3 << " present " << occurrences(ppoint2d, p3) << " times\n";
    /*expected output

    [5,0] present 3 times
    [1,0] present 1 times
    [0,1] present 0 times

    */

    nodo<point3D>* ppoint3d = nullptr;
    intesta(ppoint3d, {1, 2, 3});
    intesta(ppoint3d, {1.0, 2, 3});
    intesta(ppoint3d, {2, 5, 6.0});

    point3D p4 {1, 2.0, 3};
    cout << p4 << " present " << occurrences(ppoint3d, p4) << " times\n";

    /*expected output

    [1,2,3] present 2 times

    */

   // REMARK! A point2D is bigger than another if its distance from origin is bigger!
    if (p1 > p2) {
        cout << "p1 is farther than p2" << endl;
    }
    else if (p1==p2) {
        cout << "p1 and p2 are the same point" << endl;
    }
    else {
        cout << "p2 is farther than p2" << endl;
    }

    if (p2 > p3) {
        cout << "p2 is farther than p3" << endl;
    }
    else if (p2==p3) {
        cout << "p2 and p3 are the same point" << endl;
    }
    else {
        cout << "p3 is farther than p2" << endl;
    }

    /*expected output

    p1 is farther than p2
    p3 is farther than p2

    */

    return 0;
}
