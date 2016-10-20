//RESCALC
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
		int point[n];
		FOR(i,0,n-1)
		{
			int c, A[6]={};
			scanf("%d", &c);
			FOR(j,0,c-1)
			{
				int temp;
				scanf("%d", &temp);
				A[temp-1]++;
			}
			sort(A,A+6);
			point[i] = c + 4*A[0] + 2*max(0,A[1]-A[0]) + max(0,A[2]-A[1]);
		}

		int maxm=point[0], maxIdx=0;
		FOR(i,1,n-1)
		{
			if(point[i]>maxm)
			{
				maxm = point[i];
				maxIdx = i;
			}
		}
		int same=0;
		FOR(i,0,n-1)
		{
			printf("%d ", point[i]);
			if(point[i]==maxm)
				same++;
		}
		printf("\n");
		if(same>=2)
			printf("tie\n");
		else
		if(maxIdx==0)
			printf("chef\n");
		else
			printf("%d\n", maxIdx+1);
	}

}
