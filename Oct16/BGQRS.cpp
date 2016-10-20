//BGQRS [Segment Tree]
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

inline void read(int &x)
{
	x=0;
	register char c=getchar_unlocked();
	for(;c<'0' || c>'9';c=getchar_unlocked());
	 for(;c>='0' && c<='9';c=getchar_unlocked())
	  x=(x<<3)+(x<<1)+(c-'0');
}

void buildTree(int A[], int tree[], int node, int a, int b, int flag)
{
		if(a>b)
			return;

		if(a==b)
		{
			tree[node] = 0;
			int temp = A[a];
			while(temp%flag == 0 && temp>1)
			{
				tree[node]++;
				temp /= flag;
			}
			return;
		}

		buildTree(A, tree, 2*node, a, (a+b)/2, flag);
		buildTree(A, tree, 2*node+1, 1+(a+b)/2, b, flag);
		tree[node] = tree[2*node] + tree[2*node+1];
}

void updateTree(int A[], int tree[], int node, int a, int b, int l, int r, int value, int flag, int type)
{
	if(a > b || a > r || b < l)
		return;

	if(a==b)
	{
		if(type == 1)
			tree[node] += value;
		else
		if(type == 2)
		{
			tree[node] = value;
			int temp = a-l+1;
			while(temp%flag == 0 && temp>1)
			{
				tree[node]++;
				temp /= flag;
			}
		}
		return;
	}

	updateTree(A, tree, 2*node, a, (a+b)/2, l, r, value, flag, type);
	updateTree(A, tree, 2*node+1, 1+(a+b)/2, b, l, r, value, flag, type);
	tree[node] = tree[2*node] + tree[2*node+1];
}

int getQuery(int A[], int tree[], int node, int a, int b, int l, int r)
{
	if(a>b || l>b || r<a)
		return 0;
	if(a>=l && b<=r)
		return tree[node];

	int q1 = getQuery(A, tree, 2*node, a, (a+b)/2, l, r);
	int q2 = getQuery(A, tree, 2*node+1, 1+(a+b)/2, b, l, r);
	return q1+q2;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	read(t);
	//scanf("%d", &t);
	while(t--)
	{
		int n,m;
		//scanf("%d %d", &n, &m);
		read(n); read(m);

		int A[n];
		FOR(i,0,n-1)
			read(A[i]);

		int maxm = 4*n;//(int)pow(2, 1+(int)log2(n));
		int treeA[maxm], treeB[maxm];
		buildTree(A, treeA, 1, 0, n-1, 2);
		buildTree(A, treeB, 1, 0, n-1, 5);

		int ans = 0;
		FOR(i,0,m-1)
		{
			int type;
			//scanf("%d", &type);
			read(type);
			if(type==3)
			{
				int l,r;
				//scanf("%d %d", &l, &r);
				read(l); read(r);
				l--;r--;
				ans += min(getQuery(A, treeA, 1, 0, n-1, l, r), getQuery(A, treeB, 1, 0, n-1, l, r));
			}
			else
			{
				int l,r,value;
				read(l); read(r); read(value);
				//scanf("%d %d %d", &l, &r, &value);
				l--;r--;

				int temp=value, idx1=0, idx2=0;
				while(temp%2 == 0 && temp>1)
				{
					idx1++;
					temp /= 2;
				}
				temp=value;
				while(temp%5 == 0 && temp>1)
				{
					idx2++;
					temp /= 5;
				}
				updateTree(A, treeA, 1, 0, n-1, l, r, idx1, 2, type);
				updateTree(A, treeB, 1, 0, n-1, l, r, idx2, 5, type);
			}
		}
		printf("%d\n", ans);
	}
}
