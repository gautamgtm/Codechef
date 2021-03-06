//CHFNFRN
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
		int n,m;
		scanf("%d %d", &n, &m);

		//G is the complement of the actual graph
		bool G[n][n];
		FOR(i,0,n-1)
		{
			FOR(j,0,n-1)
			{
				if(i!=j)
					G[i][j] = 1;
				else
					G[i][j] = 0;
			}
		}
		FOR(i,0,m-1)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			a--,b--;
			G[a][b]=0;
			G[b][a]=0;
		}

		if(n<=2)
		{
			printf("YES\n");
			continue;
		}

		bool isPossible = true;
		//Check if the complement of Graph is Bipartite.
		int color[n];
		FOR(i,0,n-1)
			color[i] = -1;
		//BFS
		FOR(i,0,n-1)
		{
			if(color[i]!=-1)
				continue;

			color[i] = 1;
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int u = q.front();
				q.pop();

				FOR(v,0,n-1)
				{
					if(G[u][v]==1 && color[v]==-1)
					{
						color[v] = 1-color[u];
						q.push(v);
					}
					else
					if(G[u][v]==1 && color[v]==color[u])
					{
						isPossible = false;
						break;
					}
				}
				if(!isPossible)
				break;
			}
			if(!isPossible)
				break;
		}

		if(isPossible)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
