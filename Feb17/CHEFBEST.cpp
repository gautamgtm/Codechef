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

int solveBruteForce(bool A[], int n, int oneCount)
{
	int totalTime = 0;
	while(true)
	{
		int cons=0;
		FOR(i,0,n-1)
		{
			if(A[i])
				cons++;
			else
				break;
		}
		if(cons==oneCount)
			break;

		totalTime++;
		FORD(i,n-1,1)
		{
			if(A[i]==1 && A[i-1]==0)
			{
				A[i] = 0; A[i-1] =1;
				i--;
			}
		}
	}
	return totalTime;
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
		bool A[n];
		FOR(i,0,n-1)
			scanf("%d", &A[i]);

		int oneCount=0, count=0, totalTime=0;
		FOR(i,0,n-1)
			if(A[i])
				oneCount++;

		if(oneCount==0 || oneCount==n)
		{
			printf("0\n");
			continue;
		}

		int idx=-1;
		while(A[idx+1])
			idx++;
		while(!A[idx+1] && idx <= n-2)
			idx++;

		if(idx == n-1)
		{
			printf("0\n");
			continue;
		}

		int start = idx+1;
		idx = n;
		while(!A[idx-1])
			idx--;
		int end = idx-1;
		FOR(i,start,end)
			if(A[i])
				count++;
		printf("%d %d %d %d %d %d\n", oneCount, start, end, count, 1+end-oneCount, count-1-(end-start+1-count));
		totalTime = 1+end-oneCount + max(0, count-1-(end-start+1-count));

		int a = solveBruteForce(A,n,oneCount);
		printf("%d %d\n", a, totalTime);
	}
}
