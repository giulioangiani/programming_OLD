/* ES. num.31 pag.293
  dato un elenco di cognomi degli studenti di 1A e quelli di 1B
  memorizzare in un unico vettore l elenco alfabetico 
  degli stidenti delle due classi
*/
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
using namespace std;
vector<string> caricaVettore( )
{
	vector<string> v;
	string s;
// inserimento studenti
	cout<< "studente (inserire fine per concludere): ";
	getline(cin,s);
//aggiunge gli stidenti nel vettore
	while (s != "fine") {
		v.push_back(s);
		cout << "Altro studente (inserire fine per concludere): "<<endl;
		cin >> s;
	}
	return v;
}
void visualizza(vector<string> v)
{
	cout<<"il vettore creato \x8a: "<<endl;
	for(int i = 0; i < v.size(); i++)
		cout << v.at(i) <<endl;
}
int main()
{
	vector<string> vA,vB;
	cout<<"inserisci l elenco degli studenti della 1A: "<<endl;
	vA= caricaVettore();
	cin.ignore();
	cout<<"inserisci l elenco degli studenti della 1B: "<<endl;
	vB=caricaVettore();
	cin.ignore();
//	visualizza(vA);
	sort(vA.begin(),vA.end());
	sort(vB.begin(),vB.end());
	visualizza(vA);
	cout<<endl;
	visualizza(vB);
	int dvAB = vA.size() + vB.size();
	vector<string> vAB(dvAB);
	merge(vA.begin(),vA.end(),vB.begin(),vB.end(),vAB.begin());
	cout<<endl;
	cout<<"visualizza l elenco ordinato degli studenti della 1A e della 1B: "<<endl;
	visualizza(vAB);
	system("pause");
	return 0;
}	
	
