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
		int n,q;
		scanf("%d %d", &n, &q);
		vector<set<string> > Tree(n+1);
		Tree[0].insert("0");
		int count = 1;
		string str, base;
		FOR(i,0,n-1) str += '0';
		base = str;
		while(q--)
		{
			string a;
			cin>>a;
			if(a == "!")
			{
				int x;
				scanf("%d", &x);
				if(str[x] == '0') str[x] = '1';
				else
				{
					int i=x;
					while(str[i] == '1') str[i++] = '0';
					if(i != n) str[i] = '1';
				}
				string s;
				FOR(i,1,n)
				{
					s += '0';
					if(str[n-i] == '1') s[s.size()-1] = '1';

					if(Tree[i].find(s) == Tree[i].end())
					{
						count++;
						Tree[i].insert(s);
					}
				}

			}
			else
				printf("%d\n", count);
		}

	}

}
