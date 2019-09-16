#include <iostream>
#include <fstream>
#include <list>
#include <typeinfo>

using namespace std;

struct element {
    char name[100], familyname[100];
    int age;
};

list<element> persons;

void insert(element x, const string fname) {
    //ofstream fp(fname, ios::binary);
    // use ofstream fp(fname, ios::binary|ios:app) for appending data
    ofstream fp(fname, ios::binary|ios::app);
    fp.write((char*) (&x), sizeof(x));
    fp.close();
}

list<element> readfile(const string fname) {
    ifstream fp(fname, ios::in | ios::binary);
    list<element> result;
    while(!fp.eof()) {
		element x;
		fp.read((char*) &x, sizeof(x));
		if (fp) {
		//	cout << x.name << ":" << x.age << " : " << typeid(x).name() << " > " << sizeof(x) << "-" << fp.eof() << endl;
			result.push_back(x);
		}
	}
	//cout << "EOF reached " << endl;
    fp.close();
    return result;
}

int main()
{

    string fname = "test.dat";
    cout << "\n ### write data into file ### \n";

	element tmp {"giulio", "angiani", 46};
	insert(tmp, fname);
	element tmp2 {"barbara", "cattani", 48};
	insert(tmp2, fname);

    cout << "\n ### file content ### \n";
	persons = readfile(fname);
	int cont = 1;
	for (list<element>::iterator it = persons.begin(); it != persons.end(); ++it  ) {
		cout << cont << ") " << it->name << ":" << it->familyname << ":" << it->age << endl;
		cont++;
	}
	
	return 0;
}

