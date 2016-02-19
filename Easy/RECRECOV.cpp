//RECRECOV
/*
Motivation: let's split each vertex v into 2 parts (let's call them vin and vout) connected by an edge vin-> vout 
such that all edges directed into v will now be directed into vin and all edges directed out of v will be directed out of vout. 
Intuitively, a path is something like a flow of 1 in this graph and the splitting guarantees that no two "flows" can cross the 
edge vin-> vout for any v, which is something like path disjointness. And the solution really reduces to finding a maximum flow.

We'll make a new flow-graph Gf in a similar way: there are vertices vin and vout in Gf corresponding to 
each vertex v in G and also edges uout-> vin in Gf corresponding to each edge u -> v in G, 
but no edges vin-> vout. Instead, we'll have a source ss, a sink t and edges s -> vout and vin-> t for each v. 
All edges have capacities 1.

The answer is N minus the maximum flow F in Gf between s and t. Why it works isn't so obvious, unless we look at the problem 
from a different perspective - if there are P paths covering our DAG, they will have N−P edges in total 
(a path with v vertices has v−1 edges and there are N vertices in P paths), and 
we're computing the maximum number of edges which can be assigned to paths. Those edges are the ones through which we're sending the flow.

Think about what the constraints on edges of Gf mean: edges s -> vout with capacity 1 say that we can only 
send a flow of 1 through one outcoming edge (that actually appears in the DAG) from vertex v, edges vin-> t mean a 
similar thing for incoming edges. Since any path cover corresponds to a valid flow and vice versa, the max. number of edges a
ssigned to paths will be F and the minimum number of paths P=N−F.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <utility>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int T;
	scanf(" %d",&T);
	for(int t =0; t < T; t++) 
	{
		int N,M;
		scanf(" %d %d",&N,&M);
		int n =2*N+2; //1 Source, 1 Sink, and N vertices divided into 2N vertices
		vector< vector<int> > F(n,vector<int>(n,0));
		for(int i =0; i < N; i++) F[0][i+1] =F[N+i+1][n-1] =1; //Source to Vout = 1 & Vin to Sink = 1 for All vertex
		for(int i =0; i < M; i++) 
		{
			int a,b;
			scanf(" %d %d",&a,&b);
			if(a != b) F[a][N+b] =1;//Vout of "a" to Vin of "b"
		}
		int f =0;// Maxm flow of new bipartite graph
		while(true) 
		{
			queue<int> q;
			vector<int> ako(n,-1);//Vertices initialized as not visited
			q.push(0);
			ako[0] =0;//Source as visited
			//Find a path from source to sink
			while(!q.empty()) 
			{
				int t = q.front();
				for(int i =0; i < n; i++) if(F[t][i] > 0 && ako[i] == -1) 
				{
					ako[i] =t;
					q.push(i);
				}
				q.pop();
			}
			//Path not found; Exit;
			if(ako[n-1] == -1) break;
			//Path found; increase flow by 1.
			f++;
			//Going back from sink to source
			int akt =n-1;
			while(akt > 0) 
			{
				//Reducing the forward flow by 1
				F[ako[akt]][akt]--;
				//Increasing the reverse flow by 1 [To maintain equilibrium]
				F[akt][ako[akt]]++;
				//Back to parent of this node
				akt =ako[akt];
			}
			//Continue to find more paths
		}
		printf("%d\n",N-f);
	}
	return 0;
}

