//STROPR
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
using namespace std;
 
#define VI vector <int>
#define PII pair <int, int>
#define LL unsigned long long int
#define LLd long
#define LDB long double
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,a,b) for (auto i = (a); i <= (b); i++)
#define FORD(i,a,b) for (auto i = (a); i >= (b); i--)
#define FORV(CAKE,it) for(auto it =CAKE.begin(); it != CAKE.end(); it++)
#define FIT(it,v) for (auto it = v.begin(); it != v.end(); it++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x < 0)?-(x):x)
 
#define MP make_pair
#define PB push_back
 
#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity
 
LL inverseMod[100005], reverseFact[100005], fact[100005];
 
LL degree(LL a, LL x) {
    //calculates a^x mod p in logarithmic time.
    LL res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        x /= 2;
    }
    return res;
}
 
LL modInverse(LL a, LL p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return degree(a, p-2);
}
 
LL modBinomial(LL n, LL k) {
// calculates C(n,k) mod p (assuming p is prime).
 
    /*LL numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (LL i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % MOD;
    }*/
    LL numerator = reverseFact[k-1];
 
    /*LL denominator = 1; // k!
    for (LL i=1; i<=k; i++) {
        denominator = (denominator * i) % MOD;
    }*/
    LL denominator = fact[k]%MOD;
 
    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,MOD) ) % MOD;
}
 
void sieve()
{
	fact[0] = 1; fact[1] = 1;
	FOR(i,2,100004)
	{
		fact[i] = ( i * fact[i-1])%MOD;
	}
}
 
void updateReverseFact(LL m)
{
	memset(reverseFact,0,sizeof(reverseFact));
	reverseFact[0] = m%MOD;
	FOR(i,1,100004)
	{
		LL temp = (m+i)%MOD;
		reverseFact[i] = (temp * reverseFact[i-1])%MOD;
	}
}
 
int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	sieve();
	while(t--)
	{
		LL n,x,m;
		scanf("%llu %llu %llu", &n, &x, &m);
		LL A[n+1];
		FOR(i,1,n)
		{
			scanf("%llu", &A[i]);
			A[i] = A[i]%MOD;
		}
		//Base Cases
		if(x == 1)
		{
			printf("%llu\n", A[1]);
			continue;
		}
		if(x == 2)
		{
			LL temp = ( A[2] + ( (m%MOD) * A[1] )%MOD )%MOD;
			printf("%llu\n", temp);
			continue;
		}
 		
 		updateReverseFact(m);
 
		LL Arr[x];
		Arr[0] = 1; Arr[1] = m%MOD;
		FOR(i,2,x-1)
		{
			Arr[i] = modBinomial(m+i-1, i)%MOD;
			//Arr[i] = ( reverseFact[i-1]%MOD * inverseMod[i]%MOD )%MOD;
		}
 
		LL ans=0;
		FOR(i,0,x-1)
		{
			ans = ( ans + ( A[x-i] * Arr[i] )%MOD )%MOD;
		}
 
		printf("%llu\n", ans);
	}
 
}  
