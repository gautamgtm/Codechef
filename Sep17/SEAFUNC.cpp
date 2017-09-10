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

struct Ans{
		int col,d,l,r;
};

struct comp{
	bool operator() (const Ans& a, const  Ans& b){
		return a.d > b.d;
	}
};

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, dest=0, curr=0, count=0;
		scanf("%d", &n);
		string str[n];
		FOR(i,0,n-1) cin>>str[i];
	 	VI countOne(n,0);
		FOR(i,0,n-1) FOR(j,0,n-1) if(str[i][j] == '1') dest++;

		vector<Ans> v;
		FOR(i,0,n-1)
		{
			int j=0;
			while(j<n)
			{
				if(str[j][i] == '0') { j++; continue; }
				int l=j;
				while(j<n && str[j][i] == '1') j++;
				Ans a;
				a.col = i; a.l = l; a.r = j-1; a.d = (j-l);
				v.push_back(a);
			}
		}
		if(v.empty())
		{
			printf("0\n");
			continue;
		}

		sort(v.begin(), v.end(), comp());

		FOR(i,0,v.size()-1)
		{
			if(curr >= dest - 100) break;
			curr += v[i].d;
			count++;
		}

		printf("%d\n", count);
		if(!count) continue;
		FOR(i,0,count-1) printf("0 1 0 1 0 1 %d %d %d\n", 1+v[i].col, 1+v[i].l, 1+v[i].r);
	}

}
