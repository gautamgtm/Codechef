//GOODPROB
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

void build_tree(int *A, int *tree, int node, int start, int end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node] = A[start];
		return;
	}

	build_tree(A,tree,node*2,start,(end+start)/2);
	build_tree(A,tree,node*2+1,1+(end+start)/2,end);

	tree[node] = max(tree[node*2], tree[node*2+1]);
}

//Query tree to get max element value within range [i, j]
int query_tree(int *tree, int node, int start, int end, int i, int j)
{
	if(start>end || start>j || end<i)
		return -1;
	if(i<=start && j>=end)
		return tree[node];

	int q1 = query_tree(tree,2*node,start,(start+end)/2,i,j);
	int q2 = query_tree(tree,2*node+1,1+(start+end)/2,end,i,j);

	return max(q1,q2);
}

int main()
{
	cin.sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	int A[n];
	FOR(i,0,n-1)
	{
		scanf("%d", &A[i]);
	}

	//Build a segment tree
	int ht = (int)ceil(log2(n)+1);
	int maxSize = (int)pow(2,ht)-1;
	int tree[maxSize];
	build_tree(A,tree,1,0,n-1);

	//Query for Max in a range
	LL ans = 0;
	FOR(i,0,n-2)
	{
		FOR(j,i+1,n-1)
		{
			if((A[i] & A[j]) == A[i] || (A[i] & A[j]) == A[j])
			{
				printf("%d %d %d %d\n", i, j, A[i], A[j]);
				ans += query_tree(tree,1,0,n-1,i,j);
			}
		}
	}
	printf("%Ld\n", ans);

}
