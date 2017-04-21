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
#define lmt 1000001

vector<bool> notPrime(lmt);
vector<int> primes;

LL degree(VI& A)
{
	LL ans = 0;
	sort(A.begin(), A.end());
	while(A[A.size()-1] != 0)
	{
	  LL temp=1;
		FIT(it, A)
			temp = temp * (1 + (*it));
		ans += temp;

		A[A.size()-1]--;
		sort(A.begin(), A.end());
	}
	return ans;
}

void sieve()
{
	notPrime[0] = 1; notPrime[1] = 1;
	for(int i=4; i<lmt; i+=2)
		notPrime[i] = 1;
	for(int i=3; i<lmt; i+=2)
	{
		if(notPrime[i] == 0)
		{
			for(int j=2*i; j<lmt; j+=i)
				notPrime[j] = 1;
		}
	}

	FOR(i,0,lmt-1)
	{
		if(notPrime[i] == 0)
			primes.PB(i);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	sieve();
	LL a,b;
	scanf("%Ld %Ld", &a, &b);

	vector<VI> primeFactors(b-a+1), expoFactors(b-a+1);
	for(LL i=0; i<primes.size(); i++)
	{
		if(primes[i] > b)
			break;

		LL from = 1LL * primes[i];
		if(primes[i] < a)
			from = (LL)(ceil)((double)a/(double)primes[i]) * primes[i];
		for(LL j = (from - a); j <= (b - a); j += primes[i])
			primeFactors[j].PB(primes[i]);
	}

	FOR(i,a,b)
	{
		if(primeFactors[i-a].size() == 0)
		{
			expoFactors[i-a].PB(1);
			continue;
		}
		LL num = i;
		FIT(it,primeFactors[i-a])
		{
			int count=0;
			while(num % *it == 0)
			{
				num /= *it;
				count++;
			}
			expoFactors[i-a].PB(count);
		}
		if(num > 1)
			expoFactors[i-a].PB(1);
	}

	LL ans = 0;
	if(a==1)
	{
		FOR(i,a+1,b)
			ans += degree(expoFactors[i-a]);
	}
	else
	{
		FOR(i,a,b)
			ans += degree(expoFactors[i-a]);
	}

	printf("%Ld\n", ans);

}
