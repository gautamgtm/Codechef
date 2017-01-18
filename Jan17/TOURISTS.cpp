//TOURISTS
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
#define lmt 100005

int n,e;
vector<vector<PII> > graph(lmt);
vector<PII> edges;
vector<int> edgesIn(lmt,0), edgesOut(lmt,0);
queue<int> q;
bool visited[lmt]={};
int parent[lmt], color[lmt];
VI circuit;

void printCycle(int u, int v)
{
	//VI circuit;
	circuit.clear();
	int a=u, b=v;
	while(a!=b)
	{
		circuit.PB(a);
		printf("%d ", a);
		a = parent[a];
	}
	circuit.PB(a);
	circuit.PB(u);
	printf("%d %d", a, u);
	printf("\n");

	//Correct the order of edges in original graph
	FOR(i,0,circuit.size()-2)
	{
		//Find edge and correct order : circuit[i] --> circuit[i+1]
		int a = circuit[i], b=circuit[i+1];
		if(graph[circuit[i]].size() > graph[circuit[i+1]].size())
		{
			a = circuit[i+1]; b= circuit[i];
		}
		FOR(j,0,graph[a].size()-1)
		{
			if(graph[a][j].first == b)
			{
				//printf("%d %d\n", circuit[i], circuit[i+1]);
				edges[graph[a][j].second] = MP(circuit[i],circuit[i+1]);
				break;
			}
		}
	}
}

void dfs(int idx)
{
	bool cycle = false;
	color[idx] = 0; //Gray
	FIT(it, graph[idx])
	{
		if(color[it->first]==-1)
		{
			parent[it->first] = idx;
			dfs(it->first);
		}
		else
		if(color[it->first]==0 && parent[idx] != it->first)
		{
			cycle = true;
			//Print cycle
			printCycle(idx,it->first);
			//break;
		}
	}
	color[idx] = 2; //Black
}

void findCycles()
{
	//int parent[n], color[n];
	FOR(i,0,n-1)
	{
		color[i] = -1; //White
		parent[i] = -1;
	}

	FOR(i,0,n-1)
	{
		if(color[i]==-1)
			dfs(i);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	scanf("%d %d", &n, &e);
	FOR(i,0,e-1)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		edges.PB(MP(a-1,b-1));
		edgesIn[b-1]++;edgesOut[a-1]++;
		graph[a-1].PB(MP(b-1,i));
		graph[b-1].PB(MP(a-1,i));
	}

	//Odd number of edges for a node : Not possible
	FOR(i,0,n-1)
	{
		if((edgesIn[i]+edgesOut[i])%2 == 1)
		{
			printf("NO\n");
			return 0;
		}
	}

	//Check if undirect version of graph is fully connected using BFS
	//bool visited[n]={};
	//queue<int> q;
	q.push(0);
	visited[0] = 1;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(auto it=graph[node].begin(); it!=graph[node].end(); it++)
		{
			if(visited[it->first] != 1)
			{
				q.push(it->first);
				visited[it->first] = 1;
			}
		}
	}
	FOR(i,0,n-1)
	{
		if(visited[i] == 0)
		{
			printf("NO\n");
			return 0;
		}
	}

	//Possible now. Find a way to make for every node, edgesIn = edgesOut
	findCycles();

	printf("YES\n");
	FOR(i,0,e-1)
	{
		printf("%d %d\n", 1+edges[i].first, 1+edges[i].second);
	}

}
