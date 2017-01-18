//SEAINCR
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

int length(int A[], int l, int r)
{
    int n = r-l+1;
		int temp[n], ans=0;
		FOR(i,0,n-1)
			temp[i] = 1;

		FOR(i,1,n-1)
			FOR(j,0,i-1)
				if(A[l+i]>A[l+j] && temp[i]<temp[j]+1)
					temp[i] = temp[j]+1;

    FOR(i,0,n-1)
			ans = max(ans, temp[i]);
    return ans;
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

		int A[n];
		FOR(i,0,n-1)
			scanf("%d", &A[i]);

		FOR(i,0,m-1)
		{
			int l,r;
			scanf("%d %d", &l, &r);
			printf("%d\n", length(A,l-1,r-1));
		}
	}

}
