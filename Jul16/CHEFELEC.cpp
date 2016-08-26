//CHEFELEC
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

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, lastHouse = 0;
		scanf("%d", &n);
		string house;
		cin>>house;
		int dist[n];
		FOR(i,0,n-1)
			scanf("%d", &dist[i]);

		while(house[lastHouse] == '0')
			lastHouse++;
		LL cable = dist[lastHouse] - dist[0];
		int maxm = 0;
		FOR(i,lastHouse+1,n-1)
		{
			maxm = max(maxm, dist[i]-dist[i-1]);
			if(house[i] == '1')
			{
				cable += (dist[i]-dist[lastHouse])-maxm;
				lastHouse = i;
				maxm = 0;
			}
		}
		if(lastHouse != (n-1))
		{
			cable += (dist[n-1] - dist[lastHouse]);
		}

		printf("%Ld\n", cable);
	}

}
