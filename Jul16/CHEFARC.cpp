//CHEFARC
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

bool A[105][105];
int dist[105][105];

bool isValid(int i, int j, int n, int m)
{
	if(i>=0 && i<n && j>=0 && j<m)
		return 1;
	else
		return 0;
}

void findPath(bool (*A)[105], int (*dist)[105], int len, int r, int c, int n, int m, vector<int> &minimum)
{
	int path[105][105];
	memset(path,0,sizeof(path));

	if(r == 0 && c == m-1)
		minimum.PB(len);
	else
	if(A[r][c] == 1 || (A[r][c] == 0 && dist[r][c] != 0))
		return;
	else
	if((A[r][c] == 0 && dist[r][c] == 0 ) || (r == 0 && c == 0))
	{
		FOR(i,0,n-1)
			FOR(j,0,m-1)
				path[i][j] = dist[i][j];
		path[r][c] = 1;
		len++;

		if(isValid(r,c-1,n,m))
			findPath(A, path, len, r, c-1, n, m, minimum);
		if(isValid(r,c+1,n,m))
			findPath(A, path, len, r, c+1, n, m, minimum);
		if(isValid(r-1,c,n,m))
			findPath(A, path, len, r-1, c, n, m, minimum);
		if(isValid(r+1,c,n,m))
			findPath(A, path, len, r+1, c, n, m, minimum);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m,k1,k2;
		scanf("%d %d %d %d", &n, &m, &k1, &k2);
		memset(A,0,sizeof(A));
		FOR(i,0,n-1)
			FOR(j,0,m-1)
				scanf("%d", &A[i][j]);

		int minm = 100000;
		vector<int> minimum;
		memset(dist,0,sizeof(dist));
		findPath(A, dist, 0, 0, 0, n, m, minimum);
		FORV(minimum, it)
			minm = min(minm, (*it));

		int ans = (int)ceil(double(minm)/(k1+k2));
		if(minm != 100000)
			printf("%d\n", ans);
		else
			printf("-1\n");

	}

}
