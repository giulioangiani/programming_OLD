#include <iostream>
#include "lista.cpp"

using namespace std;

bool recursive_search(node_ptr p, int n) {
    if (p == nullptr) return false;
    else return (
                    (p->content == n)
                    ||
                    (recursive_search(p->next, n))
                 );
}

int contaoccorrenze(node_ptr p, int n) {
    if (p == nullptr) return 0;
    else if (p->content == n) return 1 + contaoccorrenze(p->next, n);
    else return contaoccorrenze(p->next, n);
}

int main()
{
    node_ptr p = nullptr;
    in_testa(3, p);
    in_testa(7, p);
    in_testa(8, p);
    in_testa(9, p);
    in_testa(8, p);
    print_list(p);
    cout << " 10 presente: " << recursive_search(p, 10) << endl;
    cout << " 8 presente: " << recursive_search(p, 8) << endl;
    cout << endl;
    cout << " 8 presente: " << contaoccorrenze(p, 8) << " volte" << endl;
    cout << " 10 presente: " << contaoccorrenze(p, 10) << " volte" << endl;

    return 0;
}
