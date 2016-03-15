//SPOON
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <climits>
#include <utility>
using namespace std;

#define VI vector <int>
#define PII pair <int, int>
#define LL long long
#define ULL unsigned long long
#define LDB long double
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,a,b) for (auto i = (a); i <= (b); i++)
#define FORD(i,a,b) for (auto i = (a); i >= (b); i--)
#define FORV(CAKE,it) for(auto it =CAKE.begin(); it != CAKE.end(); it++)
#define FIT(it,v) for (auto it = v.begin(); it != v.end(); it++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x < 0)?-(x):x)

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		char matrix[n][m];
		FOR(i,0,n-1)
		{
			string str;
			cin>>str;
			FOR(j,0,m-1)
			{
				if(str[j]>=97 && str[j]<=122)
					matrix[i][j] = str[j]-97+65;
				else
					matrix[i][j] = str[j];
			}
		}

		string spoon = "SPOON", found = "There is a spoon!", notFound = "There is indeed no spoon!";
		bool flag = false;

		if(n<5 && m<5)
		{
			cout<<notFound<<endl;
			continue;
		}

		//Search in Row
		FOR(i,0,n-1)
		{
			int idx=0, start=0;
			while(start<m && idx <5)
			{
				if(matrix[i][start] == spoon[idx])
				{
					idx++;start++;
				}
				else
				{
					if(idx == 0)
						start++;
					idx = 0;
				}
			}
			if(idx == 5)
			{
				flag = true;
				break;
			}
		}

		if(flag)
		{
			cout<<found<<endl;
			continue;
		}
			
		//Search in Columns
		FOR(i,0,m-1)
		{
			int idx=0, start=0;
			while(start<n && idx <5)
			{
				if(matrix[start][i] == spoon[idx])
				{
					idx++;start++;
				}
				else
				{
					if(idx == 0)
						start++;
					idx = 0;
				}
			}
			if(idx == 5)
			{
				flag = true;
				break;
			}
		}

		if(flag)
			cout<<found<<endl;
		else
			cout<<notFound<<endl;
	}

}