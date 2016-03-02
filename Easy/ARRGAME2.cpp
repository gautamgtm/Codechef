//ARRGAME2
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
		int n;
		scanf("%d", &n);
		int A[n], B[n];
		FOR(i,0,n-1)
			scanf("%d", &A[i]);
		FOR(i,0,n-1)
			scanf("%d", &B[i]);

		sort(A,A+n);
		sort(B,B+n);

		int countOne = 0, countTwo = 0;
		FOR(i,0,n-1)
		{
			if(B[i] == 1)
				countOne++;
			if(B[i] == 2)
				countTwo++;
		}

		LL answer = 0;
		FOR(i,0,n-1)
		{
			if(A[i] == 1)
				continue;
			if(A[i] == 2)
			{
				answer += countOne;
				auto firstLargest = upper_bound(B, B+n, 4);
				answer += (B + n - firstLargest);
				continue;
			}
			if(A[i] == 3)
			{
				answer +=  countTwo;
			}

			answer += countOne;
			auto firstLargest = upper_bound(B, B+n, A[i]);
			answer += (B + n - firstLargest);
		}

		double ans = double(answer)/n;

		printf("%f\n", ans);
	}

}