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

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity

LL sumGeometric(LL r, LL n, LL m)
{
	if(n==0)
		return 1;
	else
	{
		r = r%m;
		if(n%2)
			return ((1+r)%m * sumGeometric((r*r)%m, (n-1)/2, m)%m)%m;
		else
			return (1 + (r+(r*r)%m)%m * sumGeometric((r*r)%m, (n-2)/2, m)%m)%m;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		LL a, n, m;
		scanf("%Ld %Ld %Ld", &a, &n, &m);
		if(a==0)
		{
			printf("0\n");
			continue;
		}

		LL mult = 10;
		while(mult<=a)
			mult *= 10;

		LL num = (a%m * sumGeometric(mult, n-1, m)%m )%m;

		printf("%Ld\n", num);
	}

}
