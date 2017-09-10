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

int t=0;

void dfs(vector<VI> graph, vector<LL>& depth, vector<LL>& visited, int u)
{
	visited[u] = 1;
	//st[u] = t++;
	//B.PB(u);
	//sz[u] = 1;
	FIT(it, graph[u])
	if(!visited[*it]){
		depth[*it] = depth[u] + 1;
		dfs(graph,depth,visited,*it);
		//sz[u] += sz[*it];
	}
}

int main()
{
	cin.sync_with_stdio(0);
	int n,q;
	scanf("%d %d", &n, &q);
	vector<VI> graph(n);
	FOR(i,1,n-1)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		graph[a].PB(b);
		graph[b].PB(a);
	}
	vector<LL> A(n), depth(n,0), visited(n,0);//, B, st(n), sz(n),;
	FOR(i,0,n-1) scanf("%Ld ", &A[i]);

	dfs(graph,depth,visited,0);

	LL maxDepth=0;
	FOR(i,0,n-1) maxDepth = max(maxDepth, depth[i]);
	vector<LL> depthXor(maxDepth+1,0);
	FOR(i,0,n-1) depthXor[depth[i]] ^= A[i];

	FOR(i,0,q-1)
	{
		LL tm,ans=0;
		scanf("%Ld", &tm);
		tm--;
		FOR(j,0,maxDepth) if((tm & j) == 0) ans ^= depthXor[j];
		printf("%Ld\n", ans);
	}

}
