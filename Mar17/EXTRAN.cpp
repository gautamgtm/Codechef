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
#define PRINTV(it,v) for (auto it = v.begin(); it != v.end(); it++) printf("%d ", *it);
#define PRINTA(A, n) for (auto i = 0; i <= (a); i++) printf("%d ", A[i]);

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
		int A[n], minm=MOD, maxm=0;
		LL sum=0;
		FOR(i,0,n-1)
		{
			scanf("%d", &A[i]);
			minm = min(minm, A[i]);
			maxm = max(maxm, A[i]);
			sum += A[i];
		}

		//Check if the minimum value is the outlier
		bool isFound = false;
		FOR(i,0,n-1)
		{
			if(A[i] == minm+1)
			{
				isFound = true;
				break;
			}
		}
		if(isFound == false)
		{
			printf("%d\n", minm);
			continue;
		}

		//Check if the maximum value is the outlier
		isFound = false;
		FOR(i,0,n-1)
		{
			if(A[i] == maxm-1)
			{
				isFound = true;
				break;
			}
		}
		if(isFound == false)
		{
			printf("%d\n", maxm);
			continue;
		}

		printf("%Ld\n", sum - ( (LL)(minm+maxm)*(LL)(maxm-minm+1) )/2);

	}

}
