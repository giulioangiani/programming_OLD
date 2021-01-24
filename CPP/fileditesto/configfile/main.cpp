#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin;
    fin.open("config.ini");

    string nome,cognome,account,email;

    string tmp;
     while ( !fin.eof() ) {
            fin>>tmp;
//        getline(fin, tmp);
        if (tmp == "[User]") {
            // blocco user
            fin>>nome;
            nome = nome.replace(0, 5, "");

            fin>>cognome;
            cognome = cognome.replace(0, 11, "");

            getline(fin, account);
            account = account.replace(0, 8, "");

            getline(fin, email);
            email = email.replace(0, 6, "");

            fin >> account;
            fin >> email;
        }
    }

    cout << nome << endl;
    cout << cognome << endl;
    cout << account << endl;
    cout << email << endl;

    fin.close();
    return 0;
}
