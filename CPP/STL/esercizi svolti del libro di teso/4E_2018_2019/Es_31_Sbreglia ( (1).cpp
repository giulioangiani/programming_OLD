//Es 32 pagina 293
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
//Definzione dei prototipi:
void inputVettore(vector<float>&);
int main()
{
	vector<float> v;
	vector<float> podio(3);
	inputVettore(v);
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), podio.begin());
	for(vector<float>::iterator i=podio.begin(); i!=podio.end(); i++)
		cout<<*i<<endl;
	system("pause");
	return(0);
}
//Definizione delle funzioni:
void inputVettore(vector<float>&v)
{
	float x;
	cout<<"Inserisci un numero o 0 per terminare: ";
	cin>>x;
	while(x!=0)
	{
		v.push_back(x);
		cout<<"Inserisci un numero o 0 per terminare: ";
		cin>>x;
	}
}
