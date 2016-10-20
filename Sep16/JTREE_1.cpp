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

void printList(auto v, auto sz)
{
    FOR(i,0,sz-1)
    	cout<<v[i]<<" ";
    cout<<endl;
}

void explorePath(vector<VI> &A, int currNode, vector<int> &v, int sz, vector<vector<pair<int,int> > > &ticket, vector<LL> &distance, vector<LL> &cost, vector<LL> &dummyCost)
{
  int currentNode =  v[sz-1];
  //Path to current node available. Update the cost of this node
  //printList(v, sz);
  LL minCost = 1e+17;
  if(currentNode != 0)
  {
    if(ticket[currentNode][0].second >= distance[currentNode])
      minCost = ticket[currentNode][0].first;
    //Browse across the node with max distance possible with each ticket
    for(int i=0; i<ticket[currentNode].size(); i++)
    {
      if(ticket[currentNode][i].second > distance[currentNode])
        break;
      int toNode = v[sz-1-ticket[currentNode][i].second];
      minCost = min(minCost, ticket[currentNode][i].first + dummyCost[toNode]);
    }
    cost[currentNode] = minCost;
    dummyCost[currentNode] = minCost;

    int idx=2;
    while(minCost < dummyCost[v[sz-idx]] && idx<sz)
    {
      dummyCost[v[sz-idx]] = minCost;
      idx++;
    }
  }

  //Recursively Explore
  for(int i=0; i< A[currNode].size(); i++)
  {
    v[sz] = A[currNode][i];
    explorePath(A, A[currNode][i], v, sz+1, ticket, distance, cost, dummyCost);
  }
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

	vector<LL> cost(n), distance(n), dummyCost(n);
	cost[0] = 0; distance[0] = 0; dummyCost[0] = 0;

	vector<vector<pair<int,int> > > ticket(n);
	FOR(i,0,m-1)
	{
		int v,k,w;
		scanf("%d %d %d", &v, &k, &w);
		if(v != 1)
			ticket[v-1].PB(MP(w,k));
	}
  /*
	FOR(i,1,n-1)
	{
		sort(ticket[i].begin(), ticket[i].end());
		//Remove redundant tickets
		int maxm = 0;
		for(auto it=ticket[i].begin(); it != ticket[i].end();)
		{
			if(it->second <= maxm)
				it = ticket[i].erase(it);
			else
			{
				maxm = it->second;
				it++;
			}
		}
	}*/

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

  //Minm Travelling cost
  vector<int> myPath(n);
  myPath[0] = 0;
  explorePath(revPath, 0, myPath, 1, ticket, distance, cost, dummyCost);

	int query;
	scanf("%d", &query);
	FOR(i,0,query-1)
	{
		int a;
		scanf("%d", &a);
		printf("%Ld\n", cost[a-1]);
	}

}
