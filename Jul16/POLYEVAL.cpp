//POLYEVAL
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
#define MOD 786433
#define INF INT_MAX //Infinity

int main()
{
	cin.sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	LL A[n+1];
	FOR(i,0,n)
		scanf("%Ld", &A[i]);

	int q;
	scanf("%d", &q);
	FOR(i,0,q-1)
	{
		int x;
		scanf("%d", &x);

		LL powerX[n+1];
		powerX[0] = 1;
		FOR(i,1,n)
			powerX[i] = (powerX[i-1] * x)%MOD;

		LL ans = 0;
		FOR(i,0,n)
		{
			ans = (ans + (A[i]*powerX[i])%MOD )%MOD;
		}

		printf("%Ld\n", ans);

	}


}
