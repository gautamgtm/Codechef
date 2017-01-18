//KIRLAB
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
#define MAXM 10000005

int gcd(int a, int b)
{
	if(a%2==0 && b%2==0)
		return 2;
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int A[n];
		FOR(i,0,n-1)
			scanf("%d", &A[i]);

		multimap<int,int> myMap;
		int answer[n]={};
		answer[n-1] = 1;
		myMap.insert(MP(answer[n-1],n-1));
		FORD(i,n-2,0)
		{
			answer[i] = 1;
			if(A[i]==1)
				continue;
			for(auto it=myMap.rbegin(); it!=myMap.rend(); it++)
			{
				if(gcd(A[i],A[it->second])>1)
				{
					answer[i] = max(answer[i], 1+it->first);
					break;
				}
			}
			myMap.insert(MP(answer[i],i));
		}

		int ans=answer[0];
		FOR(i,1,n-1)
			ans = max(ans, answer[i]);

		printf("%d\n", ans);

	}

}
