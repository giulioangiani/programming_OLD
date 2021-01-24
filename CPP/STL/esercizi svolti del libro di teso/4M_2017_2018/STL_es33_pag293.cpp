/*es 33 oag 293.cpp I voti assegnati a 30 studenti di una classe i una prova di italiano sono memorizzati in un vettore.
Dopo aver ordinato i voti in ordine crescente, visualizzare quali voti diversi tra loro sono stati assegnati, 
riducendo a uno i voti uguali*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

    int main(){
	
	float voti;
	vector<float> v;
    vector<float>::iterator i;
	int cont, cont_uguali;
	
	cout <<" Inserisci i voti dei 30 studenti "<<endl;
  cout<< " Inserisci il voto dello studente 1: ";
 cin>>voti;
 	v.push_back(voti);
 	
 	
   while (cont<29){
	  
	cont++; 
    cout<< " Inserisci il voto dello studente  "<< cont+1 <<": ";
    cin>>voti;
    v.push_back(voti);
    
    if (voti<0 || voti>10){
    	
    	cout<<" REINSERIRE, DATO ERRATO "<<endl;
    	cont--;
	}
}



sort(v.begin(), v.end()); //ordinamento
cout<<endl;
cout<<" VOTI ORDINATI IN ORDINE CRESCENTE  " <<endl;
for(i=v.begin(); i!=v.end() ; i++){
	cout<< *i <<endl;

}
cout<<endl;

int g;
int num=0;

for(i=v.begin(); i!=v.end() ; i++){

g=count(v.begin(), v.end(), num);

if (g!=0){
	cout<<" Il voto " <<num<< " e' presente: "<<g<<" volte "<<endl;
}
num++;
}

i=unique(v.begin(), v.end());
v.erase(i, v.end());
cout<<endl;
cout<<" VOTI ORDINATI IN ORDINE CRESCENTE, TOGLIENDO I DOPPI " <<endl;
	for(i=v.begin(); i!=v.end() ; i++){
	cout<< *i <<endl;

}
	}
