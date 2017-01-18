//KTHMAX
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

void buildTree(int tree[], int A[], int node, int i, int j)
{
	if(i>j)
		return;
	if(i==j)
	{
		tree[node] = A[i];
		return;
	}

	buildTree(tree, A, 2*node, i, (i+j)/2);
	buildTree(tree, A, 2*node+1, 1+(i+j)/2, j);

	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int queryTree(int tree[], int A[], int node, int i, int j, int a, int b)
{
	if(b<i || a>j || i>j)
		return 0;

	if(i>=a && j<=b)
		return tree[node];

	int q1 = queryTree(tree, A, 2*node, i, (i+j)/2, a, b);
	int q2 = queryTree(tree, A, 2*node+1, 1+(i+j)/2, j, a, b);
	return max(q1,q2);

}

int binarySearch(int A[], int num, int n)
{
	int l=0, r=n;
	while(l!=r)
	{
		int mid = (l+r)/2;
		if(A[mid] == num)
			return mid;
		else
		if(A[mid] < num)
			l = mid+1;
		else
			r = mid;
	}
	return l;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);

		int A[n],B[n];
		vector<PII> myVec;
		FOR(i,0,n-1)
		{
			int temp;
			scanf("%d", &temp);
			myVec.PB(MP(temp,i));
			A[i] = temp;
		}

		int tree[4*n];
		buildTree(tree, A, 1, 0, n-1);

		sort(myVec.begin(), myVec.end());
		reverse(myVec.begin(), myVec.end());

		int idx=0,count=0;
		FIT(it,myVec)
		{
			count += (n - it->second);
			B[idx] = count; idx++;
		}

		FOR(i,0,m-1)
		{
			int p, j, k;
			scanf("%d", &p);

			j = binarySearch(B, p, n);
			if(j!=0)
				k = p - B[j-1];
			else
				k = p;
			int ans = queryTree(tree, A, 1, 0, n-1, myVec[j].second, n-k);
			printf("%d %d %d\n", ans, myVec[j].second, n-k);

		}
	}

}
