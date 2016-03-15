//EQUATION
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

LL solve(LL n)
{
	if(n<0)
		return 0;
	else
		return (n+1)*(n+2)*(n+3)/6;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		LL n,a,b,c;
		scanf("%Ld %Ld %Ld %Ld", &n, &a, &b, &c);

		//LL ans = solve(n) - solve(n-a-1)- solve(n-b-1) - solve(n-c-1) + solve(n-a-b-2) + solve(n-b-c-2) + solve(n-c-a-2) - solve(n-a-b-c-3);
		LL ans = 0;
		FOR(i,0,a)
		{
			FOR(j,0,b)
			{
				LL temp = n-i-j;
				if(temp < 0)
					break;

				 ans += min(temp,c)+1;
			}
		}
		printf("%Ld\n", ans);
	}

}