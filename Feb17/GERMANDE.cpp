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

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity

bool check(int countOne[], int a, int b)
{
	int countWin=0;
	FOR(i,0,a-1)
		if(countOne[i]> b/2)
			countWin++;

	if(countWin> a/2)
		return true;
	else
		return false;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		bool A[a*b];
		FOR(i,0,a*b-1)
				scanf("%d", &A[i]);

		int countOne[a]={}, start[a], end[a];
		FOR(i,0,a-1)
		{
			start[i] = b*i;
			end[i] = b*(i+1)-1;
			FOR(j,start[i],end[i])
				countOne[i] += A[j];
		}

		bool isPossible = check(countOne,a,b);
		if(isPossible)
		{
			printf("1\n");
			continue;
		}
		FOR(i,1,b-1)
		{
			//Shift 1 step to right
			int tmp = start[0];
			FOR(j,0,a-1)
			{
				if(j != a-1)
					countOne[j] += A[start[j+1]] - A[start[j]];
				else
					countOne[j] += A[tmp] - A[start[j]];
				start[j] = (start[j]+1)%(a*b); end[j] = (end[j]+1)%(a*b);
			}

			//Check if it is possible now
			if(check(countOne,a,b))
			{
				isPossible = true;
				break;
			}
		}

		if(isPossible)
			printf("1\n");
		else
			printf("0\n");

	}

}
