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

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity
#define lmt 100005
#define ln 18

int n, q, ln_, timePassed=-1, A[lmt], B[2*lmt], lvl[lmt], DP[ln][lmt], st[lmt], en[lmt];
vector<VI> tree(lmt);

inline void read(int &x)
{
	x=0;
	register char c=getchar_unlocked();
	for(;c<'0' || c>'9';c=getchar_unlocked());
	 for(;c>='0' && c<='9';c=getchar_unlocked())
	  x=(x<<3)+(x<<1)+(c-'0');
}

void dfs(int node, bool visited[])
{
	st[node] = ++timePassed;
	B[timePassed] = node;
	visited[node] = 1;
	FOR(i,1,ln_-1)
		DP[i][node] = DP[i - 1][DP[i - 1][node]];
	FIT(it,tree[node])
	{
		if(!visited[*it])
		{
			lvl[*it] = lvl[node] + 1;
			DP[0][*it] = node;
			dfs(*it,visited);
		}
	}
	en[node] = ++timePassed;
	B[timePassed] = node;
}

int lca(int u, int v)
{
	if(lvl[u] > lvl[v])
		swap(u,v);

	//u is the node at a greater depth/lower level
	//So we have to raise u to be at the same level as v.
	FORD(i,ln_-1,0)
		if(lvl[v] - (1<<i) >= lvl[u])
			v = DP[i][v];

	if(u==v)
		return u;

	//Now we keep raising the two nodes by equal amount
	//Untill each node has been raised uptill its (k-1)th ancestor
	//Such that the (k)th ancestor is the lca.
	//So to get the lca we just return the parent of (k-1)th ancestor of each node
	FORD(i,ln_-1,0)
	{
		//Checking P[u][j] != P[v][j] because if P[u][j] == P[v][j]
    //P[u][j] would be the Lth ancestor such that (L >= k)
    //where kth ancestor is the LCA . But we want the (k-1)th ancestor.
		if(DP[i][u] != DP[i][v])
		{
			u = DP[i][u];
			v = DP[i][v];
		}
	}

	return DP[0][u];
}

int main()
{
	cin.sync_with_stdio(0);
	//scanf("%d %d", &n, &q);
	read(n);read(q);
	ln_ = ceil(log2(n));
	FOR(i,0,n-1)
		read(A[i]);
		//scanf("%d", &A[i]);
	FOR(i,0,n-2)
	{
		int a,b;
		//scanf("%d %d", &a, &b);
		read(a);read(b);
		a--;b--;
		tree[a].PB(b);
		tree[b].PB(a);
	}

	DP[0][0] = 0;
	bool visited[n]={};
	dfs(0,visited);

	FOR(i,0,q-1)
	{
		int a,b,c;
		//scanf("%d %d %d", &a, &b, &c);
		read(a); read(b); read(c);
		if(a==1)
		{
			b--;c--;
			int j = lca(b,c);
			if (st[b] > st[c]) swap(b, c);
			//map<int, int> bag;
			int arr[n]={};
			int l,r;
			if(j == b)
			{
				//Range is [st[u], st[v]]. If (x) occurs twice, then don't consider it's value.
				l = st[b]; r = st[c];
			}
			else
			{
				//Range is [en[u], st[v]] + [j]. If (x) occurs twice, then don't consider it's value.
				l = en[b]; r = st[c];
				arr[j]++;
			}
			FOR(i,l,r)
			{
				arr[B[i]]++;
			}

			set<int> mySet;
			FOR(i,0,n-1)
			{
				if(arr[i] == 1)
					mySet.insert(A[i]);
			}
			printf("%d\n", mySet.size());
		}
		else
			A[b-1] = c;
	}

}
