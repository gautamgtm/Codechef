//LEBALONS
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
#define lmt 40

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		int ballon[lmt+1]={}, cost[lmt+1]={};
		FOR(i,0,n-1)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			ballon[a]++;
			cost[a] += b;
		}

		LL costDP[lmt+5][lmt+5]={0}, numDP[lmt+5][lmt+5]={0};

		FOR(i,0,lmt)
		{
			numDP[i][0] = 1;
		}

		for(int i=1; i<=lmt; i++)
		{
			for(int j=1; j<=i; j++)
			{
				if(ballon[i]>0)
					numDP[i][j] = numDP[i-1][j] + numDP[i-1][j-1]*(pow(2,ballon[i]) - 1);
				else
					numDP[i][j] = numDP[i-1][j];
			}
		}

		for(int i=1; i<=lmt; i++)
		{
			for(int j=1; j<=i; j++)
			{
				if(ballon[i]>0)
					costDP[i][j] = costDP[i-1][j] + costDP[i-1][j-1]*(pow(2, ballon[i])-1) + numDP[i-1][j-1]*cost[i]*pow(2, ballon[i]-1);
				else
					costDP[i][j] = costDP[i-1][j];
			}
		}

		LL num=0, den=0;
		FOR(i,m,n)
		{
			den += numDP[lmt][i];
			num += costDP[lmt][i];
		}
		double ans = double(num)/double(den);

		printf("%f\n", ans);
	}

}