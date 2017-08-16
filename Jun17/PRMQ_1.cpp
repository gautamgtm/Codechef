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
#define lmt 1000005

int spf[lmt]={};
vector<PII> primeList[lmt];

inline void read(int &x)
{
	x=0;
	register char c=getchar_unlocked();
	for(;c<'0' || c>'9';c=getchar_unlocked());
	 for(;c>='0' && c<='9';c=getchar_unlocked())
	  x=(x<<3)+(x<<1)+(c-'0');
}

struct node
{
	int l,r,idx,flag;
};

vector<struct node> Q[lmt];

void sieve()
{
	spf[2] = 2;
	for(int i=2*2; i<lmt; i+=2)
		spf[i] = 2;
	for(int i=3; i<lmt; i+=2)
	{
	  if(spf[i] != 0)
			continue;
		spf[i] = i;
		for(int j=2*i; j<lmt; j+=i)
			if(spf[j] == 0)
				spf[j] = i;
	}
}

void process(int num, int idx)
{
	if(spf[num] == num)
		primeList[num].PB(MP(idx,1));
	else
	{
		while(num != 1)
		{
			if(primeList[spf[num]].size() == 0 || primeList[spf[num]][primeList[spf[num]].size()-1].first != idx)
				primeList[spf[num]].PB(MP(idx,1));
			else
				primeList[spf[num]][primeList[spf[num]].size()-1].second++;
			num /= spf[num];
		}
	}
}

void updateTree(int tree[], int node, int l, int r, int idx, int adder)
{
	if(l>r || idx < l || idx > r)
		return;
	if(l == r)
	{
		tree[node] += adder;
		return;
	}

	updateTree(tree, 2*node, l, (l+r)/2, idx, adder);
	updateTree(tree, 2*node+1, 1+(l+r)/2, r, idx, adder);
	tree[node] = tree[2*node] + tree[2*node+1];
}

int queryTree(int tree[], int node, int l, int r, int a, int b)
{
	if(l>r || l>b || r<a)
		return 0;

	if(l>=a && r<=b)
		return tree[node];

	int q1 = queryTree(tree, 2*node, l, (l+r)/2, a, b);
	int q2 = queryTree(tree, 2*node+1, 1+(l+r)/2, r, a, b);

	return q1+q2;
}


int main()
{
	cin.sync_with_stdio(0);
	sieve();
	int n,q,num;
	read(n);
	FOR(i,0,n-1)
	{
		read(num);
		process(num,i);
	}

	read(q);
	int ans[q]={}, segmentTree[4*lmt]={};
	FOR(i,0,q-1)
	{
		int l,r,x,y;
		read(l);read(r);read(x);read(y);
		l--;r--;
		struct node q1,q2;
		q1.l=l;q2.l=l;
		q1.r=r;q2.r=r;
		q1.idx=i;q2.idx=i;
		q1.flag=0;q2.flag=1;
		Q[x-1].PB(q1);Q[y].PB(q2);
	}

	FOR(i,0,lmt-1)
	{
		FIT(it, primeList[i])
			updateTree(segmentTree,1,0,n-1,it->first,it->second);

		FIT(it, Q[i])
		{
			if(it->flag == 0)
				ans[it->idx] -= queryTree(segmentTree,1,0,n-1,it->l,it->r);
			else
				ans[it->idx] += queryTree(segmentTree,1,0,n-1,it->l,it->r);
		}
	}

	FOR(i,0,q-1)
		printf("%d\n", ans[i]);

}
