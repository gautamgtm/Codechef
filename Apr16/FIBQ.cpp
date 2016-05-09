//FIBQ
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
#define lmt 100000
#define maxm (1+(1<<(int)(log2(lmt))))

int A[lmt + 5], tree[maxm];

LL fib(LL n)
{
	//Zero indexed; assuming fib(0)=fib(1)=1
	if(n<2)
		return 1;

	LL ans = ((fib((n+1)/2) * fib(n/2) )%MOD + (fib((n-1)/2) * fib((n-2)/2) )%MOD )%MOD;
	return ans;
}

void buildTree(int node, int a, int b)
{
	if(a>b)
		return;

	if(a == b)
	{
		tree[node] = fib(a-1);
		return;
	}

	buildTree(2*node, a, (a+b)/2);
	buildTree(2*node+1, 1+(a+b)/2, b);

	tree[node] = max(tree[2*node], tree[2*node+1]);
}

void updateTree(int node, int a, int b, int i, int j, int value)
{
	if(a>b || a>j || b<i)
		return;

	if(a == b)
	{
		tree[node] += value;
		return;
	}

	updateTree(2*node, a, (a+b)/2, i, j, value);
	updateTree(2*node+1, 1+(a+b)/2, b, i, j, value);

	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int queryTree(int node, int a, int b, int i, int j)
{
	if(a>b || a>j || b<i)
		return -INF;

	if(a>=i && b<=j)
		return tree[node];

	int q1 = queryTree(2*node, a, (a+b)/2, i, j);
	int q2 = queryTree(2*node+1, 1+(a+b)/2, b, i, j);

	int res = max(q1,q2);

	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	int n,q;
	scanf("%d %d", &n, &q);
	FOR(i,0,n-1)
		scanf("%d", &A[i]);

	//Build Segment Tree
	buildTree(1, 0, n-1);

	FOR(i,1,q)
	{
		char type;
		int a,b;
		scanf(" %c %d %d", &type, &a, &b);

		if(type == 'C')
		{
			//printf("Change\n");
			updateTree(1, 0, n-1, a-1, a-1, b - A[a-1]);
		}
		else
		{
			//printf("Output\n");
			int ans = queryTree(1, 0, n-1, a-1, b-1);
			printf("%d\n", ans);
		}
	}

}