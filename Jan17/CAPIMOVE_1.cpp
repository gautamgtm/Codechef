//CAPIMOVE
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
		vector<PII> population;
		FOR(i,0,n-1)
		{
			int a;
			scanf("%d", &a);
			population.PB(MP(a,i));
		}
		sort(population.begin(), population.end());
		reverse(population.begin(), population.end());

		vector<VI> network(n);
		FOR(i,0,n-2)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			a--;b--;
			network[a].PB(b);
			network[b].PB(a);
			network[i].PB(i);
		}
		network[n-1].PB(n-1);

		FOR(i,0,n-1)
		{
			bool flag = false;
			FIT(it,population)
			{
				//if(binary_search(network[i].begin(), network[i].end(), it->second) == false)
				if(find(network[i].begin(), network[i].end(), it->second) == network[i].end())
				{
					printf("%d ", 1+it->second);
					flag = true;
					break;
				}
			}
			if(flag == false)
				printf("0 ");
		}
		printf("\n");

	}

}
