//DIVMAC
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
#define lmt 1000005

int LeastPrimeDivisor[lmt];

void sieve()
{
	memset(LeastPrimeDivisor,0,sizeof(LeastPrimeDivisor));
	LeastPrimeDivisor[0] = 1;
	LeastPrimeDivisor[1] = 1;
	for(int i=2; i<lmt; i+=2)
		LeastPrimeDivisor[i] = 2;

	for(int i=3; i<lmt; i+=2)
	{
		if(LeastPrimeDivisor[i])
			continue;
		for(int j=i; j<lmt; j+=i)
		{
			if(!LeastPrimeDivisor[j])
				LeastPrimeDivisor[j] = i;
		}
	}
}

void buildTree(int *A, int *tree, int node, int i, int j)
{
	if(i>j)
		return;
	if(i==j)
	{
		tree[node] = LeastPrimeDivisor[A[i]];
		return;
	}

	buildTree(A,tree,2*node,i,(i+j)/2);
	buildTree(A,tree,2*node+1,1+(i+j)/2,j);
	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int queryTree(int *A, int *tree, int node, int i, int j, int a, int b)
{
	if(a<=i && j<=b)
		return tree[node];

	if(b<i || a>j || i>j)
		return 0;

	int t1 = queryTree(A,tree,2*node,i,(i+j)/2,a,b);
	int t2 = queryTree(A,tree,2*node+1,1+(i+j)/2,j,a,b);

	return max(t1,t2);
}

void updateTree(int *A, int *tree, int node, int i, int j, int a, int b)
{
	if(tree[node]==1)
		return;
	if(b<i || a>j || i>j)
		return;

	if(i==j)
	{
		//Update leaf
		A[i] = A[i]/LeastPrimeDivisor[A[i]];
		tree[node] = LeastPrimeDivisor[A[i]];
		return;
	}

	updateTree(A,tree,2*node,i,(i+j)/2,a,b);
	updateTree(A,tree,2*node+1,1+(i+j)/2,j,a,b);
	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int main()
{
	cin.sync_with_stdio(0);
	sieve();
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		int A[n];
		FOR(i,0,n-1)
			scanf("%d", &A[i]);

		int maxm = (int)pow(2,(int)(ceil(log2(n)+1)))-1;
		int segTree[maxm];
		buildTree(A, segTree, 1, 0, n-1);

		FOR(i,0,m-1)
		{
			int type,l,r;
			scanf("%d %d %d", &type, &l, &r);
			l--;r--;
			if(type)
				printf("%d ", queryTree(A, segTree, 1, 0, n-1, l, r));
			else
				updateTree(A, segTree, 1, 0, n-1, l, r);
		}
		printf("\n");
	}

}
