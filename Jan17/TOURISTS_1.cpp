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

bool isFullyConnected(vector<map<int, int> > graph, int n)
{
	bool visited[n]={};
	queue<int> q;
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
		if(visited[i] == 0)
			return 0;

	return 1;
}

bool alreadyGood(vector<map<int, int> > graph, vector<map<int, int> > revGraph, vector<int> edgesIn, vector<int> edgesOut, int n)
{
	FOR(i,0,n-1)
		if(edgesIn[i] != edgesOut[i])
			return 0;

	if(!isFullyConnected(graph,n) || !isFullyConnected(revGraph,n))
		return 0;

	return 1;

}

void findEulerianCycle(vector<map<int, int> > &graph, vector<map<int, int> > dummy, vector<PII> &edges)
{
	VI circuit;
	stack<int> s;
	int vertex = 0;
	while(!s.empty() || graph[vertex].size())
	{
		if(graph[vertex].size() == 0)
		{
			circuit.PB(vertex);
			vertex = s.top();
			s.pop();
		}
		else
		{
			s.push(vertex);
			auto it=graph[vertex].begin();
			int neighbor = it->first;
			//Delete edge
			graph[vertex].erase(it);
			FIT(itt, graph[neighbor])
			{
				if(itt->first == vertex)
				{
					graph[neighbor].erase(itt);
					break;
				}
			}
			vertex = neighbor;
		}
	}
	circuit.PB(vertex);

	//Correct the order of edges in original graph
	FOR(i,0,circuit.size()-2)
	{
		//Find edge and correct order : circuit[i] --> circuit[i+1]
		int a = circuit[i], b=circuit[i+1];
		if(dummy[a].size() > dummy[b].size())
		{
			a = circuit[i+1]; b= circuit[i];
		}

		auto it = dummy[a].find(b);
		edges[it->second] = MP(circuit[i],circuit[i+1]);
	}

}

int main()
{
	cin.sync_with_stdio(0);
	int n,e;
	scanf("%d %d", &n, &e);
	vector<map<int, int> > path(n), revPath(n),graph(n), dummy(n);
	vector<PII> edges;
	vector<int> edgesIn(n,0), edgesOut(n,0);
	FOR(i,0,e-1)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		edges.PB(MP(a-1,b-1));
		edgesIn[b-1]++;edgesOut[a-1]++;
		path[a-1].insert(MP(b-1,i));
		revPath[b-1].insert(MP(a-1,i));

		graph[a-1].insert(MP(b-1,i));
		graph[b-1].insert(MP(a-1,i));
		dummy[a-1].insert(MP(b-1,i));
		dummy[b-1].insert(MP(a-1,i));
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
	if(!isFullyConnected(graph, n))
	{
		printf("NO\n");
		return 0;
	}

	//Possible now.
	//Check if the actual graph is actually good
	//If not,Find a way to make for every node, edgesIn = edgesOut
	if(!alreadyGood(path, revPath, edgesIn, edgesOut, n))
		findEulerianCycle(graph, dummy, edges);

	printf("YES\n");
	FOR(i,0,e-1)
	{
		printf("%d %d\n", 1+edges[i].first, 1+edges[i].second);
	}

}
