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
		int n,k;
		scanf("%d %d", &n, &k);
		bool sad=false;
		int A[k]={0}, count=0;
		vector<VI> dish(n);
		FOR(i,0,n-1)
		{
			int a,b;
			scanf("%d", &a);
			FOR(i,0,a-1)
			{
				scanf("%d", &b);
				A[b-1]++;
				dish[i].PB(b-1);
			}
		}

		FOR(i,0,k-1)
		{
			if(A[i]==0)
			{
				sad = 1;
				printf("sad\n");
				break;
			}
		}
		if(sad == 1)
			continue;

		FOR(i,0,n-1)
		{
			FIT(it, dish[i])
			{
				if(A[*it] == 1)
				{
					count++;
					break;
				}
			}
		}

		if(count == n)
			printf("all\n");
		else
			printf("some\n");
	}

}
