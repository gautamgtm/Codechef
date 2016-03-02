//VOTERS
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
#define lmt 1000000

int main()
{
	cin.sync_with_stdio(0);
	int n1, n2, n3;
	scanf("%d %d %d", &n1, &n2, &n3);
	map<int, int> myMap;
	FOR(i,0,n1-1)
	{
		int temp;
		scanf("%d", &temp);
		myMap[temp] = 1;
	}
	FOR(i,0,n2+n3-1)
	{
		int temp;
		scanf("%d", &temp);
		if(myMap.find(temp) == myMap.end())
		{
			myMap[temp] = 1;
		}
		else
		{
			myMap[temp]++;
		}
	}

	int size = 0;
	for(auto it=myMap.begin(); it != myMap.end(); it++)
	{
		if(it->second >= 2)
		{
			size++;
		}
	}
	printf("%d\n", size);
	for(auto it=myMap.begin(); it != myMap.end(); it++)
	{
		if(it->second >= 2)
		{
			printf("%d\n", it->first);
		}
	}	
}