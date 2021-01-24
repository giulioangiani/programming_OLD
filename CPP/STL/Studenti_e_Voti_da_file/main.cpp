#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>

/*

Sia dato il file allegato così strutturato:
La prima riga contiene il numero N di studenti presenti
Le successive N righe contengono i dati degli studenti nel formato matricola,nome,cognome
La riga successiva contiene il numero V di voti presenti
Le successive V righe contengono i dati delle verifiche nel formato matricola,materia,voto.

Leggere il file voti.txt e, dopo aver creato e caricato le strutture dati adeguate,
stampare a video:
- La media dei voti di ogni studenti in Matematica e Italiano
- Lo studente con la media in Matematica più alta
- Lo studente con il voto in Italiano più alto

*/

using namespace std;

vector<string> split(string str, char delim)
{
    stringstream ss(str);
    string token;
    vector<string> result;
    while (getline(ss, token, delim)) {
        result.push_back(token);
    }
    return result;
}

int main() {

    map<string, list<double>> voti_mate;
    map<string, list<double>> voti_ita;
    map<string, string> studenti;

    ifstream fin;
    fin.open("voti.txt");

    int N;
    fin >> N;
    // leggo i dati di tre persone e li scrivo su file
    for (int i=0; i<N; i++) {
        string s;
        fin >> s;
        vector<string> persona = split(s, ',');
        string matricola = persona[0];
        string nome = persona[1];
        string cognome = persona[2];
        // inserisco studente nella mappa studenti
        studenti[matricola] = cognome + " " + nome;
        // creo una lista vuota con la lista dei voti per lo studente indicato nella mappa voti
        voti_mate[matricola] = {};
        voti_ita[matricola] = {};

    }

    /*
    for (map<string, string>::iterator it = studenti.begin(); it != studenti.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    for (map<string, list<double>>::iterator it = voti_mate.begin(); it != voti_mate.end(); it++) {
        cout << "voti mate di " << it->first << "  " << endl;
    }
    for (map<string, list<double>>::iterator it = voti_ita.begin(); it != voti_ita.end(); it++) {
        cout << "voti ita di " << it->first << "  " << endl;
    }
    */

    // adesso leggo i voti
    int V;
    fin >> V;
    // leggo i dati di tre persone e li scrivo su file
    for (int i=0; i<V; i++) {
        string s;
        fin >> s;
        vector<string> voto = split(s, ',');
        string matricola = voto[0];
        string materia = voto[1];
        double votomateria = stod(voto[2]);
        // inserisco il voto ne
        if (materia == "Matematica") {
            voti_mate[matricola].push_back(votomateria);
        }
        if (materia == "Italiano") {
            voti_ita[matricola].push_back(votomateria);
        }
    }
      cout << "\n\n";

    // calcolo la media di ogni studente in Italiano
     string matricola_voto_ita_piu_alto = "";
     double voto_ita_piu_alto = -1;
     for (map<string, list<double>>::iterator it = voti_ita.begin(); it != voti_ita.end(); it++) {
            string matricola = it->first;
            list<double> voti_studente = it->second;
            int numerovoti_ita = voti_studente.size();
            string nomestudente = studenti[matricola];

            double sum=0;
            for (list<double>::iterator it=voti_studente.begin(); it != voti_studente.end(); ++it){
                double singolovoto_ita = *it;
                sum = sum + singolovoto_ita;

                if (singolovoto_ita > voto_ita_piu_alto) {
                    voto_ita_piu_alto = singolovoto_ita;
                    matricola_voto_ita_piu_alto = matricola;
                }
            }
            double media_studente = sum/numerovoti_ita;
            cout << "Media Voti Ita di " << nomestudente << " : " << media_studente << endl;
      }
      string nome_studente_voto_ita_piu_alto = studenti[matricola_voto_ita_piu_alto];
      cout << "Lo studente con il voto Ita più alto è " << nome_studente_voto_ita_piu_alto << " ["<<voto_ita_piu_alto<<"]\n";

      cout << "\n\n";



    // calcolo la media di ogni studente in Matematica

     string matricola_media_mate_piu_alta = "";
     double media_mate_piu_alta = -1;
     for (map<string, list<double>>::iterator it = voti_mate.begin(); it != voti_mate.end(); it++) {
            string matricola = it->first;
            list<double> voti_studente = it->second;
            int numerovoti_mate = voti_studente.size();
            string nomestudente = studenti[matricola];

            double sum=0;
            for (list<double>::iterator it=voti_studente.begin(); it != voti_studente.end(); ++it){
                sum+=*it;
            }
            double media_studente = sum/numerovoti_mate;
            cout << "Media Voti Mate di " << nomestudente << " : " << media_studente << endl;

            if (media_studente > media_mate_piu_alta) {
                media_mate_piu_alta = media_studente;
                matricola_media_mate_piu_alta = matricola;
            }
      }
      string nome_studente_media_mate_piu_alta = studenti[matricola_media_mate_piu_alta];
      cout << "Lo studente con la media Mate più alta è " << nome_studente_media_mate_piu_alta << " ["<<media_mate_piu_alta<<"]\n";

    fin.close();
    return 0;
}
