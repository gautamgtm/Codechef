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
#define lmt 100005
#define ln 19

int n, m, h[lmt];
vector<PII> A[lmt];
map<PII, int> edges;
int par[lmt][ln]; // initially all -1

void dfs(int v,int p = -1){
	par[v][0] = p;
	if(p + 1)
		h[v] = h[p] + 1;
	for(int i = 1;i < ln;i ++)
		if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : A[v])	if(p - u.first)
		dfs(u.first,v);
}

int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = ln - 1;i >= 0;i --)
		if(par[v][i] + 1 and h[par[v][i]] >= h[u])
			v = par[v][i];
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = ln - 1;i >= 0;i --)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		FOR(i,0,n-1) A[i].clear();
		edges.clear();
		FOR(i,0,n-2)
		{
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			A[a].PB(MP(b,c));
			A[b].PB(MP(a,c));
			edges[MP(min(a,b),max(a,b))] = c;
		}

		dfs(0);

		scanf("%d", &m);
		FOR(i,0,m-1)
		{
			int u,v,k,ans=0;
			scanf("%d %d %d", &u, &v, &k);
			u--;v--;
			int p = LCA(u,v), parent, cost;
			while(u!=p)
			{
				parent = par[u][0];
				cost = edges[MP(min(u,parent), max(u,parent))];
				if(cost<=k) ans ^= cost;
				u = parent;
			}
			while(v!=p)
			{
				parent = par[v][0];
				cost = edges[MP(min(v,parent), max(v,parent))];
				if(cost<=k) ans ^= cost;
				v = parent;
			}

			printf("%d\n", ans);
		}
	}
}
