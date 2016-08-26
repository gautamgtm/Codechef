//EBOLA
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
#include <time.h>
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

vector<VI> myGraph(10005);

bool areAllInfected(bool A[], int size)
{
	FOR(i,0,size-1)
	{
		if(A[i] == 0)
			return false;
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	int n,m,k,s;
	scanf("%d %d %d %d", &n, &m, &k, &s);
	s--;
	int wt[n];
	FOR(i,0,n-1)
		scanf("%d", &wt[i]);

	FOR(i,0,m-1)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		a--;b--;
		myGraph[a].PB(b);
	}
	srand(time(0));

	queue<int> q;
	bool used[n] = {0};
	q.push(s);
	used[s] = 1;

	if(myGraph[s].size())
	{
		printf("%d ", myGraph[s][0]+1);
		used[myGraph[s][0]] = 1;
	}

	FOR(i,0,k-2)
	{
		//BFS
		if(!q.empty())
		{
			int front = q.front();
			q.pop();
			for(auto it=myGraph[front].begin(); it != myGraph[front].end(); it++)
			{
				if(used[*it] == 0)
				{
					q.push(*it);
					used[*it] = 1;
				}
			}
		}

		int poll = rand() % n;
		if(!areAllInfected(used, n))
		{
			while(used[poll])
				poll = rand() % n;
		}
		printf("%d ", poll+1);
		used[poll] = 1;
	}
	printf("\n");

}
