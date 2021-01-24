#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void successivo(int x) {
    cout << x+1 << endl;
}

void stampa20 (pair<string, double> elem) {
    cout << elem.first << ":" << elem.second*0.8 << endl;
}

int main()
{
    cout << "==================== QUEUE =========================\n";

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "front: " << q.front() << endl;
    cout << "size: " << q.size() << endl;
    cout << "empty: " << q.empty() << endl;
    cout << endl;
    q.pop();
    cout << "front: " << q.front() << endl;
    cout << "size: " << q.size() << endl;
    cout << "empty: " << q.empty() << endl;
    cout << endl;
    q.pop();
    cout << "front: " << q.front() << endl;
    cout << "size: " << q.size() << endl;
    cout << "empty: " << q.empty() << endl;
    cout << endl;
    q.pop();
    cout << "front: " << q.front() << endl;
    cout << "size: " << q.size() << endl;
    cout << "empty: " << q.empty() << endl;

    cout << "==================== MAP =========================\n";

    map<string, string> rubrica;
    rubrica["giulio"] = "3474001416";
    rubrica["alle"] = "3339876543";
    rubrica.insert(pair<string, string>{"barbara", "3471234567"});
    for ( map<string, string>::iterator it=rubrica.begin(); it!=rubrica.end(); ++it)
        cout << it->first << " => " << it->second << '\n';

    cout << "Barbara: " << rubrica.at("barbara") << endl;
   cout << "presente nonce?: " << rubrica.count("nonce") << endl;
//    cout << "Nonce: " << rubrica.at("nonce") << endl;

    vector<int> v {4,7,2,3,9,7};
    for_each(v.begin(), v.end(), successivo);

    cout << "=================================\n";

    sort(v.begin(), v.end());
    for ( vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
        cout << *it << '\n';


    map<string, double> menu { {"Pizza", 5.4}, {"Sushi", 10.99} };
    cout << menu.size();
    for_each(menu.begin(), menu.end(), stampa20);

    return 0;
}
