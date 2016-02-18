//DEVLDISC
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
#define LLd long
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
		if(n < 7)
		{
			printf("-1\n");
			continue;
		}
 
		//Print the Graph
		printf("%d\n", n);
		printf("1 2\n1 3\n2 4\n3 5\n2 6\n3 6\n");
		int edgesLeft = n-6;
 
		int vertex = 7;
		FOR(j,1,edgesLeft)
		{
			printf("6 %d\n",vertex);
			vertex++;
		}
 
		printf("1\n");
	}
 
} 
