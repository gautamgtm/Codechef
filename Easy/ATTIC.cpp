//ATTIC
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
		char path[1000005];
		scanf("%s", path);
		int pathsize = 0;
		FOR(i,0,1000005)
		{
			if(path[i] == '\0')
				break;
			pathsize++;
		}
		int level = 0, start = 1, day = 0;
		while(start < pathsize-1 )
		{
			if(path[start] == '#')
				start++;
			else
			{
				int counter= start;
				start++;
				while(path[start] != '#' && start < pathsize-1)
				{
					//length++;
					start++;
				}
				counter = start-counter;
				if(counter>level)
				{
					level = counter;
					day++;
				}
			}
		}

		printf("%d\n", day);

	}

}