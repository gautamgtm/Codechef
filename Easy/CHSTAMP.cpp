//CHSTAMP
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
#define LLd long
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

LLd find_parent(LLd x, vector<LLd>& parent)
{
	while(parent[x] != x)
	{
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void unionNode(LLd x, LLd y, vector<LLd>& parent, vector<LLd>& size)
{
	LLd a = find_parent(x, parent), b = find_parent(y, parent);
	if(a == b)
		return;
	if(size[a] >= size[b])
	{
		size[a] += size[b];
		parent[b] = a;
	}
	else
	{
		size[b] += size[a];
		parent[a] = b;
	}
	return;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		LLd stamps, offers;
		LLd lastDay = 0;
		scanf("%ld %ld", &stamps, &offers);
		vector<LLd> collection(50005);

		//Input
		FOR(i,0,stamps-1)
		{
			LLd temp;
			scanf("%ld", &temp);
			collection[temp]++;
		}

		vector<pair<LLd, LLd> > offerDay[50005];
		FOR(i,0,offers-1)
		{
			LLd t,a,b;
			scanf("%ld %ld %ld", &t, &a, &b);
			offerDay[t].PB(MP(a,b));
			lastDay = max(lastDay, t);
		}

		//Solution Using Disjoint Union Set
		vector<LLd> max_type(50005);
		vector<LLd> parent(50005);
		vector<LLd> size(50005);
		FOR(i,0,50004)
		{
			max_type[i] = i;
			parent[i] = i;
			size[i] = 1;
		}

		FORD(i,lastDay,0)
		{
			//Make a disjoint union set
			FORV(offerDay[i], it)
			{
				unionNode(it->FF, it->SS, parent, size);
			}

			FORV(offerDay[i], it)
			{
				LLd a = it->FF, b = it->SS;
				LLd c = find_parent(a, parent); LLd d = find_parent(b, parent);
				//Updating the Root of each disjoint set with maxm of all the values in that set
				max_type[c] = max(max_type[a], max_type[c]);
				max_type[d] = max(max_type[b], max_type[d]);
			}
			FORV(offerDay[i], it)
			{
				LLd a = it->FF, b = it->SS;
				LLd c = find_parent(a, parent); LLd d = find_parent(b, parent);
				//Updating max_type of each node with the maxm of all the connected nodes
				max_type[a] = max_type[c];
				max_type[b] = max_type[d]; 
			}
			//Clear Parent and Size for next(previous) day
			FORV(offerDay[i], it)
			{
				LLd a = it->FF, b = it->SS;
				parent[a] = a;
				parent[b] = b;
				size[a] = 1;
				size[b] = 1;
			}
		}	

		LL answer = 0;
		FOR(i, 0, 50004)
		{
			answer += collection[i]*max_type[i];
		}
		printf("%Ld\n", answer);
	}

}