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
#define root 0
#define N 1005
#define LN 18

VI graph[N], magicNum[N], idx[N], st[4*N], xr[4*N];
int baseArray[N], ptr, n, m;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];

// Segment Tree
void buildTree(int node, int l, int r)
{
	if(l>r) return;
	if(l==r)
	{
		st[node].PB(baseArray[l]);
		xr[node].PB(baseArray[l]);
		return;
	}
	buildTree(2*node, l, (l+r)/2);
	buildTree(1+2*node, 1+(l+r)/2, r);
	merge(st[2*node].begin(), st[2*node].end(), st[1+2*node].begin(), st[1+2*node].end(), back_inserter(st[node]));
	for(int i=1; i<=st[node].size(); i++)
		xr[node].PB(xr[node][i-1]^st[node][i-1]);
}

int queryTree(int node, int l, int r, int a, int b, int k)
{
	if(l>r || b<l || r<a)
		return 0;
	if(l>=a && r<=b)
	{
		int t = upper_bound(st[node].begin(),st[node].end(),k)-st[node].begin();
		return xr[node][t];
	}
	int q1 = queryTree(2*node, l, (l+r)/2, a, b, k);
	int q2 = queryTree(1+2*node, 1+(l+r)/2, r, a, b, k);
	return q1 ^ q2;
}

// Heavy Light Decomposition

int query_up(int u, int v, int k)
{
	if(u == v) return 0;
	int uchain, vchain = chainInd[v], ans = 0;
	while(true)
	{
		uchain = chainInd[u];
		if(uchain == vchain)
		{
			if(u==v) break;
			//printf("%d %d\n", posInBase[v]+1, posInBase[u]+1);
			ans ^= queryTree(1, 0, ptr-1, posInBase[v]+1, posInBase[u], k);
			break;
		}
		//printf("%d %d\n", posInBase[chainHead[uchain]], posInBase[u]);
		ans ^= queryTree(1, 0, ptr-1, posInBase[chainHead[uchain]], posInBase[u], k);
		u = chainHead[uchain];
		u = pa[0][u];
	}
	return ans;
}

int LCA(int u, int v)
{
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	FOR(i,0,LN-1) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	FORD(i,LN-1,0)
	{
		if(pa[i][u] != pa[i][v])
		{
			u = pa[i][u];
			v = pa[i][v];
		}
	}
	return pa[0][u];
}

void query(int u, int v, int k)
{

	int lca = LCA(u, v);
	int ans1 = query_up(u, lca, k);
	int ans2 = query_up(v, lca, k);
	printf("%d\n", ans1^ans2);
}

void HLD(int curNode, int cost, int prev) {
	if(chainHead[chainNo] == -1)
		chainHead[chainNo] = curNode;
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;

	int sc = -1, ncost;
	FOR(i,0,graph[curNode].size()-1)
	{
		if(graph[curNode][i] != prev)
		{
			if(sc == -1 || subsize[sc] < subsize[graph[curNode][i]])
			{
				sc = graph[curNode][i];
				ncost = magicNum[curNode][i];
			}
		}
	}

	if(sc != -1) HLD(sc, ncost, curNode);

	FOR(i,0,graph[curNode].size()-1)
	{
		if(graph[curNode][i] != prev)
		{
			if(sc != graph[curNode][i])
			{
				// New chains at each normal node
				chainNo++;
				HLD(graph[curNode][i], magicNum[curNode][i], curNode);
			}
		}
	}

}

void dfs(int cur, int prev, int _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	FOR(i,0,graph[cur].size()-1)
	{
		if(graph[cur][i] != prev)
		{
			otherEnd[idx[cur][i]] = graph[cur][i];
			dfs(graph[cur][i], cur, _depth+1);
			subsize[cur] += subsize[graph[cur][i]];
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		//Clean
		FOR(i,0,n-1)
		{
			graph[i].clear();
			magicNum[i].clear();
			idx[i].clear();
			chainHead[i] = -1;
			FOR(j,0,LN-1)	pa[i][j] = -1;
			FOR(j,0,3)  st[4*i + j].clear();
			FOR(j,0,3)  xr[4*i + j].clear();
			FOR(j,0,3)  xr[4*i + j].PB(0);
		}
		ptr=0;

		FOR(i,1,n-1)
		{
			int u,v,c;
			scanf("%d %d %d", &u, &v, &c);
			u--; v--;
			graph[u].PB(v); graph[v].PB(u);
			magicNum[u].PB(c); magicNum[v].PB(c);
			idx[u].PB(i-1); idx[v].PB(i-1);
		}

		chainNo = 0;
		dfs(root, -1); // Parent, SubSize and Depth of nodes
		HLD(root,0,-1); //Decompose Tree and Create baseArray
		buildTree(1,0,ptr-1);

		//Dynamic Programming for lca
		FOR(i,1,LN-1)
			FOR(j,0,n-1)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];

		scanf("%d", &m);
		while(m--)
		{
			int u,v,k;
			scanf("%d %d %d", &u, &v, &k);
			u--; v--;
			query(u,v,k);
		}
	}
}
