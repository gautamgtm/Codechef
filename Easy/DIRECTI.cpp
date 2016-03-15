//DIRECTI
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		string move[n], on, name[n];
		for(int i=0; i<n;i++)
		{
			cin>>move[i]>>on;
			getline(cin,name[i]);
		}
		
		cout<<"Begin on"<<name[n-1]<<endl;
		for(int i=n-2; i>=0; i--)
		{
			if(move[i+1] == "Left")
				cout<<"Right on"<<name[i]<<endl;
			else if(move[i+1] == "Right")
				cout<<"Left on"<<name[i]<<endl;
		}
		cout<<endl;
	}

}