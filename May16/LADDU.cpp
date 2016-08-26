//LADDU
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
		int divider, activity, laddu = 0;
		string origin;
		cin>>activity>>origin;
		if(origin == "INDIAN")
			divider = 200;
		else
			divider = 400;

		FOR(i,0,activity-1)
		{
			string name;
			cin>>name;
			if(name == "CONTEST_WON")
			{
				int temp;
				cin>>temp;
				laddu += 300 + max(0, 20-temp);
			}
			else if(name == "TOP_CONTRIBUTOR")
				laddu += 300;
			else if(name == "BUG_FOUND")
			{
				int temp;
				cin>>temp;
				laddu += temp;				
			}
			else
				laddu += 50;
		}

		printf("%d\n", laddu/divider);
	}

}