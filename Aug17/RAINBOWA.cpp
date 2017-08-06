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
		int n, flag=1;
		scanf("%d", &n);
		int A[n];
		for(int i=0; i<n; i++)
		{
			scanf("%d", &A[i]);
			if(A[i]>7) flag = 0;
		}
		if(flag==0)
		{
			printf("no\n");
			continue;
		}

		int l=0, r=n-1, num=1;
		while(l<=r)
		{
			if(A[l]==A[r] && A[l]==num)
			{
				while(A[l]==A[r] && A[l]==num)
					l += 1, r -=1;
				num++;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if(num==7 && flag) printf("yes\n");
		else printf("no\n");
	}

}
