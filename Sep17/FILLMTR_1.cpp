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

bool isBipartite(vector<VI> graph, int u, VI& color)
{
	color[u] = 1;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int t = q.front();
		q.pop();

		FIT(it, graph[t])
		{
			int v = *it;
			if(color[v] == -1)
			{
				color[v] = 1 - color[t];
				q.push(v);
			}
			else
			if(color[t] == color[v]) return 0;
		}
	}
	return 1;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,q,flag=1;
		scanf("%d %d", &n, &q);
		map<int,int> mp[n];
		vector<VI> graph(n);
		int vert=n;
		FOR(i,0,q-1)
		{
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			if(a>b) swap(a,b);
			if(a==b)
			{
				if(c) flag=0;
				continue;
			}
			if(mp[a].find(b) == mp[a].end())
			{
				mp[a][b] = c;
				if(c)
				{
					graph[a].PB(b);
					graph[b].PB(a);
				}
				else
				{
					graph[a].PB(vert);
					graph[b].PB(vert++);
					VI temp = {a,b};
					graph.push_back(temp);
				}
			}
			else if(mp[a][b] != c) flag=0;
		}
		if(!flag)
		{
			printf("no\n");
			continue;
		}

		VI color(vert,-1);
		FOR(i,0,vert-1)
		{
			if(color[i] == -1)
			{
				if(isBipartite(graph,i,color) == 0) {flag = 0; break;}
			}
		}

		if(flag) printf("yes\n");
		else printf("no\n");
	}

}
