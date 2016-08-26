//CHEFCRUN
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
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int A[n];
		FOR(i,0,n-1)
		{
			scanf("%d", &A[i]);
		}
		int start,end;
		scanf("%d %d", &start, &end);
		start--;end--;

		LL path1=0, path2=0;
		//Clockwise Path
		FOR(i,start,end-1)
			path1 += A[i];

		//Anticlockwise Path
		FORD(i,start-1,0)
			path2 += A[i];
		FORD(i,n-1,end)
			path2 += A[i];

		LL st[n], en[n];
		LL minm=MOD, sum=0;
		//Along Path 1
		FOR(i,start,end-1)
		{
			sum += A[i];
			minm = min(minm, sum);
			st[i] = minm;
		}

		minm = MOD; sum = 0;
		FORD(i,end-1,start)
		{
			sum += A[i];
			minm = min(minm, sum);
			en[i] = minm;
		}

		//Along Path 2
		minm = MOD; sum = 0;
		FORD(i,start-1,0)
		{
			sum += A[i];
			minm = min(minm, sum);
			st[i] = minm;
		}
		FORD(i,n-1,end)
		{
			sum += A[i];
			minm = min(minm, sum);
			st[i] = minm;
		}

		minm = MOD; sum = 0;
		FOR(i,end,n-1)
		{
			sum += A[i];
			minm = min(minm, sum);
			en[i] = minm;
		}
		FOR(i,0,start-1)
		{
			sum += A[i];
			minm = min(minm, sum);
			en[i] = minm;
		}

		LL ans = min(path1, path2);
		//Along Path 2 + Some on Path 1
		ans = min(ans, path2+2*en[start]);
		FOR(i,start,end-2)
		{
			LL s = st[i], e = en[i+1];
			LL temp = min(s, min(e, s+e));
			ans = min(ans, path2+2*temp);
		}
		ans = min(ans, path2+2*st[end-1]);

		//Along Path1 + Some on Path 2
		if(start)
		{
			ans = min(ans, path1+2*en[start-1]);
			FORD(i,start-1,1)
			{
				LL s = st[i], e = en[i-1];
				LL temp = min(s, min(e, s+e));
				ans = min(ans, path1+2*temp);
			}
		}
		if(start>0 && end<n-1)
			ans = min(ans, path1+2*st[0]+2*en[n-1]);
		if(end<n-1)
		{
			FORD(i,n-1,end+1)
			{
				LL s = st[i], e = en[i-1];
				LL temp = min(s, min(e, s+e));
				ans = min(ans, path1+2*temp);
			}
			ans = min(ans, path1+2*st[end]);
		}


		/*
		FOR(i,0,n-1)
			printf("%Ld ", st[i]);
		printf("\n");
		FOR(i,0,n-1)
			printf("%Ld ", en[i]);
		printf("\n");
		printf("%Ld %Ld\n", path1, path2);*/

		printf("%Ld\n", ans);
	}

}
