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
#define MOD1 1000000007
#define MOD2 1000000009
#define INF INT_MAX //Infinity

LL expPower(LL n, LL k, LL MOD)
{
	LL res = 1;
	n = n%MOD;
	while(k)
	{
		if(k%2) res = (res * n)%MOD;
		n = (n * n)%MOD;
		k = k/2;
	}
	return res%MOD;
}

LL gcd(LL a, LL b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		LL n;
		cin>>n;

		LL den = (4*n - 6);
		LL g1 = gcd(n,den); den /= g1;
		LL g2 = gcd(n-1,den); den /= g2;

		LL num1 = ((n/g1)%MOD1 * ((n-1)/g2)%MOD1)%MOD1, num2 = ((n/g1)%MOD2 * ((n-1)/g2)%MOD2)%MOD2;
		LL den1 = den%MOD1, den2 = den%MOD2;;

		LL ans1 = (num1 * expPower(den1, 1LL*(MOD1-2), 1LL*MOD1))%MOD1;
		LL ans2 = (num2 * expPower(den2, 1LL*(MOD2-2), 1LL*MOD2))%MOD2;

		cout<<ans1<<" "<<ans2<<endl;
	}

}
