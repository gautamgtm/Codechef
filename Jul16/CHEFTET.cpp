//CHEFTET
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
		LL sum = 0;
		LL B[n], A[n];
		FOR(i,0,n-1)
		{
			scanf("%Ld", &B[i]);
			sum += B[i];
		}
		FOR(i,0,n-1)
		{
			scanf("%Ld", &A[i]);
			sum += A[i];
		}

		if(n == 1)
		{
			printf("%Ld\n", sum);
			continue;
		}

		LL dest = sum/n;
		bool isPossible = true;

		if(sum%n)
		{
			isPossible = false;
			printf("-1\n");
			continue;
		}

		if(A[0] == dest)
		{
			A[0] = 0;
		}
		else
		if(A[0]+B[0] == dest)
		{
			A[0] = 0; B[0] = 0;
		}
		else
		if(A[0]+B[1] == dest)
		{
			A[0] = 0; B[1] = 0;
		}
		else
		if(A[0]+B[0]+B[1] == dest)
		{
			A[0] = 0; B[0] = 0; B[1] = 0;
		}
		else
		{
			isPossible = false;
			printf("-1\n");
			continue;
		}

		FOR(i,1,n-2)
		{
			if(A[i] == dest)
			{
				A[i] = 0;
			}
			else
			if(A[i]+B[i-1] == dest)
			{
				A[i] = 0; B[i-1] = 0;
			}
			else
			if(A[i]+B[i-1]+B[i] == dest)
			{
				A[i] =0; B[i] = 0; B[i-1] = 0;
			}
			else
			if(A[i]+B[i-1]+B[i+1] == dest)
			{
				A[i] =0; B[i-1] = 0; B[i+1] = 0;
			}
			else
			if(A[i]+B[i-1]+B[i]+B[i+1] == dest)
			{
				A[i] =0; B[i] = 0; B[i+1] = 0; B[i-1] = 0;
			}
			else
			if(A[i]+B[i] == dest)
			{
				A[i] =0; B[i] = 0;
			}
			else
			if(A[i]+B[i+1] == dest)
			{
				A[i] =0; B[i+1] = 0;
			}
			else
			if(A[i]+B[i]+B[i+1] == dest)
			{
				A[i] =0; B[i] = 0; B[i+1] = 0;
			}
			else
			{
				isPossible = false;
				printf("-1\n");
				break;
			}
		}

		if(isPossible == false)
			continue;

		if(A[n-1] == dest)
		{
			A[n-1] = 0;
		}
		else
		if(A[n-1]+B[n-2] == dest)
		{
			A[n-1] = 0; B[n-2] = 0;
		}
		else
		if(A[n-1]+B[n-2]+B[n-1] == dest)
		{
			A[n-1] = 0; B[n-1] = 0; B[n-2] = 0;
		}
		else
		if(A[n-1]+B[n-1] == dest)
		{
			A[n-1] = 0; B[n-1] = 0;
		}
		else
		{
			isPossible = false;
			printf("-1\n");
			continue;
		}

		FOR(i,0,n-1)
		{
			if(B[i]>0 || A[i]>0)
			{
				isPossible = false;
				printf("-1\n");
				break;
			}
		}

		if(isPossible == true)
			printf("%Ld\n", dest);
	}

}
