//Es 30 pagina 293
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
//Definzione dei prototipi:
void inputVettore(vector<int>&);
void copiaVettore(vector<int>, vector<int>&);
int main()
{
	vector<int> v1;
	
	inputVettore(v1);
	vector<int> v2(0);
	copiaVettore(v1, v2);
	system("pause");
	return(0);
}
//Definizione delle funzioni:
void inputVettore(vector<int>&v1)
{
	int x;
	cout<<"Inserisci un numero o 0 per terminare: ";
	cin>>x;
	while(x!=0)
	{
		v1.push_back(x);
		cout<<"Inserisci un numero o 0 per terminare: ";
		cin>>x;
	}
}
void copiaVettore(vector<int> v1, vector<int>&v2)
{
	vector<int>::iterator i;
	for(i=v1.begin(); i!=v1.end(); i++)
	{
		if((*i)<=100)
			*i=(*i)*2;
		else
			*i=(*i)*3;
	}
	copy(v1.begin(), v1.end(), v2.begin());	//la copia non viene eseguita
	cout<<"visua copia\n";
	for(i=v2.begin(); i!=v2.end(); i++)
	{
		cout<<*i<<endl;
	}
}
