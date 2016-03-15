//LEDIV
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

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity
#define lmt 100000

int smallestDivisor[lmt + 5];

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

void sieve()
{
	FOR(i,0,lmt)
	{
		smallestDivisor[i] = i;
	}
	for(int i=2; i<=lmt; i+=2)
	{
		smallestDivisor[i] = 2;
	}
	for(int i=3; i<=lmt; i+=2)
	{
		if(smallestDivisor[i] == i)
		{
			for(int j=i; j<=lmt; j += i)
			{
				smallestDivisor[j] = min(i, smallestDivisor[j]);
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	sieve();
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int ans;
		scanf("%d", &ans);
		FOR(i,0,n-2)
		{
			int temp;
			scanf("%d", &temp);
			ans = gcd(ans, temp);
		}

		if(ans<=1)
			printf("-1\n");
		else
			printf("%d\n", smallestDivisor[ans]);
			
	}
}