//ORACLCS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		//int countA[n] = {0}, countB[n] = {0};
		int answer = 100;
 
		for (int i=0; i<n; i++)
		{
			int countA = 0, countB = 0;
			string input;
			cin>>input;
 
			for (int j=0; j< input.size(); j++)
			{
				if(input[j] == 'a')
				{
					countA++;
				}
				else if(input[j] == 'b')
				{
					countB++;
				}
			}
			if (countA < answer)
			{
				answer = countA;
			}
			if (countB < answer)
			{
				answer = countB;
			}
		}
		printf("%d\n", answer);
	}
}
