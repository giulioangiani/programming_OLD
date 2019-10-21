#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <set>

using namespace std;

// grafo con matrice di adiacenza - orientato ciclico
// matrice di interi con valore positivo sugli archi (peso)
// valore 0 se non c'è arco
// breadth-first search - ricerca in ampiezza

// albero ricoprente (BFS) rappresentato con map di liste di char

const int N = 9;
const int MAXINT = 1000000;

typedef int grafo[N][N];
char archi[N] { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

char rootnode = 'A';

map<char, list<char>> bfs;


grafo g {
                {0, 2, 0, 3, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 3, 0, 8, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 8},
                {0, 0, 3, 0, 4, 1, 0, 0, 0},
                {0, 0, 0, 4, 0, 2, 0, 0, 0},
                {0, 0, 4, 1, 0, 0, 0, 0, 2},
                {0, 0, 0, 0, 0, 0, 0, 3, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 7},
                {0, 0, 0, 0, 0, 2, 0, 4, 0},
            };


int getNodePosition(char c) {
    // get item position
    int idx = -1;
    for (int i=0; i<N; i++) {
        if (archi[i] == c) idx = i;
    }
    return idx;
}

list<char> adiacenti(char node, grafo g) {
    int pos = getNodePosition(node);
    list<char> result {};
    for (int i=0; i<N; i++) {
        if (g[pos][i] > 0) result.push_back(archi[i]);
    }
    return result;
}

map<char, list<char>> bfsearch(char startnode, grafo g) {
    // ritorna l'albero ricoprente di g a partire da startnode
    set<char> visited {};
    map<char, list<char>> result {};

    // use a queue for managing nodes which are not visited yet
    queue<char> q {};
    q.push(startnode);
    while (!q.empty()) {
        // get first element from queue
        char c = q.front();
   //     printf("Extract : %c\n", c);
        q.pop();
        // set node as visited
        visited.insert(c);
        // get its adjacent nodes
        list<char> a = adiacenti(c, g);

        // put in the queue and in the result tree all not visited adjacent nodes
        for (list<char>::iterator it=a.begin(); it!=a.end(); ++it) {
            char adj = *it;
            if (!visited.count(adj)) {
                visited.insert(adj);
                q.push(adj);
                result[c].push_back(adj);
            }
        }
    }
    return result;
}

list<char> dijkstra(char start, char end, grafo g) {
    list<char> bestpath {};


    // if start == end return emptylist
    if (start == end) return bestpath;

    // distance from start to other nodes
    map<char, int> distance;


    return bestpath;
}


using namespace std;

int main()
{
    cout << "GRAFO" << endl;
    printf(" ");
    for (int i=0; i<N; i++) {
        printf(" %c", archi[i]);
    }
    cout << endl;
    for (int i=0; i<N; i++) {
        printf("%c ", archi[i]);
        for (int j=0; j<N; j++) {
            printf("%d ", g[i][j]);
        }
        cout << endl;
    }

    for(char c = 'A'; c<= 'F' ; c++) {
        cout << "Adiacenti di " << c << " : ";
        list<char> a = adiacenti(c, g);
        for (list<char>::iterator it=a.begin(); it!=a.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

    }


    cout << "****************************************************" << endl;
    cout << "************* ALBERI RICOPRENTI ********************" << endl;
    for(char c = 'A'; c<= 'F' ; c++) {
        printf("\n\nAlbero a partire da '%c'\n",  c);
        map<char, list<char>> bfs_tree = bfsearch(c, g);
   //     cout << "len di bfs_tree " << bfs_tree.size() << endl;

        for (map<char, list<char>>::iterator it=bfs_tree.begin(); it!=bfs_tree.end(); ++it) {
            cout << it->first << " : ";

            for (list<char>::iterator it2=it->second.begin(); it2!=it->second.end(); ++it2) {
                cout << *it2 << " ";
            }

            cout << endl;

        }
    }


    return 0;
}

