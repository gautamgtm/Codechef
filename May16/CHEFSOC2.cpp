//CHEFSOC2
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
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m,s;
		scanf("%d %d %d", &n, &m, &s);
		int St[m];
		FOR(i,0,m-1)
			scanf("%d", &St[i]);

		//DP Solution
		int DP[m][n];
		memset(DP,0,sizeof(DP));

		//Find the minm pass that could be made by the first dog
		int idx=0;
		while(!(s-1+St[idx] < n || s-1-St[idx] >= 0))
			idx++;
		if(idx < m)
		{
			if(s-1+St[idx] < n)
			{
				DP[idx][s-1+St[idx]] = 1;
			}
			if(s-1-St[idx] >= 0)
			{
				DP[idx][s-1-St[idx]] = 1;
			}

			FOR(t,idx+1,m-1)
			{
				FOR(pos,0,n-1)
				{
					if(pos-St[t] >= 0)
						DP[t][pos] = (DP[t][pos] + DP[t-1][pos-St[t]])%MOD;					
					if(pos+St[t] < n)
						DP[t][pos] = (DP[t][pos] + DP[t-1][pos+St[t]])%MOD;					
				}	
			}			
		}
	
		FOR(i,0,n-1)
		{
			printf("%d ", DP[m-1][i]);
		}
		printf("\n");
	}

}