//RRCODE
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
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,k,ans;
		scanf("%d %d %d", &n, &k, &ans);
		int A[n];
		FOR(i,0,n-1)
		{
			scanf("%d", &A[i]);
		}
		string opn;
		cin>>opn;

		if(opn == "AND")
		{
			int temp = A[0];
			FOR(i,1,n-1)
				temp = temp & A[i];

			if(k)
				printf("%d\n", ans & temp);
			else
				printf("%d\n", ans);

			continue;
		}

		if(opn == "OR")
		{
			int temp = A[0];
			FOR(i,1,n-1)
				temp = temp | A[i];

			if(k)
				printf("%d\n", ans | temp);
			else
				printf("%d\n", ans);
		}

		if(opn == "XOR")
		{
			int temp = A[0];
			FOR(i,1,n-1)
				temp = temp ^ A[i];

			if(!k)
				printf("%d\n", ans);
			else
			if(k%2)
				printf("%d\n", ans ^ temp);
			else
				printf("%d\n", ans ^ 0);
		}

	}

}