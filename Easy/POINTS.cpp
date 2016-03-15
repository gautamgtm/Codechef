//POINTS
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
		int n;
		cin>>n;
		vector<PII> point;
		FOR(i,0,n-1)
		{
			int x,y;
			cin>>x>>y;
			point.PB(MP(x,y));
		}
		
		sort(point.begin(), point.end(), [](auto &left, auto &right) 
		{
			if(left.first < right.first)
				return 1;
    		if(left.first == right.first)
			{
				if(left.second > right.second)
					return 1;
			}
			return 0;
		});

		double distance = 0.0;
		FOR(i,1,n-1)
		{
			distance += sqrt( (point[i].first - point[i-1].first)*(point[i].first - point[i-1].first) + (point[i].second - point[i-1].second)*(point[i].second - point[i-1].second) );
		}

		printf("%.2lf\n", distance);

	}

}