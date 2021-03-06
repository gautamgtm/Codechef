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
#define lmt 1000005

bool notPrime[lmt]={};
int spf[lmt]={};
VI primes;

inline void read(int &x)
{
	x=0;
	register char c=getchar_unlocked();
	for(;c<'0' || c>'9';c=getchar_unlocked());
	 for(;c>='0' && c<='9';c=getchar_unlocked())
	  x=(x<<3)+(x<<1)+(c-'0');
}

void sieve()
{
	notPrime[0]=1; notPrime[1]=1;
	primes.PB(2); spf[2] = 2;
	for(int i=2*2; i<lmt; i+=2)
	{
		notPrime[i] = 1;
		spf[i] = 2;
	}
	for(int i=3; i<lmt; i+=2)
	{
	  if(notPrime[i])
			continue;
		primes.PB(i); spf[i] = i;
		for(int j=2*i; j<lmt; j+=i)
		{
			notPrime[j] = 1;
			if(spf[j] == 0)
				spf[j] = i;
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	sieve();
	FOR(i,0,1000)
		printf("%d ", spf[i]);
	int n,q;
	read(n);
	int A[n];
	FOR(i,0,n-1)
		read(A[i]);

	read(q);
	while(q--)
	{
		int l,r,x,y,ans=0;
		read(l); read(r); read(x); read(y);
		l--;r--;
		FOR(i,l,r)
		{
			if(x>1005)
			{
				FOR(j,168,primes.size()-1)
				{
					if(primes[j] > y)
						break;
					if(A[i]%primes[j] == 0)
					{
						ans++;break;
					}
				}
			}
			else
			{
				int temp = A[i];
				while(temp != 1)
				{
					if(spf[temp] >= x && spf[temp] <= y)
						ans++;
					temp /= spf[temp];
				}
			}
		}
		printf("%d\n", ans);
	}
}
