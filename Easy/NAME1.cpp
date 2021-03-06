//NAME1
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
		string father, mother;
		int children;
		cin>>father>>mother>>children;
		int parent[26]={}, child[26]={};

		FOR(i,0,father.size()-1)
			parent[father[i]-97]++;
		FOR(i,0,mother.size()-1)
			parent[mother[i]-97]++;

		FOR(i,0,children-1)
		{
			string temp;
			cin>>temp;
			FOR(j,0,temp.size()-1)
				child[temp[j]-97]++;
		}

		bool flag = true;
		FOR(i,0,25)
		{
			if(child[i] > parent[i])
			{
				flag = false;
				break;
			}
		}

		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

}