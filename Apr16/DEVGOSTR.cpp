//DEVGOSTR
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
#define lmt 50

int main()
{
	cin.sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		int a,k;
		cin>>a>>k;
		string str;
		cin>>str;
		
		int n = str.size();
		int A[n];
		FOR(i,0,n-1)
		{
			if(str[i] == 'a')
				A[i] = 0;
			else
			if(str[i] == 'b')
				A[i] = 1;
			else
				A[i] = 2;
		}

		//Base Case
		if(a == 1)
		{
			if(n > 2)
				printf("0\n");
			else
				printf("1\n");
			continue;	
		}
		if(a == 2)
		{
			LL ans = 1;
			

			printf("%Ld\n", ans);
			continue;
		}
		if(a == 3)
		{
			LL ans = 1;


			printf("%Ld\n", ans);
			continue;
		}
	}

}