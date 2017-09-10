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

#define VI vector <long long>
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

void update(VI& segTree, VI& lazy, int node, int l, int r, int a, int b, LL c)
{
	if(lazy[node])
	{
		segTree[node] += lazy[node]*(r-l+1);
		if(l != r)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(l>r || r<a || l>b) return;
	if(l>=a && r<=b)
	{
		segTree[node] += 1LL*c*(r-l+1);
		if(l != r)
		{
			lazy[2*node] += c;
			lazy[2*node+1] += c;
		}
		return;
	}

	update(segTree,lazy,2*node,l,(l+r)/2,a,b,c);
	update(segTree,lazy,2*node+1,1+(l+r)/2,r,a,b,c);
	segTree[node] = segTree[2*node] + segTree[2*node+1];
}

LL query(VI& segTree, VI& lazy, int node, int l, int r, int idx)
{
	if(l>r) return 0;
	if(lazy[node])
	{
		segTree[node] += lazy[node]*(r-l+1);
		if(l != r)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(l==r) return segTree[node];

	if(idx > (l+r)/2) return query(segTree,lazy,2*node+1,1+(l+r)/2,r,idx);
	return query(segTree,lazy,2*node,l,(l+r)/2,idx);
}

int main()
{
	cin.sync_with_stdio(0);
	int m,n,q;
	scanf("%d %d %d", &m, &n, &q);
	vector<VI> down(m,VI(n,0)), right(m,VI(n,0));
	FOR(i,0,m-2) FOR(j,0,n-1) scanf("%d", &down[i][j]);
	FOR(i,0,m-1) FOR(j,0,n-2) scanf("%d", &right[i][j]);

	VI segTree(4*n,0), lazy(4*n,0);
	FOR(i,0,q-1)
	{
		int type;
		scanf("%d", &type);
		if(type == 1)
		{
			int i1, j1, i2, j2;
			LL c;
			scanf("%d %d %d %d %Ld", &i1, &j1, &i2, &j2, &c);
			i1--; j1--; i2--; j2--;
			if(j1>j2) swap(j1,j2);
			update(segTree,lazy,1,0,n-1,j1,j2,c);
		}
		else
		{
			int i1, j1;
			scanf("%d %d", &i1, &j1);
			i1--; j1--;
			printf("%Ld\n", query(segTree,lazy,1,0,n-1,j1));
		}
	}
}
