//NOTATRI
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

int main()
{
	cin.sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	while(n)
	{
		int A[n];
		FOR(i,0,n-1)
		{
			scanf("%d", &A[i]);
		}

		sort(A,A+n);
		LL ans = 0;
		/*FORD(i,n-1,2)
		{
			int a = A[i];
			FORD(j,i-1,1)
			{
				int idx=j-1;
				while(A[j]+A[idx] >= A[i] && idx >= 0)
				{
					idx--;
				}
				ans += idx+1;
			}			
		}*/
		FOR(i,0,n-3)
		{
			int idx = i+2;
			FOR(j,i+1,n-2)
			{
				while(idx<n && A[i] + A[j] >= A[idx])
				{
					idx++;
				}
				ans += n-idx;
			}
		}

		printf("%Ld\n", ans);

		scanf("%d", &n);
	}

	return 0;

}