/*
22) Dopo aver memorizzato in un vettore di interi 20 numeri visualizzare gli ultimi 4 inseriti usando un iteratore

*/
#include<iostream>
#include<vector>
#define massimo 20;
using namespace std;

int main()
{
	vector <int> vet;
	vector <int>::iterator iteratore;
	int num;
	for(int i=0; i<massimo ;i++)
	{
		cout<<"Numero :"<<endl;
		cin>>num;
		vet.push_back(num);
		cout<<endl;
	}
	cout<<endl;
	for(iteratore = vet.end()-1; iteratore != vet.end()-5; iteratore--)
	{
        cout<< *iteratore << endl;  
	}

}


