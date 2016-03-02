//BESTBATS
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

LL fact[20];
void sieve()
{
	fact[0]=1;
	FOR(i,1,19)
	{
		fact[i] = i*fact[i-1];
	}
}
LL combination(int a, int b)
{
	LL temp = fact[a]/(fact[b]*fact[a-b]);

	return temp;
}
int main()
{
	cin.sync_with_stdio(0);
	sieve();
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int score[101]={},num;
		FOR(i,0,10)
		{
			int temp;
			scanf("%d", &temp);
			score[temp]++;
		}
		scanf("%d", &num);

		int till = 100, k=num;
		while(k>0)
		{
			k -= score[till];
			till--;
		}

		FOR(i,till+2,100)
		{
			if(score[i])
			{
				num -= score[i];
			}
		}
		LL ans = combination(score[till+1], num);

		printf("%d\n", ans);

	}
}