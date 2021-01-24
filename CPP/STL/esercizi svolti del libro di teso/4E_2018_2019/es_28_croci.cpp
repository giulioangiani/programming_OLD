/*vettore di numeri 
dato un numero controllare se presente*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int d,num;
	vector <int> v;
	cout<<"Numero (0 per terminare) ";
	cin>>d;
	vector <int>::iterator p;
	
	while( d!=0)
	{
		v.push_back(d);
		cout<<"Altro numero (0 per terminare)";
		cin>>d;
	}
	cout<<endl;
	cout<<"Che numero vuoi cercare? ";
	cin>>num;
	p=find(v.begin(),v.end(),num)+1;
	if(*p==0)
	{
		cout<<"Numero assente\n";
	}
	else
	{
		cout<<"Numero presente\n";
	}
	system("pause");
	return 0;
}
