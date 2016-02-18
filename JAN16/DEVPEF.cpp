//DEVPERF
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
typedef unsigned long long int ll;
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		bool A[n][m];
		for(int i=0; i<n;i++)
		{
			string s;
			cin>>s;
			for(int j=0; j<m;j++)
			{
				if(s[j] == '.') A[i][j] = 0;
				else A[i][j] = 1;
			}
		}
		//Solution
		int sumRow[n]={0}, sumColumn[m]={0};
		for(int i=0; i<n;i++)
		{
			for(int j=0; j<m; j++)
			{
				sumRow[i] += A[i][j];
			}
		}
		for(int i=0; i<m;i++)
		{
			for(int j=0; j<n; j++)
			{
				sumColumn[i] += A[j][i];
			}
		}
		int minRow = -1, maxRow = -1, minColumn = -1, maxColumn = -1;
		for(int i=0; i<n; i++)
		{
			if(sumRow[i])
			{
				minRow = i; break;
			}
		}
		for(int i=n-1; i>-1; i--)
		{
			if(sumRow[i])
			{
				maxRow = i; break;
			}
		}
		for(int i=0; i<m; i++)
		{
			if(sumColumn[i])
			{
				minColumn = i; break;
			}
		}
		for(int i=m-1; i>-1; i--)
		{
			if(sumColumn[i])
			{
				maxColumn = i; break;
			}
		}
 
		int answer;
		if(minRow == -1 || maxRow == -1 || minColumn == -1 || maxColumn == -1)
		{
			answer = 0;
		}
		else
		{
			answer = max((maxRow-minRow+1)/2, (maxColumn-minColumn+1)/2) + 1;
		}
		
		printf("%d\n", answer);		
	}
}
 
