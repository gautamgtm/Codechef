//CANDLE
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
# define lmt 1000000000

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		vector<PII> A;
		FOR(i,0,9)
		{
			int temp;
			scanf("%d", &temp);
			A.PB(MP(temp,i));
		}

		sort(A.begin(), A.end());

		int num = A[0].first;
		//Base Case
		if(A[0].second == 0)
		{
			if(A[1].first > A[0].first)
			{
				printf("1");
				FOR(i,0,A[0].first)
				{
					printf("0");
				}
				printf("\n");
			}
			else
			{
				FOR(i,0,A[0].first)
					printf("%d", A[1].second);
				printf("\n");
			}
			continue;
		}
			

		FOR(i,0,num)
		{
			printf("%d", A[0].second);
		}
		printf("\n");

	}
}