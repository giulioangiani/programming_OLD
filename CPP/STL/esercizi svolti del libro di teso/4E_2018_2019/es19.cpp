#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<float> vet;
	vector<float>::iterator i;
	float num;
	float x;
	do
	{
		cout<<"Inserisci un numero (0 per terminare l'inserimento):"<<endl;
		cin>>num;
		vet.push_back(num);
	}while(num!=0);
	cout<<"Numero da controllare: "<<endl;
	cin>>x;
	cout<<"-------------------------Numeri piu grandi di "<<x<<"---------------------------"<<endl;
	
	
	for (i=vet.begin();i!=vet.end();i++)
 	{
		if(*i>x)
		{
			cout<<*i<<endl;
		}
	}
	return 0;
}


