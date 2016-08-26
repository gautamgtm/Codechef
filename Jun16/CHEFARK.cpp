//CHEFARK
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
#define lmt 100000

LL Fact[lmt+5], invFact[lmt+5];

LL expPower(LL n, LL k)
{
	LL res=1;
	while(k>0)
	{
		 if(k%2==1) res=(res*n)%MOD;
		 n=(n*n)%MOD;
		 k/=2;
	}
	return res%MOD;
}

void sieve()
{
		Fact[0] = 1;
		FOR(i,1,lmt+4)
			Fact[i] = (Fact[i-1]*i)%MOD;

		invFact[0] = 1;
		FOR(i,1,lmt+4)
			invFact[i] = (invFact[i-1] * expPower(i,MOD-2) )%MOD;
}

LL count(LL n, LL k)
{
	if(n < k)
		return 0;
	else
	if(n == k)
		return 1;
	else
		return (((Fact[n]*invFact[k])%MOD)*invFact[n-k])%MOD;
}

int main()
{
	cin.sync_with_stdio(0);
	memset(Fact,0, sizeof(Fact));
	memset(invFact,0, sizeof(invFact));
	sieve();
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,k;
		scanf("%d %d", &n, &k);
		int temp, countZero=0;
		FOR(i,0,n-1)
		{
			scanf("%d", &temp);
			if(temp == 0)
				countZero++;
		}

		n = n - countZero;

		int idx = 0, step = 2;
		if(k%2)
			idx = 1;
		if(countZero)
		{
			step = 1;
			idx = 0;
		}

		LL ans = 0;
		for(int i=idx; i<=k; i+=step)
		{
			ans = (ans + count(n,i))%MOD;
		}

		printf("%Ld\n", ans);
	}
}
