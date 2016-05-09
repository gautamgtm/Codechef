//DAILY
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
#define lmt 54

LL fact[10];

void sieve()
{
	fact[0] = 1;
	FOR(i,1,9)
		fact[i] = fact[i-1]*i;
}

LL count(int n, int r)
{
	LL temp;
	if(n>=r)
		temp = fact[n]/(fact[r]*fact[n-r]);
	else
		temp = 0;

	return temp;
}

int main()
{
	cin.sync_with_stdio(0);
	sieve();
	int x,n;
	scanf("%d %d", &x, &n);
	int seatLeft[n][9]={};
	FOR(i,0,n-1)
	{
		char seat[lmt+5];
		scanf("%s", seat);

		FOR(j,0,8)
		{
			FOR(k,0,3)
			{
				seatLeft[i][j] += (seat[4*j+k] == '0');
			}
			FOR(k,0,1)
			{
				seatLeft[i][j] += (seat[53-2*j-k] == '0');
			}
		}
	}

	LL ans = 0;
	FOR(i,0,n-1)
	{
		FOR(j,0,8)
		{
			ans += count(seatLeft[i][j],x);
		}
	}
	printf("%Ld\n", ans);
}