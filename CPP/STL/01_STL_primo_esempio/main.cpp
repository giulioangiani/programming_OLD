#include <iostream>
#include <vector>
#include <list>
using namespace std;


struct punto {
    float x;
    float y;
};
ostream& operator<<(ostream& os, const punto &p) {
    os << "[" << p.x << "," << p.y << "]";
}

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    v.push_back(1);
    cout << v.size() << endl;
    v.pop_back();
    cout << v.size() << endl;
    cout << v[0] << endl;
    cout << v[2] << endl;
    cout << v.size() << endl;
    cout << v[3] << endl;

    for (int i=0; i<v.size(); i++) {
        cout << i << ":" << v[i] << endl;
    }

    vector<int>::iterator vit = v.begin();
    cout << *vit << endl;
    cout << &*vit << endl;
    vit++;
    cout << *vit << endl;
    cout << &*vit << endl;
    vit = v.end();
    cout << &*vit << endl;

    for (vit = v.begin(); vit != v.end(); vit++) {
        cout << *vit << endl;
    }
    cout << "========\n";
    vector<int>::reverse_iterator rvit = v.rbegin();
    for (rvit = v.rbegin(); rvit != v.rend(); rvit++) {
        cout << *rvit << endl;
    }
    cout << "========\n";

    for (vit = v.end()-1; vit != v.begin()-1; vit--) {
        cout << *vit << endl;
    }


    ///////////////////////////////////
    // LIST
    cout << "========LIST========\n";

    list<int> l;
    l.push_back(5);
    l.push_back(2);
    l.push_back(1);
    l.push_back(8);
    for (list<int>::iterator lit = l.begin(); lit != l.end(); lit++) {
        cout << *lit << endl;
    }
    cout << endl;
    l.pop_back();
    for (list<int>::iterator lit = l.begin(); lit != l.end(); lit++) {
        cout << *lit << endl;
    }
    cout << "SORT" << endl;
    l.sort();
    for (list<int>::iterator lit = l.begin(); lit != l.end(); lit++) {
        cout << *lit << endl;
    }
    cout << "REVERSE" << endl;
    l.reverse();
    for (list<int>::iterator lit = l.begin(); lit != l.end(); lit++) {
        cout << *lit << endl;
    }

    ///////////////////////////////////
    // PUNTO
    cout << "========PUNTO========\n";
    list<punto> plist;

    punto a {0, 5};
    plist.push_back(a);
    plist.push_back({3,5});
    plist.push_back({1,2});
    plist.push_back({7,4});
    for (list<punto>::iterator pit = plist.begin(); pit != plist.end(); pit++) {
        cout << *pit << endl;
    }
    plist.sort(); /// CORREGGILO!!!

    return 0;
}
