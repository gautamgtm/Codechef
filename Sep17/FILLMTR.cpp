//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map>
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
#define PRINTV(it,v) for (auto it = v.begin(); it != v.end(); it++) printf("%d ", *it);
#define PRINTA(A, n) for (auto i = 0; i <= (a); i++) printf("%d ", A[i]);

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
		int n,q, flag=1;
		scanf("%d %d", &n, &q);
		unordered_map<int, int> mp[n];
		FOR(i,0,q-1)
		{
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			if(a>b) swap(a,b);
			if(a==b)
			{
				if(c) flag=0;
				continue;
			}
			if(mp[a].find(b) == mp[a].end()) mp[a][b] = c;
			else if(mp[a][b] != c) flag=0;
		}
		if(!flag)
		{
			printf("no\n");
			continue;
		}

		FOR(i,0,n-1)
		{
			FIT(it,mp[i])
			{
				for(auto itt=it; itt!=mp[i].end(); itt++)
				{
					if(it==itt) continue;
					int a = it->first, b = itt->first;
					int c = it->second, d = itt->second;
					if(a>b) swap(a,b);
					if(mp[a].find(b) != mp[a].end())
					{
						if(mp[a][b] != c^d)
						{
							flag=0;
							break;
						}
					}
				}
				if(!flag) break;
			}
			if(!flag) break;
		}

		if(flag) printf("yes\n");
		else printf("no\n");
	}

}
