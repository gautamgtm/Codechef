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
#define N 100005

vector<PII> graph[N], par[N];
int n,m,M[N],visited[N],ans[N];

struct query{
	int u, v, k, idx;
};

struct comp{
	bool operator ()(const query& q1, const query& q2)
	{
		if(q1.u!=q2.u)
    	return (q1.u < q2.u);
    else
		if(q1.v!=q2.v)
        return (q1.v < q2.v);
    else
    	return (q1.k < q2.k);
	}
};

void dfs(int u, int c, int parent)
{
		visited[u]=1;
    par[u].PB(MP(parent,c));
		FIT(it,graph[u])
		if(!visited[it->first])
				dfs(it->first, it->second, u);
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		FOR(i,0,n-1)
			visited[i] = 0, M[i] = -1;
		scanf("%d", &n);
		FOR(i,1,n-1)
		{
			int u,v,c;
			scanf("%d %d %d\n", &u, &v, &c);
			graph[u].PB(MP(v,c));
			graph[v].PB(MP(u,c));
		}

		scanf("%d", &m);
		query q[m];
		FOR(i,0,m-1)
		{
			int u,v;
			scanf("%d %d %d\n", &u, &v, &q[i].k);
			q[i].u = min(u,v); q[i].v = max(u,v);
			q[i].idx=i;
		}
		sort(q,q+n,comp());
		dfs(1,0,1);

		int idx=0;
		while(idx<m)
		{
			VI vec;
			int f=0, f1=0, f2=0, u=q[idx].u, v=q[idx].v, num=0;
			while(true)
			{
				if(M[u]==idx && u!=f1)
				{
					f = u; break;
				}
				M[u] = idx;
				f1 = u;
				u = par[u][0].first;

				if(M[v]==idx && v!=f2)
				{
					f = v; break;
				}
				M[v] = idx;
				f2 = v;
				v = par[v][0].first;
			}

			u=q[idx].u; v=q[idx].v;
			while(u!=f && u!=1)
			{
				vec.PB(par[u][0].second);
				u = par[u][0].first;
			}
			while(v!=f && v!=1)
			{
				vec.PB(par[v][0].second);
				v = par[v][0].first;
			}

			sort(vec.begin(), vec.end());
			u=q[idx].u; v=q[idx].v;
			int i=0;
			while(true)
			{
				if(idx>=m || q[idx].u != u || q[idx].v!=v)
				{
					vec.clear();break;
				}

				while(vec[i]<=q[idx].k && i<vec.size())
					num ^= vec[i], i+=1;
				ans[q[idx].idx] = num;
				idx++;
			}
		}

		FOR(i,0,m-1)
			printf("%d\n", ans[i]);
	}
}
