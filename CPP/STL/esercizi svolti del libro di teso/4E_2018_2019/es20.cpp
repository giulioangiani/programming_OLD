#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void vectorContent(vector<string>&, vector<string>::iterator);
void getString(vector<string>&, vector<string>::iterator);

int main() {
	
	vector<string> vet;
	vector<string>::iterator i;	
	
	getString(vet, i);
	
	cout<<"-------------------Contenuto vettore--------------------"<<endl;
	
	vectorContent(vet, i);
	
	cout<<"Ho appena eliminato tutte le parole dal vettore... provare per credere."<<endl;
	vet.clear();
	
	cout<<"-------------------Contenuto vettore--------------------"<<endl;
	
	vectorContent(vet, i);
	
	return 0;
	
}

void vectorContent(vector<string>& vet, vector<string>::iterator i) {
	
	for(i=vet.begin(); i!=vet.end(); i++) {
		cout<<*i<<endl;
	}
	
}

void getString(vector<string>& vet, vector<string>::iterator i) {
	
	string s;
	
	while (s!="*") {
		cout<<"Inserisci una parola (* per terminare l'inserimento): "<<endl;
		cin>>s;
		vet.push_back(s);
	}
	
	vet.erase(remove(vet.begin(), vet.end(), "*"), vet.end());
	
}
