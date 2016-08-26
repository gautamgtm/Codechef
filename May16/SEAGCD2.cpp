//SEAGCD2
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
#define lmt 105

bool notPrime[lmt];
int numPrime[lmt];
int invFact[lmt];

LL choose(int n, int k)
{
	if(k == 0)
		return 1;

	LL temp = n;
	int a = max(k,n-k), b=min(k,n-k);

	FORD(i,n-1,a+1)
		temp = (temp * (LL)i)%MOD;

	//temp = (temp * invFact[b])%MOD;
	FOR(i,1,b)
		temp = (temp / (LL)i)%MOD;	

	return temp;
}

void sieve()
{
	//Sieve of Erasthmus
	notPrime[0]=1;
	for(int i=4; i<lmt; i+=2)
		notPrime[i] = 1;
	for(int i=3; i<lmt; i+=2)
	{
		if(notPrime[i] == 0)
		{
			for(int j=i+i; j<lmt; j+=i)
				notPrime[j] = 1;
		}
	}

	//Count the num of primes before a number(including the number)
	int count = 0;
	FOR(i,2,lmt-1)
	{
		if(notPrime[i] == 0)
			count++;
		numPrime[i] = count;
	}

	//Inverse Factorial
	
}

int main()
{
	cin.sync_with_stdio(0);
	memset(notPrime,0,sizeof(notPrime));
	memset(numPrime,0,sizeof(numPrime));
	memset(invFact,0,sizeof(invFact));
	sieve();
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);

		int ans=0;

		//Use only 1's and primes less than m.
		int num = numPrime[m];
		FOR(i,0,min(num,n))
		{
			LL temp = (choose(n,i) * choose(num,i) )%MOD;
			ans = (ans + temp)%MOD;
		}

		//Use coprimes also now
		

	}

}