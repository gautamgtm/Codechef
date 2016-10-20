//JTREE
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

int calCost(vector<PII>& v, int d)
{
	int ans = MOD;
	int l=0, r=v.size()-1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(v[mid].second == d)
			return v[mid].first;
		else
		if(v[mid].second < d)
			l++;
		else
		{
			ans = v[mid].first;
			r--;
		}
	}
	return ans;
}

int main()
{
	cin.sync_with_stdio(0);
	int n,m;
	scanf("%d %d", &n, &m);

	vector<int> path(n);
	vector<VI > revPath(n);
	FOR(i,0,n-2)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		a--;b--;
		path[a] = b;
		revPath[b].PB(a);
	}

	vector<LL> cost(n), distance(n), maxDist(n,0);
	cost[0] = 0; distance[0] = 0;

	vector<vector<pair<int,int> > > ticket(n);
	FOR(i,0,m-1)
	{
		int v,k,w;
		scanf("%d %d %d", &v, &k, &w);
		if(v != 1)
			ticket[v-1].PB(MP(w,k));
	}
	FOR(i,1,n-1)
	{
		sort(ticket[i].begin(), ticket[i].end());
		//Remove redundant tickets
		int maxm = 0;
		for(auto it=ticket[i].begin(); it != ticket[i].end();)
		{
			if(it->second <= maxm)
			{
				it = ticket[i].erase(it);
			}
			else
			{
				maxm = it->second;
				it++;
			}
		}
		maxDist[i] = ticket[i][ticket[i].size()-1].second;
	}

	//BFS for shortest distance
	queue<int> q;
	q.push(0);
	int visited[n] = {};
	visited[0] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(int v=0; v<revPath[u].size(); v++)
		{
			if(!visited[revPath[u][v]])
			{
				//dist.PB(MP(revPath[u][v], dist[u].second + 1));
				distance[revPath[u][v]] = distance[u] + 1;
				visited[revPath[u][v]] = 1;
				q.push(revPath[u][v]);
			}
		}
	}

	//Mimn travellng cost
	vector<PII> dist;
	for(int i=0; i<distance.size(); i++)
		dist.PB(MP(i,distance[i]));
	sort(dist.begin(), dist.end(), [=](pair<int, int>& a, pair<int, int>& b){return a.second < b.second;});

	FOR(i,1,dist.size()-1)
	{
		LL minCost = 1e+17;
		int node = dist[i].first, j=0;
		while(node != 0)
		{
			j++;
			//Cost of ticket to travel j distance
			LL temp =  calCost(ticket[dist[i].first], j);
			if(j > maxDist[dist[i].first] || temp == MOD)
				break;
			node = path[node];
			minCost = min(minCost, temp+cost[node]);
		}
		cost[dist[i].first] = minCost;
	}

	int query;
	scanf("%d", &query);
	FOR(i,0,query-1)
	{
		int a;
		scanf("%d", &a);
		printf("%Ld\n", cost[a-1]);
	}

}
 
