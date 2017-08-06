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
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,k;
		long long num=0,ans=0;
		scanf("%d %d", &n, &k);
		int A[n];
		FOR(i,0,n-1)
		{
			scanf("%d", &A[i]);
			num += A[i];
		}
		if(num % n)
		{
			printf("-1\n");
			continue;
		}
		num = num / n;

		bool flag=1;
		FOR(i,0,k-1)
		{
			long long sum = 0, j = i, elem=0, m=0;
			while(j<n)
			{
				sum += A[j];
				elem++;

				m += (A[j]-num);
				ans += abs(m);
				j += k;
			}
			if(elem * num != sum)
			{
				flag = 0;
				printf("-1\n");
				break;
			}
		}

		if(flag) printf("%Ld\n", ans);
	}

}
