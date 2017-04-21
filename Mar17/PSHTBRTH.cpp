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

int DP[1<<4][1<<4][1<<4][1<<4];

void toMatrix(vector<VI> &mat, int a, int b, int c, int d)
{
	FOR(i,0,3)
		mat[0][3-i] = a>>i & 1;
	FOR(i,0,3)
		mat[1][3-i] = b>>i & 1;
	FOR(i,0,3)
		mat[2][3-i] = c>>i & 1;
	FOR(i,0,3)
		mat[3][3-i] = d>>i & 1;
}

int fromMatrix(VI mat)
{
	int ans = 0;
	FOR(i,0,3)
		ans += mat[3-i] * 1<<i;
	return ans;
}

bool allZeros(vector<VI> &mat, int a, int b, int c, int d)
{
	FOR(i,a,b)
		FOR(j,c,d)
			if(mat[i][j] != 1)
				return false;
	return true;
}

int mex(set<int> mySet)
{
	int ans=0;
	FIT(it, mySet)
	{
		if(*it == ans)
			ans++;
		else
			return ans;
	}
	return ans;
}

int grundy(vector<VI> mat)
{
	set<int> mySet;
	FOR(a,0,3){
		FOR(b,a,3){
			FOR(c,0,3){
				FOR(d,c,3)
				{
					//Submatrix : (a->b)*(c->d)
					if(allZeros(mat,a,b,c,d))
					{
						vector<VI> tempVec = mat;
						FOR(i,a,b)
							FOR(j,c,d)
								tempVec[i][j] = 0;
						if(DP[fromMatrix(tempVec[0])][fromMatrix(tempVec[1])][fromMatrix(tempVec[2])][fromMatrix(tempVec[3])] != -1)
							mySet.insert(DP[fromMatrix(tempVec[0])][fromMatrix(tempVec[1])][fromMatrix(tempVec[2])][fromMatrix(tempVec[3])]);
						else
						{
							DP[fromMatrix(tempVec[0])][fromMatrix(tempVec[1])][fromMatrix(tempVec[2])][fromMatrix(tempVec[3])] = grundy(tempVec);
							mySet.insert(DP[fromMatrix(tempVec[0])][fromMatrix(tempVec[1])][fromMatrix(tempVec[2])][fromMatrix(tempVec[3])]);
						}
					}

				}}}}
	return mex(mySet);
}

void sieve()
{
	FOR(a,0,(1<<4) - 1)
		FOR(b,0,(1<<4) - 1)
			FOR(c,0,(1<<4) - 1)
				FOR(d,0,(1<<4) - 1)
					DP[a][b][c][d] = -1;

	DP[0][0][0][0] = 0;
	FOR(a,0,(1<<4) - 1){
		FOR(b,0,(1<<4) - 1){
			FOR(c,0,(1<<4) - 1){
				FOR(d,0,(1<<4) - 1)
				{
					if(DP[a][b][c][d] != -1)
						continue;
					vector<VI> mat(4, VI(4));
					toMatrix(mat,a,b,c,d);
					DP[a][b][c][d] = grundy(mat);
				}}}}
}

int solve(char str[4][5])
{
	vector<VI> tempVec(4,VI(4));
	FOR(i,0,3)
		FOR(j,0,3)
			tempVec[i][j] = (int)(str[i][j] - '0');
	return DP[fromMatrix(tempVec[0])][fromMatrix(tempVec[1])][fromMatrix(tempVec[2])][fromMatrix(tempVec[3])];
}

void buildTree(int A[], int tree[], int node, int a, int b)
{
	if(a>b)
		return;
	if(a==b)
	{
		tree[node] = A[a];
		return;
	}

	buildTree(A,tree,2*node,a,(a+b)/2);
	buildTree(A,tree,2*node+1,1+(a+b)/2,b);
	tree[node] = tree[2*node] ^ tree[2*node+1];
}

void updateTree(int tree[], int node, int a, int b, int i, int val)
{
	if(i<a || i>b || a>b)
		return;
	if(a==b)
	{
		tree[node] = val;
		return;
	}
	updateTree(tree,2*node,a,(a+b)/2,i,val);
	updateTree(tree,2*node+1,1+(a+b)/2,b,i,val);
	tree[node] = tree[2*node] ^ tree[2*node+1];
}

int queryTree(int tree[], int node, int a, int b, int l, int r)
{
	if(l>b || r<a || a>b)
		return 0;
	if(l<=a && r>=b)
		return tree[node];

	int q1 = queryTree(tree,2*node,a,(a+b)/2,l,r);
	int q2 = queryTree(tree,2*node+1,1+(a+b)/2,b,l,r);

	return q1 ^ q2;
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
		char c[4][5];
		FOR(i,0,n-1)
		{
			FOR(j,0,3)
				scanf("%s", c[j]);
			A[i] = solve(c);
		}
		int tree[4*n];
		buildTree(A,tree,1,0,n-1);
		FOR(i,0,m-1)
		{
			int a;
			scanf("%d", &a);
			if(a==1)
			{
				int l,r;
				scanf("%d %d", &l, &r);
				l--;r--;
				int ans = queryTree(tree,1,0,n-1,l,r);
				if(ans)
					printf("Pishty\n");
				else
					printf("Lotsy\n");
			}
			else
			{
				int b;
				scanf("%d", &b);
				b--;
				FOR(j,0,3)
					scanf("%s", c[j]);
				updateTree(tree,1,0,n-1,b,solve(c));
			}
		}
	}

}
