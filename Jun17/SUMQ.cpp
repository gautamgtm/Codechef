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

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int p,q,r;
		scanf("%d %d %d", &p, &q, &r);
		LL A[p], B[q], C[r], D[q];
		FOR(i,0,p-1)
			scanf("%Ld", &A[i]);
		FOR(i,0,q-1)
			scanf("%Ld", &B[i]);
		FOR(i,0,r-1)
			scanf("%Ld", &C[i]);

		sort(A, A+p);
		sort(B, B+q);
		sort(C, C+r);

		LL sum = 0, j = 0, ans=0, sum_ = 0;
		FOR(i,0,q-1)
		{
			while(C[j] <= B[i] && j<r)
			{
				sum = (sum +C[j])%MOD; j++;
			}
			D[i] = (sum + (B[i]*(j))%MOD)%MOD;
		}

		j = q-1; sum = 0;
		FORD(i,p-1,0)
		{
			while(B[j] >= A[i] && j>=0)
			{
				sum = (sum + D[j])%MOD;
				sum_ = (sum_ + (D[j]*B[j])%MOD)%MOD;
				j--;
			}
			ans = (ans + sum_ + (sum*A[i])%MOD)%MOD;
		}

		printf("%Ld\n", ans);
}

}
