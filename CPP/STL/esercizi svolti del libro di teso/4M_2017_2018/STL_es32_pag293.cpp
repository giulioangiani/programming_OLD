/*es 32 oag 293.cpp Dopo aver memorizzato in un vettore i tempi conseguiti da 10 concorrenti in una prova
di velocità, copiare in un altro vettore i primi tre tempi migliori. */



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	float tempo;
	vector<float> v;
	vector<float> v2(3);
    vector<float>::iterator i;
    vector<float>::iterator j;
    int cont;

 cout <<" Inserisci il tempo di 10 concorrenti "<<endl;
  cout<< " Inserisci tempo del concorrente 1: ";
 cin>>tempo;
 	v.push_back(tempo);
 	
 	
   while (cont<9){
	  
	cont++; 
    cout<< " Inserisci tempo del concorrente  "<< cont+1 <<": ";
    cin>>tempo;
    v.push_back(tempo);
}


sort(v.begin(), v.end());

/*for(i=v.begin(); i!=v.begin() +3; i++){   //visualizzare solo un certo numero di elementi
	cout<< *i <<endl;
}*/
/*for(i=v.end(); i!=v.end() -3 ; i++){   //non funzionante
	cout<< *i <<endl;
}*/


for(i=v.begin(); i!=v.end() ; i++){
	cout<< *i <<endl;
}

cout<< " VETTORE DUE " <<endl;

copy(v.begin(), v.begin() +3, v2.begin());

for (j=v2.begin(); j!=v2.end(); j++){
		cout<< *j <<endl;
}


//copy(v.begin(), v.begin() + 3, v2.begin());
}

	


