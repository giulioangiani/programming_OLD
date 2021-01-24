//Es 31 pagina 293
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
void inputVettore(vector<string>&);
int main()
{
	vector<string> v1;
	vector<string> v2;
	cout<<"Classe A\n";
	inputVettore(v1);
	cout<<"Classe B\n";
	inputVettore(v2);
	vector<string> v3(v1.size()+v2.size());
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	vector<string>::iterator i;
	cout<<"Output nuovo vettore:\n\n";
	for(i=v3.begin(); i!=v3.end(); i++)
	{
		cout<<*i<<endl;
	}
	system("pause");
	return(0);
}
//Definizione delle funzioni:
void inputVettore(vector<string>&v)
{
	string x;
	cout<<"Inserisci un cognome: ";
	cin>>x;
	while(x!="*")
	{
		v.push_back(x);
		cout<<"Inserisci un cognome: ";
		cin>>x;
	}
}
