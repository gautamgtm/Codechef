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
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int minS[n], maxS[m], maxC[m];
		FOR(i,0,n-1) scanf("%d", &minS[i]);
		FOR(i,0,m-1) scanf("%d %d", &maxS[i], &maxC[i]);
		string qual[n];
		FOR(i,0,n-1) cin>>qual[i];

		long long job=0, salary=0, company=0;
		bool employer[m]={0};

		FOR(i,0,n-1)
		{
			int maxm=-1, idx=-1;
			FOR(j,0,m-1)
			{
				if(maxC[j] && maxS[j]>minS[i] && maxS[j]>maxm && qual[i][j]=='1')
				{
					maxm = maxS[j];
					idx = j;
				}
			}
			if(idx != -1)
			{
				job++;
				salary += maxS[idx];
				employer[idx] = 1;
				maxC[idx]--;
			}
		}

		FOR(i,0,m-1) company += employer[i];
		printf("%Ld %Ld %Ld\n", job, salary, m-company);
	}
}
