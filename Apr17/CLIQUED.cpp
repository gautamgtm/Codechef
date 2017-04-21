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
#include <assert.h>
using namespace std;

#define VI vector <int>
#define PII pair <int, int>
#define PLI pair <int, long long int>
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

struct prioritize
{
	bool operator ()(PLI&p1 ,PLI&p2)
			{return p1.second>p2.second;}
};

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,k,x,m,s;
		scanf("%d %d %d %d %d", &n, &k, &x, &m, &s);
		vector<vector<PII> > network(n);
		FOR(i,0,m-1)
		{
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			network[a-1].PB(MP(b-1,c));
			network[b-1].PB(MP(a-1,c));
		}

		bool flag=false;
		priority_queue<PLI ,vector<PLI>, prioritize> pq;
		vector<LL> dist(n, 1e+18);
		vector<bool> visited(n,0);
		dist[s-1] = 0;
		pq.push(MP(s-1,0));
		while(!pq.empty())
		{
			int currVertex = pq.top().first;
			pq.pop();

			if(visited[currVertex])
				continue;
			visited[currVertex] = 1;
			for(auto it=network[currVertex].begin(); it!=network[currVertex].end(); it++)
			{
				LL nextVertex = it->first, weight = it->second;
				if(!visited[nextVertex] && (weight + dist[currVertex] < dist[nextVertex]) )
				{
					dist[nextVertex] = weight + dist[currVertex];
					pq.push(MP(nextVertex, dist[nextVertex]));
				}
			}
			if(currVertex < k && flag==false)
			{
				flag = true;
				FOR(i,0,k-1)
				{
					if(!visited[i] && (x + dist[currVertex] < dist[i]) )
					{
						dist[i] = x + dist[currVertex];
						pq.push(MP(i, dist[i]));
					}
				}
			}
		}

		FOR(i,0,n-1)
			printf("%Ld ", dist[i]);
		printf("\n");
	}

}
