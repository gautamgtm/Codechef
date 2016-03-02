//MARCHA2
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
		int k;
		scanf("%d", &k);
		int A[k];
		FOR(i,0,k-1)
		{
			scanf("%d", &A[i]);
		}
		
		//Base Case
		if(k==1)
		{
			if(A[0] == 1)
				printf("Yes\n");
			else
				printf("No\n");
			continue;
		}

		if(A[k-1]%2)
		{
			printf("No\n");
			continue;
		}
		bool flag = true; int stem=1;
		FOR(i,1,k-1)
		{
			if(A[i] > 2*stem)
			{
				flag = false;
			}

			stem = 2*stem - A[i];

			//No stems in last level. Only leaves allowed
			if(i == k-1 && stem>0)
				flag = false;
		}

		if(flag)
			printf("Yes\n");
		else
			printf("No\n");

	}
	
}