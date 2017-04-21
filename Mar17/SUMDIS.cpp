//
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
#include <assert.h>
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
#define IN(A, B, C)  (B) <= (A) && (A) <= (C)
#define AIN(A, B, C) assert(IN(A, B, C))
#define PRINTV(it,v) for (auto it = v.begin(); it != v.end(); it++) printf("%d ", *it);
#define PRINTA(A, n) for (auto i = 0; i <= (a); i++) printf("%d ", A[i]);

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
		int n,wt;
		scanf("%d", &n);
		bool isSame1 =  true, isSame2 = true;
		vector<vector<PII> > graph(n);
		FOR(i,0,n-2)
		{
			scanf("%d", &wt);
			graph[i].PB(MP(i+1,wt));
		}
		FOR(i,0,n-3)
		{
			scanf("%d", &wt);
			graph[i].PB(MP(i+2,wt));
		}
		FOR(i,0,n-4)
		{
			scanf("%d", &wt);
			graph[i].PB(MP(i+3,wt));
		}

		LL ans=0;
		FOR(i,0,n-3)
		{
			if(graph[i][1].second != graph[i][0].second + graph[i+1][0].second)
			{
				isSame1 = false; break;
			}
		}
		FOR(i,0,n-4)
		{
			if(graph[i][2].second != graph[i][0].second + graph[i+1][0].second  + graph[i+2][0].second)
			{
				isSame2 = false; break;
			}
		}

		//Base Case
		if(isSame1 && isSame2)
		{
			FOR(i,0,n-2)
				ans += (LL)(i+1) * (LL)graph[i][0].second * (LL)(n-1-i);
			printf("%Ld\n", ans);
			continue;
		}
		

		printf("0\n");

	}

}
