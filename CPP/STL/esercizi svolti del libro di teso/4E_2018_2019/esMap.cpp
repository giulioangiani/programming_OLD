#include <iostream>
#include <map>
#include <string>

using namespace std;

int main () {

	map<int, string> note;
	int freq;
	string nomenota;
	
	cout<<"Frequenza della nota (0=fine): "<<endl;
	cin>>freq;
	
	while (freq != 0) {
		cout<<"Nome della nota: "<<endl;
		cin>>nomenota;
		note[freq]=nomenota;
		cout<<"Frequenza della nota: "<<endl;
		cin>>freq;
	}
	
	map<int, string>::iterator i;
	for (i=note.begin(); i != note.end(); i++) {
		cout<<i->second <<" : "<<i->first<<" Hz"<<endl;
	}
	return 0;
	

}
